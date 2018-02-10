// Advanced Wall Avoidance 
// servo points forward
// move forward 
// ping distance 
// check for wall
// if(wall within x distance)
//  {
//    stop moving forward
//    store the distance from wall in distances array, in the 0 element
//  } 
// Turn servo 30 degrees left
// ping distance
// store distance in distances array, in element 1
// turn servo an additional 30 degrees left
// ping distance 
// store distance in distances array, in element 2
// turn servo another 30 degrees left
// ping distance 
// store distance in distances array, in element 3
// return servo to center 
// turn servo 30 degrees right 
// ping distance 
// store distance in distances array, in element 4
// turn servo 30 degrees right 
// ping distance 
// store distance in distances array, in element 5
// turn servo 30 degrees right 
// ping distance 
// store distance in distances array, in element 6
// for(int i = 0; i <= 6; i = i + 1)
//   
#include <Sparki.h>
void setup() 
{
  // Reset Servo to Center
  sparki.servo(SERVO_CENTER);
  // Clear LCD
  sparki.clearLCD();
}

void loop() 
{
  int checkDistances[6];
  int angleToCheck[6] = -30, -60, -90, 0, 30, 60, 90;
  int initialDistance = sparki.ping();

  if(initialDistance != -1)
  {
    if(initialDistance < 20) //if the distance is less than 20
    {
      sparki.moveStop();
      
      for(int i = 0; i <= 6; i++) //sample distances with the corresponding angle 
      {
        // iterate through angleToCheck[]
        sparki.servo(angleToCheck[i]);
        // ping the distance and store in checkDistances array 
        checkDistances[i] = sparki.ping();
      }
      // which element of checkDistances[] had the greatest value? 
      for(int i = 0; i <= 6; i++) 
      {
        
      }
    }
  sparki.moveForward();
  delay(100);
  }
}
