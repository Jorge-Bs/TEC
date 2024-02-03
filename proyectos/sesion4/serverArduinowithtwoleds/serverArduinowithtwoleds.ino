#include <WiFi.h>
#include <WebServer.h>

// Parametros de la WiFi
const char* ssid = "Tec-2";             
const char* password = "playTime";   

// IP del servidor HTTP
IPAddress local_ip(192,168,20,1);
IPAddress gateway(192,168,20,1);
IPAddress subnet(255,255,255,0);

// declaraciones
WebServer server(80);
uint8_t LEDpinOne = 5;
uint8_t LEDpinTwo = 4;
bool LEDstatusTwo = LOW; 
bool LEDstatusOne = LOW;   


// ---------------- SETUP  -----------------
void setup() {
  
  // Para logging
  Serial.begin(115200);
  // configuración pin LED como salida
  pinMode(LEDpinOne, OUTPUT);
  pinMode(LEDpinTwo, OUTPUT);

  //configuración WiFi modo AP
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  // Funciones de callback según ruta de solicitud recibida
  server.on("/", handle_OnConnect);
  server.on("/H", handle_ledon);
  server.on("/H1", handle_ledonOne);
  server.on("/H2", handle_ledonTwo);
  server.on("/L", handle_ledoff);
  server.on("/L1", handle_ledoffOne);
  server.on("/L2", handle_ledoffTwo);
  server.onNotFound(handle_NotFound);

  // Arranque del servidor
  server.begin();
  Serial.println("HTTP server started...");
}
// ---------------- FIN SETUP  -----------------



// ---------------- LOOP -----------------
void loop() {

  // Pooling esperando solicitudes del cliente
  server.handleClient();
  // actualización del estado del LED
  digitalWrite(LEDpinOne, !LEDstatusOne); 
  digitalWrite(LEDpinTwo, !LEDstatusTwo);    
  delay(2); // permite CPU cambiar a otras tareas
}
// ---------------- FIN LOOP  -----------------



// --------- Funciones de Callback -------------

void handle_OnConnect() {
  LEDstatusOne = LOW;
  LEDstatusTwo = HIGH;
  Serial.println("GPIO5 Status: OFF");
  server.send(200, "text/html", SendHTML()); 
}


void handle_ledon() {
  LEDstatusOne = HIGH;
  LEDstatusTwo = LOW;
  Serial.println("GPIO5 Status: ON");
  server.send(200, "text/html", SendHTML()); 
}
void handle_ledonOne() {
  LEDstatusOne = HIGH;
  Serial.println("GPIO5 Status: ON");
  server.send(200, "text/html", SendHTML()); 
}
void handle_ledonTwo() {
  LEDstatusTwo = LOW;
  Serial.println("GPIO5 Status: ON");
  server.send(200, "text/html", SendHTML()); 
}


void handle_ledoff() {
  LEDstatusOne = LOW;
  LEDstatusTwo = HIGH;
  Serial.println("GPIO5 Status: OFF");
  server.send(200, "text/html", SendHTML()); 
}
void handle_ledoffOne() {
  LEDstatusOne = LOW;
  Serial.println("GPIO5 Status: OFF");
  server.send(200, "text/html", SendHTML()); 
}
void handle_ledoffTwo() {
  LEDstatusTwo = HIGH;
  Serial.println("GPIO5 Status: OFF");
  server.send(200, "text/html", SendHTML()); 
}


void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}
//  -------------------------------------------


// Construcción de la página Web   
String SendHTML(){
    String 
       ptr  ="<title>TEC LED Control</title>\n";
       ptr +="<h1>TEC ESP32 HTTP Server</h1>\n";
       ptr +=  "Clic <a href=\"/H1\">aqui</a> para ENCEDER el LED del pin 5.<br><br>"; 
                          // \" para incluir  comillas en el texto
       ptr +=  "Clic <a href=\"/L1\">aqui</a> para APAGAR el LED del pin 5.<br><br>";
       
       ptr +=  "Clic <a href=\"/H2\">aqui</a> para ENCEDER el LED del pin 4.<br><br>"; 
                          // \" para incluir  comillas en el texto
       ptr +=  "Clic <a href=\"/L2\">aqui</a> para APAGAR el LED del pin 4.<br><br>";

       ptr +=  "Clic <a href=\"/H\">aqui</a> para ENCEDER los LEDs.<br><br>"; 
                          // \" para incluir  comillas en el texto
       ptr +=  "Clic <a href=\"/L\">aqui</a> para APAGAR los LEDs.<br><br>";
       return ptr;
}
