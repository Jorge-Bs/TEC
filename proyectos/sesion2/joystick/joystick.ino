#include <Servo.h>
const byte ejeX=A0;
const byte ejeY=A1;
const byte pulsacion=3;// boton del joystick

/**
Imprime por pantalla la posicion del joystick respecto al eje X e Y
**/

void setup() {
  pinMode(ejeX,INPUT);
  pinMode(ejeY,INPUT);
  pinMode(pulsacion,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int x = analogRead(ejeX);
  int y = analogRead(ejeY);
  Serial.println(digitalRead(pulsacion));
  Serial.print("Eje X  ");
  Serial.println(x);
  Serial.print("Eje Y  ");
  Serial.println(y);

  delay(2000);
}
