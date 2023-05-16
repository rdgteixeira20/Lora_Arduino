#include <SoftwareSerial.h>
#include <LoRa.h>

SoftwareSerial LoRaSerial(11, 10); // TX, RX
int bot = 12;
int botao = 0;
void setup() {
  Serial.begin(9600);
  while (!Serial);

  LoRaSerial.begin(9600);
  while (!LoRaSerial);
  
  pinMode(bot, INPUT_PULLUP);
  
}

void loop() {
  botao = digitalRead(bot);
  //Serial.println(botao);
 if (botao == LOW){ 
  String message = "ok";
 
  LoRaSerial.print(message);
  Serial.println("Mensagem Enviada via LORA");

  delay(500);
 } 
}
  
