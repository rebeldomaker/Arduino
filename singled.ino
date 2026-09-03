#include "pitches.h"

// Define LED and Buzzer pins
const int LED_GREEN = 2;
const int LED_YELLOW = 3;
const int LED_RED = 4;
const int LED_BLUE = 5;
const int BUZZER = 13;

void setup() {
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Initial greeting sound
  tone(BUZZER, 523, 200); // C5 note, short happy tune
  delay(200);
  noTone(BUZZER);

  // Start-up sequence
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    tone(BUZZER, 1000, 500); // Buzzer on
    delay(500);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);
    noTone(BUZZER);
    delay(500);
  }

  // Loading bar effect
  int leds[] = {LED_BLUE, LED_RED, LED_YELLOW, LED_GREEN};
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], HIGH);
    delay(500);
    digitalWrite(leds[i], LOW);
  }
  tone(BUZZER, 523, 200); // C5 note, completion sound
  delay(200);
  noTone(BUZZER);
}

void loop() {
  trafficLightSequence();
  policeCarEffect();
  heartbeatSequence();
  ledDanceSequence();
  playMusicBox();
  delay(5000); // Delay before repeating the loop
}

void trafficLightSequence() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(LED_GREEN, HIGH);
    delay(8000);
    digitalWrite(LED_GREEN, LOW);

    digitalWrite(LED_YELLOW, HIGH);
    delay(2000);
    digitalWrite(LED_YELLOW, LOW);

    digitalWrite(LED_RED, HIGH);
    delay(8000);
    digitalWrite(LED_RED, LOW);
  }
}

void policeCarEffect() {
  for (int i = 0; i < 24; i++) {
    digitalWrite(LED_RED, HIGH);
    tone(BUZZER, 700, 250);
    delay(250);
    digitalWrite(LED_RED, LOW);
    noTone(BUZZER);

    digitalWrite(LED_BLUE, HIGH);
    tone(BUZZER, 600, 250);
    delay(250);
    digitalWrite(LED_BLUE, LOW);
    noTone(BUZZER);
  }
}

void heartbeatSequence() {
  for (int i = 0; i < 40; i++) {
    digitalWrite(LED_BLUE, HIGH);
    tone(BUZZER, 659, 100); // E note
    delay(100);
    digitalWrite(LED_BLUE, LOW);
    noTone(BUZZER);
    delay(400);
  }
}

void ledDanceSequence() {
  unsigned long startTime = millis();
  while (millis() - startTime < 60000) { // Dance for 1 minute
    int ledPin = random(LED_GREEN, LED_BLUE + 1);
    digitalWrite(ledPin, HIGH);
    delay(200);  // Slowed down the flashing
    digitalWrite(ledPin, LOW);
    delay(200);  // Consistent off period
  }
}

void playMusicBox() {
  // Simplified version of Puppet's music box melody from FNaF 2
  int melody[] = {
    NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_E5, NOTE_G5,
    NOTE_C5, NOTE_E5, NOTE_G5, NOTE_C6, NOTE_E6, NOTE_G6
  };

  int noteDurations[] = {
    500, 500, 500, 500, 500, 500,
    500, 500, 500, 500, 500, 500
  };

  int numNotes = sizeof(melody) / sizeof(melody[0]);
  for (int i = 0; i < numNotes; i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(BUZZER, melody[i], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.3;
    delay(pauseBetweenNotes);
    noTone(BUZZER);
  }
  delay(1000); // Delay between repetitions
}
