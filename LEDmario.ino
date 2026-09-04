#include "pitches.h"

// Define LED and Buzzer pins
const int LED_GREEN = 2;
const int LED_YELLOW = 3;
const int LED_RED = 4;
const int LED_BLUE = 5;
const int BUZZER = 13;

// Morse code for "NUMBAT"
String morseCode = "-. ..- -- -... .- -";

void setup() {
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Pac-Man intro sound at boot up
  playPacManIntro();

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
  // Pac-Man intro sound at the start of each loop
  playPacManIntro();

  trafficLightSequence();
  policeCarEffect();
  heartbeatSequence();
  playMorseCode(); // Morse code moved after heartbeat
  ledDanceSequence();
  delay(5000); // Delay before repeating the loop
}

void playPacManIntro() {
  int melody[] = {NOTE_B4, NOTE_E5, NOTE_A5};
  int durations[] = {150, 150, 300};
  for (int i = 0; i < 3; i++) {
    tone(BUZZER, melody[i], durations[i]);
    delay(durations[i] * 1.3);
    noTone(BUZZER);
  }
}

void trafficLightSequence() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(LED_GREEN, HIGH);
    delay(7000);
    digitalWrite(LED_GREEN, LOW);

    digitalWrite(LED_YELLOW, HIGH);
    delay(2000);
    digitalWrite(LED_YELLOW, LOW);

    digitalWrite(LED_RED, HIGH);
    delay(7000);
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
  for (int i = 0; i < 20; i++) {
    digitalWrite(LED_BLUE, HIGH);
    tone(BUZZER, 659, 100); // First deeper beep
    delay(100);
    tone(BUZZER, 784, 100); // Second less deep beep
    delay(100);
    digitalWrite(LED_BLUE, LOW);
    noTone(BUZZER);
    delay(800);
  }
}

void ledDanceSequence() {
  playMarioTheme();
  unsigned long startTime = millis();
  while (millis() - startTime < 60000) {
    int ledPin = random(LED_GREEN, LED_BLUE + 1);
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(300);
  }
}

void playMarioTheme() {
  // Extended Super Mario theme melody
  int melody[] = {
    NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0, NOTE_G7, 0, 0, 0,
    NOTE_G6, 0, 0, 0, NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0,
    NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0,
    NOTE_F7, NOTE_G7, 0, NOTE_E7, 0, NOTE_C7, NOTE_D7, NOTE_B6, 0, 0
  };
  int durations[] = {
    150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150,
    150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150,
    150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150,
    150, 150, 150, 150, 150, 150, 150, 150, 150, 150
  };
  for (int i = 0; i < sizeof(melody)/sizeof(int); i++) {
    if (melody[i] != 0) {
      tone(BUZZER, melody[i], durations[i]);
    }
    delay(durations[i] * 1.3);
    noTone(BUZZER);
  }
}

void playMorseCode() {
  for (int i = 0; i < morseCode.length(); i++) {
    if (morseCode[i] == '.') {
      digitalWrite(LED_BUILTIN, HIGH);
      tone(BUZZER, 700, 200);  // Using police siren sound for Morse code
      delay(200);
      digitalWrite(LED_BUILTIN, LOW);
      noTone(BUZZER);
    } else if (morseCode[i] == '-') {
      digitalWrite(LED_BUILTIN, HIGH);
      tone(BUZZER, 600, 600);  // Using police siren sound for Morse code
      delay(600);
      digitalWrite(LED_BUILTIN, LOW);
      noTone(BUZZER);
    } else if (morseCode[i] == ' ') {
      delay(600); // Space between letters
    }
  }
  delay(2000); // Space between repetitions
}
