#include <SoftwareSerial.h>
String data;
const int LED = 8;
SoftwareSerial BT(10, 11);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code ere, to run repeatedly:
  digitalWrite(LED, HIGH);
  if (BT.available()) {
    data = BT.readString();
    Serial.println(data);
    if (data == "1") {
      digitalWrite(LED, HIGH);
    } else if (data == "0") {
      digitalWrite(LED, LOW);
    }
  }
}