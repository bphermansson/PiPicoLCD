#include <TFT_eSPI.h> // Hardware-specific library
#include "NotoSansBold36.h"
#include <WiFi.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

#define AA_FONT_LARGE NotoSansBold36

#ifndef STASSID
#define STASSID "BrandstorpWifi"
#define STAPSK "Brandstorp"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

const char* host = "djxmmx.net";
const uint16_t port = 17;

WiFiMulti multi;

void setup() {
  tft.init();
  tft.setRotation(2);
  tft.loadFont(AA_FONT_LARGE); 

   tft.setCursor(0, 0, 2);
  // Set the font colour to be white with a black background, set text size multiplier to 1
  tft.setTextColor(TFT_WHITE,TFT_BLACK);  tft.setTextSize(1);
  // We can now plot text on screen using the "print" class
  tft.println("Hello World!");

  tft.setTextSize(3);   
  tft.setTextColor(TFT_YELLOW);  // Set text colour to black, no background (so transparent)
  tft.setCursor(76, 150, 4);    // Set cursor to x = 76, y = 150 and use font 4
  tft.println("TEST");  

  // We start by connecting to a WiFi network
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  multi.addAP(ssid, password);

    if (multi.run() != WL_CONNECTED) {
      Serial.println("Unable to connect to network, rebooting in 10 seconds...");
      delay(10000);
      rp2040.reboot();
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println("OK");


}

void loop() {
 // tft.fillScreen(random(0xFFFF));

}
