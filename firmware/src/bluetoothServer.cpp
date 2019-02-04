#include "bluetoothServer.h"

BluetoothServer::BluetoothServer(void)
{
  this->bluetoothServerCallbacks = new BluetoothServerCallbacks();
}

void BluetoothServer::init()
{
  BLEDevice::init("ESP32");
  this->pServer = BLEDevice::createServer();
  this->pServer->setCallbacks(this->bluetoothServerCallbacks);

  this->pService = this->pServer->createService(SERVICE_UUID);
  this->pCharacteristic = this->pService->createCharacteristic(
      CHARACTERISTIC_UUID,
      BLECharacteristic::PROPERTY_READ |
          BLECharacteristic::PROPERTY_NOTIFY |
          BLECharacteristic::PROPERTY_INDICATE |
          BLECharacteristic::PROPERTY_WRITE);

  auto config = new BLE2902();
  config->setIndications(false);
  config->setNotifications(true);

  this->pCharacteristic->addDescriptor(config);

  auto configCharacteristicCallback = new WifiSsidCharacteristicCallback(this->configurationManager);
  this->pCharacteristic->setCallbacks(configCharacteristicCallback);
  // this->pCharacteristic

  this->pService->start();

  this->pAdvertising = BLEDevice::getAdvertising();

  this->pAdvertising->addServiceUUID(SERVICE_UUID);
  this->pAdvertising->setScanResponse(false);
  this->pAdvertising->setMinPreferred(0x0); // set value to 0x00 to not advertise this parameter

  BLEDevice::startAdvertising();

  // Serial.println("Waiting a client connection to notify...");
}

void BluetoothServer::loop()
{
  std::string oldValue = "";
  if (this->bluetoothServerCallbacks->isConnected())
  {
    std::string value = this->configurationManager->configurationInfo->WifiPass;
    if (oldValue.compare(value) != 0)
    {
      // pCharacteristic->setValue(value);
      // oldValue = value;
      // this->pCharacteristic->notify();
    }

    // this->value++;
    delay(10);
  }

  // disconnecting
  if (!this->bluetoothServerCallbacks->isDisconnecting())
  {
    delay(500);                        // give the bluetooth stack the chance to get things ready
    this->pServer->startAdvertising(); // restart advertising
    // Serial.println("start advertising");
    this->bluetoothServerCallbacks->updateConnectionState();
  }

  // connecting
  if (this->bluetoothServerCallbacks->isConnecting())
  {
    // do stuff here on connecting
    this->bluetoothServerCallbacks->updateConnectionState();
  }
}