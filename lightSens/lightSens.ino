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

  val = analogRead(lightSensPin);

  Serial.print(val);
  Serial.print("\n");

  if(val<valuel){
    digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
      }
      delay(200);
}
