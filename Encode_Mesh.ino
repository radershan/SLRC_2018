void Scan() {  
  lPos = pos;
  irSensorsL = irSensors;
  irSensors = B00000000;
  unsigned int position = qtrrc.readLine(sensorValues,QTR_EMITTERS_ON,true);
  pos=position;  
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(sensorValues[i]);
    Serial.print(" | ");
    if (sensorValues[i] <= treashold) {
        irSensorDigital[i] = 1;
    }
    else {irSensorDigital[i] = 0;}
        int b = 7-i;
      irSensors = irSensors + (irSensorDigital[
      i]<<b);
    } 
    Serial.print('\t');
    Serial.print(irSensors,BIN);
    Serial.print('\t');
    Serial.println(pos);
      
}

void Update(){
  switch(irSensors){
    //Detecting Dead End
    case B00000000:
    if(lPos < 2500){
      //turn right side
      }
    else if (lPos > 4500){
      //turn left side
      }
    else{
      //Box detection
      }
    break;

    //Detecting MazeEnd, T , + Junction
    case B11111111:
       LinePass();
       Scan();
       //MazeEnd
       if(irSensors == B11111111){
        //End of Maze
        }
       //T or + Junction
       else{
        TurnLeft();
       }
    break;

    //Detecting -| or left L
    case B11111100:
       LinePass();
       TurnLeft();
    break;

    case B11111000:
       LinePass();
       TurnLeft();
    break;

    //Detecting |- or right L
    case B00111111:
       LinePass();
       Scan();
       if(irSensors == B00000000){
       TurnRight();
       }
       else{
        Pid_Line();
       }
    break;

    case B00011111:
       LinePass();
       Scan();
       if(irSensors == B00000000){
       TurnRight();
       }
       else{
        Pid_Line();
       }
    break;
    
    default :
    Pid_Line();
    
    }
    
  }
