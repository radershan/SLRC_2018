
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

  lineError=3500-pos;
 //Serial.print(lineError);
  //Serial.print('\t');
 
  float espeed=(lineKp*lineError)+lineKd*(lineError-lineLastError);
  rightSpeed=initalspeed+espeed;
  leftSpeed=initalspeed-espeed;
  lineLastError=lineError;
  
  
  if (rightSpeed > MaxSpeed ) rightSpeed = MaxSpeed; // prevent the motor from going beyond max speed
  if (leftSpeed > MaxSpeed ) leftSpeed = MaxSpeed; // prevent the motor from going beyond max speed
  if (rightSpeed < MinSpeed) rightSpeed = MinSpeed; // keep the motor speed positive
  if (leftSpeed < MinSpeed) leftSpeed = MinSpeed; // keep the motor speed 
 //Serial.print(rSpeed);
 //Serial.print("  ");
  //Serial.print(lSpeed);
 // Serial.print('\t');
 // Serial.println();
  Drive();
 delay(40);
 rightSpeed=0;
  leftSpeed=0;
 Drive();
  //Drive(200,200);
  
  
}
