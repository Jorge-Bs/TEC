#define PIR_PIN 2 // Define el pin al que está conectado el sensor PIR
#define BUZZER_PIN 3 // Define el pin al que está conectado el buzzer
/**
Programa que hace sonar un buzzer cuando el sensor PIR se activa
**/
void setup() {
  pinMode(PIR_PIN, INPUT); // Configura el pin del PIR como entrada
  pinMode(BUZZER_PIN, OUTPUT); // Configura el pin del buzzer como salida
}

void loop() {
  int pirValue = digitalRead(PIR_PIN); // Lee el valor del sensor PIR

  if(pirValue == HIGH) { // Si el sensor PIR está activado
    digitalWrite(BUZZER_PIN, HIGH); // Hace sonar el buzzer
  } else {
    digitalWrite(BUZZER_PIN, LOW); // Apaga el buzzer
  }
}
