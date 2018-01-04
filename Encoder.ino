void LinePass(){
  attachInterrupt(digitalPinToInterrupt(leftA), EncodeLinePass, RISING);
  leftCounter = 0;
  Drive(100,100);
  encoding = true;
  while(encoding){
  }
  detachInterrupt(digitalPinToInterrupt(leftA));
  
  
  }
void EncodeLinePass(){
  if(turningLeftCounter<=leftCounter){
    noInterrupts();
    Drive(0,0);
    encoding = false;
    interrupts();
    }
  else{
    leftCounter++;
    }
  }


void TurnLeft(){
  attachInterrupt(digitalPinToInterrupt(leftA), EncodeTurnL, RISING);
  leftCounter = 0;
  Drive(100,-100);
  encoding = true;
  while(encoding){
  }
  detachInterrupt(digitalPinToInterrupt(leftA));
  
  
  }
void EncodeTurnL(){
  if(turningLeftCounter<=leftCounter){
    noInterrupts();
    Drive(0,0);
    encoding = false;
    interrupts();
    }
  else{
    leftCounter++;
    }
  }

void TurnRight(){
  attachInterrupt(digitalPinToInterrupt(rightA), EncodeTurnR, RISING);
  
  rightCounter = 0;
  Drive(-100,100);
  encoding = true;
  while(encoding){
  }
  detachInterrupt(digitalPinToInterrupt(rightA));
  
  
  }
void EncodeTurnR(){
  if(turningRightCounter<=rightCounter){
    noInterrupts();
    Drive(0,0);
    encoding = false;
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

