#include <Arduino.h> 

#include <Servo.h> 

#include <Mouse.h> 

 

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

 

    Mouse.begin(); // Initialize Mouse control 

} 

 

void loop() { 

    // Read joystick values 

    joyXValue = analogRead(joyXPin); 

    joyYValue = analogRead(joyYPin); 

 

    // Map joystick values to servo positions 

    int servoXPosition = map(joyXValue, 0, 1023, -10, 10); // Adjust the range based on your joystick sensitivity 

    int servoYPosition = map(joyYValue, 0, 1023, -10, 10); // Adjust the range based on your joystick sensitivity 

 

    // Move the mouse cursor based on joystick position 

    Mouse.move(servoXPosition, servoYPosition, 0); 

 

    // Check if the shooting button is pressed 

    if (digitalRead(buttonPin) == LOW && !shooting) { 

        // Button is pressed and shooting is not in progress 

        Serial.println("Shoot"); 

        shooting = true; 

        // Simulate mouse click 

        Mouse.press(); 

    } else if (digitalRead(buttonPin) == HIGH && shooting) { 

        // Button is released and shooting is in progress 

        shooting = false; 

        // Release mouse click 

        Mouse.release(); 

    } 

 

    delay(50); // Adjust delay according to your requirements 

} 

 

 
