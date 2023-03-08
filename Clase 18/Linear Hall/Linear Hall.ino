//initiation des pins
int digitalPin = 25; //pin Digital
int analogPin = 39; //pin Analógico
int digitalVal;
int analogVal;

void setup()
{
 	Serial.begin(9600); // Inicia la comunicación serial
 	pinMode(digitalPin, INPUT); //Se defiune el pin digital como uno de entrada
}
void loop()
{
 	digitalVal = digitalRead(digitalPin); //Lectura del pin
 	if (digitalVal == HIGH){
 			Serial.println("Se detecta un campo magnético");
 	}
 	else{
 			Serial.println("No se está detectando nada");
 	}
 	analogVal = analogRead(analogPin);
 	Serial.println(analogVal); //Se imprime el valor del pin analógico
 	delay(500); //Espera 500 milisegundos
}