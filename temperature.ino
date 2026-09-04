#include <LiquidCrystal.h>
#include <DHT.h>

// Set the DHT pin
#define DHTPIN 8

// Uncomment the type of sensor in use:
#define DHTTYPE DHT11   // DHT 11

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Initialize the LCD and set up the number of columns and rows
// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  dht.begin();         // Start the DHT sensor
  lcd.begin(16, 2);    // Set up the LCD's number of columns and rows

  // Print a static message to the LCD.
  lcd.print("Temp:      C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity:   %");
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  float temp = dht.readTemperature(); // Read temperature as Celsius
  float humi = dht.readHumidity();    // Read humidity (in percentage)

  // Check if any reads failed and exit early (to try again).
  if (isnan(humi) || isnan(temp)) {
    lcd.clear();
    lcd.print("Failed to read");
    return;
  }

  // Print the temperature and humidity to the LCD.
  lcd.setCursor(7, 0);  // Position the cursor to (column 7, row 0)
  lcd.print(temp);
  lcd.setCursor(0, 1);  // Position the cursor to (column 0, row 1)
  lcd.print("Humidity: ");
  lcd.print(humi);
  lcd.print("%");

  // Wait five seconds before updating again.
  delay(5000);

  // Clear the previous readings from the LCD
  lcd.setCursor(7, 0);  // Position the cursor to (column 7, row 0)
  lcd.print("     ");   // Overwrite previous temp with spaces
  lcd.setCursor(10, 1); // Position the cursor to (column 10, row 1)
  lcd.print("    ");    // Overwrite previous humidity with spaces
}

