/* https://lastminuteengineers.com/oled-display-arduino-tutorial/ */

#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);   // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally

  display.display();  // Show initial display buffer contents on the screen -- the library initializes this with an Adafruit splash screen.  delay(2000); // Pause for 2 seconds
  display.clearDisplay();// Clear the buffer


  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0, 0);            // Start at top-left corner
  display.println(" SSID/PSW: speechbee");
  display.setCursor(0, 9);            // Start at top-left corner
  display.println("Project Title");
  display.display();


}

void loop() {





}
