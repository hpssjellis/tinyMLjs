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

 
 

 * 
 * By Jeremy Ellis 
 * Twitter @rocksetta
 * Website https://rocksetta.com
 * created Aug 6th, 2020
 * 
*/
#include <RocksettaTinyML.h>

// sine_model.h contains the array you exported from the previous step with xxd or tinymlgen
#include "xor_model.h"

#define NUMBER_OF_INPUTS 25
#define NUMBER_OF_OUTPUTS 2
#define RETURN_TYPE_FROM_PREDICT float
// in future projects you may need to tweek this value: it's a trial and error process

// Create an area of memory to use for input, output, and intermediate arrays.
// The size of this will depend on the model you're using, and may need to be
// determined by experimentation.
// from other examples  constexpr int kTensorArenaSize = 60 * 1024;


//#define TENSOR_ARENA_SIZE 2*1024   
#define TENSOR_ARENA_SIZE 8*1024   // ???
//#define TENSOR_ARENA_SIZE 60*1024  



Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;


void setup() {
    randomSeed(analogRead(A0));
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    ml.begin(model_tflite);  // Not the name of the header file, name of the unsigned char Array
}

void loop() {

    
   // float input[] = { 0, 0 };   // 2 inputs. 
    //int myInA = rand() % 2;   // either 0 or 1
    //int myInB = rand() % 2;

    String myTemp;
    
    int32 input[NUMBER_OF_INPUTS];
    for (int myLoop = 0; myLoop < NUMBER_OF_INPUTS; myLoop++){
      input[myLoop] = rand() % 1000; //  0 to 999  

    }
    //int32 input[] = { myInA, myInB };   // 2 inputs. 
    //TfLiteTensor *myOutput;
    float myOutput[NUMBER_OF_OUTPUTS];
    float myPredicted = ml.predict(input, myOutput);   // the return float is just the first output good for testing
    if (myPredicted >= 0.5){
      digitalWrite(LED_BUILTIN, LOW); // grounds the LED turns it on only on portenta and nano 33 BLE
    } else {  
      digitalWrite(LED_BUILTIN, HIGH); //  turns it off only on portenta and nano 33 BLE
    }

    // First print all the inputs to the model
    for (int myLoop2 = 0; myLoop2 < NUMBER_OF_INPUTS; myLoop2++){
      Serial.print(String(input[myLoop2]) + ", ");
    }
    Serial.println();

   // Then print the predicted first label float inference
  //  Serial.println("Predicted:  " + String(myPredicted,3) + ", " + String(myOutput->data.f[1],3) );
    Serial.print("Predicted:  " + String(myPredicted,3)  );

    // Then print all the other label inference floats
    for (int myLoop3 = 0; myLoop3 < NUMBER_OF_OUTPUTS; myLoop3++){
      Serial.print(", Label[" + String(myLoop3) + "]: " + String(myOutput[myLoop3]));
    }
   Serial.println();
   Serial.println("-------------------------");

   // Serial.println("Predicted:  " + String(myPredicted,3)  );
  
    delay(3000); // slows things down
}
