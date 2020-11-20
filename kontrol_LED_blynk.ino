#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "ayFBISn_3Q1m4E63FEwG5zBeWm7mZDp6";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Kos";
char pass[] = "TMB6868TMB";

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
}
void loop()
{
  Blynk.run();
}

