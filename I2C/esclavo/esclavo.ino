#include <Wire.h>

int izq = 11;
int der = 12;

void setup() {
  Wire.begin(9);
  Wire.onReceive(motor);
  
  pinMode(izq, OUTPUT);
  pinMode(der, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  
  
}

void motor(int numBytes){
  byte conf;
  
  if(numBytes == 1){
    
    while(Wire.available()){
      conf = Wire.read();
    }
    
    Serial.print(conf);
    
    switch(conf){
      case 1:
        digitalWrite(izq, LOW);
        digitalWrite(der, HIGH);
        break;
        
      case 2:
        digitalWrite(izq, HIGH);
        digitalWrite(der, LOW);
        break;
      
      case 3:
        digitalWrite(izq, HIGH);
        digitalWrite(der, HIGH);
        break;
        
      default:
        digitalWrite(izq, LOW);
        digitalWrite(der, LOW);
        break;
    }
  }
}
