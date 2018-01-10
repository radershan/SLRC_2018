
void Wall_FollowR(){
 int dis1 =Distance(trigPinRF,echoPinRF);
 int dis2 =Distance(trigPinRB,echoPinRB);
 int dis=Cal_Distance(dis1,dis2);
 int frontDis=Distance(trigPinF,echoPinF);
 int angle=dis1-dis2;
 Serial.print(frontDis);
 Serial.print('\t');
 Serial.print(dis1);
 Serial.print('\t');
  Serial.print(dis2);
 Serial.print('\t');
 Serial.print(dis);
 Serial.print('\t');
  Serial.print(angle);
 Serial.print('\t');
 if (frontDis<=20){
  //TurnLeft();
  leftSpeed =-70; 
  rightSpeed =70; 
  Drive();
  delay(100);
  Serial.print('\t');
  Serial.print("front");
 }
 /*else if (angle<=-50){
  while(angle>-50){
    leftSpeed =-50; 
  }
  rightSpeed =50; 
  Drive();
 }*/
 else if (angle>=40 && angle <=200){
  //Break();
  Serial.print('\t');
  Serial.print("close");
  leftSpeed =abs(60+0.6*(200-angle)); 
  rightSpeed =abs(60-0.6*(200-angle)); 
  Drive();
  //delay(5);
 }
 else{
 wallError=dis -12;
 int wallValue=wallKp*wallError+wallKd*(wallError-wallLastError);
 leftSpeed =70+wallValue; 
 rightSpeed =70-wallValue; 
 if (rightSpeed<0) rightSpeed=0;
 if (leftSpeed<0) leftSpeed=0;
  Drive();
wallLastError=wallError;
 }
}

void Wall_FollowL(){
 int dis1 =Distance(trigPinLF,echoPinLF);
 int dis2 =Distance(trigPinLB,echoPinLB);
 int dis=Cal_Distance(dis1,dis2);
 int frontDis=Distance(trigPinF,echoPinF);
 int angle=dis1-dis2;
 Serial.print(frontDis);
 Serial.print('\t');
 Serial.print(dis1);
 Serial.print('\t');
  Serial.print(dis2);
 Serial.print('\t');
 Serial.print(dis);
 Serial.print('\t');
  Serial.print(angle);
 Serial.print('\t');
 if (frontDis<=20){
  //TurnLeft();
  leftSpeed =70; 
  rightSpeed =-70; 
  Drive();
  delay(100);
  Serial.print('\t');
  Serial.print("front");
 }
 /*else if (angle<=-50){
  while(angle>-50){
    leftSpeed =-50; 
  }
  rightSpeed =50; 
  Drive();
 }*/
 else if (angle>=40 && angle <=200){
  //Break();
  Serial.print('\t');
  Serial.print("close");
  leftSpeed =abs(60-0.6*(200-angle)); 
  rightSpeed =abs(60+0.6*(200-angle)); 
  Drive();
  //delay(5);
 }
 else{
 wallError=dis -12;
 int wallValue=wallKp*wallError+wallKd*(wallError-wallLastError);
 leftSpeed =70-wallValue; 
 rightSpeed =70+wallValue; 
 if (rightSpeed<0) rightSpeed=0;
 if (leftSpeed<0) leftSpeed=0;
  Drive();
wallLastError=wallError;
 }
}





void Wall_followLeft(){ 
  while(true){
   float dis1 = Distance(trigPinLF,echoPinLF);
   float dis2 = Distance(trigPinLB,echoPinLB);
   
    Scan();
   
   float front =Distance(trigPinF,echoPinF);
  //Serial.print(front);
  //Serial.println();
   if (front <=20) {
    //Break();
    leftSpeed=70;
    rightSpeed=-70;
    Drive();
    delay(70);
    }
   else{
    if(dis1!=4000 || dis2 !=4000){
    int angle = dis1-dis2;
    float dis = Cal_Distance(dis1,dis2);
    float interDistance = 0.5 * Cal_Distance(dis1,dis2) + 0.5 * 8;
   /* Serial.print('\t');
    Serial.print(angle);
    Serial.print('\t');
    Serial.print(interDistance);
    Serial.println();*/
  disError =  interDistance-8;
 
  disCorrection =  disKp*disError+disKd*(disError-disLastError);
  disLastError = disError;
Serial.print('\t');
    Serial.print(disError);
   //pid angle
   angleCorrection = angKp*angle + angKd*(angle-lastAngle);
   lastAngle = angle;

   drive = disCorrection + angleCorrection;
  leftSpeed=0;
    rightSpeed=0;
    Drive();
    delay(5);
   /*if (drive<=0) {
    drive=(-1*drive);
   }*/
   if (drive>=100) {
    drive=100 ;
   }
   leftSpeed =60-drive; 
   rightSpeed =60+drive;
 /* if (rightSpeed > 160 ) rightSpeed = 160; 
  if (leftSpeed > 160 ) leftSpeed = 160; 
  if (rightSpeed < 0) rightSpeed = 0; 
  if (leftSpeed < 0) leftSpeed = 0;*/
   Drive();

    }
   /*
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
   else if (dis>=interDistance+5){
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
    if (angle<5){
        //away
        Serial.print("a");
        leftSpeed +=drive;
       rightSpeed-=drive;
      }
      else if (angle>15){
      
        
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
  
   */
   }
   Serial.println();
   }
}

