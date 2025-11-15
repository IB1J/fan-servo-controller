#include <Servo.h>

Servo myServo;
int servoPin = 3;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  float x = analogRead(A0);
  int y = analogRead(A1);

  x = ((-(x-520)/522)*90 + 90);
  y = abs(((y-513)/522)*255);

  if (y < 5) {
    y = 0;
  }

  if (abs(x-90) < 3) x = 90;
  analogWrite(5, y);
  myServo.write(x);
}