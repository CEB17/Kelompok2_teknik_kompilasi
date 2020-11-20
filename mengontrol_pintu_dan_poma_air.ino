#define BLYNK_PRINT Serial
#define Trigger 39
#define Echo 36
#define Trigger2 35
#define Echo2 34
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

long duration, duration2;
long distance, distance2;
char auth[] = "Ti2Gj_Vdi-jfxxOoNr5zi299UoUr__uT";
char ssid[] = "Crateme";
char pass[] = "carisajasendiri";
BlynkTimer waktu;
bool flag = false;

void Notifikasi(){
  if(flag == true)
  {
    Blynk.notify("Door Opened");
    Serial.println("Door Opened");
  } 
  else if(flag == false) 
  {
    Blynk.notify("Door Closed");
    Serial.println("Door Closed");
  }
}

void setup() {
// put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(Trigger2, OUTPUT);
  pinMode(Echo2, INPUT);
  Blynk.begin(auth,ssid,pass);
  waktu.setInterval(22000L, Notifikasi);
}

void UltraPintu(){
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  duration = pulseIn(Echo, HIGH);
  distance = duration * 0.034/2;
  if(distance <= 5 && distance2 <= 5)
  {
    Serial.println("Terlalu dekat!!");
  } 
  else 
  {
    Serial.print("Jarak : ");
    Serial.print(distance);
    Serial.print(" ");
    Serial.print("Jarak 2: ");
    Serial.println(distance2);
  }
  delay(500);
  if(distance < 20 && flag == true){
    flag = false;
  } else if(distance > 20 && flag == false) {
    flag = true;
  }
  Blynk.virtualWrite(V5, distance);
}

void loop() {
// put your main code here, to run repeatedly:
  UltraPintu();
  Blynk.run();
  waktu.run();
}
