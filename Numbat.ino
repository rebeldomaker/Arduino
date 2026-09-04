// Define the Morse code for each letter.
const char* morseN = "-.";
const char* morseU = "..-";
const char* morseM = "--";
const char* morseB = "-...";
const char* morseA = ".-";
const char* morseT = "-";

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // Initialize the built-in LED pin as an output.
  Serial.begin(9600); // Begin serial communication for debugging purposes.
}

void loop() {
  // Spell "NUMBAT" in Morse code using the LED.
  emitMorse(morseN);
  emitMorse(morseU);
  emitMorse(morseM);
  emitMorse(morseB);
  emitMorse(morseA);
  emitMorse(morseT);

  // Wait five seconds before repeating.
  delay(5000);
}

void emitMorse(const char* code) {
  // Loop through each character in the Morse code string.
  for (int i = 0; code[i]; i++) {
    if (code[i] == '.') {
      // If the character is a dot, blink the LED briefly.
      dot();
    } else {
      // If the character is a dash, blink the LED for a longer time.
      dash();
    }
    // Wait for a short period (the space between parts of the same letter) after each dot or dash.
    delay(200); // This is the standard space between signals within a letter.
  }

  // Wait for a longer period (the space between letters) after each letter.
  delay(600); // This is the standard space between letters.
}

void dot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200); // The standard length of a Morse code dot.
  digitalWrite(LED_BUILTIN, LOW);
  // Don't need to wait after a dot because the emitMorse function includes the wait.
}

void dash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(600); // The standard length of a Morse code dash is three times a dot.
  digitalWrite(LED_BUILTIN, LOW);
  // Don't need to wait after a dash because the emitMorse function includes the wait.
}
