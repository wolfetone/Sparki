#include <Sparki.h>
#define NO_ACCEL   // disables the Accelerometer, frees up 598 Bytes Flash Memory
#define NO_MAG     // disables the Magnetometer, frees up 2500 Bytes Flash Memory

//FUNCTIONS

void wallSense()
{
  if(sparki.ping() != -1)
  {
    if(sparki.ping() < 20)
    {
      //lcd control 
      sparki.clearLCD();
      sparki.drawRectFilled(0,54, 74,40); //draw a big exclamation mark
      sparki.drawRectFilled(54,64, 74,50);
      sparki.updateLCD();
      //actions
      sparki.RGB(RGB_RED);
      sparki.moveStop(500); //stop for 500ms
      sparki.moveBackward(5);
      sparki.moveRight(45); //turn right 45 degree
      sparki.RGB(RGB_GREEN); 
    }
  }
}

void edgeSense()
{
  if (sparki.edgeLeft() <= 200) //if left edge sensor detects a distance greater than or equal to 50
  {
    //lcd control 
    sparki.clearLCD();
    sparki.drawRectFilled(0,54, 74,40); //draw a big exclamation mark
    sparki.drawRectFilled(54,64, 74,50);
    sparki.updateLCD();
    //actions
    sparki.RGB(RGB_RED); //turn light red
    sparki.moveStop(500); //stop for 500ms
    sparki.moveBackward(5); //move backwards 5cm
    sparki.moveRight(45); //turn right 45 degrees
    sparki.RGB(RGB_GREEN); //return light to green
  }
  
  if(sparki.edgeRight() <= 200)
  {
    //lcd control 
    sparki.clearLCD();
    sparki.drawRectFilled(0,54, 74,40); //draw a big exclamation mark
    sparki.drawRectFilled(54,64, 74,50);
    sparki.updateLCD();
    //actions
    sparki.RGB(RGB_RED);
    sparki.moveStop();
    sparki.moveBackward(5);
    sparki.moveLeft(45);
    sparki.RGB(RGB_GREEN);
  }
}
void setup() 
{
  sparki.servo(SERVO_CENTER); // Center the Servo
}
void loop() 
{
  edgeSense();
  wallSense();
  sparki.moveForward();
  delay(100);
}
