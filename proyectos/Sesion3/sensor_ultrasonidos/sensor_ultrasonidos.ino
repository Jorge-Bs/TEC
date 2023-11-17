#define TRIGGER_PIN 9 // Define el pin al que está conectado el pin TRIGGER del sensor
#define ECHO_PIN 10 // Define el pin al que está conectado el pin ECHO del sensor
/**
Programa que mide la distancia con un sensor de ultrasonidos y la imprime por pantalla
**/
void setup() {
  Serial.begin(9600); // Inicia la comunicación serial
  pinMode(TRIGGER_PIN, OUTPUT); // Configura el pin TRIGGER como salida
  pinMode(ECHO_PIN, INPUT); // Configura el pin ECHO como entrada
}

void loop() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH); // Lee el tiempo que tarda la señal en volver
  float distance = duration * 0.034 / 2; // Calcula la distancia en cm

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000); // Espera un segundo antes de la próxima medición
}

