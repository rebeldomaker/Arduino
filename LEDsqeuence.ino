// Define the LED pins
int LED1 = 13; // Note it is using the built-in LED for LED1
int LED2 = 12;
int LED3 = 11;

// Morse code for "GNU LINUX IS NOT UNIX"
String morseMessage = "--. -. ..-   .-.. .. -. ..- -..-   .. ...   -. --- -   ..- -. .. -..-";

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // Initial blinking of all LEDs
  for (int i = 0; i < 3; i++) {
    allLEDsOn();
    delay(1000); // All LEDs on for 1 second
    allLEDsOff();
    delay(1000); // All LEDs off for 1 second
  }

  // Sequential turning on and off for 5 loops
  for (int i = 0; i < 5; i++) {
    sequentialLEDs();
  }

  // Morse code on LED1 for "NUMBAT", repeat 3 times
  for (int i = 0; i < 3; i++) {
    morseCode(LED1, ".- -.- .-");
    delay(2000); // 2-second pause after the Morse code
  }

  // Morse code on LED2 for "GNU LINUX", repeat 3 times
  for (int i = 0; i < 3; i++) {
    morseCode(LED2, "--. -. ..-   .-.. .. -. ..- -..-");
    delay(2000); // 2-second pause after the Morse code
  }

  // Morse code on LED3 for "FREE SOFTWARE FREE SOCIETY", only once
  morseCode(LED3, "..-. .-. . .   ... --- ..-. - .-- .- .-. .   ..-. .-. . .   ... --- -.-. .. . - -.--");
  delay(2000);

  // Traffic light simulation
  for (int i = 0; i < 10; i++) {
    trafficLightSequence();
  }

  // Morse code message on the built-in LED, repeat indefinitely
  while(true) {
    morseCodeMessageOnBuiltInLED(morseMessage);
    delay(6000); // 6-second pause after the message
  }
}

void allLEDsOn() {
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED1, HIGH); // Built-in LED
}

void allLEDsOff() {
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED1, LOW); // Built-in LED
}

void sequentialLEDs() {
  digitalWrite(LED2, HIGH);
  delay(200);
  digitalWrite(LED3, HIGH);
  delay(200);
  digitalWrite(LED2, LOW);
  delay(300);
  digitalWrite(LED3, LOW);
  delay(300);
}

void morseCode(int led, String code) {
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '.') {
      digitalWrite(led, HIGH);
      delay(200); // Dot
      digitalWrite(led, LOW);
      delay(200);
    } else if (code[i] == '-') {
      digitalWrite(led, HIGH);
      delay(600); // Dash
      digitalWrite(led, LOW);
      delay(200);
    } else if (code[i] == ' ') {
      delay(600); // Space between words or letters, as appropriate
    }
  }
}

void trafficLightSequence() {
  digitalWrite(LED2, HIGH);
  delay(5000);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  delay(1000);
  digitalWrite(LED3, LOW);
  delay(4000);
}

void morseCodeMessageOnBuiltInLED(String code) {
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '.') {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(200); // Dot
      digitalWrite(LED_BUILTIN, LOW);
      delay(200);
    } else if (code[i] == '-') {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(600); // Dash
      digitalWrite(LED_BUILTIN, LOW);
      delay(200);
    } else if (code[i] == ' ') {
      delay(600); // Space between words or letters, as appropriate
    }
  }
  // After the message, turn off the LED and add a longer delay to signify the end of the message
  digitalWrite(LED_BUILTIN, LOW);
  delay(1400); // Longer pause between repetitions of the message
}
