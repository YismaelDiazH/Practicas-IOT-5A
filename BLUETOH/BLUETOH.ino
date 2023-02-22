#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // Creamos un objeto de tipo SoftwareSerial

void setup() {
  Serial.begin(9600);
  BTSerial.begin(38400); // Configuramos el puerto serie para el Bluetooth
}

void loop() {
  if (BTSerial.available()) {
    Serial.write(BTSerial.read()); // Leemos los datos que llegan por el Bluetooth y los mostramos por el puerto serie
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read()); // Enviamos los datos que llegan por el puerto serie al Bluetooth
  }
}