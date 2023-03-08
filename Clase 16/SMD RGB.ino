//Pines para dar salida a los colores RGB
#define RED 22
#define GRN 21
#define BLU 19
 
void setup() {
   pinMode(RED, OUTPUT);
   pinMode(GRN, OUTPUT);
   pinMode(BLU, OUTPUT);
}
 
void loop() {
   // Encender el LED de color rojo
   digitalWrite(RED, HIGH);
   digitalWrite(GRN, LOW);
   digitalWrite(BLU, LOW);
   delay(1000);
 
   // Encender el LED de color verde
   digitalWrite(RED, LOW);
   digitalWrite(GRN, HIGH);
   digitalWrite(BLU, LOW);
   delay(1000);
 
   // Encender el LED de color azul
   digitalWrite(RED, LOW);
   digitalWrite(GRN, LOW);
   digitalWrite(BLU, HIGH);
   delay(1000);
}