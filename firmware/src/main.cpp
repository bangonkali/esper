#include "main.h"

// Configuration c();

void setup()
{
  Serial.begin(BAUD_RATE);
  Serial.print("Current core: ");
  Serial.print(xPortGetCoreID());
  Serial.print("\n");

  configurationManager = new Configuration();
  configurationManager->configurationInfo = new Configuration::ConfigurationInfoStruct();
  strcpy(configurationManager->configurationInfo->WifiPass, "000");

  bluetoothServer = new BluetoothServer();
  bluetoothServer->configurationManager = configurationManager;
  bluetoothServer->init();
}

void loop()
{
  // put your main code here, to run repeatedly:
  bluetoothServer->loop();
}