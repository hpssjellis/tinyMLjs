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
 */



#include <Arduino.h> // Only needed for https://platformio.org/

/**********/
/*INCLUDES*/
/**********/


// REV 2 CHANGES HERE 

/* For LSM9DS1 9-axis IMU sensor */
#include <Arduino_LSM9DS1.h>         // REV 1
//#include "Arduino_BMI270_BMM150.h" // REV 2

/* For HTS221 Temperature and humidity sensor */
#include <Arduino_HTS221.h>          // REV 1
//#include <Arduino_HS300x.h>        // REV 2
//#define HTS HS300x                   // For REV 2 to work with old REV1 code


// END REV 2 CHANGES  



/* For MP34DT05 microphone */
#include <PDM.h>



/* For APDS9960 Gesture, light, and proximity sensor */
#include <Arduino_APDS9960.h>

/* For LPS22HB barometric barometricPressure sensor */
#include <Arduino_LPS22HB.h>





#define FREQUENCY_HZ        36     // how many samples per second 
#define COLLECTION_SECONDS  1     // how many seconds to collect samples
#define INTERVAL_MS  (1000 / (FREQUENCY_HZ + 1)) // need for the timer 
#define CONVERT_G_TO_MS2    9.80665f   // accleration conversion

int myMaxData = FREQUENCY_HZ * COLLECTION_SECONDS;
int myCount = 0;
int myDelay = INTERVAL_MS;   // non-block delay in milliseconds
unsigned long myStart; 

String readString;
bool mySendData = true;
bool mySendFancy1 = false;
bool mySendFancy2 = false;




// For PDM microphone buffer to read samples into, each sample is 16-bits 
short sampleBuffer[256];

// For PDM microphone  number of samples read
volatile int samplesRead;

/* used for the PDM microphone */
long myAverageSound = 0;
long myTotalSounds = 0;
long myMappedSound = 0;

/* variables to hold LSM9DS1 accelerometer data */
float accelerometerX, accelerometerY, accelerometerZ;
/* variables to hold LSM9DS1 gyroscope data */
float gyroscopeX, gyroscopeY, gyroscopeZ;
/* variables to hold LSM9DS1 magnetic data */
float magneticX, magneticY, magneticZ;
/* variables to hold LPS22HB  barometric pressure data */
float barometricPressure;
/* variables to hold APDS9960 proximity, gesture and colour data */
int proximity, gesture, colourR, colourG, colourB;
/* variables to hold HTS221 temperature and humidity data */
float temperature, humidity;




void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // onboard LED, HIGH = off
  //while (!Serial) {}                 // do nothing and wait
  
  myStart = millis();   // set delay
  randomSeed(analogRead(A0));  // AO pin on XIAO does not have to be connected to anything
  Serial.println("accX,accY,accZ");  // CSV file heading titles

  // configure the data receive callback
  PDM.onReceive(onPDMdata);

  // optionally set the gain, defaults to 20
  // PDM.setGain(30);

  // initialize PDM with:
  // - one channel (mono mode)
  // - a 16 kHz sample rate
  if (!PDM.begin(1, 16000)) {
    Serial.println("Failed to start PDM!");
    while (1);
  }


  
  /* IMU setup for LSM9DS1*/
  /* default setup has all sensors active in continous mode. Sample rates
   *  are as follows: magneticFieldSampleRate = 20Hz, gyroscopeYroscopeSampleRate = 109Hz,
   * accelerationSampleRate = 109Hz */
  if (!IMU.begin())
  {
    Serial.println("Failed to initialize IMU!");
    /* Hacky way of stopping program executation in event of failure. */
    while(1);
  }


  /* Set sensitivity from 0 to 100. Higher is more sensitive. In
   * my experience it requires quite a bit of experimentation to
   * get this right, as if it is too sensitive gestures will always
   * register as GESTURE_DOWN or GESTURE_UP and never GESTURE_LEFT or
   * GESTURE_RIGHT. This can be called before APDS.begin() as it just
   * sets an internal sensitivity value.*/
  APDS.setGestureSensitivity(70);  // 0 to 100
  if (!APDS.begin())
  {
    Serial.println("Error initializing APDS9960 sensor.");
    /* Hacky way of stopping program executation in event of failure. */
    while(1);
  }
  /* As per Arduino_APDS9960.h, 0=100%, 1=150%, 2=200%, 3=300%. Obviously more
   * boost results in more power consumption. */
  APDS.setLEDBoost(0);

  /* Barometric sensor setup for LPS22HB*/
  if (!BARO.begin())
  {
    Serial.println("Failed to initialize barometricPressure sensor!");
    while (1);
  }

  /* Temperature/Humidity sensor setup for HTS221*/
  if (!HTS.begin())
  {
    Serial.println("Failed to initialize humidity temperature sensor!");
    /* Hacky way of stopping program executation in event of failure. */
    while(1);
  }
}





void onPDMdata() {
  // query the number of bytes available
  int bytesAvailable = PDM.available();

  // read into the sample buffer
  PDM.read(sampleBuffer, bytesAvailable);

  // 16-bit, 2 bytes per sample
  samplesRead = bytesAvailable / 2;
}




