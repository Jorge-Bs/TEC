// =================================================================
// PROGRAMA DEL MODULO TRANSMISOR - MODULO DE CONTROL POR JOYSTICK
// =================================================================
// TRABAJO EN GRUPO
// TECNOLOGIA ELECTRONICA DE COMPUTADORES 
// UNIVERSIDAD DE OVIEDO
// (C) jC Anton 2022
// 
// ATENCION !!!  
// Este programa debe cargarse en el modulo del Joystick. 
// El programa es una plantilla, debe completarse
// 
// Pasos para ejecutarlo:
// 1. Poner a ON el interruptor "serial" del modulo transmisor. 
// 2. Cargar el programa en el modulo transmisor (Joystick)
// 3. Poner a OFF el interruptor "serial" del modulo transmisor.  
// 4. Resetear el robot 
//
// Operacion:
// Mueva el mando para dirigir el robot. 
// Enjoy!
// 
//====================================================================

// formato del paquete
struct __attribute__((packed)) frame_t {
byte Joystick_eje_X_data;
byte Joystick_eje_Y_data;
byte parada;
};


frame_t frame;

// Pines del Joystic al NANO
#define Joystick_X_pin      A0
#define Joystick_Y_pin      A1
#define claxon_pin          3
int parada=2;

void setup() {
    Serial.begin(9600);                 //  
    pinMode(Joystick_X_pin,INPUT);
    pinMode(Joystick_Y_pin,INPUT);
    pinMode(parada,INPUT_PULLUP);
    pinMode(claxon_pin,OUTPUT);
}

//----------------
// Bucle principal
//----------------
void loop() {
    // lectura del Joystick
    frame.Joystick_eje_X_data  = (analogRead(Joystick_X_pin)/4.01);   // lectura de coordenada X del Joystick X   
    frame.Joystick_eje_Y_data  = (analogRead(Joystick_Y_pin)/4.01);   // lectura de coordenada Y del Joystick Y 
    if(digitalRead(parada)!=HIGH){
      frame.parada=255;
      digitalWrite(claxon_pin,HIGH);
    }else{
      frame.parada=0;
      digitalWrite(claxon_pin,LOW);
    }
        
    // transmision de datos por RF
    Serial.write((const byte *)&frame, sizeof(frame_t)); //  
    Serial.flush();                                      //  
     
    delay(100) ;   // tiempo entre transmisiones de frames.
           
}