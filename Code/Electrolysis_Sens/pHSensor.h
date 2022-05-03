#ifndef pHSensor.h
#define pHSensor.h

#include "Essential.h"

#define PH_CALIBRATE 21.34
unsigned long int avgVal;
int buff[10], temp;

void pH_read(bool debug){
  for (int i = 0; i < 10; i++){
    buff[i] = analogRead(PH_PIN);
    delay(10);
  }
  for (int i = 0; i < 9; i++){
    for (int j = i + 1; j < 10; j++){
      if (buff[i] > buff[j]){
        temp = buff[i];
        buff[i] = buff[j];
        buff[j] = temp;
      }
    }
  }
  avgVal = 0;
  for (uint8_t i = 2; i < 8; i++){
    avgVal += buff[i];
  }
  ph = (float) avgVal/6*3.4469/4095;
  ph = -5.70 * ph + PH_CALIBRATE;
  if (debug == true){
    Serial.print("pH = ");
    Serial.println(ph); 
  }
}

#endif
