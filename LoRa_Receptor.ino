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

   
