// Pin definitions for the LEDs
int greenLED = A0;
int yellowLED = A1;
int redLED = A2;
int blueLED = A3;
// Replace A6 with another available digital pin, e.g., 9
int additionalLEDs[] = {A4, A5, 9, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12};

void setup() {
    // Initialize all pins as output
    pinMode(greenLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    pinMode(blueLED, OUTPUT);
    
    for(int i = 0; i < sizeof(additionalLEDs) / sizeof(int); i++) {
        pinMode(additionalLEDs[i], OUTPUT);
    }

    // Flash all LEDs 3 times
    for(int j = 0; j < 3; j++) {
        flashAllLEDs(500);
    }

    // Start with traffic light sequence
    trafficLightSequence();
}

void loop() {
    // Police car flashing pattern
    policeCarFlashing(10000);

    // Loop through patterns
    for (int i = 0; i < 10; i++) {
        playPattern(i);
    }
}

// Function to flash all LEDs
void flashAllLEDs(int duration) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, HIGH);
    digitalWrite(blueLED, HIGH);
    for(int i = 0; i < sizeof(additionalLEDs) / sizeof(int); i++) {
        digitalWrite(additionalLEDs[i], HIGH);
    }
    delay(duration);
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);
    for(int i = 0; i < sizeof(additionalLEDs) / sizeof(int); i++) {
        digitalWrite(additionalLEDs[i], LOW);
    }
    delay(duration);
}

void trafficLightSequence() {
    for (int i = 0; i < 3; i++) { // Loop 3 times
        // Red on
        digitalWrite(redLED, HIGH);
        delay(2000); // 2 seconds
        digitalWrite(redLED, LOW);
        
        // Yellow on
        digitalWrite(yellowLED, HIGH);
        delay(2000); // 2 seconds
        digitalWrite(yellowLED, LOW);
        
        // Green on
        digitalWrite(greenLED, HIGH);
        delay(4000); // 4 seconds
        digitalWrite(greenLED, LOW);
    }
}

void policeCarFlashing(unsigned long duration) {
    unsigned long startTime = millis();
    while (millis() - startTime < duration) {
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

void playPattern(int patternNumber) {
    switch (patternNumber) {
        case 0:
            ledChaser(100);
            break;
        case 1:
            slowDancingLights(300);
            break;
        case 2:
            snakePattern(150);
            break;
        case 3:
            alternateFlashing(250);
            break;
        case 4:
            wavePattern(200);
            break;
        case 5:
            rippleEffect(200);
            break;
        case 6:
            trailChaser(150);
            break;
        case 7:
            flashAllLEDs(200); // Shortened duration
            policeCarFlashing(5000); // 5 seconds
            break;
        case 8:
            morseCodeSOS(200);
            break;
        case 9:
            chaseBackAndForth(150);
            break;
        default:
            break;
    }
}

// Pattern functions

void ledChaser(int delayTime) {
    for(int i = 0; i < sizeof(additionalLEDs) / sizeof(int); i++) {
        digitalWrite(additionalLEDs[i], HIGH);
        delay(delayTime);
        digitalWrite(additionalLEDs[i], LOW);
    }
}

void slowDancingLights(int delayTime) {
    for(int i = 0; i < 10; i++) {
        int randLed = random(0, sizeof(additionalLEDs) / sizeof(int));
        digitalWrite(additionalLEDs[randLed], HIGH);
        delay(delayTime);
        digitalWrite(additionalLEDs[randLed], LOW);
    }
}

void snakePattern(int delayTime) {
    for(int i = 0; i < sizeof(additionalLEDs) / sizeof(int); i++) {
        digitalWrite(additionalLEDs[i], HIGH);
        delay(delayTime);
    }
    for(int i = sizeof(additionalLEDs) / sizeof(int) - 1; i >= 0; i--) {
        digitalWrite(additionalLEDs[i], LOW);
        delay(delayTime);
    }
}

void alternateFlashing(int delayTime) {
    for(int i = 0; i < sizeof(additionalLEDs) / sizeof(int); i += 2) {
        digitalWrite(additionalLEDs[i], HIGH);
    }
    delay(delayTime);
    for(int i = 0; i < sizeof(additionalLEDs) / sizeof(int); i += 2) {
        digitalWrite(additionalLEDs[i], LOW);
    }
    delay(delayTime);
    for(int i = 1; i < sizeof(additionalLEDs) / sizeof(int); i += 2) {
        digitalWrite(additionalLEDs[i], HIGH);
    }
    delay(delayTime);
    for(int i = 1; i < sizeof(additionalLEDs) / sizeof(int); i += 2) {
        digitalWrite(additionalLEDs[i], LOW);
    }
    delay(delayTime);
}

void wavePattern(int delayTime) {
    for(int i = 0; i < sizeof(additionalLEDs) / sizeof(int); i++) {
        digitalWrite(additionalLEDs[i], HIGH);
        delay(delayTime);
        digitalWrite(additionalLEDs[i], LOW);
    }
}

void rippleEffect(int delayTime) {
    for(int i = 0; i < sizeof(additionalLEDs) / sizeof(int); i++) {
        digitalWrite(additionalLEDs[i], HIGH);
        delay(delayTime);
        digitalWrite(additionalLEDs[i], LOW);
        delay(delayTime / 2);
    }
}

void trailChaser(int delayTime) {
    // Turn on LEDs one by one
    for(int i = 0; i < sizeof(additionalLEDs) / sizeof(int); i++) {
        digitalWrite(additionalLEDs[i], HIGH);
        delay(delayTime);
    }
    // Turn off LEDs one by one in reverse
    for(int i = sizeof(additionalLEDs) / sizeof(int) - 1; i >= 0; i--) {
        digitalWrite(additionalLEDs[i], LOW);
        delay(delayTime);
    }
}

void morseCodeSOS(int delayTime) {
    // SOS in Morse: ... --- ...
    int morseSOS[] = {1, 1, 1, 0, 2, 2, 2, 0, 1, 1, 1}; // 1 for short, 2 for long, 0 for space
    for(int i = 0; i < sizeof(morseSOS) / sizeof(int); i++) {
        if (morseSOS[i] == 1) { // Short blink
            digitalWrite(additionalLEDs[0], HIGH);
            delay(delayTime);
            digitalWrite(additionalLEDs[0], LOW);
        } else if (morseSOS[i] == 2) { // Long blink
            digitalWrite(additionalLEDs[0], HIGH);
            delay(delayTime * 3);
            digitalWrite(additionalLEDs[0], LOW);
        }
        delay(delayTime); // Space between blinks
    }
}

void chaseBackAndForth(int delayTime) {
    for (int j = 0; j < 5; j++) { // Repeat 5 times
        for(int i = 0; i < sizeof(additionalLEDs) / sizeof(int); i++) {
            digitalWrite(additionalLEDs[i], HIGH);
            delay(delayTime);
            digitalWrite(additionalLEDs[i], LOW);
        }
        for(int i = sizeof(additionalLEDs) / sizeof(int) - 1; i >= 0; i--) {
            digitalWrite(additionalLEDs[i], HIGH);
            delay(delayTime);
            digitalWrite(additionalLEDs[i], LOW);
        }
    }
}
