#include "configuration.h"

void Configuration::saveToFlash()
{
    EEPROM.put(0, &this->configurationInfo);
    EEPROM.commit();
}

void Configuration::readFromFlash()
{
    EEPROM.begin(sizeof(ConfigurationInfoStruct));
    EEPROM.get(0, *this->configurationInfo);
}

void Configuration::parseString(std::string confStr)
{
    Serial.print(confStr.c_str());
}