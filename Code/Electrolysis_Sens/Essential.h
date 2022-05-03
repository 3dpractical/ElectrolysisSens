#ifndef Essential.h
#define Essential.h

// ======== IO PIN & Comm. Address =============

// pH Sensor ===================================
#define PH_PIN 36

// MQ8 Hydrogen (H2) Sensor ====================
#define MQ8_PIN 39

// INA226 Current Sensor =======================
#define INA226_ADDR 0x40

long presentTick, prevTick, interval = 5000;
float ph, h2;
double amp;
uint8_t wifiTick;

#include "MQ8.h"
#include "pHSensor.h"
#include "Network.h"
#include "Current.h"

void sensorInit(){
  MQ8_init();
  Current_init();
}

void readSensor(){
  pH_read(true);
  MQ8_readH2(true);
  INA226_read(true);
  
}

#endif
