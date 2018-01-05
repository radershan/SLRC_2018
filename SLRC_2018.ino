//Swithces
int switch1 = 8;
int switch2 = 9;
int switch3 =10;
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
QTRSensorsRC qtrrc((unsigned char[]) {39,41,43,45,47,49,51,53},NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];

int irSensorDigital[8] = {0,0,0,0,0,0,0,0};
int treashold = 500; 
int irSensors = B00000000; 
int irSensorsL = B00000000; 

int pos;
int lPos;
float lineError;
float lineLastError;
float lineKp=0.06;
float lineKd=4;
int  initalspeed=100;
int MaxSpeed =200;
int MinSpeed=0;

//wallfollower
float wallError;
float wallLastError;
float wallKp=0.06;
float wallKd=5;

//Encoder
int leftA =20;
int leftB =21;
int rightA =18;
int rightB =19;
volatile byte rightBState;
volatile byte leftBState;

int leftCounter =0;
int rightCounter =0;
int turningLeftCounter = 200;
bool encoding = false;
int turningRightCounter = 200;
int linePassCounter = 200;

//Color Sensor
#define S0 22
#define S1 23
#define S2 24
#define S3 25
#define sensorOut 26
#define ledPin 27
int currentColor[3] = {0,0,0};

//Send Color
#include <Wire.h>
#define ANSWERSIZE 1
String answer = "NONE!";

void setup() {
  
Serial.begin(9600);
//Switches
pinMode(switch1,INPUT);
pinMode(switch2,INPUT);
pinMode(switch3,INPUT);

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
pinMode(leftA,INPUT_PULLUP);
pinMode(rightA,INPUT_PULLUP);
pinMode(leftB,INPUT_PULLUP);
pinMode(rightB,INPUT_PULLUP);

//color sensor
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  digitalWrite(ledPin,LOW);



Qtr_Calibration();

}


void loop() {


//Drive(200,200);
Pid_Line();
//delay(100);
//Wall_Follow();


}

