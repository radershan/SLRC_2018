
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

//Line_Follower
#include <QTRSensors.h>
#define NUM_SENSORS   8     
#define TIMEOUT       2500  
#define EMITTER_PIN   2     
QTRSensorsRC qtrrc((unsigned char[]) {14, 15, 16, 17, 18, 19, 20, 21},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];

int pos;
float lineError;
float lineLastError;
float lineKp=0.01;

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

//Line_Follower
Qtr_Calibration();
}


void loop() {
Read_Line();
 
}
