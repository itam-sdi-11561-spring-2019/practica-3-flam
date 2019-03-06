#include <SoftwareSerial.h>
int TX = 50;
int RX = 51;
int bauds = 9600;
byte cmd;
SoftwareSerial xbee(RX, TX);

void setup() {
  xbee.begin(bauds);
  // boton <- pin 20
  // leds <- pines 22, 23, 24 (Port A0, A1, A2)
  cli();
  DDRA |= (1 << DDA0) | (1 << DDA1) | (1 << DDA2);
  //PORTA |= (1 << PORTA0) | (1 << PORTA1) | (1 << PORTA2);
  DDRD &= ~(1 << DDD1);
  PORTD |= (1 << PORTD1);
  EICRA |= (1 << ISC10) | (1 << ISC11);
  EIMSK |= (1 << INT1);
  sei();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(xbee.available()>0){
      cmd = xbee.read();
      PORTA = cmd;
  }
}

ISR(INT1_vect){
  xbee.write(0xFF);
}
