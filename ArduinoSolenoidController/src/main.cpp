#include <Arduino.h>

bool system_initialized = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT); //solenoid
  digitalWrite(10, LOW);
  pinMode(8, INPUT); //esp32 controller
}

bool previous = false;
unsigned long debounce_timer = 6000; //milliseconds
unsigned long last_debounce_trigger_time = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() - last_debounce_trigger_time >= debounce_timer) {
    bool current = digitalRead(8);
    if((current != previous) && current == true) {
      digitalWrite(10, HIGH);
      delay(50);
      digitalWrite(10, LOW);
      last_debounce_trigger_time = millis();
    }
  }
}