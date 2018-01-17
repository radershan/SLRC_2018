void DistanceMeasure(){
  Scan();
  while(irSensors != B11111100 and irSensors != B11111000 ){
    Pid_Line();
    Scan();
    }
  TurnLeft();
  Scan();
   while(irSensors != B11111111){
    Pid_Line();
    Scan();
    }
  
  attachInterrupt(digitalPinToInterrupt(leftA), EncodeDistance, RISING);
  leftCounter = 0;
  while(Distance(trigPinF,echoPinF)>40){
    Scan();
    Pid_Line();
    }
  detachInterrupt(digitalPinToInterrupt(leftA));
  }
