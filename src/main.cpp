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


BLYNK_WRITE(V0)
{
  digitalWrite(D4,!param.asInt());
}
BLYNK_WRITE(V1)
{
  digitalWrite(D3,!param.asInt());
}
BLYNK_WRITE(V2)
{
  digitalWrite(D2,!param.asInt());
}
BLYNK_WRITE(V3)
{
  digitalWrite(D1,!param.asInt());
}
BLYNK_WRITE(V4)
{
  digitalWrite(D5,!param.asInt());
}

BLYNK_CONNECTED(){
  Blynk.syncVirtual(V0, V1, V2, V3, V4);
}



void yourSetup()
{
  Blynk.begin(auth, ssid, password, serverName, 8080);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
}

void yourLoop()
{
  Blynk.run();
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