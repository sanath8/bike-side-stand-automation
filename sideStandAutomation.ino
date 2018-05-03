#include <Servo.h>
Servo myservo;                  // initialising servo motor
int sensor = 4;                 // tilt sensor as input pin
int LED = 13;                   // led as output pin

boolean switchState = false;   
int sensorState=0;              // Setting current state as 0

void openStand()
{
   myservo.write(110);          // Function to open bike stand 
}

void closeStand()
{
   myservo.write(20);           // Function to close the bike stand
}

void setup()
{
  pinMode(sensor, INPUT);
  digitalWrite(sensor, HIGH);      //set the sensor as HIGH
  pinMode(LED, OUTPUT);
  myservo.attach(LED); 
  myservo.write(15); 
}

void loop()
{
  sensorState=digitalRead(sensor); //read value of the sensor either high or low

  if(sensorState==LOW)             //when tilt switch lays flat 
  {
    //digitalWrite(LED,HIGH);
    closeStand();
  }
  else
  {
    //digitalWrite(LED, LOW);      //when switch tilt on some angle 
    openStand();
  }
}
