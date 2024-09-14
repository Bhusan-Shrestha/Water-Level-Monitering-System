const int analogInPin = A0;
const int thresholdLow = 100;
const int thresholdMedium = 550;
const int thresholdHigh = 625;
const int thresholdMax = 750;

const int lowpin = 2;
const int mediumpin = 3;
const int highpin = 4;
const int buzzerpin = 5;
int sensorValue = 0;

void setup() {
  // Initialize LED pins as outputs
  for (int i = 0; i < 4; i++) {
    pinMode(lowpin, OUTPUT);
    pinMode(mediumpin, OUTPUT);
    pinMode(highpin, OUTPUT);
    pinMode(buzzerpin, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  Serial.print("sensor = ");
  Serial.println(sensorValue);
  delay(2);

  if (sensorValue >= thresholdLow && sensorValue <= thresholdMedium) {
    digitalWrite(lowpin, HIGH);
    digitalWrite(mediumpin, LOW);
    digitalWrite(highpin, LOW);
    digitalWrite(buzzerpin, LOW);
  } else if (sensorValue > thresholdMedium && sensorValue <= thresholdHigh) {
    digitalWrite(lowpin, LOW);
    digitalWrite(mediumpin, HIGH);
    digitalWrite(highpin, LOW);
    digitalWrite(buzzerpin, LOW);
  } else if (sensorValue > thresholdHigh && sensorValue <= thresholdMax) {
    digitalWrite(lowpin, LOW);
    digitalWrite(mediumpin, LOW);
    digitalWrite(highpin, HIGH);
    digitalWrite(buzzerpin, HIGH);
  } else {
    digitalWrite(lowpin, LOW);
    digitalWrite(mediumpin, LOW);
    digitalWrite(highpin, LOW);
    digitalWrite(buzzerpin, LOW);

  }
}

