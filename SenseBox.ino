void DetectBox(){
  if(Distance(trigPinF,echoPinF)<=10){
    DetectColor();
    }
  }

  
void DetectColor(){
  digitalWrite(ledPin,HIGH);
 //  Serial.println("Detecting Color");
  SenseRGB();
  while(currentColor[0]==0 or currentColor[1]==0 or currentColor[2]==0){
    SenseRGB();
 //   Serial.println("No color");
    }
/*/  Serial.print(currentColor[0]);
  Serial.print('\t');
  Serial.print(currentColor[1]);
  Serial.print('\t');
  Serial.print(currentColor[2]);
  Serial.println('\t');*/
  
  if(currentColor[0] < currentColor[1] and currentColor[0] < currentColor[2]){
    //Red
  //  Serial.println("RED");
    answer = "273 085 2";
    }
  else if(currentColor[1] < currentColor[0] and currentColor[1] < currentColor[2]){
    //Green
  //  Serial.println("GREEN");
   answer = "210 080 2";
    }
  else{
    //Blue
  // Serial.println("BLUE");
   answer = "047 082 2";;
    }
 // SendData();
  digitalWrite(ledPin,LOW);
  }



void SenseColor(){
  int frequency = 0;
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  currentColor[0]= pulseIn(sensorOut, LOW);
  delay(10);
  
  // Setting Green filtered photodiodes to be read
 digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  currentColor[1] = pulseIn(sensorOut, LOW);
  delay(10);
  
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  currentColor[2] = pulseIn(sensorOut, LOW);
  delay(10);
  }

float Average( float Reading[]){
  for (int i=0;i<=3;i++){
    int count=0;
    float total=0;
    for (int j=0;j<10;j++){
      if ((Reading[j]<=Reading[i]+100) && (Reading[j]>=Reading[i]-100)) {
        total=total+Reading[j];
        count=count+1;
      }
    }
    if (count>=8){
      return total/count; 
    }
  }
  return 1;
}



float SenseRGB(){
   Serial.println("Sense RGB");
  int frequency;
  float red[10];
  float green[10];
  float blue[10];
 for (int i=0;i<10;i++){
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  red[i]=frequency;
  delay(100);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  green[i]=frequency;
  delay(100);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  blue[i]=frequency;
  delay(100);
 }
 
  currentColor[0] = Average(red);
  currentColor[1] = Average(green);
  currentColor[2] = Average(blue);
 
}

