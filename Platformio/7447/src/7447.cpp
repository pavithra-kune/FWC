
#include <Arduino.h>

int Z;
int D,C,B,A;

void disp_7447(int D,int C,int B,int A)
{
  digitalWrite(2,A);   // LSB
  digitalWrite(3,B);
  digitalWrite(4,C);
  digitalWrite(5,D);   // MSB
}

void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  pinMode(6,INPUT);    // Z input
}

void loop()
{
  Z = digitalRead(6);

  int F = !Z;     // F = Z'

  if(F==0)
  {
    D=0;
    C=0;
    B=0;
    A=0;      // display 0
  }
  else
  {
    D=0;
    C=0;
    B=0;
    A=1;      // display 1
  }

  disp_7447(D,C,B,A);
}
