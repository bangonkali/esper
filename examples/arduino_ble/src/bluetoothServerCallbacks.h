#include <BLEDevice.h>

#ifndef BLESERVERCALLBACKS_H
#define BLESERVERCALLBACKS_H

class BluetoothServerCallbacks : public BLEServerCallbacks
{
private:
  BLECharacteristic *pCharacteristic = NULL;
  BLEServer *pServer = NULL;
  bool deviceConnected = false;
  bool oldDeviceConnected = false;

public:
  void onConnect(BLEServer *pServer);
  void onDisconnect(BLEServer *pServer);
  bool isConnected();
  bool isDisconnecting();
  bool isConnecting();
  void updateConnectionState();
};

#endif