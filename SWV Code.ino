#include <Arduino.h>
#include <Servo.h>
#define empty 0
#define ina 3
#define inb 9
#define outa 10
#define ref 200
#define sp 150
int ir[5] = { A0, A1, A2, A3, A4 };
int sen[5];
long int Read;
int Left;
Servo s;
void setup() {
  Serial.begin(9600);
  s.attach(5);
  for (int i = 0; i < 5; i++) {
    pinMode(ir[i], INPUT);
  }
  pinMode(ina, OUTPUT);
  pinMode(inb, OUTPUT);
  pinMode(outa, OUTPUT);
}


void loop() {
  sensorRead();
  goAhead();
  // analogWrite(ina, 100);
  // analogWrite(inb, 0);

  Serial.println(Read);
  // motor(200, 0);
  // delay(5000);
  // motor(0, 0);
  // delay(2000);
  // motor(-200, 0);
  // delay(5000);
  // motor(0, 0);
  // delay(2000);
  // s.write(115);  //115=90
  // delay(400);
  // s.write(115);
  // delay(400);
}
void goAhead() {
  if (Read == 10000) {
    motor(sp);
    s.write(70);
    
  } else if (Read == 2000) {
    motor(sp);
    s.write(145);
  } else if (Read == 12000) {
    motor(sp);
    s.write(115);
  } else if (Read == 12300) {
    motor(-sp);
    s.write(160);
    delay(3000);
    s.write(70);
    motor(sp);
  } else if (Read == 0 || Read == 5) {
    motor(sp);
    s.write(70);
  } else if (Read == 40) {
    motor(sp);
    s.write(40);
  } else if (Read == 45) {
    motor(sp);
    s.write(55);
  } else if (Read == 300) {
    motor(0);
    s.write(160);
    delay(100);
    motor(-sp);
    // delay(50000);
  } else if (Read == 345) {
    motor(0);
    s.write(160);
    delay(100);
    motor(-sp);
    // delay(50000);
  } else {
    motor(sp);
    s.write(115);
  }
}