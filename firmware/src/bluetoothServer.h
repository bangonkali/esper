#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <Arduino.h>
#include "bluetoothServerCallbacks.h"
#include "wifiSsidCharacteristicCallback.h"

#ifndef BLESERVER_H
#define BLESERVER_H

#define SERVICE_UUID "4faf2a3d-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb52a3d-36e1-4688-b7f5-ea07361b26a8"

class BluetoothServer
{

private:
  BluetoothServerCallbacks *bluetoothServerCallbacks = NULL;

public:
  Configuration *configurationManager = NULL;

  BLEServer *pServer = NULL;
  BLEService *pService = NULL;
  BLECharacteristic *pCharacteristic = NULL;
  BLEAdvertising *pAdvertising = NULL;
  
  BluetoothServer();
  void init();
  void loop();
};
#endif