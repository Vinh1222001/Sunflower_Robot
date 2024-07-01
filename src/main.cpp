#include <Arduino.h>
#include <Servo.h>

#define MIN_ANGLE 0
#define MAX_ANGLE_SERVO1 80
#define MAX_ANGLE_SERVO2 180

static uint8_t x_angle = MIN_ANGLE;
static uint8_t y_angle = MIN_ANGLE;

Servo myservo1; //rotate range = [0,80] for up-down
Servo myservo2; //rotate range = [0,180] for left-right

int pos = 0;    // variable to store the servo position

String faceLocation;

void setup() {
  Serial.begin(9600);

  myservo1.attach(9);
  myservo2.attach(10); 

  myservo1.write(x_angle);
  myservo2.write(y_angle);

}

void loop() {

  if (Serial.available())
  {
    faceLocation = Serial.readStringUntil('\r');
    // Serial.println("faceLocation");
    int x_location = faceLocation.substring(0, faceLocation.indexOf(',')).toInt();
    int y_location = faceLocation.substring(faceLocation.indexOf(',') + 1).toInt();

    x_angle = map(x_location, 0, 1920, MAX_ANGLE_SERVO1, MIN_ANGLE);
    y_angle = map(y_location, 0, 1080, MAX_ANGLE_SERVO2, MIN_ANGLE);
    // Serial.println(x_axis);
    if (x_angle >=0 && x_angle <= MAX_ANGLE_SERVO1)
    {
      myservo1.write(x_angle);
      
    }

    if(y_angle >= 0 && y_angle <= MAX_ANGLE_SERVO2){
      myservo2.write(y_angle);
    }   

  }
  
}