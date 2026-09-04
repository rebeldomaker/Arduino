#include <avr/wdt.h>
#include "pitches.h"

// Define LED and Buzzer pins
const int LED_GREEN = 2;
const int LED_YELLOW = 3;
const int LED_RED = 4;
const int LED_BLUE = 5;
const int BUZZER = 13;
    
bool firstRun = true; // Flag to ensure the initial sequence runs only once

    void setup() {
  wdt_enable(WDTO_2S); // Set the watchdog timer to have a timeout of 2 seconds
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(BUZZER, OUTPUT);
        
  // Initial sequence runs only once upon reset or power on
  initialSequence();
}
    
    void loop() {
  if (firstRun) {
    firstRun = false;
    delay(4000); // Optional delay before starting the hourly loop
    playNyanCatSong(); // Plays right after the initial sequence
  }
  runHourlyLoop(); // Continuously run the hourly loop
        void loop() {
    wdt_reset(); // Reset the watchdog
    // Your repetitive code here
}

}

    void initialSequence() {
  playBootUpSequence();
  loadBarSequence();
  singleLEDSequence();
  playMorseCode();
  trafficLightSequence();
  policeCarEffect();
  heartbeatSequence();
  playZeldaTheme();
  playTwoSecondBeep();
  playMarioTheme();
  playItsAMysterySong();
  playDoomE1M1Song();
  playPokemonLevelUpSound();
}
 void playBootUpSequence() {
    for (int i = 0; i < 3; i++) {
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_YELLOW, HIGH);
        digitalWrite(LED_RED, HIGH);
        digitalWrite(LED_BLUE, HIGH);
        tone(BUZZER, 1000, 500);  // Happy tune
        delay(500);
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_BLUE, LOW);
        noTone(BUZZER);
        delay(500);
    }
    // Ensure everything is turned off at the end
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);
    noTone(BUZZER);
}

void loadBarSequence() {
    int leds[] = {LED_BLUE, LED_RED, LED_YELLOW, LED_GREEN};
    for (int i = 0; i < 4; i++) {
        digitalWrite(leds[i], HIGH);
        delay(500);
    }
    // Play the Pokémon level-up sound when the green LED lights up
    playPokemonLevelUpSound();
    // Flash green LED twice
    digitalWrite(LED_GREEN, HIGH);
    delay(200);
    digitalWrite(LED_GREEN, LOW);
    delay(200);
    digitalWrite(LED_GREEN, HIGH);
    delay(200);
    digitalWrite(LED_GREEN, LOW);
    // Add a short delay to allow the completion of the sequence to be noticed
    delay(500);
    // Turn off all LEDs
    for (int led : leds) {
        digitalWrite(led, LOW);
    }
        // Ensure everything is turned off at the end
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);
    noTone(BUZZER);
}

void playPokemonLevelUpSound() {
  // Assuming the melody and duration are defined correctly to mimic the Pokémon level-up sound
  int melody[] = {NOTE_E5, NOTE_G5, NOTE_E6, NOTE_C6, NOTE_D6, NOTE_G6};
  int noteDurations[] = {100, 100, 100, 100, 100, 400};  // Duration of each note in milliseconds

  for (int i = 0; i < 6; i++) {
    tone(BUZZER, melody[i], noteDurations[i]);
    delay(noteDurations[i] + 50);  // Slightly longer delay for the sound to complete before the next starts
  }
  noTone(BUZZER);
}
void trafficLightSequence() {
    for (int i = 0; i < 2; i++) {  // Repeat sequence twice
        digitalWrite(LED_GREEN, HIGH);
        delay(2000);  // Green light for 2 seconds
        digitalWrite(LED_GREEN, LOW);
        
        digitalWrite(LED_YELLOW, HIGH);
        delay(1000);  // Yellow light for 1 second
        digitalWrite(LED_YELLOW, LOW);
        
        digitalWrite(LED_RED, HIGH);
        delay(3000);  // Red light for 3 seconds
        digitalWrite(LED_RED, LOW);
    }
        // Ensure everything is turned off at the end
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);
    noTone(BUZZER);
}
void policeSirenAndLED() {
    for (int i = 0; i < 20; i++) {  // Number of cycles doubled
        digitalWrite(LED_RED, HIGH);  // Red LED on
        tone(BUZZER, 700);  // Lower tone
        delay(250);
        digitalWrite(LED_RED, LOW);  // Red LED off
        noTone(BUZZER);
        
        digitalWrite(LED_BLUE, HIGH);  // Blue LED on
        tone(BUZZER, 900);  // Higher tone
        delay(250);
        digitalWrite(LED_BLUE, LOW);  // Blue LED off
        noTone(BUZZER);
    }
        // Ensure everything is turned off at the end
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);
    noTone(BUZZER);
}

