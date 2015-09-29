#include "DHT.h"

#define DHTPIN 5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int ledPin = 8;
int lightSensPin = 0;
int val = 0;
int valuel = 300;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  float h = dht.readHumidity();
  Serial.print("The humidity is: ");
  Serial.println(h);
  
  // empty params for C, true for F
  float t = dht.readTemperature(true);
  Serial.print("The temperature is: ");
  Serial.print(t);
  Serial.println("*F");

  float hif = dht.computeHeatIndex(t, h);
  Serial.print("Heat index: ");
  Serial.println(hif);
   val = analogRead(lightSensPin);

  Serial.print(val);
  Serial.print("\n");

  if(val<valuel){
    digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
      }
}
