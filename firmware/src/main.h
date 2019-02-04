#include <Arduino.h>
#include "bluetoothServer.h"

#ifndef MAIN_H
#define MAIN_H

#define ID_LIGHTS_TASK "000"
#define ID_BLUETOOTHSERVER_TASK "001"

TaskHandle_t HLights;
TaskHandle_t HBluetoothServerTask;

void BluetoothServerInitTask(void *parameter);
void BluetoothServerTask(void *parameter);

const unsigned int DELAY = 2000;
const unsigned int BAUD_RATE = 115200;

BluetoothServer *bluetoothServer = NULL;
Configuration *configurationManager = NULL;

#endif