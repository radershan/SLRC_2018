
void Qtr_Calibration()
{
  delay(500);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);    
  for (int i = 0; i < 400; i++)  
  {

    qtrrc.calibrate(QTR_EMITTERS_ON);       

  }
  digitalWrite(13, LOW);     
  /*for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMinimumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  
  // print the calibration maximum values measured when emitters were on
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMaximumOn[i]);
    Serial.print(' ');
  }*/
}
 
  
  void Read_Line()
{
  //  qtrrc.read(sensorValues); instead of unsigned int position = qtrrc.readLine(sensorValues);
  unsigned int position = qtrrc.readLine(sensorValues,QTR_EMITTERS_ON,true);
  pos=position;
  /*for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println(position); 
  delay(250);*/
}

void Pid_Line(){
  Read_Line();
  lineError=3200-pos;
 //Serial.print(lineError);
  //Serial.print('\t');
 
  float espeed=(lineKp*lineError)+lineKd*(lineError-lineLastError);
  int rSpeed=initalspeed+espeed;
  int lSpeed=initalspeed-espeed;
  lineLastError=lineError;
  
  
  if (rSpeed > MaxSpeed ) rSpeed = MaxSpeed; // prevent the motor from going beyond max speed
  if (lSpeed > MaxSpeed ) lSpeed = MaxSpeed; // prevent the motor from going beyond max speed
  if (rSpeed < MinSpeed) rSpeed = MinSpeed; // keep the motor speed positive
  if (lSpeed < MinSpeed) lSpeed = MinSpeed; // keep the motor speed 
 //Serial.print(rSpeed);
 //Serial.print("  ");
  //Serial.print(lSpeed);
 // Serial.print('\t');
 // Serial.println();
  Drive(lSpeed,rSpeed);
  delay(10);
  Drive(0,0);
  //Drive(200,200);
  
  
}
