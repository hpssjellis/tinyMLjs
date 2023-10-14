#include <RocksettaTinyML.h>
// sine_model.h contains the array you exported from the previous step with xxd or tinymlgen
#include "sine_model.h"

#define NUMBER_OF_INPUTS 1
#define NUMBER_OF_OUTPUTS 1
// in future projects you may need to tweek this value: it's a trial and error process
#define TENSOR_ARENA_SIZE 2*1024

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;

float myCount, myX, myY = 0;


void setup() {
  Serial.begin(115200);
  ml.begin(sine_model);
  pinMode(LED_BUILTIN, OUTPUT);   // try on Portenta LEDB = blue, LEDG or LED_BUILTIN = green, LEDR = red 

}

void loop() {

  myCount +=1;
  if (myCount >= 360){  // count all degrees of a circle
      myCount = 0;
  }

  myX = myCount * 3.14/180;  // degrees to radians
  myY = sin(myX);            // what the sin should be

  float input[1] = { myX };
  float myPredict = ml.predict(input); // make the sin prediction

  Serial.println(String(myPredict) + ",0," + String(myY) );  // output for plotter minimal formating
  if (myPredict < 0.50) {  
    digitalWrite(LED_BUILTIN, LOW); 
  } else
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  delay(9);  // just to slow it a bit
}
