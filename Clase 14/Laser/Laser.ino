const int pin = 9; //conectado al pin 9

void setup() {
  pinMode(pin, OUTPUT);  //definir pin como salida
  Serial.begin(9600);    //iniciar la comunicación serial en el puerto 9600
}
 
void loop(){
  digitalWrite(pin, HIGH);   // poner el Pin en HIGH
  Serial.println("Laser encendido");
  delay(5000);               // esperar 5 segundos
  digitalWrite(pin, LOW);    // poner el Pin en LOW
  Serial.println("Laser apagado");
  delay(3000);               // esperar 20 segundos
}