// Incluímos la librería para poder controlar el servo
#include <Servo.h>

// Declaramos la variable para controlar el servo
Servo servoMotor;

// Variable para el pin del sensor
const int SensorPin = 39;

void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
  // Iniciamos el servo para que empiece a trabajar con el pin 27
  servoMotor.attach(27);
  // Se define el pin del sensor como entrada
  pinMode(SensorPin, INPUT);
}

void loop() {
  int value = analogRead(SensorPin);
  Serial.println(value);
  delay(1000);
  if(value > 20){
    servoMotor.write(90);
    delay(1000);
    servoMotor.write(180);
    delay(1000);
  }else{
    servoMotor.write(0);
  }
}