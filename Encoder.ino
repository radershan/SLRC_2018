void turnLeft(){
  attachInterrupt(digitalPinToInterrupt(leftA), EncoderL, RISING);
  attachInterrupt(digitalPinToInterrupt(leftB), EncoderBL, CHANGE);
  leftBState = digitalRead(leftB);
  leftCounter = 0;
  Drive(100,-100);
  turningLeft = true;
  while(turningLeft){
    Drive(0,0);
    noInterrupts();
    if(turningLeftCounter<=abs(leftCounter)){
      detachInterrupt(digitalPinToInterrupt(leftA));
      detachInterrupt(digitalPinToInterrupt(leftB));
      Drive(0,0);
    
      turningLeft = false;
      break;
      }
    interrupts();
    Drive(125,-125);
      }
  
  }

void EncoderR() { 
  
   if (rightBState ==LOW){
    rightCounter++;
    }
   else{
    rightCounter--;
    }
   
 }

void EncoderL() { 

   if (leftBState ==LOW){
    leftCounter++;
    }
    
   else{
    leftCounter--;
    }
  
 }

void EncoderBL(){

  leftBState = !leftBState;
  }

void EncoderBR(){

  rightBState = !rightBState;
  }

