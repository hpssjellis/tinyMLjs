/*
* RocksettaTinyML by Jeremy Ellis,keyfreemusic@gmail.com
*
* Based on the Arduino Library
* EloquentTinyML by Simone Salerno,eloquentarduino@gmail.com
* https://github.com/eloquentarduino/EloquentTinyML
* 
* Passed from the main program
* #define NUMBER_OF_INPUTS 8
* #define TYPE_OF_INPUTS int32             // uint8_t | int32 | float | bool | double | String 
* 
* #define NUMBER_OF_OUTPUTS 4
* #define TYPE_OF_OUTPUTS float            // uint8_t |int32 | float | bool | double | String 
* 
* #define RETURN_TYPE_FROM_PREDICT float    // void | uint8_t | int32 | float | bool | double | String 
* 
*/




#include <Arduino.h> // Only needed for https://platformio.org/
#include <RocksettaTinyML.h>
#include "niclaMotion.h"


//#include <Arduino_LSM9DS1.h> 
#include <Arduino_LSM6DSOX.h>
//#include "VL53L1X.h"

// GLOBAL VAERIABLES
//VL53L1X proximity;










/*
#define FREQUENCY_HZ        25     // how many samples per second 
#define COLLECTION_SECONDS  1     // how many seconds to collect samples
#define INTERVAL_MS  (1000 / (FREQUENCY_HZ + 1)) // need for the timer 
#define CONVERT_G_TO_MS2    9.80665f   // accleration conversion

int myMaxData = FREQUENCY_HZ * COLLECTION_SECONDS;
int myCount = 0;
int myDelay = INTERVAL_MS;   // non-block delay in milliseconds
unsigned long myStart; 

String readString;
bool mySendData = true;
bool mySendProximity = false;
int myProximityReading = 0;


*/

#define NUMBER_OF_INPUTS 75    //  3 senses x 25 readings each input array has 25 integer readings
#define NUMBER_OF_OUTPUTS 3    // one float output
// in future projects you may need to tweek this value: it's a trial and error process
#define TENSOR_ARENA_SIZE 2*1024

// GLOBAL VARIABLES
Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;
float myInput[NUMBER_OF_INPUTS];
float myOutput[NUMBER_OF_OUTPUTS];
int myCurrentIndex = 0;



void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // onboard LED, HIGH = off
  //while (!Serial) {}                 // do nothing and wait

  ml.begin(model_tflite);   // standard name inside proximityModel.h


  //myStart = millis();   // set delay
 // randomSeed(analogRead(A0));  // AO pin on XIAO does not have to be connected to anything
  Serial.println("accX,accY,accZ");  // CSV file heading titles
  
  if (!IMU.begin()) {
     Serial.println("Failed to initialize IMU!");
     while (1);
  }


  // Initilize the Proximity sensor and com using wire1
  //Wire1.begin();
  //Wire1.setClock(400000); // use 400 kHz I2C
  //proximity.setBus(&Wire1);



 // if (!proximity.init()) {
 //   Serial.println("Failed to detect and initialize sensor!");
 //   while (1);
 // }

 // proximity.setDistanceMode(VL53L1X::Long);
 // proximity.setMeasurementTimingBudget(10000);
 // proximity.startContinuous(10);


  // initialize buffer to zeros
  for (int i = 0; i < NUMBER_OF_INPUTS; i++) {
    myInput[i] = 0.0;
  }
}

void loop() {

float x, y, z;
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    x *= 1.00;  //9.81;
    y *= 1.00;  //9.81;
    z *= 1.00;  //9.81;
  }

  myInput[myCurrentIndex] = x;
  myInput[myCurrentIndex+1] = y;
  myInput[myCurrentIndex+2] = z;

  // this could be done easier
  myCurrentIndex = (myCurrentIndex + 3) % NUMBER_OF_INPUTS; // Wrap around to the beginning when the end is reached.

if (myCurrentIndex % NUMBER_OF_INPUTS == 0) {   // slows down showing the results



  float myPredict = ml.predict(myInput, myOutput); // make the proximity prediction on the last 25 samples

  Serial.print("Predicted: "+String(myPredict)  );  // output with minimal formating
 // Serial.println(String(ml.output[0]) );  
 // Serial.println("--" );  
  Serial.println("Label[0]:"+String(myOutput[0]) + ", label[1]" + String(myOutput[1]) + ", label[2]" + String(myOutput[2]) );  // output for plotter minimal formating
  
  if (myPredict < 0.50) {  
    digitalWrite(LED_BUILTIN, LOW);    // on for portenta, off for Nano33BleSense
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  delay(10);  // just to slow it a bit
}

}