void loop() {
  float x, y, z;
  if ( (millis() - myStart ) >= myDelay) {       
     myStart = millis();      //  reset the delay time
     myCount += 1;



    
   //map(value, fromLow, fromHigh, toLow, toHigh)
   myMappedSound = map(myAverageSound, -1000, 1000, 0, 100);


    barometricPressure = BARO.readPressure(); //*-5;
    temperature = HTS.readTemperature();   //*-10;
    humidity = HTS.readHumidity();   //*-5;




  /* If new acceleration data is available on the LSM9DS1 get the data.*/
  if(IMU.accelerationAvailable())
  {
    IMU.readAcceleration(accelerometerX, accelerometerY, accelerometerZ);
    accelerometerX = 9.8 *accelerometerX ; //+ 100;   // acceleration to Force F = gA = 9.8 *a
    accelerometerY = 9.8 *accelerometerY ; //+ 200;  
    accelerometerZ = 9.8 *accelerometerZ ; //+ 300;  
  }
  /* If new gyroscope data is available on the LSM9DS1 get the data.*/
  if(IMU.gyroscopeAvailable())
  {
    IMU.readGyroscope(gyroscopeX, gyroscopeY, gyroscopeZ);
//gyroscopeX = 0.1 *gyroscopeX + 400; 
   // gyroscopeY = 0.1 *gyroscopeY + 500; 
   // gyroscopeZ = 0.1 *gyroscopeZ + 600; 
  }
  /* If new magnetic data is available on the LSM9DS1 get the data.*/
  if (IMU.magneticFieldAvailable())
  {
    IMU.readMagneticField(magneticX, magneticY, magneticZ);
   // magneticX = 0.5 * magneticX + 600; 
   // magneticY = 0.5 * magneticY + 700; 
   // magneticZ = 0.5 * magneticZ + 800; 
  }
  /* If new proximity data is available on the APDS9960 get the data.*/
  if (APDS.proximityAvailable())
  {
    proximity = APDS.readProximity();
   // proximity *= 3;
  }
  /* If new colour data is available on the APDS9960 get the data.*/
  if (APDS.colorAvailable())
  {
    APDS.readColor(colourR, colourG, colourB);
    
   // colourR -= 200;
    //colourG -= 300;
    //colourB -= 400;
  }
  /* If new gesture data is available on the APDS9960 get the data.*/
  if (APDS.gestureAvailable())
  {
    gesture = APDS.readGesture();  //*0.5;  // random number (5) to make it easier to see
  } 

////////////////////////////////// end random changes



     //Serial.println( String(myStart)+ "," + String(analogRead(A0)) + "," + String(analogRead(A1)) + "," +  String(analogRead(A2))  );
     if (myCount >= myMaxData){
        mySendData = false;   // stop sending data when amount reached
     }
     if (mySendData){
       // Serial.println( String(accelerometerX,2) + "," + String(accelerometerY,2) + "," +  String(accelerometerZ,2)  );
       if (mySendFancy1){
           Serial.println( String(gesture) );
       } else if (mySendFancy2){
            Serial.print(String(myMappedSound) + ",");
            Serial.print(String(accelerometerX,4) + "," + String(accelerometerY,4)+"," + String(accelerometerZ,4) + ","  );
          
            Serial.print(String(gyroscopeX) + "," + String(gyroscopeY)+"," + String(gyroscopeZ) +","  );
            Serial.print(String(magneticX) + "," + String(magneticY)+"," + String(magneticZ) +","   );
            Serial.print(String(barometricPressure) +"," );
          
            Serial.print(String(proximity) + "," + String(gesture)  +","  );

            Serial.print(String(colourR) + "," + String(colourG)+"," + String(colourB)  +"," );
            Serial.print(String(temperature) + "," + String(humidity) );
          
            Serial.println();
                    //sound,a-x,a-y,a-z,g-x,g-y,g-z,m-x,m-y,m-z,pres,prox,gesture,R,G,B,temp,humid
       } else {
           // if neither of the fancy settings then just do acceleration
            Serial.println( String(accelerometerX,2) + "," + String(accelerometerY,2) + "," +  String(accelerometerZ,2)  );
     
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
      mySendFancy1 = false;
      mySendFancy2 = false;
      mySendData = true;
      myStart = millis();      //  reset the delay time
      myCount = 0;
    }
    if (readString == "fancy1"){
      mySendFancy1 = true;
      mySendFancy2 = false;
      mySendData = true;
      myStart = millis();      //  reset the delay time
      myCount = 0;
    }
    if (readString == "fancy2"){
      mySendFancy1 = false;
      mySendFancy2 = true;
      mySendData = true;
      myStart = millis();      //  reset the delay time
      myCount = 0;
    }
    if (readString == "stop"){
      mySendData = false;
      Serial.println("Stopping at count: "+ String(myCount));  // CSV file heading titles
    }
    if (readString == "firstline"){
     // Serial.println("accX,accY,accZ");  // CSV file heading titles
       if (mySendFancy1){
          Serial.println("gestures");
       } else if (mySendFancy2){
          Serial.println("sound,a-x,a-y,a-z,g-x,g-y,g-z,m-x,m-y,m-z,pres,prox,gesture,R,G,B,temp,humid");
       }
       else {
          Serial.println("accX,accY,accZ");
       }
    }
    readString="";
  } 
  
}
   
