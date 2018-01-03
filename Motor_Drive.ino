void Drive(int leftSpeed, int rightSpeed){
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

  
  if (leftSpeed==0 and rightSpeed == 0){
    digitalWrite(leftMotorE,HIGH);
    digitalWrite(rightMotorE,HIGH);
    }
  else{
    analogWrite(leftMotorE,abs(leftSpeed));
  analogWrite(rightMotorE,abs(rightSpeed));
    }
  }
