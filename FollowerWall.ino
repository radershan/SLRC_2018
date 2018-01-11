
void Wall_FollowR(){
 int dis1 =Distance(trigPinRF,echoPinRF);
 int dis2 =Distance(trigPinRB,echoPinRB);
 float dis=Cal_Distance(dis1,dis2);
 float frontDis=Distance(trigPinF,echoPinF);

 int angle=dis1-dis2;
 
 
 if(dis1 !=4000 || dis2 !=4000 ){
  /*if (dis1>=100){
 
  //Break();
 /*Serial.print('\t');
  Serial.print("close");*/
  /*leftSpeed =abs(60+0.4*(dis1-100)); 
  rightSpeed =abs(60-0.4*(dis1-100)); 
  Drive();
  //delay(5);
 }*/
/*else if(angle>=50){
  Buzzer();
  leftSpeed =abs(60+0.5*(angle-50));
  rightSpeed =abs(60-0.5*(angle-50)); 
  Drive();
 
 }
 else if(angle<=2){
  leftSpeed =60-20*(2-angle); 
  rightSpeed =60+20*(2-angle); 
  Drive();
 }*/
  
 //else{
 wallError=dis -11;
 /*Serial.print(wallError);
 Serial.print('\t');
 Serial.print("pid");*/
 int wallValue=wallKp*wallError+wallKd*(wallError-wallLastError);
/* Serial.print('\t');
 Serial.print(wallValue);*/
 leftSpeed =100+wallValue; 
 rightSpeed =100-wallValue; 
 if (rightSpeed<0) rightSpeed=0;
 if (leftSpeed<0) leftSpeed=0;
  Drive();
 /* Serial.print('\t');
 Serial.print(leftSpeed);
 Serial.print('\t');
 Serial.print(rightSpeed);*/
 
wallLastError=wallError;
 //}
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
  
   if (drive<=0) {
    drive=(-1*drive);
   }
   if (drive>=100) {
    drive=100 ;
   }
  
    
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
      //break;
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
   leftSpeed =70; 
   rightSpeed =70;


   
   
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
  if (rightSpeed > 120 ) rightSpeed = 120; 
  if (leftSpeed > 120 ) leftSpeed = 120;
  if (rightSpeed < 0) rightSpeed = 0; 
  if (leftSpeed < 0) leftSpeed =0 ;
 
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

