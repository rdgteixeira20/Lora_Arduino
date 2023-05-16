# Lora_Arduino
Transmissor e Receptor Lora 915MHz com Arduino

Arduino UNO Receptor - LED de Confirmação de recebimento de Pacote

Arduino Nano Transmissor

Teste de Distâncias : à realizar


$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

Código Transmissor :

//Autor : Rodrigo Teixeira
//Data : 16/05/2023

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

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

Código Receptor

//Autor : Rodrigo Teixeira
//Data : 16/05/2023

#include <SoftwareSerial.h>
 
int led = 13;  
int led2 = 9; 
SoftwareSerial loraSerial(2, 1); // TX, RX
 
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  loraSerial.begin(9600);  
}
 
void loop() { 
  String message = "ok";
  String input = loraSerial.readString();
  if(input == message){
       Serial.println(input);  
       digitalWrite(13, HIGH);
       digitalWrite(9, HIGH);
  }else{
      digitalWrite(led, LOW);
      digitalWrite(led2, LOW);
    
  }
  delay(20);
}

