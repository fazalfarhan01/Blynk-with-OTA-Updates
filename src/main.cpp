/***************************************************************************
 * THIS CODE IMPARTS THE OTA UPDATES CAPABILITY TO BLYNK HARDWARE USING
 * THE ARDUINO OTA LIBRARY...
 * 
 * INCLUDE THE REGULAR CODE IN THE "yourSetup() and "yourLoop()"" FUNCTION
 * 
 * "void yourSetup()" WORKS JUST LIKE "void Setup()"
 * "void yourLoop()" WORKS JUST LIKE "void loop()"
 * USE THEM APPROPRIATELY
 * 
 * *************************************************************************
 * 
 * AUTHOR: MOHAMED FARHAN FAZAL
 * DATE: 2020-08-23
 * VERSION: 1.1
 * WEBSITE: https://fazals.ddns.net
 * GITHUB: https://github.com/fazalfarhan01
 * LINKEDIN: https://linkedin.com/in/fazalfarhan01
 * 
***************************************************************************/

/**************************************************************************/
#include <Arduino.h>
#include <BlynkSimpleEsp8266.h>
#include <Credentials.h>
#include <OTAFunctions.h>
/******************************INCLUDES DONE*******************************/

#define BLYNK_PRINT Serial

BLYNK_WRITE(V0)
{
  digitalWrite(D4, !param.asInt());
}
BLYNK_WRITE(V1)
{
  digitalWrite(D3, !param.asInt());
}
BLYNK_WRITE(V2)
{
  digitalWrite(D2, !param.asInt());
}
BLYNK_WRITE(V3)
{
  digitalWrite(D1, !param.asInt());
}
BLYNK_WRITE(V4)
{
  digitalWrite(D5, !param.asInt());
}
BLYNK_WRITE(V5)
{
  digitalWrite(D6, !param.asInt());
}
BLYNK_WRITE(V12)
{
  if (param.asInt() >= 100)
  {
    Serial.println("Received Restart Count: " + String(param.asInt()));
    Blynk.notify("Restarting, Please Wait..!");
    Blynk.virtualWrite(V12, 0);
    ESP.restart();
  }
}

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0, V1, V2, V3, V4);
}

void sendUpTime()
{
  long uptime = millis() / 1000;
  Serial.println("Sending Uptime: " + String(uptime));
  Blynk.virtualWrite(V10, uptime);
}

void sendWiFiStrengthAndIP()
{
  long wifiStrength = WiFi.RSSI();
  String localIP = WiFi.localIP().toString();
  Serial.println("Sending Signal Strength: " + String(wifiStrength) + " Local IP: " + localIP);
  Blynk.virtualWrite(V11, wifiStrength);
  Blynk.virtualWrite(V13, localIP);
}

unsigned long currentMillis = millis();
unsigned long previousMillis = 0;
void customTimer(unsigned int timeInMillisec)
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= timeInMillisec)
  {
    previousMillis = currentMillis;
    // Put functions to be triggered after timer
    sendWiFiStrengthAndIP();
    sendUpTime();
  }
}

void yourSetup()
{
  Blynk.begin(auth, ssid, password, serverName, 8080);
  Serial.println("NodeMCU is now connected..!");
  Blynk.notify("Yaaay... NodeMCU is now online..!");
  Serial.println("Defining pinModes");
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  Serial.println("Setting up timers..!");
  Blynk.virtualWrite(V12, 0);
}

void yourLoop()
{
  Blynk.run();
  customTimer(1000);
}

void setup()
{
  initialiseOTA();
  yourSetup();
}

void loop()
{
  loopOTA();
  yourLoop();
}