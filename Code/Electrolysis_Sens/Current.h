#ifndef Current.h
#define Current.h

#include <Wire.h>
#include <INA226_WE.h>

INA226_WE AMP = INA226_WE(INA226_ADDR);

void Current_init(){
  Wire.begin();
  bool stat = AMP.init();
  if(!stat){
    Serial.println("INA226 error");
  }
  delay(100);

  AMP.waitUntilConversionCompleted();
}

float INA226_read(bool debug){
  amp = AMP.getCurrent_mA();
  if (debug == true){
    Serial.print("Current = ");
    Serial.println(amp);
  }
}

//void Current_init(){
//  bool stat = AMP.begin();
//  if(!stat){
//    Serial.println("INA226 Error");
//  }
//  delay(100);
//
//  AMP.configure(INA226_AVERAGES_1, INA226_BUS_CONV_TIME_1100US, INA226_SHUNT_CONV_TIME_1100US, INA226_MODE_SHUNT_BUS_CONT);
//  AMP.calibrate(0.100, 4);
//}
//
//float INA226_read(bool debug){
//  amp = AMP.readShuntCurrent();
//  if (debug == true){
//    Serial.print("Current = ");
//    Serial.println(amp, 5);
//  }
//}

#endif
