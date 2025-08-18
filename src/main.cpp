#include <Arduino.h>
#include <AccelStepper.h>

#define STEP_PIN 2
#define DIR_PIN 3

void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  digitalWrite(DIR_PIN, HIGH); // Richtung
}

void loop() {
  digitalWrite(STEP_PIN, HIGH);
  delay(100);   // 5 ms HIGH
  digitalWrite(STEP_PIN, LOW);
  delay(100);   // 5 ms LOW
}

/*#include <TMCStepper.h>

#define STEP_PIN 2
#define DIR_PIN  3

// Sense-Widerstand deines Moduls prüfen (meist R110 = 0.11 Ω oder R150 = 0.15 Ω)
#define R_SENSE 0.11f
#define DRIVER_ADDRESS 0b00  // abhängig von ADDR-Pins (CFG1/CFG2)

// UART an Serial1 (Due: RX1=19, TX1=18)
// Für Single-Wire: nur TX1 -> PDN_UART verbinden + GND
TMC2209Stepper driver(&Serial1, R_SENSE, DRIVER_ADDRESS);

void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(DIR_PIN, HIGH);

  Serial1.begin(115200);   // UART Kommunikation
  delay(50);

  driver.begin();
  driver.toff(4);                // Treiber aktivieren (0 = off)
  driver.blank_time(24);
  driver.rms_current(800);       // 800 mA RMS → an deinen Motor anpassen
  driver.microsteps(16);         // 1/16 Microstepping
  driver.en_spreadCycle(false);  // stealthChop aktivieren
  driver.pwm_autoscale(true);
}

void loop() {
  // Test: langsame Schritte
  digitalWrite(STEP_PIN, HIGH);
  delay(5);
  digitalWrite(STEP_PIN, LOW);
  delay(5);
}*/
