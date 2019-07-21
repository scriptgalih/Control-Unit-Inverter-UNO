void check_button(int ax) {
  int idx = 0;
  int latch1 = 1;
  while (latch1 == 1 && (ax == 1 || ax == 2 || ax == 3)) {
    int var[5];
    int gabung = 0;
    int cek_tombol = tombol();
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      switch (ax) {
        case 1:
          Serial.print("MASUKAN NILAI FREKUENSI SINYAL : ");
          lcdprint(0, 1, "freq sinyal:      ");
          lcd.setCursor(13, 1);
          break;
        case 2:
          Serial.print("MASUKAN NILAI FREKUENSI CARRIER : ");
          lcdprint(0, 2, "freq carrier:      ");
          lcd.setCursor(14, 2);
          break;
        //        case 3:
        //          Serial.print("MASUKAN NILAI FREKUENSI AMPLITUDO : ");
        //          lcdprint(0, 3, "freq Amp:      ");
        //          lcd.setCursor(10, 3);
        //          break;
        //          break;
        default:
          // if nothing else matches, do the default
          // default is optional
          break;
      }

    }

    while (cek_tombol != 99) {
      if (cek_tombol == 10) {
        idx--;
        if (idx <= 0)idx = 0;
        cek_tombol = 99;
      } else if (cek_tombol == 15) {
        digitalWrite(12, 1);
        SerialUNO.print("@"); delay(5);
        switch (ax) {
          case 1:
            SerialUNO.print("1"); delay(5);
            break;
          case 2:
            SerialUNO.print("2"); delay(5);
            break;
          case 3:
            SerialUNO.print("3"); delay(5);
            break;
            break;
          default:
            // if nothing else matches, do the default
            // default is optional
            break;
        }
        SerialUNO.print(","); delay(5);
        for (int a = 1; a <= idx; a++) {
          SerialUNO.print(var[a - 1]);
          delay(5);
        }
        SerialUNO.print("#");
        //        gabung;
        gabung = 0;
        for (int a = 1; a <= idx; a++) {
          gabung += var[a - 1] * (pow(10, (a - idx) * -1));
        }
        if (idx >= 3) {
          gabung += 1;
        }
        delay(10);
        digitalWrite(12, 0);
        switch (ax) {
          case 1:
            EEPROM.update(eFsin, gabung);
            break;
          case 2:
            EEPROM.update(eHFcar, gabung / 255);
            EEPROM.update(eLFcar, gabung % 255);
            Serial.print(gabung / 1000);
            Serial.print(" ");
            Serial.print(gabung % 255);
            break;
          case 3:
            EEPROM.update(eAmp, gabung);
            break;
            break;
          default:
            // if nothing else matches, do the default
            // default is optional
            break;
        }
        cek_tombol = 99;
        intro();
        check = 99;
        latch1 = 0;
        ax = 99;
        idx = 0;
        tampil_lcd = 0;
      } else if (cek_tombol == 11  || cek_tombol == 12 || cek_tombol == 13) {
        cek_tombol = 99;
      }else if (cek_tombol == 14) {
        cek_tombol = 99;
        intro();
        check = 99;
        latch1 = 0;
        ax = 99;
        idx = 0;
        tampil_lcd = 0;
      } else {
        var[idx] = cek_tombol;
        idx++;
        cek_tombol = 99;
        Serial.println("cucok");
      }
    }
    if (currentMillis - previousMillis >= interval) {
      if (idx == 0) {
        Serial.println("0");
        lcd.print("0");
      } else {
        for (int a = 1; a <= idx; a++) {
          Serial.print(var[a - 1]);
          lcd.print(var[a - 1]);
        }
        gabung = 0;
        for (int a = 1; a <= idx; a++) {
          gabung += var[a - 1] * (pow(10, (a - idx) * -1));
        }
        if (idx >= 3) {
          gabung += 1;
        }
        Serial.print("\t");
        Serial.print(gabung);
        Serial.println();
      }
      previousMillis = currentMillis;
    }
  }
}

