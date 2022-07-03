#include <NewPing.h>

int trigger_pin = 6;
int echo_pin = 5;
int max_dist_cm = 10;
NewPing sonar(trigger_pin, echo_pin, max_dist_cm);

void setup() {
  Serial.begin(9600); // baud rate
  delay(50); // wait 50 ms
  pinMode(13, OUTPUT);
}

void loop() {
  Serial.print("Distance from sensor in cm: ");
  int dist_cm = sonar.ping_cm();
  Serial.println(dist_cm);
  int alarm_dist_cm = 5;
  if (dist_cm <= alarm_dist_cm) {
    digitalWrite(13, HIGH); // turn on the LED (connected to pin 13)
  } else {
    digitalWrite(13, LOW); // turn off the LED
  }
  delay(1000); // wait 1 sec between print statements
  
}