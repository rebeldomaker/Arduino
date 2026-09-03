// Pin Definitions
int analogPin = A0; // Input from photoresistor connected to A0
int buzzerPin = 9;  // Buzzer connected to pin 9 (PWM-capable pin)
int ledPin = 13;    // Onboard LED on pin 13

// Morse code for "THERAMIN"
String morseCode[] = {
  "- ",  // T
  ".... ",  // H
  ". ",  // E
  ".-. ",  // R
  ".- ",  // A
  "-- ",  // M
  ".. ",  // I
  "-. "   // N
};

long max_frequency = 2500; // Max frequency for the theremin
long frequency; // The frequency to buzz the buzzer
int readVal; // The input voltage read from photoresistor

void setup() {
    pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
    pinMode(ledPin, OUTPUT);    // Set onboard LED pin as output
    Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
    // Theremin function
    readVal = analogRead(analogPin); // Reads 0-1023 (standard 10-bit ADC)
    frequency = (readVal * max_frequency) / 1023;
    
    if (frequency > 0) {
        tone(buzzerPin, frequency);
    } else {
        noTone(buzzerPin);
    }
    
    delay(10); // Short delay to smooth the transition

    // Flash onboard LED with Morse code for "THERAMIN"
    flashMorseCode();
}

void flashMorseCode() {
    for (int i = 0; i < 8; i++) {  // Length of "THERAMIN"
        String code = morseCode[i];
        for (int j = 0; j < code.length(); j++) {
            char c = code[j];
            if (c == '.') {
                digitalWrite(ledPin, HIGH);
                delay(250); // Short blink for dot
                digitalWrite(ledPin, LOW);
                delay(250); // Short space between dots and dashes
            } else if (c == '-') {
                digitalWrite(ledPin, HIGH);
                delay(750); // Long blink for dash
                digitalWrite(ledPin, LOW);
                delay(250); // Short space between dots and dashes
            }
        }
        delay(500); // Pause between letters
    }
    delay(3000); // 3-second pause between repetitions of "THERAMIN"
}
