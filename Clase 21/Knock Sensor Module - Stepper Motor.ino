#include <Stepper.h>

int Shock = 12;
int val;
double stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 18, 5, 17, 16);  // Pin inversion to make the library work

void setup() {
  pinMode (Shock, INPUT);
  myStepper.setSpeed(10);
  Serial.begin(9600);
}

void loop(){
  val = digitalRead (Shock);
  if (val == HIGH) {
  Serial.println("Detecta un golpe");
  myStepper.step(stepsPerRevolution);
  }else{
  Serial.println("No detecta un golpe");
  myStepper.step(-stepsPerRevolution);
  }
}