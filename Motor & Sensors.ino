
void sensorRead() {

  int i, j;
  Read = 0;
  for (i = 0; i < 5; i++)
    sen[i] = (ref < analogRead(ir[i])) ? empty : !empty;

  for (i = 0; i < 5; i++) {
    Read = (Read * 10 + (sen[i] * (i + 1)));
  }
}

void motor(int left) {
  int a = 0, b = 0;
  Left = left;
  (left < 0) ? b = -1 * left : a = left;
  analogWrite(ina, a);
  analogWrite(inb, b);
}
void motorrev(int a) {
  analogWrite(ina, 0);
  analogWrite(inb, a);
}
