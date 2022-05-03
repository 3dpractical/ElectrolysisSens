#include "Essential.h"
#include "Network.h"

void setup() {
  //Serial Initialization ==========================
  Serial.begin(115200);

  //All I/O & Network Initialization ===============
  sensorInit();
  networkInit();
}

void loop() {
  //5s routine =====================================
  presentTick = millis();
  if(presentTick - prevTick >= interval){
    readSensor();
    DB_stream();
    prevTick = presentTick;  
  }
}
