void scanR(int x) {
  for (int y = 0; y <= 3; y++) {
    if (y == x - 1) {
      digitalWrite(r[y], LOW);
    } else {
      digitalWrite(r[y], HIGH);
    }

  }
}
void delaay(int x) {
  while (digitalRead(c[x]) == LOW) {
//    Serial.print("aa");
    delay(1);
  }
}

int tombol() {
  int out = 99;
  scanR(1);
  if (digitalRead(c[0]) == LOW) {
    delaay(0); out = 1;
    Serial.println(out);
  } else if (digitalRead(c[1]) == LOW) {
    delaay(1); out = 2;Serial.println(out);
  } else if (digitalRead(c[2]) == LOW) {
    delaay(2); out = 3;Serial.println(out);
  } else if (digitalRead(c[3]) == LOW) {
    delaay(2); out = 12;Serial.println(out);
  }
  scanR(2);
  if (digitalRead(c[0]) == LOW) {
    delaay(0); out = 4;Serial.println(out);
  } else if (digitalRead(c[1]) == LOW) {
    delaay(1); out = 5;Serial.println(out);
  } else if (digitalRead(c[2]) == LOW) {
    delaay(2); out = 6;Serial.println(out);
  } else if (digitalRead(c[3]) == LOW) {
    delaay(2); out = 13;Serial.println(out);
  }
  scanR(3);
  if (digitalRead(c[0]) == LOW) {
    delaay(0); out = 7;Serial.println(out);
  } else if (digitalRead(c[1]) == LOW) {
    delaay(1); out = 8;Serial.println(out);
  } else if (digitalRead(c[2]) == LOW) {
    delaay(2); out = 9;Serial.println(out);
  }
  scanR(4);
  if (digitalRead(c[0]) == LOW) {
    delaay(0); out = 10;Serial.println(out);
  } else if (digitalRead(c[1]) == LOW) {
    delaay(1); out = 0;Serial.println(out);
  } else if (digitalRead(c[2]) == LOW) {
    delaay(2); out = 11;Serial.println(out);
  }

  return out;
}



