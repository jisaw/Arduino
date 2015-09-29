#include "DHT.h"

#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int ledPinLight = 13;
int ledPinTemp = 8;
int lightPin = 0;
int lightVal = 0;
float tempVal = 0;
float humidityVal = 0;
int lightThresh = 545;

void setup() {
  Serial.begin(9600);
  Serial.println("Booting system...");

  pinMode(ledPinLight, OUTPUT);
  pinMode(ledPinTemp, OUTPUT);

  dht.begin();
}

void loop() {
  // Light Logic
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  if (lightVal < lightThresh){
      digitalWrite(ledPinLight, HIGH);
    } else { digitalWrite(ledPinLight, LOW); }

  // Temp Logic
  if (dht.readHumidity() != humidityVal) {
      humidityVal = dht.readHumidity();
      Serial.print("Humidity has changed to: ");
      Serial.println(humidityVal);
      digitalWrite(ledPinTemp, HIGH);
      delay(3000);
      digitalWrite(ledPinTemp, LOW);
    } 
  if (tempVal != dht.readTemperature(true)) {
      tempVal = dht.readTemperature(true);
      Serial.print("Temperature has changed to: ");
      Serial.println(tempVal);
      digitalWrite(ledPinTemp, HIGH);
      delay(3000);
      digitalWrite(ledPinTemp, LOW);
    }

  if (isnan(humidityVal) || isnan(tempVal)){
      Serial.println("error reading dht");
    }
  delay(500);
}
