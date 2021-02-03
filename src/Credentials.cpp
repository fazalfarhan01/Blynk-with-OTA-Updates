#include <Credentials.h>

char auth[] = "REPLACE-WITH-YOUR-BLYNK-APP-CREDENTIALS";

#ifndef STASSID
#define STASSID "REPLACE-WITH-WIFI-SSOD"
#define STAPSK "REPLACE-WITH-WIFI-PASSWORD"
#define STAHOSTNAME "REPLACE-WITH-NODEMCU-DNS-NAME"
#define STAOTAPASSWORD "REPLACE-WITH-OTA-UPDATE-PASSWORD"
#define SERVERNAME "blynk-cloud.com"
#endif

const char *ssid = STASSID;
const char *password = STAPSK;
const char *hostName = STAHOSTNAME;
const char *OTAPassword = STAOTAPASSWORD;
const char *serverName = SERVERNAME;