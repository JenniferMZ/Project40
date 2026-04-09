
// Project #40 - Detecting Robot Vehicle Collisions with a Microswitch
#include <AFMotor.h>

AF_DCMotor motor3 (3);    // set up instances of each motor
AF_DCMotor motor4 (4);

boolean crash = false;



void goBackward (int speed, int duration)
{
  motor3.setSpeed (speed);
  motor4.setSpeed (speed);
  motor3.run (BACKWARD);
  motor4.run (BACKWARD);
  delay (duration);
  motor3.run (RELEASE);
  motor4.run (RELEASE);
}



void rotateLeft (int speed, int duration)
{
  motor3.setSpeed (speed);
  motor4.setSpeed (speed);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
  delay(duration);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}



void backOut()
{
  Serial.print("Crash Detected");
  crash = true;
  
}



void goForward (int speed, int duration)
{
  long a, b;
  boolean move = true;
  a = millis();
  do
  {
    Serial.println(crash);
    if (crash == false)
    {
      Serial.println("Forward");
     motor3.setSpeed (speed);
     motor4.setSpeed (speed);
     motor3.run (FORWARD);
     motor4.run (FORWARD);
     }

    if (crash == true)
    {
      Serial.print("Switch Pressed");
      Serial.println(crash);
      goBackward (50, 2000);
      rotateLeft (50, 1000);
      crash = false;
    }

    b = millis () - a;

   if (b >= duration)
    {
     move = false;
     }
  }

  while (move != false);
  //stop motors
  motor3.run (RELEASE);
  motor4.run (RELEASE);
}



void setup ()
{
  attachInterrupt (1, backOut, RISING);
  delay (5000);
  Serial.begin(9600);
}



void loop() 
{
  //goForward (5000, 127);
  goForward (70, 20000);
  delay (2000);
  //rotateLeft (127, 2000);
  //delay (1000);
}


