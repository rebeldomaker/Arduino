// Define the LED pins
int LED1 = 2; // Green LED
int LED2 = 3; // Yellow LED
int LED3 = 4; // Red LED
int LED4 = 5; // Blue LED
int buzzer = 13; // Buzzer on pin 13

// Define Morse code for "FREE SOFTWARE FREE SOCIETY"
String morseCode = "..-. .-. . .  ... --- ..-. - .-- .- .-. .  ..-. .-. . .  ... --- -.-. .. . - -.--";


void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}
void startSequence() {
  for (int i = 0; i < 3; i++) {
    // Ring the buzzer for 1 second
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);

    // Light up all LEDs for 1 second, then turn off for 1 second
    allLEDsOn();
    delay(1000);
    allLEDsOff();
    delay(1000);
  }
}

void ledTrailSequence() {
  // A trail effect where each LED lights up one after the other
  for (int i = 0; i < 2; i++) { // Repeats 2 times
    digitalWrite(LED1, HIGH); // Green LED on
    delay(1000);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH); // Yellow LED on
    delay(1000);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH); // Red LED on
    delay(1000);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH); // Blue LED on
    delay(1000);
    digitalWrite(LED4, LOW); 
  }
  // Now all LEDs on for 2 seconds to mimic loading bar
  allLEDsOn();
  delay(2000);
  allLEDsOff();
}

void allLEDsOn() {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
}

void allLEDsOff() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
}
// Function to play Morse code on a specific LED
void playMorseCode(int led, String code) {
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '.') {
      // Dot in Morse code is a short blink
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      delay(200);
    } else if (code[i] == '-') {
      // Dash in Morse code is a longer blink
      digitalWrite(led, HIGH);
      delay(600);
      digitalWrite(led, LOW);
      delay(200);
    } else if (code[i] == ' ') {
      // Space between words in Morse code
      delay(600);
    }
  }
  // Space between repetitions
  delay(2000);
}

// Function to simulate traffic lights
void trafficLightSequence() {
  for (int i = 0; i < 5; i++) {
    // Green LED on for 4 seconds
    digitalWrite(LED1, HIGH);
    delay(4000);
    digitalWrite(LED1, LOW);
    
    // Yellow LED on for 1 second
    digitalWrite(LED2, HIGH);
    delay(1000);
    digitalWrite(LED2, LOW);
    
    // Red LED on for 3 seconds
    digitalWrite(LED3, HIGH);
    delay(3000);
    digitalWrite(LED3, LOW);
  }
}
// Function to simulate police car lights
void policeCarEffect() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(LED3, HIGH);  // Red LED on
    delay(250);
    digitalWrite(LED3, LOW);   // Red LED off
    digitalWrite(LED4, HIGH);  // Blue LED on
    delay(250);
    digitalWrite(LED4, LOW);   // Blue LED off
  }
}
/#include "pitches.h" // Ensure this file exists and defines the note frequencies

// Define the buzzer pin
const int buzzerPin = 13; // Adjust this as per your hardware setup

// Notes in the melody:
int melody[] = {
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_D4
};

// Note durations: 4 = quarter note, 8 = eighth note, etc.
int noteDurations[] = {
  4, 4, 8, 8, 4, 4, 4, 4, 4, 4, 4
};

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as output
}

void loop() {
  // Play the melody
  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);

    // Pause between notes
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // Stop the tone playing
    noTone(buzzerPin);
  }

  delay(2000); // Delay 2 seconds before repeating the melody
}

void loop() {
    startSequence();  // Start with the initial sequence
    ledTrailSequence();  // Follow with the LED trail effect
    playMorseCode(LED_BUILTIN, morseCode);  // Play Morse code on the built-in LED
    trafficLightSequence();  // Simulate traffic lights
    policeCarEffect();  // Simulate police car lights
    playMusicBox();  // Play the music box melody
    delay(5000);  // Delay for 5 seconds before repeating the entire sequence
}


void startSequence() {
  for (int i = 0; i < 3; i++) {
    tone(buzzer, 1000); // Start the buzzer
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000); // LEDs on for 1 second

    noTone(buzzer); // Stop the buzzer
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000); // LEDs off for 1 second
  }
}

void ledTrailSequence() {
  // Sequentially turn on LEDs
  for (int pin = LED1; pin <= LED4; pin++) {
    digitalWrite(pin, HIGH);
    delay(1000); // Each LED lights up for 1 second
  }
  delay(2000); // All LEDs on together for 2 seconds

  // Turn off all LEDs
  for (int pin = LED1; pin <= LED4; pin++) {
    digitalWrite(pin, LOW);
  }
}

void playMorseCode(int ledPin, String code) {
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '.') {
      // Dot in Morse code is a short blink
      digitalWrite(ledPin, HIGH);
      delay(200); // Duration of a dot
      digitalWrite(ledPin, LOW);
      delay(200); // Delay between parts of the same letter
    } else if (code[i] == '-') {
      // Dash in Morse code is a longer blink
      digitalWrite(ledPin, HIGH);
      delay(600); // Duration of a dash
      digitalWrite(ledPin, LOW);
      delay(200); // Delay between parts of the same letter
    } else if (code[i] == ' ') {
      // Space between words in Morse code
      delay(600); // Duration of a space between letters
    }
  }
  // Space between repetitions
  delay(2000);
}


void trafficLightSequence() {
  // Green, Yellow, Red sequence
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED1, HIGH); // Green on for 4 seconds
    delay(4000);
    digitalWrite(LED1, LOW);
    
    digitalWrite(LED2, HIGH); // Yellow on for 1 second
    delay(1000);
    digitalWrite(LED2, LOW);
    
    digitalWrite(LED3, HIGH); // Red on for 3 seconds
    delay(3000);
    digitalWrite(LED3, LOW);
  }
}

void policeCarEffect() {
  // Blue and Red LEDs alternate
  for (int i = 0; i < 6; i++) {
    digitalWrite(LED4, HIGH); // Blue on
    delay(500);
    digitalWrite(LED4, LOW);
    digitalWrite(LED3, HIGH); // Red on
    delay(500);
    digitalWrite(LED3, LOW);
  }
}
#include "pitches.h" // Include the pitches header

void playMusicBox() {
  // Define the notes of the melody (example melody)
  int melody[] = {
    NOTE_E4, NOTE_G4, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_G5,
    NOTE_E4, NOTE_G4, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_G5,
    NOTE_E4, NOTE_G4, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_G5
  };

  // Durations of each note in milliseconds (quarter note, half note, etc.)
  int durations[] = {
    500, 500, 500, 500, 500, 500,
    500, 500, 500, 500, 500, 500,
    500, 500, 500, 500, 500, 500
  };

  // Length of the melody array
  int numNotes = sizeof(melody) / sizeof(melody[0]);

  // Play each note in a loop
  for (int thisNote = 0; thisNote < numNotes; thisNote++) {
    tone(buzzer, melody[thisNote], durations[thisNote]); // Play the note
    delay(durations[thisNote] * 1.30); // Wait for the note's duration plus a little extra
    noTone(buzzer); // Stop any tone playing
  }
  delay(1000); // Delay between repetitions of the melody
}
