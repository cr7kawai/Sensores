const int pinMicrophone = 27;

void setup()
{
  Serial.begin(9600);
  pinMode(pinMicrophone, INPUT_PULLUP);
}

void loop()
{
  bool soundDetected = digitalRead(pinMicrophone); //Realiza la lectura del sensor
  if (soundDetected == true)
  {
    Serial.println("Se detecta sonido");
  }else{
    Serial.println("No se detecta sonido");
  }
  delay (1000); //Espera 1 segundo
}