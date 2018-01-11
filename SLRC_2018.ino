#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11);
String answer ;

//Buzzer
int SPKR = 12;

//Swithces
int switch1 = 14;
int switch2 = 15;
int switch3 =16;

//Motor_Drive
int leftMotorA =5;
int leftMotorB =6;
int leftMotorE =7;
int rightMotorA =4;
int rightMotorB =3;
int rightMotorE =2;

//UltraSonic
int trigPinF = 35;
int echoPinF = 34;
int trigPinLF = 33;
int echoPinLF = 32;
int trigPinRF = 37;
int echoPinRF = 36;
int trigPinLB = 31;
int echoPinLB = 30;
int trigPinRB = 29;
int echoPinRB = 28;

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
float wallKp=6;
float wallKd=500;

float disKp= 6  ;  //20;
float disKd=500;
float disLastError=0;
float disCorrection=0;
float disError=0;

float angleCorrection=0;
int lastAngle=0;
float angKp=16;
float angKd=26;
int angle=0;
int drive=0;

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

byte state = 0;
bool endMaze = false;
bool endWall = false;


void setup() {
  
Serial.begin(9600);
pinMode(SPKR,OUTPUT);
              
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
pinMode(trigPinLF, OUTPUT);
pinMode(echoPinLF, INPUT);
pinMode(trigPinRF, OUTPUT);
pinMode(echoPinRF, INPUT);
pinMode(trigPinLB, OUTPUT);
pinMode(echoPinLB, INPUT);
pinMode(trigPinRB, OUTPUT);
pinMode(echoPinRB, INPUT);

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

BTserial.begin(9600); 

}


void loop() { 
  
 switch (state){
  case 1:
  while(!endMaze){
    Scan();
    UpdateLine();    
    }
  while(!endWall){
    //Follow Wall
    }
  DistanceMeasure();
  
  break;
  
  case 2:
  
  break;

  case 3:

  break;

  default:
  Qtr_Calibration();
  Buzzer();
  while(!endMaze){
    Scan();
    UpdateLine();    
    }
  while(!endWall){
    //Follow Wall
    }
  DistanceMeasure();
}

}


void StateChange(){
  if(digitalRead(switch1)==HIGH and digitalRead(switch2)==HIGH){
    state = 3;
    }
  else if(digitalRead(switch1)==HIGH and digitalRead(switch2)==LOW){
    state = 2;
    }
  else if(digitalRead(switch1)==LOW and digitalRead(switch2)==HIGH){
    state = 1;
    }
  else{
    state = 0;
    }
  
  }

void SendData(){
  for (byte i=0;i<9;i++) {
    BTserial.write(answer.charAt(i));
  }
  
  BTserial.write('\n');
  int inChar =0;
  while(inChar == 0){
    if(BTserial.available() > 0){
    inChar = BTserial.read();
    }
    }
  }
