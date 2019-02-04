#include <Arduino.h>
#include <EEPROM.h>

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define MAX_LENGTH 20

class Configuration
{
public:
  struct ConfigurationInfoStruct
  {
    char Name[MAX_LENGTH];
    char WifiSSID[MAX_LENGTH];
    char WifiPass[MAX_LENGTH];

    bool FromFlash = false;
  };

  ConfigurationInfoStruct *configurationInfo = NULL;

  void saveToFlash();
  void readFromFlash();
  void parseString(std::string confStr);
};

#endif
