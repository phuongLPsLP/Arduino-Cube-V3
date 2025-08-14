#include <Arduino.h>
#include <AccelStepper.h>

#define STEP_PIN  2
#define DIR_PIN 3
#define EN_PIN 8

#define PIN_MIN_DEC 4
#define PIN_MAX_DEC 5
#define PIN_MIN_STOP 6
#define PIN_MAX_STOP 7



int noOfSteps = 500;           // Number of steps to move in each direction
int microSecondsDelay = 1000;  // Delay in microseconds between each step
void setup() {
 // Configure pin modes
 pinMode(EN_PIN, OUTPUT);
 pinMode(STEP_PIN, OUTPUT);
 pinMode(DIR_PIN, OUTPUT);
 // Initialize pin states
 digitalWrite(EN_PIN, LOW);   // Enable the driver
 digitalWrite(DIR_PIN, LOW);  // Set initial direction
}
void moveSteps(int steps) {
 for (int i = 0; i < steps; i++) {
   digitalWrite(STEP_PIN, HIGH);
   delayMicroseconds(microSecondsDelay);
   digitalWrite(STEP_PIN, LOW);
   delayMicroseconds(microSecondsDelay);
 }
}
void loop() {
 // Move motor in one direction
 digitalWrite(DIR_PIN, LOW);  // Set direction to LOW
 moveSteps(noOfSteps);
 // Move motor in the opposite direction
 digitalWrite(DIR_PIN, HIGH); // Set direction to HIGH
 moveSteps(noOfSteps);
}



/*AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup(){
  Serial.begin(115220);
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);

  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
}

void loop(){
  if (Serial.available()){
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "MOVE"){
      stepper.moveTo(stepper.currentPosition() +200);
      while (stepper.distanceToGo() != 0){
        stepper.run();
      }
      Serial.println("DONE");
    }
  }
}
*/

