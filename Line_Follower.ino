
void Qtr_Calibration()
{
  delay(500);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);    
  for (int i = 0; i < 400; i++)  
  {
    qtrrc.calibrate();       
  }
  digitalWrite(13, LOW);     
  for (int i = 0; i < NUM_SENSORS; i++)
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
  }
}
 
  
  void Read_Line()
{
  //  qtrrc.read(sensorValues); instead of unsigned int position = qtrrc.readLine(sensorValues);
  unsigned int position = qtrrc.readLine(sensorValues);
  pos=position;
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println(position); 
  delay(250);
}

void Pid_Line(){
  Read_Line();
  lineError=3200-pos;
  Serial.print(lineError);
  Serial.print('\t');
  int  initalspeed=150;
  float espeed=lineKp*lineError;
  int rspeeed=initalspeed+espeed;
  int lspeed=initalspeed-espeed;
  lineLastError=lineError;
  Serial.print(rspeeed);
  Serial.print('\t');
  Serial.print(lspeed);
  Serial.print('\t');
  Serial.println();
  
}
