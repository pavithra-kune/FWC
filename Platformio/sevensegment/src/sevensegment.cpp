#include <Arduino.h>

int Z;

void display0()
{
  digitalWrite(2,LOW);  // a
  digitalWrite(3,LOW);  // b
  digitalWrite(4,LOW);  // c
  digitalWrite(5,LOW);  // d
  digitalWrite(6,LOW);  // e
  digitalWrite(7,LOW);  // f
  digitalWrite(8,HIGH); // g
}

void display1()
{
  digitalWrite(2,HIGH); // a
  digitalWrite(3,LOW);  // b
  digitalWrite(4,LOW);  // c
  digitalWrite(5,HIGH); // d
  digitalWrite(6,HIGH); // e
  digitalWrite(7,HIGH); // f
  digitalWrite(8,HIGH); // g
}

void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);

  pinMode(9,INPUT);   // Z input
}

void loop()
{
  Z = digitalRead(9);

  int F = !Z;     // F = Z'

  if(F == 1)
    display1();
  else
    display0();
}
