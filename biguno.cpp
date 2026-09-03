#include <DHT.h>

#define DHTPIN 2     // Pin where the DHT11 is connected
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// LED pins using analog pins as digital outputs
const int redLED = 14;       // A0
const int greenTempLED = 15; // A1
const int blueTempLED1 = 16; // A2
const int yellowLED = 17;    // A3
const int blueTempLED2 = 18; // A4
const int greenTempLED2 = 19; // A5

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  pinMode(redLED, OUTPUT);
  pinMode(greenTempLED, OUTPUT);
  pinMode(blueTempLED1, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(blueTempLED2, OUTPUT);
  pinMode(greenTempLED2, OUTPUT);
  
  // Flash all LEDs 3 times on startup
  for (int i = 0; i < 3; i++) {
    flashAllLEDs();
    delay(500);
  }
}

void loop() {
  // Read temperature from DHT11
  float temperature = dht.readTemperature();

  // Check if any reads failed
  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print readings to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  // Control temperature LEDs
  controlTempLEDs(temperature);

  delay(2000);  // Wait a few seconds between readings
}

void flashAllLEDs() {
  digitalWrite(redLED, HIGH);
  digitalWrite(greenTempLED, HIGH);
  digitalWrite(blueTempLED1, HIGH);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(blueTempLED2, HIGH);
  digitalWrite(greenTempLED2, HIGH);
  delay(500);
  digitalWrite(redLED, LOW);
  digitalWrite(greenTempLED, LOW);
  digitalWrite(blueTempLED1, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(blueTempLED2, LOW);
  digitalWrite(greenTempLED2, LOW);
}

void controlTempLEDs(float temperature) {
  digitalWrite(redLED, LOW);
  digitalWrite(greenTempLED, LOW);
  digitalWrite(blueTempLED1, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(blueTempLED2, LOW);
  digitalWrite(greenTempLED2, LOW);

  if (temperature <= 19) {
    digitalWrite(blueTempLED1, HIGH);
  } else if (temperature >= 20 && temperature <= 21) {
    digitalWrite(greenTempLED, HIGH);
  } else if (temperature >= 22 && temperature <= 24) {
    digitalWrite(yellowLED, HIGH);
  } else if (temperature >= 25) {
    digitalWrite(redLED, HIGH);
  }
}
