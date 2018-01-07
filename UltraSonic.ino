void TestUltraSonic(){
  Serial.print("Front : ");
  Serial.print(Distance(trigPinF, echoPinF));
  Serial.print('\t');
  Serial.print("Left : ");
  Serial.print(Distance(trigPinL, echoPinL));
  Serial.print('\t');
  Serial.print("Right : ");
  Serial.print(Distance(trigPinR, echoPinR));
  Serial.println('\t');
  }
long Distance(int trigPin, int echoPin)
{
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long cm = MicrosecondsToCentimeters(duration);
  
}


long MicrosecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

void Buzzer(){
  for (int i=0; i<250; i++) {  // generate a 1KHz tone for 1/2 second
 digitalWrite(SPKR, HIGH);
 delayMicroseconds(1000);
  digitalWrite(SPKR, LOW);
  delayMicroseconds(500);
 }
  }
