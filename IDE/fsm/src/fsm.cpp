#include <Arduino.h>

int Z = 0, Y = 0, X = 0, W = 0;
int D, C, B, A;

void disp_7447()
{
  digitalWrite(2, W); // A (LSB)
  digitalWrite(3, X); // B
  digitalWrite(4, Y); // C
  digitalWrite(5, Z); // D (MSB)
}

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(13, OUTPUT);
}

void loop()
{
  // Display present state
  disp_7447();

  // FSM next-state equations
  A = (!W);

  B = (!W && !X && Y) ||
      (W && X) ||
      (!W && Z);

  C = (!W && Z) ||
      (X && Y) ||
      (W && Y);

  D = (!W && !X && !Y && !Z) ||
      (W && Z);

  // Update state
  W = A;
  X = B;
  Y = C;
  Z = D;

  // Clock indication
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(100);
}
