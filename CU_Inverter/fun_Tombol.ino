//void setting_tombol(){
//  idx=0;
//  while(check==1){
//    int var[4];
//
//    int cek_tombol = tombol();
//    Serial.print("MASUKAN NILAI FREKUENSI SINYAL : ");
//    while(cek_tombol!=99){
////      Serial.println(cek_tombol);
//      if(cek_tombol==10){
//        idx--;
//        if(idx<=0)idx=0;
//        cek_tombol=99;
//      }else if(cek_tombol==11){
//        SerialUNO.print("@");delay(5);
//        SerialUNO.print("1");delay(5);
//        SerialUNO.print(",");delay(5);
//        for(int a=1;a<=idx;a++){
//          SerialUNO.print(var[a-1]);
//          delay(5);
//        }
//        SerialUNO.print("#");
//        cek_tombol=99;
//        intro();
//        check=99;
//      }else{
//        var[idx]=cek_tombol;
//        idx++;
//        cek_tombol=99;
//      }
//    }
//    if(idx==0){
//      Serial.println("0");
//    }else{
//      for(int a=1;a<=idx;a++){
//        Serial.print(var[a-1]);
//      }
//      Serial.println();
//    }
//
//  }
//
//  while(check==2){
//    int var[4];
//
//    int cek_tombol = tombol();
//    Serial.print("MASUKAN NILAI FREKUENSI CARRIER : ");
//    while(cek_tombol!=99){
////      Serial.println(cek_tombol);
//      if(cek_tombol==10){
//        idx--;
//        if(idx<=0)idx=0;
//        cek_tombol=99;
//      }else if(cek_tombol==11){
//        SerialUNO.print("@");delay(5);
//        SerialUNO.print("2");delay(5);
//        SerialUNO.print(",");delay(5);
//        for(int a=1;a<=idx;a++){
//          SerialUNO.print(var[a-1]);
//          delay(5);
//        }
//        SerialUNO.print("#");
//        cek_tombol=99;
//        intro();
//        check=99;
//      }else{
//        var[idx]=cek_tombol;
//        idx++;
//        cek_tombol=99;
//      }
//    }
//    if(idx==0){
//      Serial.println("0");
//    }else{
//      for(int a=1;a<=idx;a++){
//        Serial.print(var[a-1]);
//      }
//      Serial.println();
//    }
//
//  }
//  while(check==3){
//    int var[4];
//
//    int cek_tombol = tombol();
//    Serial.print("MASUKAN NILAI FREKUENSI Amplitudo : ");
//    while(cek_tombol!=99){
////      Serial.println(cek_tombol);
//      if(cek_tombol==10){
//        idx--;
//        if(idx<=0)idx=0;
//        cek_tombol=99;
//      }else if(cek_tombol==11){
//        SerialUNO.print("@");delay(5);
//        SerialUNO.print("3");delay(5);
//        SerialUNO.print(",");delay(5);
//        for(int a=1;a<=idx;a++){
//          SerialUNO.print(var[a-1]);
//          delay(5);
//        }
//        SerialUNO.print("#");
//        cek_tombol=99;
//        intro();
//        check=99;
//      }else{
//        var[idx]=cek_tombol;
//        idx++;
//        cek_tombol=99;
//      }
//    }
//    if(idx==0){
//      Serial.println("0");
//    }else{
//      for(int a=1;a<=idx;a++){
//        Serial.print(var[a-1]);
//      }
//      Serial.println("%");
//    }
//
//  }
//  while(check==13){
//    Serial.println("keluar");
//    latch=0;
//    check=99;
//  }
//}


void setting_tombol() {
  while (check == 1) {
    check_button(1);
  }
  while (check == 2) {
    check_button(2);
  }
//  while (check == 3) {
//    check_button(3);
//  }
  while (check == 14) {
    Serial.println("keluar");
    latch = 0;
    check = 99;
  }
}

