
void Wall_Follow(){
 int dis =Distance(trigPinR,echoPinR);
 int frontDis=Distance(trigPinF,echoPinF);
 Serial.println(frontDis);
 if (frontDis<=1000){
  Drive(-60,60);
  Serial.println("klk");
 }
 else{
 wallError=dis -650;
 int wallValue=wallKp*wallError+wallKd*(wallError-wallLastError);
  Drive(100+wallValue,100-wallValue);
wallLastError=wallError;
 }
}

