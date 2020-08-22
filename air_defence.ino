//the code is entirely created by: SHEEKAR BANERJEE
//Dept. of CSE, IUBAT UNIVERSITY

#include<Servo.h>  //This calls the Header of the repository containing the library files of Servo Motor Driver Modules
#define trigPin 9  //This initializes the Trig pin of HC-05 Ultrasonic Sensor to the pin no. 9 of Arduino Microcontroller
#define echoPin 10 //This initializes the Echo pin of HC-05 Ultrasonic Sensor to the pin no. 10 of Arduino Microcontroller

Servo sm;     //Servo is a Class which is providing an independent data type // sm is a variable which is representing the servo motor which will be attached with the trigger of the Anti Aircraft Gun
int sound=250;
int red = 7;    //This initializes the positive pin of Red LED Signal Bulb to the pin no. 7 of Arduino Microcontroller
int green = 4;  //This initializes the positive pin of Green LED Signal Bulb to the pin no. 4 of Arduino Microcontroller


void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);    //Here, The Red LED plays the role of a output device
  pinMode(green, OUTPUT);  //Here, The Green LED plays the role of a output device
  pinMode(trigPin,OUTPUT); //Here, Trig pin triggers the electrical impulses into the sensor as an output
  pinMode(echoPin,INPUT);  //Here, Echo pin inputs the reflective signals into the sensor
  sm.attach(3);            //The Coding Yellow Wire of the Servo motor is attached to the pin no. 3 of Arduino Microcontroller
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);        // It will wait for 2 microseconds after every single electrical implulse of Trig pin if it is sending LOW(less than 1.6V) signal
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);       //It will wait for 10 microseconds after every single electrical implulse of Trig pin if it is sending HIGH(greater than 1.6V) signal
  digitalWrite(trigPin, LOW);


  duration=pulseIn(echoPin, HIGH);  //Sensor inputs the signal through the Echo pin
  distance=(duration/2)/29.1;       //Calculation of distance
  if(distance<30)      //According to the reflection time calculation, if the distance is less than 30 cm
  {
    
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    sm.write(80);      //than the Servo Motor will rotate for 80 degrees so that it can pull the trigger of Anti Aircraft Gun
  }
  else { 
 
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    sm.write(0);       //Unless this, the Servo motor will stand still which will not pull the trigger.
 
} 
  
}
