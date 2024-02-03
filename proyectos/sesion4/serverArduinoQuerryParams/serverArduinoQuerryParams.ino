#include <WiFi.h>
#include <WebServer.h>

// Parámetros de la WiFi
const char* ssid = "Tec-2";             
const char* password = "playTime";   

// IP del servidor HTTP
IPAddress local_ip(192,168,20,1);
IPAddress gateway(192,168,20,1);
IPAddress subnet(255,255,255,0);

// Declaraciones
WebServer server(80);
uint8_t LEDpinOne = 5;
uint8_t LEDpinTwo = 4;
bool LEDstatusOne = LOW;  
bool LEDstatusTwo = LOW;  

void setup() {
  Serial.begin(115200);
  pinMode(LEDpinOne, OUTPUT);
  pinMode(LEDpinTwo, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started...");
}

void loop() {
  server.handleClient();
  digitalWrite(LEDpinOne, !LEDstatusOne); 
  digitalWrite(LEDpinTwo, !LEDstatusTwo);    
  delay(2);
}

void handle_OnConnect() {
  String stateOne = server.arg("stateOne");
  String stateTwo = server.arg("stateTwo");
  
  if (stateOne == "H") {
    LEDstatusOne = HIGH;
    Serial.println("GPIO5 Status: ON");
  } else if (stateOne == "L") {
    LEDstatusOne = LOW;
    Serial.println("GPIO5 Status: OFF");
  }
  
  if (stateTwo == "H") {
    LEDstatusTwo = HIGH;
    Serial.println("GPIO4 Status: ON");
  } else if (stateTwo == "L") {
    LEDstatusTwo = LOW;
    Serial.println("GPIO4 Status: OFF");
  }
  
  server.send(200, "text/html", SendHTML()); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(){
    String ptr  ="<title>TEC LED Control</title>\n";
    ptr +="<h1>TEC ESP32 HTTP Server</h1>\n";
    ptr +=  "Clic <a href=\"/?stateOne=H\">aqui</a> para ENCEDER el LED del pin 5.<br><br>"; 
    ptr +=  "Clic <a href=\"/?stateOne=L\">aqui</a> para APAGAR el LED del pin 5.<br><br>";
    ptr +=  "Clic <a href=\"/?stateTwo=H\">aqui</a> para ENCEDER el LED del pin 4.<br><br>"; 
    ptr +=  "Clic <a href=\"/?stateTwo=L\">aqui</a> para APAGAR el LED del pin 4.<br><br>";
    ptr +=  "Clic <a href=\"/?stateOne=H&stateTwo=H\">aqui</a> para ENCEDER los LEDs.<br><br>"; 
    ptr +=  "Clic <a href=\"/?stateOne=L&stateTwo=L\">aqui</a> para APAGAR los LEDs.<br><br>";
    return ptr;
}