void heartbeatSequence() {
  // Normal heartbeat with blue LED
  for (int i = 0; i < 20; i++) {
    heartbeat(LED_BLUE, 659, 784);
  }
  // Slower heartbeat with yellow LED
  for (int i = 0; i < 10; i++) {
    heartbeat(LED_YELLOW, 659, 784, 800); // Slower rate
  }
  // Mimic "death"
  digitalWrite(LED_RED, HIGH);
  tone(BUZZER, 659, 3000); // Long beep
  delay(3000);
  digitalWrite(LED_RED, LOW);
  noTone(BUZZER);
}

void heartbeat(int LED, int tone1, int tone2, int pause = 400) {
  digitalWrite(LED, HIGH);
  tone(BUZZER, tone1, 100);
  delay(100);
  tone(BUZZER, tone2, 100);
  delay(100);
  digitalWrite(LED, LOW);
  noTone(BUZZER);
  delay(pause);
}

void twoSecondBeep() {
    // Define a playful melody and durations
    int melody[] = {NOTE_C6, NOTE_E6, NOTE_G6, NOTE_C7};
    int durations[] = {250, 250, 250, 250}; // Each note plays for 250 ms

    // Turn all LEDs on
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_BLUE, HIGH);

    // Play each note in the melody
    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        tone(BUZZER, melody[i], durations[i]);  // Play the note
        delay(durations[i]);  // Duration of the note
    }

    // Turn all LEDs off
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);
}
 
void playZeldaLostWoodsTheme() {
    int melody[] = {
        NOTE_E5, NOTE_G5, NOTE_E6, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_G5,
        NOTE_E5, NOTE_G5, NOTE_E6, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_G5
    };
    int noteDurations[] = {
        250, 250, 250, 250, 250, 250, 500,
        250, 250, 250, 250, 250, 250, 500
    };

    int ledSequence[] = {LED_GREEN, LED_YELLOW, LED_RED, LED_BLUE};
    int ledIndex = 0;

    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        digitalWrite(ledSequence[ledIndex], HIGH);  // Turn on the current LED
        tone(BUZZER, melody[i], noteDurations[i]);  // Play the note
        delay(noteDurations[i]);                    // Wait for the duration of the note
        digitalWrite(ledSequence[ledIndex], LOW);   // Turn off the LED
        ledIndex = (ledIndex + 1) % 4;              // Move to the next LED in the sequence
    }
        // Ensure everything is turned off at the end
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);
    noTone(BUZZER);
}

void playMarioTheme() {
    int melody[] = {
        NOTE_E5, NOTE_E5, NOTE_E5, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_E4,
        NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5
    };
    int durations[] = {
        125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
        125, 125, 125, 125, 125, 125, 125, 125, 125, 125
    };

    int ledSequence[] = {LED_GREEN, LED_YELLOW, LED_RED, LED_BLUE};
    int ledIndex = 3; // Start from the last LED in the sequence (reverse order)

    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        digitalWrite(ledSequence[ledIndex], HIGH); // Turn on the current LED
        tone(BUZZER, melody[i], durations[i]);     // Play the note
        delay(durations[i]);                       // Wait for the duration of the note
        digitalWrite(ledSequence[ledIndex], LOW);  // Turn off the LED
        ledIndex = (ledIndex - 1 + 4) % 4;         // Move to the next LED in reverse order
    }
        // Ensure everything is turned off at the end
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);
    noTone(BUZZER);
}

void playItsAMysterySong() {
    int melody[] = {
        NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_G4,
        NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_G4
    };
    int durations[] = {
        400, 400, 400, 400, 800,
        400, 400, 400, 400, 800
    };

    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        int led = random(LED_BLUE, LED_GREEN + 1);  // Pick a random LED to light up
        digitalWrite(led, HIGH);  // Turn on the randomly selected LED
        tone(BUZZER, melody[i], durations[i]);  // Play the note
        delay(durations[i]);  // Duration of the note
        digitalWrite(led, LOW);  // Turn off the LED
    }
        // Ensure everything is turned off at the end
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);
    noTone(BUZZER);
}

