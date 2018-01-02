void pid(){
  readline();
//  error=338position;
Serial.print(error);
Serial.print('\t');

int  initalspeed=150;
  float espeed=kp*error+kd*lasterror;
  digitalWrite(motorR1,HIGH); 
 digitalWrite(motorR2,LOW);
 analogWrite(motorRE,initalspeed-espeed);
 digitalWrite(motorL1,HIGH); 
 digitalWrite(motorL2,LOW);
 analogWrite(motorLE,initalspeed+espeed);
 lasterror=error;
}

