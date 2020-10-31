/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

//Motor Driver
int MotorA = 5; //PWM Pin A
int AIN1 = 9;
int AIN2 = 10;

int MotorB = 6; //PWM Pin B
int BIN1 = 11;
int BIN2 =12;

int STBY = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);      //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive.
  pinMode(MotorA, OUTPUT);
  pinMode(MotorB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("KeyPressed: ");
  if (GamePad.isUpPressed())
  {
    Serial.print("UP");
    digitalWrite(STBY,HIGH);
    analogWrite(MotorA,250);//Set pwm motor A
    digitalWrite(AIN1,HIGH);
    digitalWrite(AIN2,LOW);
    analogWrite(MotorB,250); //Set pwm motor B
    digitalWrite(BIN1,HIGH);
    digitalWrite(BIN2,LOW);
    delay(5);
  }

  if (GamePad.isDownPressed())
  {
    Serial.print("DOWN");
    digitalWrite(STBY,HIGH);
    analogWrite(MotorA,250);//Set pwm motor A
    digitalWrite(AIN1,LOW);
    digitalWrite(AIN2,HIGH);
    analogWrite(MotorB,250); //Set pwm motor B
    digitalWrite(BIN1,LOW);
    digitalWrite(BIN2,HIGH);
    delay(5);
  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
    digitalWrite(STBY,HIGH);
    analogWrite(MotorA,250);//Set pwm motor A
    digitalWrite(AIN1,LOW);
    digitalWrite(AIN2,HIGH);
    analogWrite(MotorB,0); //Set pwm motor B
    digitalWrite(BIN1,HIGH);
    digitalWrite(BIN2,LOW);
    delay(5);
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("Right");
    digitalWrite(STBY,HIGH);
    analogWrite(MotorA,0);//Set pwm motor A
    digitalWrite(AIN1,HIGH);
    digitalWrite(AIN2,LOW);
    analogWrite(MotorB,250); //Set pwm motor B
    digitalWrite(BIN1,LOW);
    digitalWrite(BIN2,HIGH);
    delay(5);
  }

  if (GamePad.isSquarePressed())
  {
    Serial.print("Square");
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
  }

  if (GamePad.isCrossPressed())
  {
    Serial.print("Cross");
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("Triangle");
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }
  else{
    digitalWrite(STBY,LOW);
    analogWrite(MotorA,0);
    digitalWrite(AIN1,LOW);
    digitalWrite(AIN2,LOW);
    analogWrite(MotorB,0);
    digitalWrite(BIN1,LOW);
    digitalWrite(BIN2,LOW);
    delay(5);
    }

  
  Serial.print('\t');

  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();
}
