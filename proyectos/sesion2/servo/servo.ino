/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>
/**
Programa para controlar con un joystick el movimiento de  un brazo robitico
**/
Servo myservoX;  // create servo object to control a servo
Servo myservoY;

int ejeX = A0;  // analog pin used to connect the potentiometer
int ejeY = A1;
int valX; 
int valY;   // variable to read the value from the analog pin

void setup() {
  myservoX.attach(9);  // attaches the servo on pin 9 to the servo object
  myservoY.attach(10); // colocamos el segundo servo en el pin10
}

void loop() {
  valY = analogRead(ejeY);            // reads the value of the potentiometer (value between 0 and 1023)
  valY = map(valY, 0, 1023, 0, 180);
  valX = analogRead(ejeX);
  valX = map(valX, 523, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservoX.write(valX);
  myservoY.write(valY);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
