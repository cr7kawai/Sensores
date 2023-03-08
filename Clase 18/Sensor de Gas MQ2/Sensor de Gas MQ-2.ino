int pin_mq = 6; //Pin digital para el sensor de gas
void setup() { 
  Serial.begin(9600);
  pinMode(pin_mq, INPUT);
}


void loop() {
  
  boolean mq_estado = digitalRead(pin_mq);//Leemos el sensor
  if(mq_estado) //Si la salida del sensor es 1
  {
    Serial.println("Sin presencia de gas o humo");
  }
  else //Si la salida del sensor es 0
  {
    Serial.println("Humo o gas detectado");
  }
  delay(500); //Espera 500 milisegundos
}