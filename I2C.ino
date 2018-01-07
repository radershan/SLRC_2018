void receiveEvent(int countToRead) {
  while (0 < Wire.available()) {
    byte x = Wire.read();
    Serial.println(x);
  }
  waitForReply = false;
  digitalWrite(sendRequest,LOW);
  Serial.println("Receive event");
  Buzzer();
}

void requestEvent() {
  byte response[ANSWERSIZE];
  for (byte i=0;i<ANSWERSIZE;i++) {
    response[i] = (byte)answer.charAt(i);
  }
  Wire.write(response,sizeof(response));
  Serial.println("Request event");
}



