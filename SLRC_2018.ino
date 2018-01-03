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
QTRSensorsRC qtrrc((unsigned char[]) {39,41,43,45,47,49,51,53},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];

int pos;
float lineError;
float lineLastError;
float lineKp=0.06;
float lineKd=4;
int  initalspeed=100;
int MaxSpeed =150;
int MinSpeed=50;

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
bool turningLeft = false;
int turningRightCounter = 200;
bool turningRight = false;

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



Qtr_Calibration();
}


void loop() {

//Drive(200,200);
Pid_Line();
//delay(100);


}
