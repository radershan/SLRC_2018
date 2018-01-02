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

}


void loop() {
 Serial.print("Front : ");
 Serial.println(Distance(trigPinF,echoPinF));
 Serial.print("Left : ");
 Serial.println(Distance(trigPinL,echoPinL));
 Serial.print("Right : ");
 Serial.println(Distance(trigPinR,echoPinR));
 delay(2000);
}
