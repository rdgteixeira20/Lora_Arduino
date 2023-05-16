#include <SoftwareSerial.h>
 
int led = 13;  
 
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
  }else{
      digitalWrite(led, LOW);
    
  }
  delay(20);
}

   
