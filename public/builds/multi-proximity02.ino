/*
 * webSerial for testing javascript connection with an arduino
 * 
 * Latest work at   https://github.com/hpssjellis/webMLserial
 * 
 * Note: On the Arduino Serial monitor make sure no line-ending or if statements will not work
 * 
 * Android https://hpssjellis.github.io/web-serial-polyfill/index.html
 * Laptops Desktops  https://hpssjellis.github.io/my-examples-of-arduino-webUSB-webSerial/public/index.html
 * IOS     not really sure
 * 
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




#include <RocksettaTinyML.h>
#include "proximityModel.h"

#define NUMBER_OF_INPUTS 25
#define NUMBER_OF_OUTPUTS 2
#define RETURN_TYPE_FROM_PREDICT float
#define TENSOR_ARENA_SIZE 8*1024  

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;
int myCurrentIndex = 0;
int32 input[NUMBER_OF_INPUTS];
float myOutput[NUMBER_OF_OUTPUTS];
bool myPredictProximity = false;




#include <Arduino.h> // Only needed for https://platformio.org/
//#include <Arduino_LSM9DS1.h> 
#include <Arduino_LSM6DSOX.h>
#include "VL53L1X.h"

// GLOBAL VAERIABLES
VL53L1X proximity;

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


void setup() { 
  ml.begin(model_tflite);  // Not the name of the header file, name of the unsigned char Array
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // onboard LED, HIGH = off
  //while (!Serial) {}                 // do nothing and wait
  
  myStart = millis();   // set delay
  randomSeed(analogRead(A0));  // AO pin on XIAO does not have to be connected to anything
  Serial.println("accX,accY,accZ");  // CSV file heading titles
  
  if (!IMU.begin()) {
     Serial.println("Failed to initialize IMU!");
     while (1);
  }


  // Initilize the Proximity sensor and com using wire1
  Wire1.begin();
  Wire1.setClock(400000); // use 400 kHz I2C
  proximity.setBus(&Wire1);



  if (!proximity.init()) {
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }

  proximity.setDistanceMode(VL53L1X::Long);
  proximity.setMeasurementTimingBudget(10000);
  proximity.startContinuous(10);

}

void loop() {
  float x, y, z;
  myProximityReading = proximity.read();
  if ( (millis() - myStart ) >= myDelay) {       
     myStart = millis();      //  reset the delay time
     myCount += 1;
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    x *= 9.81;
    y *= 9.81;
    z *= 9.81;

  }

    if (myCount >= myMaxData){
      mySendData = false;   // stop sending data when amount reached
    }

    if (myPredictProximity) {
      myCurrentIndex = (myCurrentIndex + 1) % NUMBER_OF_INPUTS; // Wrap around to the beginning when the end is reached.
      input[myCurrentIndex] = myProximityReading;

      //  First print all the inputs to the model
      //  for (int myLoop2 = 0; myLoop2 < NUMBER_OF_INPUTS; myLoop2++){
      //   Serial.print(String(input[myLoop2]) + ", ");
      //  }
      //  Serial.println();
      //  Serial.print("Predicted:  " + String(myPredicted,3)  );  // not needed since same as myOutput[0]


      if (myCurrentIndex == 0) {  // only send data to the model every 25 readings
        
        float myPredicted = ml.predict(input, myOutput); 
        Serial.println("Proximity: " + String(myProximityReading) +", Far label[0]: "+String(myOutput[0]) + ", Near label[1]:" + String(myOutput[1]) );  // output for plotter minimal formating
      
        if (myPredicted >= 0.5){   // same as the first myOutput[0]
          digitalWrite(LED_BUILTIN, LOW); // grounds the LED turns it on only on portenta, off for the nano 33 BLE
        } else {  
          digitalWrite(LED_BUILTIN, HIGH); //  turns it off only on portenta and on for the nano 33 BLE
        }
      }

      delay(10);
    }


     // This should be written better perhaps a case statement etc
     if (mySendData){
        if (mySendProximity){
          Serial.println(String(myProximityReading));  
        } else {
          Serial.println( String(x) + "," + String(y) + "," +  String(z)  );
        }
     } 
   }

   while (Serial.available()) {
    delay(3);  
    char myChar = Serial.read();
    readString += myChar; 
  }

  if (readString.length() > 0) {
    readString.trim();  // get rid of last weird character
    if (readString == "a"){
      digitalWrite(LED_BUILTIN, LOW); //onboard LED LOW = on
    }
    if (readString == "b"){
      digitalWrite(LED_BUILTIN, HIGH);
    }
    if (readString == "start"){
      myPredictProximity = false;
      mySendProximity = false;
      mySendData = true;
      myStart = millis();      //  reset the delay time
      myCount = 0;
    }
    if (readString == "stop"){
      myPredictProximity = false;
      mySendData = false;
      Serial.println("Stopping at count: "+ String(myCount));  // CSV file heading titles
    }
    if (readString == "firstline"){
      myPredictProximity = false;
      if (mySendProximity){
         Serial.println("proximity"); 
      } else {
        Serial.println("accX,accY,accZ");  // CSV file heading titles
      }
    }

    if (readString == "proximity"){
      myPredictProximity = false;
      mySendProximity = true;
      mySendData = true;
      myStart = millis();      //  reset the delay time
      myCount = 0;

    }
    if (readString == "PredictProximity"){
      myPredictProximity = true;
      mySendProximity = false;
      mySendData = false;
    }

    
    readString="";
  } 
  
}

    


    
