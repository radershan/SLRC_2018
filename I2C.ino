void SendColor(String color){
  answer = color;
  Wire.begin(9);
  Wire.onRequest(requestEvent);
  Serial.print("Sending Color");
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
  delay(100);
  digitalWrite(10,LOW);
  
}

void requestEvent() {
  byte response[ANSWERSIZE];
  for (byte i=0;i<ANSWERSIZE;i++) {
    response[i] = (byte)answer.charAt(i);
  }
  Wire.write(response,sizeof(response));
  Serial.println("Request event");
}

