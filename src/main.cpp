#include <Arduino.h>
#include "test_stl.h"
static int32_t count_pressed = 0;
static int32_t random_val = 0;

int btn = USER_BTN;
int led = LED_BUILTIN;

void setup()
{
  // put your setup code here, to run once:
  // int result = myFunction(2, 3);
  // initialize digital pin PC13 as an output.
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT);
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  // make the pushbutton's pin an input:
  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
}

// // the loop function runs over and over again forever
// void loop()
// {
//   // put your main code here, to run repeatedly:
//   digitalWrite(led, HIGH); // turn the LED on (HIGH is the voltage level)
//   delay(100); // wait for a second
//   digitalWrite(led, LOW); // turn the LED off by making the voltage LOW
//   delay(100); // wait for a second
// }


// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(btn);
  random_val = random(300);
  if (buttonState == LOW)
  {
    digitalWrite(led, HIGH);
    count_pressed++;
  }

  Serial.print("count pressed: ");
  Serial.print(count_pressed);
  Serial.print("\trandom: ");
  Serial.println(random_val);

  Serial.print("C++\tmin: ");
  Serial.print(min(random_val,count_pressed));
  Serial.print("\tmax: ");
  Serial.print(max(random_val,count_pressed));
  Serial.print("\tabs: ");
  Serial.print(abs(count_pressed));
  Serial.print("\tround (count_pressed/random_val): ");
  Serial.println(round(count_pressed/random_val));

  Serial.print("C\tmin: ");
  Serial.print(test_c(random_val,count_pressed, MIN));
  Serial.print("\tmax: ");
  Serial.print(test_c(random_val,count_pressed, MAX));
  Serial.print("\tabs: ");
  Serial.print(test_c(count_pressed, 0, ABS));
  Serial.print("\tround (count_pressed/random_val) is ");
  Serial.println(test_c(count_pressed, random_val, ROUND));

  Serial.println();
  delay(100);      // delay in between reads for stability
}