void Break(){
  leftSpeed =-255; 
  rightSpeed =-255; 
  Drive();
  delay(10);
  leftSpeed =0; 
  rightSpeed =0; 
  Drive();
  delay(1000);
  };

void Drive(){
  if(rightSpeed>0){
    digitalWrite(rightMotorA,HIGH);
    digitalWrite(rightMotorB,LOW);
    }
  else if(rightSpeed<0){
    digitalWrite(rightMotorA,LOW);
    digitalWrite(rightMotorB,HIGH);
    }
  else{
    digitalWrite(rightMotorA,HIGH);
    digitalWrite(rightMotorB,HIGH);
    }
  
  if(leftSpeed>0){
    digitalWrite(leftMotorA,HIGH);
    digitalWrite(leftMotorB,LOW);
    }
  else if(leftSpeed<0){
    digitalWrite(leftMotorA,LOW);
    digitalWrite(leftMotorB,HIGH);
    }
  else{
    digitalWrite(leftMotorA,HIGH);
    digitalWrite(leftMotorB,HIGH);
    }

  

  
  if (leftSpeed==0 and rightSpeed == 0){
    digitalWrite(leftMotorE,HIGH);
    digitalWrite(rightMotorE,HIGH);
    }
  else{
    analogWrite(rightMotorE,abs(rightSpeed));
    analogWrite(leftMotorE,abs(leftSpeed));
  
    }
  }
