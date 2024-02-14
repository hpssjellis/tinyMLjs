#include <Arduino.h> 

#include <Servo.h> 

 

const int joyXPin = A0;  // Joystick X-axis connected to analog pin A0 

const int joyYPin = A1;  // Joystick Y-axis connected to analog pin A1 

const int buttonPin = 2; // Button pin connected to digital pin 2 

 

Servo servoX;  // Servo object for X-axis 

Servo servoY;  // Servo object for Y-axis 

 

int joyXValue = 0;  // Variable to store X-axis value 

int joyYValue = 0;  // Variable to store Y-axis value 

 

bool shooting = false; // Flag to track shooting state 

 

void setup() { 

    Serial.begin(9600); 

 

    servoX.attach(9);  // Servo for X-axis connected to digital pin 9 

    servoY.attach(10); // Servo for Y-axis connected to digital pin 10 

 

    pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor 

} 

 

void loop() { 

    // Read joystick values 

    joyXValue = analogRead(joyXPin); 

    joyYValue = analogRead(joyYPin); 

 

    // Map joystick values to servo positions 

    int servoXPosition = map(joyXValue, 0, 1023, 0, 180); 

    int servoYPosition = map(joyYValue, 0, 1023, 0, 180); 

 

    // Move servos to joystick positions 

    servoX.write(servoXPosition); 

    servoY.write(servoYPosition); 

 

    // Determine direction based on joystick position 

    if (joyXValue < 300) { 

        // Joystick moved left 

        Serial.println("Left"); 

    } else if (joyXValue > 700) { 

        // Joystick moved right 

        Serial.println("Right"); 

    } 

 

    if (joyYValue < 300) { 

        // Joystick moved up 

        Serial.println("Up"); 

    } else if (joyYValue > 700) { 

        // Joystick moved down 

        Serial.println("Down"); 

    } 

 

    // Check if the shooting button is pressed 

    if (digitalRead(buttonPin) == LOW && !shooting) { 

        // Button is pressed and shooting is not in progress 

        Serial.println("Shoot"); 

        shooting = true; 

    } else if (digitalRead(buttonPin) == HIGH && shooting) { 

        // Button is released and shooting is in progress 

        shooting = false; 

    } 

 

    delay(100); // Adjust delay according to your requirements 

} 

 

 
