#include <RocksettaTinyML.h>
// sine_model.h contains the array you exported from the previous step with xxd or tinymlgen
#include "proximityModel.h"
#include <Arduino.h> // Only needed for https://platformio.org/
//#include <Arduino_LSM9DS1.h> // for the nano33bleSense
#include <Arduino_LSM6DSOX.h>
#include "VL53L1X.h"

#define NUMBER_OF_INPUTS 1
#define NUMBER_OF_OUTPUTS 1
// in future projects you may need to tweek this value: it's a trial and error process
#define TENSOR_ARENA_SIZE 2*1024

// GLOBAL VAERIABLES
Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;

VL53L1X proximity;
float myCount, myX, myY = 0;
int myProximityReading = 0;

const int myBufferSize = 25;
float myInput[myBufferSize];
int myCurrentIndex = 0;



void setup() {
  Serial.begin(115200);
  ml.begin(sine_model);
  pinMode(LED_BUILTIN, OUTPUT);   // try on Portenta LEDB = blue, LEDG or LED_BUILTIN = green, LEDR = red 

  // Initilize the Proximity sensor and com using wire1
  Wire1.begin();
  Wire1.setClock(400000); // use 400 kHz I2C
  proximity.setBus(&Wire1);

  // initialize buffer to zeros
  for (int i = 0; i < myBufferSize; i++) {
    myInput[i] = 0;
  }

}

void loop() {

  myProximityReading = proximity.read();

  // Add the new value and update the current index.
  myInput[myCurrentIndex] = myProximityReading;

  // this could be done easier
  myCurrentIndex = (myCurrentIndex + 1) % myBufferSize; // Wrap around to the beginning when the end is reached.


  float myPredict = ml.predict(myInput); // make the proximity prediction on the last 25 samples

  Serial.println(String(myPredict)  );  // output with minimal formating
  if (myPredict < 0.50) {  
    digitalWrite(LED_BUILTIN, LOW);    // on for portenta, off for Nano33BleSense
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  delay(9);  // just to slow it a bit
}
