const int pinPir = 2;
const int ledPin = 7;
const int buzzerPin = 5;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(pinPir, INPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pinPir);

  if (motion == HIGH) {
    digitalWrite(ledPin, HIGH);  // LED ON
    Serial.println("Motion detected!");

    // Beep 3 times
    for (int i = 0; i < 3; i++) {
      tone(buzzerPin, 1000, 500); // 1 kHz for 0.5 sec
      delay(600);                  // wait a bit more than tone duration
    }

  } else {
    digitalWrite(ledPin, LOW);    // LED OFF
    noTone(buzzerPin);            // Stop buzzer
    Serial.println("No motion");
  }

  delay(200); // Stabilize PIR readings
}
