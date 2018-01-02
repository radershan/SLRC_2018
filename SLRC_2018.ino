//Motor_Drive
int leftMotorA =4;
int leftMotorB =3;
int leftMotorE =2;

int rightMotorA =5;
int rightMotorB =6;
int rightMotorE =7;

void setup() {
//Motor_Drive
pinMode(leftMotorA,OUTPUT);
pinMode(leftMotorB,OUTPUT);
pinMode(leftMotorE,OUTPUT);

pinMode(rightMotorA,OUTPUT);
pinMode(rightMotorB,OUTPUT);
pinMode(rightMotorE,OUTPUT);

}


void loop() {
  Drive(200,200);
  delay(5000);
  Drive(200,-200);
  delay(5000);
  Drive(-200,200);
  delay(5000);
  Drive(0,0);
  delay(5000);
}
