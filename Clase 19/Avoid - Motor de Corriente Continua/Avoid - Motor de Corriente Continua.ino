int IN3 = 35; 
int IN4 = 34;
int SensorPin = 22;
int avoid;

void setup(){
  pinMode (IN4, OUTPUT);    // Input4 conectada al pin 4 
  pinMode (IN3, OUTPUT);    // Input3 conectada al pin 5
  pinMode(SensorPin, INPUT);
  Serial.begin(9600);
}
void loop(){
  avoid = digitalRead(SensorPin);
  if(avoid == HIGH){
    // Motor gira en un sentido
    digitalWrite (IN4, HIGH);
    digitalWrite (IN3, LOW);
    Serial.println("Se detecta un obstáculo");
    delay(3000);
  }else{
    // Motor no gira
    digitalWrite (IN4, LOW);
    Serial.println("No hay obstáculos");
  }
}