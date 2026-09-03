int analogPin = A0; // Input from photoresistor connected to A0
int buzzerPin = 4;  // Positive buzzer pin connected to pin 4

long max_frequency = 1000; // Lowered max frequency to reduce high pitch
long min_frequency = 10;   // Further lowered min frequency for even deeper tones
long frequency; // The frequency to buzz the buzzer
int readVal; // The input voltage read from photoresistor

void setup() {
    pinMode(buzzerPin, OUTPUT); // Set a pin for buzzer output
    Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
    readVal = analogRead(analogPin); // Reads 0-1023
    
    // Reverse the mapping so that more light means lower frequency (deeper tone)
    frequency = map(readVal, 0, 1023, max_frequency, min_frequency);
    
    playTone(buzzerPin, frequency); // Play tone based on the light intensity

    // Print the values for debugging
    Serial.print("Analog value: ");
    Serial.print(readVal);
    Serial.print(" Frequency: ");
    Serial.println(frequency);

    delay(10); // Short delay to smooth the transition
}

void playTone(int targetPin, long frequency) {
    if (frequency > 0) {
        tone(targetPin, frequency);
    } else {
        noTone(targetPin);
    }
}
