void intro() {
  Serial.println("INVERTER AC 3 PHASA");
  Serial.println("IRAMS10UP60B-2#####");
  Serial.println("GALIH SETYAWAN#####");
  Serial.println("1 Set Frequency Signal");
  Serial.println("2 Set Freqyency Carrier");
  Serial.println("3 Set Amplitudo Amplitudo");
  Serial.println("* Turn ON INVERTER");
  Serial.println("# Turn OFF INVERTER");
}

void lcdprint(int c, int r, char text[20]) {
  lcd.setCursor(c, r);
  lcd.print(text);
}

void clearR(int z) {
  lcdprint(0, z, "                    ");
  delay(5);
}

