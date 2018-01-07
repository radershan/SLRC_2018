//Node MCU Toggle Pin
int sendRequest = 15;
#include <Wire.h>
#define ANSWERSIZE 4
String answer = "NONE";
bool waitForReply = false;


//Buzzer
int SPKR = 12;
//Swithces
int switch1 = 14;
int switch2 = 15;
int switch3 =16;
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
int trigPinE = 31;
int echoPinE = 30;

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
int leftSpeed =0; 
int rightSpeed =0;

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
int leftA =19;
int leftB =17;
int rightA =18;
int rightB =16;
volatile byte rightBState;
volatile byte leftBState;

int leftCounter =0;
int rightCounter =0;
int turningLeftCounter = 175;
bool encoding = false;
int turningRightCounter = 175;
int turningAroundCounter = 330;
int linePassCounter = 80;

//Color Sensor
#define S0 22
#define S1 23
#define S2 24
#define S3 25
#define sensorOut 26
#define ledPin 27
int currentColor[3] = {0,0,0};




void setup() {
  
Serial.begin(9600);
pinMode(SPKR,OUTPUT);
pinMode(sendRequest,OUTPUT);
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
pinMode(trigPinE, OUTPUT);
pinMode(echoPinE, INPUT);

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

//I2C
Wire.begin(9);
Wire.onRequest(requestEvent); // data request to slave
Wire.onReceive(receiveEvent); // data slave received


Serial.println("Calib...");
 Qtr_Calibration();
Serial.println("Ready...");

}


void loop() {
Scan();
UpdateLine();  

}

