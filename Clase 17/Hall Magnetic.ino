const int HALLPin = 14;
const int LEDPin = 23;

void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(HALLPin, INPUT);
}

void loop() {
  if(digitalRead(HALLPin)==HIGH){ //Realizar la lectura del pin
    Serial.println("Se detecta campo electromagn�tico");
    digitalWrite(LEDPin, HIGH);
  }
  else{
    Serial.println("No se est� detectando ning�n campo electromagn�tico");
    digitalWrite(LEDPin, LOW);
  }
}