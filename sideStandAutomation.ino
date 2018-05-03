#include <Servo.h>
Servo myservo;  
int sensor = 4;                 // tilt sensor as input pin
int LED = 13;                    // led as output pin

boolean switchState = false;   
int sensorState=0;// current state

void openStand()
{
  
   myservo.write(110); 
  
}

void closeStand()
{
  
   myservo.write(20); 
  
  
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

  if(sensorState==LOW)            //when tilt switch lays flat 
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
