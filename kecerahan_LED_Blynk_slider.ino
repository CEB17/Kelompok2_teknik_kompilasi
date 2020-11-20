#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define Led D1

char auth[] = "qJrkhXiCvARi0FJzuCrI6VGn78s9V6TE";
char ssid[] = "NAUFAL";
char pass[] = "naufal12345";

void setup()
{
  // Debug console
  Serial.begin(115200); 
  pinMode(Led, OUTPUT);
  pinMode(V1,INPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  Blynk.virtualWrite(V1, 256);
}

