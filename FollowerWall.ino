
/*void Wall_Follow(){
 int dis =Distance(trigPinR,echoPinR);
 int frontDis=Distance(trigPinF,echoPinF);
 Serial.println(frontDis);
 if (frontDis<=1000){
  leftSpeed =-50; 
  rightSpeed =50; 
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
}*/

void Wall_following(){ //12.3
   float dis1 = Distance(trigPinLF,echoPinLF);
   float dis2 = Distance(trigPinLB,echoPinLB);
   float front =Distance(trigPinF,echoPinF);
  Serial.print(front);
  Serial.println();
   if (front <=30){
    //Break();
    leftSpeed=70;
    rightSpeed=-70;
    Drive();
    delay(70);
    }
    else if(front <=10){
      leftSpeed=-70;
    rightSpeed=-70;
    Drive();
    }
   else{
    if(dis1!=4000 || dis2 !=4000){
    int angle = dis1-dis2;
    float dis = Cal_Distance(dis1,dis2);
    float interDistance = 0.5 * Cal_Distance(dis1,dis2) + 0.5 * 10;
    Serial.print('\t');
    Serial.print(angle);
    Serial.print('\t');
    Serial.print(interDistance);
    Serial.println();
  disError =  interDistance-10;
 
  disCorrection =  disKp*disError+disKd*(disError-disLastError);
  disLastError = disError;

   //pid angle
   angleCorrection = angKp*angle + angKd*(angle-lastAngle);
   lastAngle = angle;

   drive = disCorrection + angleCorrection;

   if (drive<=0) {
    drive=(-1*drive);
   }
   if (drive>=100) {
    drive=100 ;
   }
   leftSpeed =60; 
   rightSpeed =60;


   
   
   if (dis<=interDistance-2){
    Serial.print("1");
      if (angle<5){
        //away
        Serial.print("a");
        leftSpeed +=drive;
        rightSpeed-=drive;
      }
      else if (angle>5){
       
        //close
        Serial.print("c");
        rightSpeed+=drive;
        leftSpeed -=drive;
  
      }
   }
   else if (dis>=interDistance+2){
        //close
        Serial.print("3");
        if (angle>10){
         Serial.print("c");
        rightSpeed+=drive;
        leftSpeed -=drive;
        }
   }
   else{
    Serial.print("2");
    if (angle<2){
        //away
        Serial.print("a");
        leftSpeed +=drive;
       rightSpeed-=drive;
      }
      else if (angle>2){
      
        
        Serial.print("c");
        //close
        rightSpeed+=drive;
       leftSpeed -=drive;
      
      } 
   }
   }
  if (rightSpeed > 120 ) rightSpeed = 120; 
  if (leftSpeed > 120 ) leftSpeed = 120; 
  if (rightSpeed < 0) rightSpeed = 0; 
  if (leftSpeed < 0) leftSpeed = 0;
   Drive();
   Serial.println();
   }
   }

int Cal_Distance(int dis1, int dis2 ){
  if (min(dis1,dis2)<max(dis1,dis2)*0.5){
    return min(dis1,dis2);
  }
  else{
    return (dis1+dis2)/2;
  }
}

