#include "bluetoothServerCallbacks.h"

void BluetoothServerCallbacks::updateConnectionState()
{
    this->oldDeviceConnected = this->deviceConnected;
}

bool BluetoothServerCallbacks::isConnecting()
{
    return this->deviceConnected && !this->oldDeviceConnected;
}

bool BluetoothServerCallbacks::isDisconnecting()
{
    return !this->deviceConnected && this->oldDeviceConnected;
}

bool BluetoothServerCallbacks::isConnected()
{
    return this->deviceConnected;
}

void BluetoothServerCallbacks::onDisconnect(BLEServer *pServer)
{
    this->deviceConnected = false;
}

void BluetoothServerCallbacks::onConnect(BLEServer *pServer)
{
    this->deviceConnected = true;
    BLEDevice::startAdvertising();
}
