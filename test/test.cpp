// Minimal Test für TMC2209 + Schrittmotor
// STEP -> Pin 2
// DIR  -> Pin 3
// EN   -> GND (Treiber aktiv)

#include <Arduino.h>

#define STEP_PIN 2
#define DIR_PIN  3

void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  digitalWrite(DIR_PIN, HIGH); // Richtung setzen
}

void loop() {
  // Einen Schritt erzeugen
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(800);   // Pulsdauer
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(800);   // Pause zwischen Schritten
}
