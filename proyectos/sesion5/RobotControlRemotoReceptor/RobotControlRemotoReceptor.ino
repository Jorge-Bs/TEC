// =====================================
// PROGRAMA DEL MODULO RECEPTOR - ROBOT
// =====================================
// TRABAJO EN GRUPO
// TECNOLOGIA ELECTRONICA DE COMPUTADORES 
// UNIVERSIDAD DE OVIEDO
// (C) jC Anton 2022
//
// ATENCION !!!  
// Este programa debe cargarse en el uC del ROBOT. 
// El programa es una plantilla, debe completarse
//
// Pasos para ejecutarlo: 
// 
// 1. cargar el programa en el uC del robot.
// 3. Chequear que el interruptor "serial" 
//    del modulo transmisor esta en OFF.  
// 4. Resetear el robot 
// ==============================================

#include <SoftwareSerial.h>

#define DEBUG

#define AIN1_pin 2  // control motor derecho
#define AIN2_pin 3 

#define BIN1_pin  4 // control motor izquierdo
#define BIN2_pin  5 

#define PWMA_pin  9 // motor izquierdo PWM
#define PWMB_pin  10 // motor izquierdo PWM

#define STBY_pin  13 // Stanby  habilitacion driver del motor

// ... declaraciones de los pines

// formato del frame 
struct __attribute__((packed)) frame_t {
byte Joystick_eje_X_data;
byte Joystick_eje_Y_data;
};


frame_t frame;

// Puerto serie por software sobre pin 12 (lectura) 
// pin RX-mySerial (12) is connected to Xbee pin DOUT  (2)
// pin TX-mySerial (11) is connected to Xbee pin DIN   (3)  no necesario  
SoftwareSerial mySerial(12, 11);                   //  




void setup() {
//inicializa el puerto software para recibir datos del modulo Joystick
mySerial.begin(9600);

//initializa UART serie para depuracion
Serial.begin(9600);

// inicialización de los pines de control del motor
  pinMode(AIN1_pin, OUTPUT);
  pinMode(AIN2_pin, OUTPUT);

  pinMode(BIN1_pin, OUTPUT);
  pinMode(BIN2_pin, OUTPUT);

  pinMode(PWMA_pin, OUTPUT);
  pinMode(PWMB_pin, OUTPUT);

  pinMode(STBY_pin, OUTPUT);

  digitalWrite(STBY_pin , HIGH);      // habilitación de motores

  set_velocity(100);

// ... inicilizar pines del driver del motor


}  // fin setup


//----------------
// Bucle principal
//----------------
void loop(){
// comprueba que en el buffer de recepecion hay 2 bytes al menos
if (mySerial.available() > 1) {                        
  // lectura de los bytes transmitidos
  frame.Joystick_eje_X_data  =  mySerial.read();       
  frame.Joystick_eje_Y_data  =  mySerial.read();
        

// para depurar por la consola del IDE Arduino (ASCII)      
// cuando sea necesario
#ifdef DEBUG 
  Serial.print("Axis X:");
  Serial.println(frame.Joystick_eje_X_data);
  Serial.print("Axis Y:");
  Serial.println(frame.Joystick_eje_Y_data);
#endif

} // fin if


// ...  Instrucciones para controlar el movimiento del robot segun datos recibidos del Joystick




} // fin bucle principal


//-------------------
// Funcion de avance del motor
//-----------------------------
void Avanza() {
set_velocity(100);
digitalWrite(AIN1_pin,HIGH); // motor derecho
digitalWrite(AIN2_pin,LOW);   
digitalWrite(BIN1_pin,HIGH); // mmotor izquierdo
digitalWrite(BIN2_pin,LOW);     
} // ---------------------------

// ... otros movimientos
void Retroceder(){
digitalWrite(AIN1_pin,LOW); // motor derecho
digitalWrite(AIN2_pin,HIGH);   
digitalWrite(BIN1_pin,LOW); // mmotor izquierdo
digitalWrite(BIN2_pin,HIGH);
}

void Derecha(){
set_velocity(100);
digitalWrite(AIN1_pin,LOW); // motor derecho
digitalWrite(AIN2_pin,HIGH);   
digitalWrite(BIN1_pin,HIGH); // mmotor izquierdo
digitalWrite(BIN2_pin,LOW);
}

void Izquierda(){
set_velocity(100);
digitalWrite(AIN1_pin,HIGH); // motor derecho
digitalWrite(AIN2_pin,LOW);   
digitalWrite(BIN1_pin,LOW); // mmotor izquierdo
digitalWrite(BIN2_pin,HIGH);
}

//----------------------------------------
// Función que fija la velocidad del robot
//-----------------------------------------
void set_velocity (byte velocity) {
analogWrite(PWMA_pin, velocity);
analogWrite(PWMB_pin, velocity);
}

