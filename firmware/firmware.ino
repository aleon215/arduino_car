#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();
  
  myMotor1->setSpeed(150);
  myMotor2->setSpeed(150);
  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
  
}

void loop() {
  
  uint8_t i;
  
  Serial.print("tick");

  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
    
  for (i=0; i<255; i++) {
    myMotor1->setSpeed(i); 
    myMotor2->setSpeed(i);  
    delay(10);
  }
  for (i=255; i!=0; i--) {
    myMotor1->setSpeed(i);  
    myMotor2->setSpeed(i); 
    delay(10);
  }
  
  Serial.print("tock");

  myMotor1->run(BACKWARD);
  myMotor2->run(BACKWARD);
  
  for (i=0; i<255; i++) {
    myMotor1->setSpeed(i);  
    myMotor2->setSpeed(i);
    delay(10);
  }
  for (i=255; i!=0; i--) {
    myMotor1->setSpeed(i);  
    myMotor2->setSpeed(i); 
    delay(10);
  }

  Serial.print("tech");
  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
  delay(1000);
}
