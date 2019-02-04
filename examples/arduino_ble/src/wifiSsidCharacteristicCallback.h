#ifndef BLE_CONFIGURATION_CHARACTERISTIC_CALLBACK_H
#define BLE_CONFIGURATION_CHARACTERISTIC_CALLBACK_H

#include "str.h"
#include <BLEDevice.h>
#include "configuration/configuration.h"

class WifiSsidCharacteristicCallback : public BLECharacteristicCallbacks
{
public:
  Configuration *configurationManager = NULL;

  WifiSsidCharacteristicCallback(Configuration *configurationManager);
  void onWrite(BLECharacteristic *pCharacteristic);
  void onRead(BLECharacteristic *pCharacteristic);
};
#endif