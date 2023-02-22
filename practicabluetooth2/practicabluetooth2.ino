#include <SoftwareSerial.h>   
SoftwareSerial BT(10,11);
int trigger = 12;
int echo = 13;
int lecturaHumedad;
int valorHumedad;
int valorFotoresistencia;
int distancia = 0;
int time = 0;
float tempC;
int V;
int temp;
int porcentaje;
void setup() {
  BT.begin(9600); 
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

}

void loop() {

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  time = pulseIn(echo, HIGH);

  //mide la distancia
  distancia = (time / 2 * 0.034);
  Serial.print("La distancia es:");
  Serial.println(distancia);


  //mide humedad
  lecturaHumedad = analogRead(A1);
  valorHumedad = map(lecturaHumedad, 0, 1023, 100, 0);
  Serial.print("la humedad ");
  Serial.println(valorHumedad);


  //MIDE LA LUZ
  valorFotoresistencia = analogRead(A0);
  Serial.print("Nivel de luz ");
  Serial.println(valorFotoresistencia);


  //mide la temperatura
  V = analogRead(A2);
  temp = (5.0 * V * 100.0) / 1024.0;
  Serial.print("Nivel de temperatura ");
  Serial.println(temp);
  Serial.println("////////////////////////////////////////////////////////////////////");

  delay(1000);

       if(BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
  
    BT.write("La distancia es:");
  BT.write(distancia);

   BT.write("la humedad ");
  BT.write(valorHumedad);
  BT.write("Nivel de luz ");
  BT.write(valorFotoresistencia);
  BT.write("Nivel de temperatura ");
  BT.write(temp);
    Serial.write(BT.read());
  }
 
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     BT.write(Serial.read());
  }

}