void Wall_followRight(){ 
  while(true){
   float dis1 = Distance(trigPinRF,echoPinRF);
   float dis2 = Distance(trigPinRB,echoPinRB);
   float front =Distance(trigPinF,echoPinF);
    float dis3 = Distance(trigPinLB,echoPinLB);
   
    //Serial.println(dis3);
    if (dis3<=15){
      Buzzer();
      break;
    }
 /* Serial.print(front);
  Serial.print('\t');
  Serial.print(dis1);
  Serial.print('\t');
  Serial.print(dis2);
  Serial.print('\t');*/
   if (front <=20) {
    //Break();
    leftSpeed=-70;
    rightSpeed=70;
    Drive();
    }
   else{
    if(dis1!=4000 || dis2 !=4000){
    int angle = dis1-dis2;
    float dis = Cal_Distance(dis1,dis2);
    float interDistance = 0.5 * dis + 0.5 * 9;
    /*Serial.print('\t');
    Serial.print(angle);
    Serial.print('\t');
    Serial.print(interDistance);
    Serial.println();*/
  disError =  9-interDistance;
 
  disCorrection =  disKp*disError+disKd*(disError-disLastError);
  disLastError = disError;

   //pid angle
   angleCorrection = angKp*angle + angKd*(angle-lastAngle);
   lastAngle = angle;

   drive = disCorrection + angleCorrection;

   if (drive<=0) {
    drive=(-1*drive);
   }
  /* if (drive>=100) {
    drive=100 ;
   }*/
   leftSpeed =100; 
   rightSpeed =100;


   
   
   if (dis<=interDistance-2){
    Serial.print("1");
      if (angle<5){
        //away
        Serial.print("a");
        leftSpeed -=drive;
        rightSpeed+=drive;
      }
      else if (angle>5){
       
        //close
        Serial.print("c");
        rightSpeed-=drive;
        leftSpeed +=drive;
  
      }
   }
   else if (dis>=interDistance+5){
        //close
        Serial.print("3");
        //if (angle>0){
         Serial.print("c");
        rightSpeed-=drive;
        leftSpeed +=drive;
        //}
        
        
   }
   else{
   Serial.print("2");
    if (angle<15){
        //away
        Serial.print("a");
        leftSpeed -=drive;
       rightSpeed+=drive;
      }
      else if (angle>15){
      
        
       Serial.print("c");
        //close
        rightSpeed-=drive;
       leftSpeed +=drive;
      
      } 
   }
   
   
   }
  if (rightSpeed > 200 ) rightSpeed = 200; 
  if (leftSpeed > 200 ) leftSpeed = 200;
  if (rightSpeed < 0) rightSpeed = 0; 
  if (leftSpeed < 0) leftSpeed =0 ;
 
   Drive();
   delay(50);
   leftSpeed=0;
   rightSpeed=0;
   Drive();
   }
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


void wall(){
  while(true){
   float dis1 = Distance(trigPinRF,echoPinRF);
   float dis2 = Distance(trigPinRB,echoPinRB);
   float front =Distance(trigPinF,echoPinF);
    
    float dis3 = Distance(trigPinLB,echoPinLB);
    if (dis3<=15){
      Buzzer();
      break;
      
    }
    if (front<=20){
      leftSpeed=-70;
    rightSpeed=70;
    Drive();
    delay(70);
    }
    else if(dis1!=4000 || dis2 !=4000){
     int angle = dis1-dis2-3;
    float dis = Cal_Distance(dis1,dis2)-11;
 
    Serial.print('\t');
    Serial.print(angle);
    Serial.print('\t');
    Serial.print(dis);
    Serial.println();
    
 
    disCorrection =  disKp*dis+disKd*(dis-disLastError);
    disLastError = dis;

    if (disCorrection<=0) {
    disCorrection=(-1*disCorrection);
   }
   if (disCorrection>=70) {
    disCorrection=70 ;
   }
   //pid angle
   angleCorrection = angKp*angle + angKd*(angle-lastAngle);
   lastAngle = angle;
  if (angleCorrection<=0) {
    angleCorrection=(-1*disCorrection);
   }
   if (angleCorrection>=100) {
    angleCorrection=100 ;
   }
    leftSpeed=angleCorrection;
    rightSpeed=-1*angleCorrection;
    Drive();
    delay(10);
    leftSpeed=100+disCorrection;
    rightSpeed=100-disCorrection;
    Drive();
    delay(10);
    }
}
}

