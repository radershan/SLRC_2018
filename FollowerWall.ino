
void Wall_Follow(){
 int dis =Distance(trigPinR,echoPinR);
 int frontDis=Distance(trigPinF,echoPinF);
 Serial.println(frontDis);
 if (frontDis<=1000){
  leftSpeed =-60; 
  rightSpeed =60; 
  Drive();
  Serial.println("klk");
 }
 else{
 wallError=dis -650;
 int wallValue=wallKp*wallError+wallKd*(wallError-wallLastError);
 leftSpeed =100+wallValue; 
 rightSpeed =100-wallValue; 
  Drive();
wallLastError=wallError;
 }
}

