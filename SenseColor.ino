void SenseColor(){
// Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  currentColor[0]= pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
 /* lcd.setCursor(0,0);
  lcd.print("R= ");//printing name*/
  lcd.setCursor(2,0);
  lcd.print(currentColor[0]);//printing RED color frequency
  delay(10);
  // Setting Green filtered photodiodes to be read
 digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  currentColor[1] = pulseIn(sensorOut, LOW);
   // Printing the value on the serial monitor
 /* lcd.setCursor(8,0);
  lcd.print("G= ");//printing name*/
  lcd.setCursor(10,0);
  lcd.print(currentColor[1]);//printing RED color frequency
  delay(10);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  currentColor[2] = pulseIn(sensorOut, LOW);
   // Printing the value on the serial monitor
 /* lcd.setCursor(0,1);
  lcd.print("B= ");//printing name*/
  lcd.setCursor(2,1);
  lcd.print(currentColor[2]);//printing RED color frequency
  delay(10);
  }
