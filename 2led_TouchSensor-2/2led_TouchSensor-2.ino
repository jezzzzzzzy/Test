/*
   Created by ArduinoGetStarted.com

   This example code is in the public domain

   Tutorial page: https://arduinogetstarted.com/tutorials/arduino-touch-sensor-led
*/

const int TOUCH_SENSOR_PIN  = 3; // Arduino pin connected to the OUTPUT pin of touch sensor
const int LED_PIN1           = 4; // Arduino pin connected to LED's pin
const int LED_PIN2           = 2;
int ledState = 0;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  Serial.begin(9600);               // initialize serial
  pinMode(TOUCH_SENSOR_PIN, INPUT); // set arduino pin to input mode
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);   // set arduino pin to output mode
}

void loop() {
  unsigned long currentMillis = millis();
  int touchState = digitalRead(TOUCH_SENSOR_PIN); // read new state

  if (touchState == HIGH) {
    Serial.println("The sensor is being touched");;
    digitalWrite(LED_PIN1, HIGH); // turn on
    digitalWrite(LED_PIN2, LOW);
    
  } else if (touchState == LOW) {
    Serial.println("The sensor is untouched");
    digitalWrite(LED_PIN1, LOW);  // turn off

    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }
      digitalWrite(LED_PIN2, ledState);
    }
  }
}
