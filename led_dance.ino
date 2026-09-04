const int greenLED = 2;
const int yellowLED = 3;
const int redLED = 4;
const int blueLED = 5;

// Morse code definition for "NUMBAT"
const char* morseCode[] = { 
  " -. ",  // N
  " ..- ", // U
  " -- ",  // M
  " -... ",// B
  " .- ",  // A
  " - "    // T
};

// Function declarations
void randomDancingLights();
void trailEffect();
void trafficLightSequence();
void policeLights();
void morseCodeNumbat();

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  unsigned long start = millis();
  while (millis() - start < 10 * 60 * 1000) { // 10 minutes
    randomDancingLights();
    trailEffect();
  }

  start = millis();
  while (millis() - start < 10 * 60 * 1000) { // 10 minutes
    trafficLightSequence();
  }

  policeLights();
  morseCodeNumbat();
}

void randomDancingLights() {
  unsigned long start = millis();
  while (millis() - start < 60 * 1000) { // 1 minute
    int led = random(greenLED, blueLED + 1);
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
  }
}

void trailEffect() {
  unsigned long start = millis();
  while (millis() - start < 60 * 1000) { // 1 minute
    for (int i = greenLED; i <= blueLED; i++) {
      digitalWrite(i, HIGH);
      delay(100);
      digitalWrite(i, LOW);
    }
    for (int i = blueLED; i >= greenLED; i--) {
      digitalWrite(i, HIGH);
      delay(100);
      digitalWrite(i, LOW);
    }
  }
}

void trafficLightSequence() {
  digitalWrite(redLED, HIGH);
  delay(5000); // 5 seconds
  digitalWrite(redLED, LOW);

  digitalWrite(yellowLED, HIGH);
  delay(2000); // 2 seconds
  digitalWrite(yellowLED, LOW);

  digitalWrite(greenLED, HIGH);
  delay(3000); // 3 seconds
  digitalWrite(greenLED, LOW);
}

void policeLights() {
  unsigned long start = millis();
  while (millis() - start < 60 * 1000) { // 1 minute
    digitalWrite(redLED, HIGH);
    digitalWrite(blueLED, LOW);
    delay(250);
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, HIGH);
    delay(250);
  }
  digitalWrite(redLED, LOW);
  digitalWrite(blueLED, LOW);
}

void morseCodeNumbat() {
  const int morseDotDuration = 200; // Duration of a Morse code dot
  const int morseDashDuration = morseDotDuration * 3; // Duration of a Morse code dash
  const int morseSpaceDuration = morseDotDuration; // Space between parts of a letter
  const int morseLetterSpaceDuration = morseDotDuration * 7; // Space between letters

  const int ledPins[] = { greenLED, yellowLED, redLED, blueLED };

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      const char* code = morseCode[i];
      while (*code) {
        if (*code == '.') {
          digitalWrite(ledPins[j], HIGH);
          delay(morseDotDuration);
        } else if (*code == '-') {
          digitalWrite(ledPins[j], HIGH);
          delay(morseDashDuration);
        } else {
          delay(morseSpaceDuration);
        }
        digitalWrite(ledPins[j], LOW);
        delay(morseSpaceDuration);
        code++;
      }
      delay(morseLetterSpaceDuration);
    }
  }
}