void playDoomE1M1Song() {
    int melody[] = {
        NOTE_D4, NOTE_F4, NOTE_G4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
        NOTE_C5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_F5, NOTE_G5
    };
    int durations[] = {
        200, 200, 200, 200, 150, 150,
        200, 200, 150, 150, 200, 200
    };

    int ledSequence[] = {LED_GREEN, LED_YELLOW, LED_RED, LED_BLUE};
    int ledIndex = 0;

    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        digitalWrite(ledSequence[ledIndex], HIGH); // Turn on the current LED
        tone(BUZZER, melody[i], durations[i]);     // Play the note
        delay(durations[i]);                       // Duration of the note
        digitalWrite(ledSequence[ledIndex], LOW);  // Turn off the LED
        ledIndex = (ledIndex + 1) % 4;             // Move to the next LED in the sequence
    }
        // Ensure everything is turned off at the end
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);
    noTone(BUZZER);
}
void runHourlyLoop() {
    unsigned long startMillis = millis();
    unsigned long period = 3600000;  // One hour in milliseconds
    unsigned long lastLedChange = 0;
    unsigned long lastMorseCodeTime = 0;
    int currentLed = LED_BLUE;

    while (millis() - startMillis < period) {
        if (millis() - lastLedChange >= 500) {  // Update LED every 500ms
            digitalWrite(currentLed, LOW);  // Turn off the current LED
            currentLed++;
            if (currentLed > LED_GREEN) currentLed = LED_BLUE;
            digitalWrite(currentLed, HIGH);  // Turn on the next LED
            lastLedChange = millis();
        }

        if (millis() - lastMorseCodeTime >= 10000) {  // Play Morse code every 10 seconds
            playMorseCodeFreeSoftware();
            lastMorseCodeTime = millis();
        }
            // Ensure everything is turned off at the end
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);
    noTone(BUZZER);
    }

    digitalWrite(currentLed, LOW); // Ensure no LED is left on
    playNyanCatSong();
    ledDancePattern();
}

void playMorseCodeFreeSoftware() {
    String code = "..-. .-. . .  ... --- ..-. - .-- .- .-. .  ..-. .-. . .  ... --- -.-. .. . - -.--";
    for (char c : code) {
        if (c == '.') {
            digitalWrite(LED_BUILTIN, HIGH);
            tone(BUZZER, 1000, 200);
            delay(200);
            digitalWrite(LED_BUILTIN, LOW);
            delay(200);
        } else if (c == '-') {
            digitalWrite(LED_BUILTIN, HIGH);
            tone(BUZZER, 1000, 600);
            delay(600);
            digitalWrite(LED_BUILTIN, LOW);
            delay(200);
        }
        delay(200);  // Ensures spacing between Morse code characters
    }
    delay(3000);  // Wait before repeating
}

void playNyanCatSong() {
    // Simplified version of the Nyan Cat melody
    int melody[] = {
        NOTE_E5, NOTE_E5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_G4,
        NOTE_G4, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4
    };
    int durations[] = {
        125, 125, 250, 125, 250, 125,
        125, 250, 125, 125, 125, 125, 125, 250
    };

    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        tone(BUZZER, melody[i], durations[i]);
        delay(durations[i] + 50); // Adding a small gap between notes
    }
    noTone(BUZZER);
}


void ledDancePattern() {
    for (int i = 0; i < 30; i++) {  // LED "dancing" pattern
        digitalWrite(random(LED_BLUE, LED_GREEN + 1), HIGH);
        delay(200);
        digitalWrite(random(LED_BLUE, LED_GREEN + 1), LOW);
        delay(200);
    }
}


void loop() {
    playBootUpSequence();
    loadBarSequence();
    singleLEDSequence();
    playMorseCode();
    trafficLightSequence();
    policeCarEffect();
    heartbeatSequence();
    playZeldaTheme();
    playTwoSecondBeep();
    playMarioTheme();
    playItsAMysterySong();
    playDoomE1M1Song();
    playPokemonLevelUpSound();
        // Assuming playNyanCatSong() is called at the correct sequence in the project
    playNyanCatSong();
    delay(1000); // Delay before repeating or continuing with other tasks
    runHourlyLoop(); // Start the hourly loop with Morse code and Nyan Cat
}
