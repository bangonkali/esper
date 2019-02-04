#include "wifiSsidCharacteristicCallback.h"

void WifiSsidCharacteristicCallback::onWrite(BLECharacteristic *pCharacteristic)
{
    strncpy(this->configurationManager->configurationInfo->WifiPass, pCharacteristic->getValue().c_str(), MAX_LENGTH);
    this->configurationManager->saveToFlash();
}

void WifiSsidCharacteristicCallback::onRead(BLECharacteristic *pCharacteristic)
{
    this->configurationManager->readFromFlash();
    std::string value = this->configurationManager->configurationInfo->WifiPass;
    pCharacteristic->setValue(value);
}

WifiSsidCharacteristicCallback::WifiSsidCharacteristicCallback(Configuration *configurationManager)
{
    this->configurationManager = configurationManager;
}