
void TestUltraSonic(){
  Serial.print("Front : ");
  Serial.print(Distance(trigPinF, echoPinF));
  Serial.print('\t');
  Serial.print("LeftF : ");
  Serial.print(Distance(trigPinLF, echoPinLF));
  Serial.print('\t');
  Serial.print("LeftB : ");
  Serial.print(Distance(trigPinLB, echoPinLB));
  Serial.print('\t');
  Serial.print("RightF : ");
  Serial.print(Distance(trigPinRF, echoPinRF));
  Serial.print('\t');
  Serial.print("RightB : ");
  Serial.print(Distance(trigPinRB, echoPinRB));
  Serial.println('\t');
  }

float Distance(int trigPin, int echoPin)
{
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  //long cm = MicrosecondsToCentimeters(duration);
   float dist=duration/58.2;
   
  if (dist==0.0||dist>=240.0){
    dist=4000.0;
  }
  return dist;
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
