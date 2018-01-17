void TurnAround(){
//  interr
  attachInterrupt(digitalPinToInterrupt(leftA), EncodeTurnA, RISING);
  leftCounter = 0;
  leftSpeed =-100; 
  rightSpeed =100; 
  Drive();
  encoding = true;
  while(encoding){
    Serial.println("In turning around");
    
    delay(10);
  }
  detachInterrupt(digitalPinToInterrupt(leftA));
  
  
  }
void EncodeTurnA(){
  noInterrupts();
  if(turningAroundCounter<=leftCounter){    
    leftSpeed =0; 
    rightSpeed =0; 
    Drive();    
    encoding = false;
    }
  else{
    leftCounter++;
    }
  interrupts();
  }
  
void LinePass(){
 
  attachInterrupt(digitalPinToInterrupt(leftA), EncodeLinePass, RISING);
  leftCounter = 0;
  leftSpeed =100; 
  rightSpeed =100; 
  Drive();
  encoding = true;
  while(encoding){
      Serial.println("In line loop");
      delay(10);
  }
  detachInterrupt(digitalPinToInterrupt(leftA));
  
  
  }
void EncodeLinePass(){
  noInterrupts();
  if(turningLeftCounter<=leftCounter){
    leftSpeed =100; 
    rightSpeed =100; 
    Drive();
    encoding = false;
    }
  else{
    leftCounter++;
    leftSpeed =140-leftCounter; 
    rightSpeed =140-leftCounter; 
    Drive();
    }
  interrupts();
  }


void TurnLeft(){
  attachInterrupt(digitalPinToInterrupt(leftA), EncodeTurnL, RISING);
  leftCounter = 0;
  leftSpeed =-100; 
  rightSpeed =100; 
  Drive();
  encoding = true;
  while(encoding){
    Serial.println("In around loop");
    delay(10);
  }
  detachInterrupt(digitalPinToInterrupt(leftA));
  
  
  }
void EncodeTurnL(){
  noInterrupts();
  if(turningLeftCounter<=leftCounter){    
    leftSpeed =0; 
    rightSpeed =0; 
    Drive();    
    encoding = false;
    }
  else{
    leftCounter++;
    }
  interrupts();
  }

void TurnRightL(){
  attachInterrupt(digitalPinToInterrupt(leftA), EncodeTurnL, RISING);
  leftCounter = 0;
  leftSpeed =100; 
  rightSpeed =-100; 
  Drive();
  encoding = true;
  while(encoding){
    Serial.println("In Right(L) loop");
    delay(10);
  }
  detachInterrupt(digitalPinToInterrupt(leftA));
  
  
  }

void TurnRight(){
  attachInterrupt(digitalPinToInterrupt(rightA), EncodeTurnR, RISING);
  rightCounter = 0;
  leftSpeed =100; 
  rightSpeed =-100; 
  Drive();
  encoding = true;
  while(encoding){
    delay(10);
    Serial.println("In right loop");
  }
  detachInterrupt(digitalPinToInterrupt(rightA));
  
  
  }
void EncodeTurnR(){
noInterrupts();
  if(turningRightCounter<=rightCounter){
    leftSpeed =0; 
    rightSpeed =0; 
    Drive();
    encoding = false;
    }
  else{
    rightCounter++;
    }
 interrupts();
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
void EncodeDistance(){
  leftCounter++;
  }

