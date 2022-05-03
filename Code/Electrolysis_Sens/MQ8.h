#ifndef MQ8.h
#define MQ8.h

#include "Essential.h"

#include <MQUnifiedsensor.h>

#define ABREF             (12)
#define AVREF             (3.3)

#define RATIO_H2          (70)

MQUnifiedsensor H2 ("ESP-32", AVREF, ABREF, MQ8_PIN, "MQ-8");

void MQ8_init(){
  //H2 Initialization ========================
  Serial.println("Initialize MQxx sensor");
  H2.setRegressionMethod(1);
  H2.setA(976.97); H2.setB(-0.688);
  delay(3000);

  H2.init();
  H2.setRL(10);
  float H2_R0 = 0;
  for (uint8_t i = 1; i <= 10; i++){
    H2.update();
    H2_R0 += H2.calibrate(RATIO_H2);
    delay(20);
  }
  H2.setR0(H2_R0 / 10.0); 
}

void MQ8_readH2(bool debug){
  H2.update();
  h2 = H2.readSensor() + 200;
  if (debug == true){
    Serial.print("H2 = ");
    Serial.println(h2);
  }
}

//#define         RL_VALUE                     (10)
//#define         RO_CLEAN_AIR_FACTOR          (9.21)
//
//#define         CALIBRATION_SAMPLE_TIMES     (50)
//#define         CALIBRATION_SAMPLE_INTERVAL  (500)
//
//#define         READ_SAMPLE_INTERVAL         (50)
//#define         READ_SAMPLE_TIMES            (5)
//
//#define         GAS_H2                      (0)
//
//float           H2Curve[3]  =  {2.3, 0.93,-1.44};
//float           Ro           =  10;
//
//float MQResistanceCalculation(int raw_adc) {
//  return ( ((float)RL_VALUE*(4095-raw_adc)/raw_adc));
//}
//
//float MQCalibration(int mq_pin) {
//  int i;
//  float val=0;
// 
//  for (i=0;i<CALIBRATION_SAMPLE_TIMES ;i++) {            //take multiple samples
//    val += MQResistanceCalculation(analogRead(mq_pin));
//    delay(CALIBRATION_SAMPLE_INTERVAL);
//  }
//  val = val/CALIBRATION_SAMPLE_TIMES ;                   //calculate the average value
// 
//  val = val/RO_CLEAN_AIR_FACTOR;                        //divided by RO_CLEAN_AIR_FACTOR yields the Ro 
//                                                        //according to the chart in the datasheet 
// 
//  return val; 
//}
//
//float MQRead(int mq_pin) {
//  int i;
//  float rs=0;
// 
//  for (i=0;i<READ_SAMPLE_TIMES;i++) {
//    rs += MQResistanceCalculation(analogRead(mq_pin));
//    delay(READ_SAMPLE_INTERVAL);
//  }
// 
//  rs = rs/READ_SAMPLE_TIMES;
// 
//  return rs;  
//}
//
//uint8_t MQGetPercentage(float rs_ro_ratio, float *pcurve) {
//  return (pow(10,( ((log(rs_ro_ratio)-pcurve[1])/pcurve[2]) + pcurve[0])));
//}
//
//uint8_t MQGetGasPercentage(float rs_ro_ratio, int gas_id) {
//  if ( gas_id == GAS_H2) {
//     return MQGetPercentage(rs_ro_ratio,H2Curve);
//  }  
//  return 0;
//}
//
//void MQ8_init(){
//  Ro = MQCalibration(MQ8_PIN);                        //Calibrating the sensor. Please make sure the sensor is in clean air 
//                                                     //when you perform the calibration                    
//  Serial.print("Calibration is done...\n"); 
//  Serial.print("Ro=");
//  Serial.print(Ro);
//  Serial.print("kohm");
//  Serial.print("\n");
//}
//
//void MQ8_readH2(bool debug){
//  h2 = MQGetGasPercentage(MQRead(MQ8_PIN)/Ro,GAS_H2);
//  if (debug == true){
//    Serial.print("H2 = ");
//    Serial.println(h2);
//  }
//}



#endif
