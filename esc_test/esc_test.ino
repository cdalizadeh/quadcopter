#include <Servo.h>
 
Servo esc;
int throttlePin = 0;
 
void setup()
{
  esc.attach(3);
  Serial.begin(9600);
}
 
void loop()
{
  int throttle = analogRead(throttlePin);
  throttle = map(throttle, 0, 1023, 0, 179);
  Serial.println(throttle);
  esc.write(throttle);
}
