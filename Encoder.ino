void turnLeft(){
  attachInterrupt(digitalPinToInterrupt(leftA), EncodeTurnL, RISING);
  leftCounter = 0;
  Drive(100,-100);
  turningLeft = true;
  while(turningLeft){
  }
  detachInterrupt(digitalPinToInterrupt(leftA));
  
  
  }
void EncodeTurnL(){
  if(turningLeftCounter<=leftCounter){
    noInterrupts();
    Drive(0,0);
    turningLeft = false;
    interrupts();
    }
  else{
    leftCounter++;
    }
  }

void turnRight(){
  attachInterrupt(digitalPinToInterrupt(rightA), EncodeTurnR, RISING);
  
  rightCounter = 0;
  Drive(-100,100);
  turningRight = true;
  while(turningRight){
  }
  detachInterrupt(digitalPinToInterrupt(rightA));
  
  
  }
void EncodeTurnR(){
  if(turningRightCounter<=rightCounter){
    noInterrupts();
    Drive(0,0);
    turningRight = false;
    interrupts();
    }
  else{
    rightCounter++;
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

