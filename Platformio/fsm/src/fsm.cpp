#include <Arduino.h>
int W,X,Y,Z;
int D,C,B,A;

void disp_fsm(int D,int C,int B,int A)
{
  digitalWrite(2,A);
  digitalWrite(3,B);
  digitalWrite(4,C);
  digitalWrite(5,D);
}

void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(13,OUTPUT);
}

void loop()
{
  digitalWrite(13,HIGH);
  delay(10);
  digitalWrite(13,LOW);

  W = digitalRead(6);
  X = digitalRead(7);
  Y = digitalRead(8);
  Z = digitalRead(9);

  // FSM state transition: next state = current+1, reset at 9
  int state = (Z<<3)|(Y<<2)|(X<<1)|W;
  int next = (state >= 9) ? 0 : state+1;

  A = (next>>0)&1;
  B = (next>>1)&1;
  C = (next>>2)&1;
  D = (next>>3)&1;

  disp_fsm(D,C,B,A);
  delay(1000);
}
