#include <Arduino.h>
#include <Servo.h>

#define MIN_ANGLE 0
#define MAX_ANGLE_SERVO1 80
#define MAX_ANGLE_SERVO2 180

#define FRAME_HEIGHT 480
#define FRAME_WIDTH 640

static uint8_t x_angle = MIN_ANGLE;
static uint8_t y_angle = MIN_ANGLE;

Servo myservo1; //rotate range = [0,80] for up-down
Servo myservo2; //rotate range = [0,180] for left-right

String faceLocation;

void setup() {
  Serial.begin(9600);

  myservo1.attach(10);
  myservo2.attach(9); 

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

    y_angle = map(x_location, 0, FRAME_WIDTH, MAX_ANGLE_SERVO2, MIN_ANGLE);
    x_angle = map(y_location, 0, FRAME_HEIGHT, MIN_ANGLE, MAX_ANGLE_SERVO1);
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