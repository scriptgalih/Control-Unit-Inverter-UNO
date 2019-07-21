#include <SoftwareSerial.h>
#include <Wire.h>  // i2C Conection Library
#include <LiquidCrystal_I2C.h>  //i2C LCD Library
#include <EEPROM.h>

#define eFsin 0
#define eHFcar 1
#define eLFcar 2
#define eAmp 3
#define iTrip 7



int sInv = 0;
SoftwareSerial SerialUNO(10, 11); // RX, TX
LiquidCrystal_I2C lcd(0x27, 20, 4);
int r[4] = {A1, 9, A2, 8}; //5x4
int c[4] = { 4, 3, 5, 2};

//int r[4] = {8, A2, 9, A1}; //4x4
//int c[4] = { 4, 3, 5, 2};
unsigned long previousMillis = 0;
const long interval = 500;
int lfSin ;
int lfCar ;
void setup() {
  pinMode(12,1);
  digitalWrite(12,1);
  // put your setup code here, to run once:
  Serial.begin(9600);
  SerialUNO.begin(4800);
  lfSin = EEPROM.read(eFsin);
  lfCar = (EEPROM.read(eHFcar) * 255) + EEPROM.read(eLFcar);
  SerialUNO.print("@"); delay(5);
  SerialUNO.print("1"); delay(5);
  SerialUNO.print(","); delay(5);
  SerialUNO.print(lfSin); delay(5);
  SerialUNO.print("#");

  delay(100);

  SerialUNO.print("@"); delay(5);
  SerialUNO.print("2"); delay(5);
  SerialUNO.print(","); delay(5);
  SerialUNO.print(lfCar); delay(5);
  SerialUNO.print("#");

  lcd.begin();
  lcdprint(0, 0, "-INVERTER AC 3 FASA-");
  lcdprint(0, 1, "GALIH SETYAWAN");
  lcdprint(0, 2, "SEKOLAH VOKASI");
  lcdprint(0, 3, "UGM");
  delay(200);
  pinMode(iTrip, INPUT);
  digitalWrite(iTrip, HIGH);
  lcd.clear();
  delay(100);
  //  lcdprint(0,0,"-INVERTER OFF");
  //  lcdprint(0,1,"f sin:50Hz temp:20'c");
  //  lcdprint(0,2,"f carrier:2KHz");
  //  lcdprint(0,3,"*:ON #:OFF A:Menu");

  //EEPROM.update(0, 50);
  //EEPROM.update(1, 2);
  //EEPROM.update(2, 0);
  //EEPROM.update(3, 100);

  for (int x = 0; x <= 3; x++) {
    pinMode(r[x], OUTPUT);
  }
  for (int x = 0; x <= 3; x++) {
    pinMode(c[x], INPUT);
  }
  for (int x = 0; x <= 3; x++) {
    digitalWrite(r[x], HIGH);
  }
  for (int x = 0; x <= 3; x++) {
    digitalWrite(c[x], HIGH);
  }
  intro();
}
int check;
int idx = 0;
int latch = 0;
int tampil_lcd = 0;
void loop() {
  // put your main code here, to run repeatedly:
  //int a = digitalRead(iTrip);
  //Serial.println(a);
  if (tampil_lcd == 0) {
    lcd.clear(); delay(5);
    int lfSin = EEPROM.read(eFsin);
    int lfCar = (EEPROM.read(eHFcar) * 255) + EEPROM.read(eLFcar);
    lcdprint(0, 0, "INVERTER");
    delay(10);
    if (sInv == 0) {
      lcd.print(" OFF ");
    } else {
      lcd.print(" ON  ");
    }
    //        lcdprint(0,1,"f sin:50Hz temp:20'c");
    lcdprint(0, 1, "f sin:"); lcd.print(lfSin); lcd.print("Hz");
    lcdprint(0, 2, "f car:"); lcd.print(lfCar); lcd.print("Hz");
    lcdprint(13, 0, "Amp:1");
    lcdprint(0, 3, "*:ON #:OFF A:Menu");
    tampil_lcd = 1;
  }
  check = tombol();


  while (check == 10) {
    if(sInv == 1){
      break;
    }
    digitalWrite(12,1);
    
    Serial.print("INVERTER AKTIF . . .");
    SerialUNO.print("@"); delay(5);
    SerialUNO.print("0"); delay(5);
    SerialUNO.print(","); delay(5);
    SerialUNO.print("1"); delay(5);
    SerialUNO.print("#");
    tampil_lcd = 0;
    sInv = 1;
    intro();
    check = 99;
    delay(100);
    digitalWrite(12,0);
  }
  while (check == 11) {
    digitalWrite(12,1);
    Serial.print("INVERTER TIDAK AKTIF . . .");
    SerialUNO.print("@"); delay(5);
    SerialUNO.print("0"); delay(5);
    SerialUNO.print(","); delay(5);
    SerialUNO.print("0"); delay(5);
    SerialUNO.print("#");
    tampil_lcd = 0;
    sInv = 0;
    intro();
    check = 99;
  }
  if (check == 12 && sInv == 0) {
    Serial.println("masuk menu");
    latch = 1;
    tampil_lcd = 0;
    while (latch == 1) {
      if (tampil_lcd == 0) {
        lcd.clear(); delay(5);
        lcdprint(0, 0, "MENU");
        lcdprint(0, 1, "1. Set freq Sinyal");
        lcdprint(0, 2, "2. Set freq Carrier");
//        lcdprint(0, 3, "3. Set freq Amp");
        tampil_lcd = 1;
      }
      check = tombol();
      //    int latch=1;
      setting_tombol();
    }
    tampil_lcd = 0;
  }
}


