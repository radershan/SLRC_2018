void Scan() {  
  lPos = pos;
  irSensorsL = irSensors;
  irSensors = B00000000;
  unsigned int position = qtrrc.readLine(sensorValues,QTR_EMITTERS_ON,true);
  pos=position;  
  for (int i = 0; i < NUM_SENSORS; i++) {
   /* Serial.print(sensorValues[i]);
    Serial.print(" | ");*/
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

void UpdateLine(){
  
  switch(irSensors){
    //Break();
    //Detecting Dead End
    case B00000000:
    if(irSensorsL ==B00111100 or irSensorsL ==B00011100 or irSensorsL ==B00111000 or irSensorsL ==B01111000 or irSensorsL ==B00011110 or irSensorsL ==B01110000 or irSensorsL ==B00001110){
      Buzzer();
      delay(500);
      Buzzer();
      delay(1000);
      DetectBox();
      Buzzer();
      
      TurnAround();
      }
   
    
    else{
      //Box detection
      Pid_Line();
      }
    break;

    //Detecting MazeEnd, T , + Junction
    case B11111111:
       //LinePass();
      // Break();
       Scan();
       //MazeEnd
       if(irSensors == B11111111){
        //End of Maze
         pinMode(13, OUTPUT);
         digitalWrite(13, HIGH); 
        }
       //T or + Junction
       else{
       
        TurnLeft();
       }
    break;

    //Detecting -| or left L
    case B11111100:
      //  Break();
      // LinePass();
       TurnLeft();
    break;

    case B11111000:
     //   Break();
       //LinePass();
       TurnLeft();
    break;

    //Detecting |- or right L
    case B00111111:
       //LinePass();
       //Break();
       Scan();
       if(irSensors == B00000000){
        
       TurnRight();
       }
       else{
     
        Pid_Line();
       }
    break;

    case B00011111:
     // Break();
      // LinePass();
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
  
    

