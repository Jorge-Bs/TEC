// =============================================
// PROGRAMA DEL DRIVER DEL ROBOT: EJERCICIOS
// =============================================
// TRABAJO EN GRUPO
// TECNOLOGIA ELECTRONICA DE COMPUTADORES 
// UNIVERSIDAD DE OVIEDO
// (C) jC Anton 2022 
//==============================================

#define DEBUG

// declaraciones de pines
#define AIN1_pin 2  // control motor derecho
#define AIN2_pin 3 

#define BIN1_pin  4 // control motor izquierdo
#define BIN2_pin  5 

#define PWMA_pin  9 // motor izquierdo PWM
#define PWMB_pin  10 // motor izquierdo PWM

#define STBY_pin  13 // Stanby  habilitacion driver del motor

#define Photo_Left_pin  A0 // pin sensor Izquierdo
#define Photo_Right_pin A1 // pin sensor Derecho

// ...

// almacena lecturas de los sensores óptico
int Photo_Left  = 0;  
int Photo_Right = 0; 


void setup() {

  // inicialización de los pines de control del motor
  pinMode(AIN1_pin, OUTPUT);
  pinMode(AIN2_pin, OUTPUT);

  pinMode(BIN1_pin, OUTPUT);
  pinMode(BIN2_pin, OUTPUT);

  pinMode(PWMA_pin, OUTPUT);
  pinMode(PWMB_pin, OUTPUT);

  pinMode(STBY_pin, OUTPUT);

  pinMode(Photo_Left_pin, INPUT);
  pinMode(Photo_Right_pin, INPUT);
  // inicialización de pines sensores ópticos
  // ....
  
  digitalWrite(STBY_pin , HIGH);      // habilitación de motores

  set_velocity(100);             // fija una velocidad 
}



//----------------
// Bucle principal
//----------------
void loop(){


// test de movimentos del robot: avance, atras, giros
// ---------------------------------------------------
  delay(1000);
  Avanza(); 
  //delay(1000);
  //Retroceder();
  //delay(1000);
  //Izquierda();
  //delay(1000);
  //Derecha();

  
// .... resto de movimientos
  

// test de velocidad
// -------------------
//
// set_velocity(...);


// test de lectura del estado de los sensores ópticos
//---------------------------------------------------
// 
// Photo_Left = analogRead(Photo_Left_pin);
// .... resto de codigo ....




} 
//----------- fin bucle principal ---------
//-----------------------------
// Funcion de avance del motor
//-----------------------------
void Avanza() {
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
digitalWrite(AIN1_pin,LOW); // motor derecho
digitalWrite(AIN2_pin,HIGH);   
digitalWrite(BIN1_pin,HIGH); // mmotor izquierdo
digitalWrite(BIN2_pin,LOW);
}

void Izquierda(){
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