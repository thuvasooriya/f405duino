#include <Arduino.h>
// #include "test_stl.h"
static int32_t count_pressed = 0;
static int32_t random_val = 0;

int btn = USER_BTN;
int led = LED_BUILTIN;
int testpin1 = PC12;
int testpin2 = PD2;

void setup()
{
  // put your setup code here, to run once:
  // int result = myFunction(2, 3);
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT);
  pinMode(testpin1, OUTPUT);
  pinMode(testpin2, OUTPUT);
  Serial.begin(115200);
}

// // the loop function runs over and over again forever
void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH); // turn the LED on (HIGH is the voltage level)
  digitalWrite(testpin1, HIGH); // turn the LED on (HIGH is the voltage level)
  digitalWrite(testpin2, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(100); // wait for a second
  digitalWrite(led, LOW); // turn the LED off by making the voltage LOW
  digitalWrite(testpin1, LOW); // turn the LED off by making the voltage LOW
  digitalWrite(testpin2, LOW); // turn the LED off by making the voltage LOW
  delay(100); // wait for a second
}