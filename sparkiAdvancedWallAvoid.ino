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
  int checkDistances[6];
  int angleToCheck[7] = {-30, -60, -90, 0, 30, 60, 90};
  int initialDistance = sparki.ping();
  int greatestDistance = 0;
  int whichDistance = 0;

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
        delay(200);
      }
      
      // Evaluate which element of checkDistances[] had the greatest value
      for(int i = 0; i <= 6; i++) 
      {
        greatestDistance = checkDistances[i]; 
        
        if(checkDistances[i] > greatestDistance)
        {
          greatestDistance = checkDistances[i];
          whichDistance = i;
        }
      }

      
    }
  sparki.moveForward();
  delay(100);
  }
}
