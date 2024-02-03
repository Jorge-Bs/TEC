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
#define PWMB_pin  10 // motor derecho PWM

#define STBY_pin  13 // Stanby  habilitacion driver del motor

#define Photo_Left_pin  A0 // pin sensor Izquierdo
#define Photo_Right_pin A1 // pin sensor Derecho

// ...

// almacena lecturas de los sensores óptico
int Photo_Left  = 0;  
int Photo_Right = 0; 


void setup() {
  Serial.begin(9600);
  // inicialización de los pines de control del motor
  pinMode(AIN1_pin, OUTPUT);
  pinMode(AIN2_pin, OUTPUT);

  pinMode(BIN1_pin, OUTPUT);
  pinMode(BIN2_pin, OUTPUT);

  pinMode(PWMA_pin, OUTPUT);
  pinMode(PWMB_pin, OUTPUT);

  pinMode(STBY_pin, OUTPUT);
  
  // inicialización de pines sensores ópticos
  pinMode(Photo_Left_pin, INPUT);
  pinMode(Photo_Right_pin, INPUT);
  
  digitalWrite(STBY_pin , HIGH);      // habilitación de motores

  set_velocity(100);
  delay(2000);             // fija una velocidad 
}



//----------------
// Bucle principal
//----------------
void loop(){



// ---------------------------------------------------
if(analogRead(Photo_Left_pin)<=200 && analogRead(Photo_Right_pin)<=200){
  Avanza();  
}else
if(analogRead(Photo_Left_pin)>=200 && analogRead(Photo_Right_pin)>=200){
  Retroceder();
  if(analogRead(Photo_Left_pin)<=200 && analogRead(Photo_Right_pin)<=200){
    Derecha();
  }
}else 
if(analogRead(Photo_Left_pin)>=200){
  Derecha();
}else
if(analogRead(Photo_Right_pin)>=200){
  Izquierda();
}
  

  


} 

void Avanza() {
set_velocity(100);
digitalWrite(AIN1_pin,HIGH); // motor derecho
digitalWrite(AIN2_pin,LOW);   
digitalWrite(BIN1_pin,HIGH); // mmotor izquierdo
digitalWrite(BIN2_pin,LOW);     
} // ---------------------------


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

