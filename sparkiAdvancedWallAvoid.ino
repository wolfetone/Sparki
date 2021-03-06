// Advanced Wall Avoidance 
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
  int checkDistances[7];
  int angleToCheck[7] = {-30, -60, -90, 0, 30, 60, 90};
  int angleToTurnLeft[3] = {30, 60, 90};
  int angleToTurnRight[3] = {30, 60, 90};
  int initialDistance = sparki.ping();
  int greatestDistance = 0;
  int whichDistance = 0;
  int turnTo = 0;

  if(initialDistance != -1)
  {
    if(initialDistance < 20) //if the distance is less than 20
    {
      sparki.moveStop();
      
      //sample distances with the corresponding angle
      for(int i = 0; i < 7; i++)  
      {
        // iterate through angleToCheck[]
        sparki.servo(angleToCheck[i]);
        // ping the distance and store in checkDistances array 
        checkDistances[i] = sparki.ping();
        delay(200);
      }
      
      // Evaluate which element of checkDistances[] had the greatest value
      for(int i = 0; i < 7; i++) 
      {
        if(checkDistances[i] > greatestDistance)
        {
          greatestDistance = checkDistances[i];
          whichDistance = i;
        }
      }

      if(whichDistance == 0)
      {
        sparki.moveLeft(angleToTurnLeft[0]);
      }
      else if(whichDistance == 1)
      {
        sparki.moveLeft(angleToTurnLeft[1]);
      }
      else if(whichDistance == 2)
      {
        sparki.moveLeft(angleToTurnLeft[2]);
      }
      else if(whichDistance == 3)
      {
        
      }
      else if(whichDistance == 4)
      {
        sparki.moveRight(angleToTurnRight[0]);
      }
      else if(whichDistance == 5)
      {
        sparki.moveRight(angleToTurnRight[1]);
      }
      else if(whichDistance == 6)
      {
        sparki.moveRight(angleToTurnRight[2]);
      }

      
    }
  sparki.moveForward();
  delay(100);
  }
}
