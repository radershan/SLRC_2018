//Motor_Drive
int leftMotorA =4;
int leftMotorB =3;
int leftMotorE =2;
int rightMotorA =5;
int rightMotorB =6;
int rightMotorE =7;

//UltraSonic
int trigPinF = 35;
int echoPinF = 34;
int trigPinL = 33;
int echoPinL = 32;
int trigPinR = 37;
int echoPinR = 36;

//Encoder
int leftA =46;
int leftB =47;
int rightA =48;
int rightB =49;
bool rightState;
bool rightLState;
bool leftState;
bool leftLState;
int leftCounter =0;
int rightCounter =0;

void setup() {
Serial.begin(9600);
//Motor_Drive
pinMode(leftMotorA,OUTPUT);
pinMode(leftMotorB,OUTPUT);
pinMode(leftMotorE,OUTPUT);
pinMode(rightMotorA,OUTPUT);
pinMode(rightMotorB,OUTPUT);
pinMode(rightMotorE,OUTPUT);

//UltraSonic
pinMode(trigPinF, OUTPUT);
pinMode(echoPinF, INPUT);
pinMode(trigPinL, OUTPUT);
pinMode(echoPinL, INPUT);
pinMode(trigPinR, OUTPUT);
pinMode(echoPinR, INPUT);

//Encoder
pinMode(leftA,INPUT);
pinMode(rightA,INPUT);
pinMode(leftB,INPUT);
pinMode(rightB,INPUT);

leftLState = digitalRead(leftA);
rightLState = digitalRead(rightA);
}


void loop() {
 Drive(-200,-200);
 EncoderL();
 Serial.print("Left : ");
 Serial.print(leftCounter);
 EncoderR();
 Serial.print("|| rightt : ");
 Serial.println(rightCounter);
}
