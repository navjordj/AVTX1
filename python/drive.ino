#include <Servo.h>

Servo esc;
Servo throttle;

int incomingByte= 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  throttle.attach(7);
}

void loop() {
  throttle.write(90);
  if (Serial.available() > 0) {
    esc.attach(9);
    incomingByte = Serial.read();
    Serial.println(incomingByte);
  if (incomingByte == 48) {
    esc.write(500);
  }
  else if (incomingByte == 49) {
    esc.write(0);
  } 
  } else {
    //Serial.println("not aveliable");
  }
  Serial.flush();
}
