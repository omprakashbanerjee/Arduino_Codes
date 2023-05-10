#include<Arduino.h>
#include <PID_v1.h>

// Thermistor pins
#define THERMISTOR_PIN A2
#define THERMISTOR_SERIES_RESISTOR 10000
#define BAUDRATE 115200
#define HEATER_PWM 5
#define HEATER_PIN1 3
#define HEATER_PIN2 4 

// Heating element pin
#define HEATING_PIN 5

// Setpoint temperature
#define SETPOINT 110

// PID constants
// #define KP 4
// #define KI 0.5
// #define KD 0.1
// #define KP 3.5
// #define KI 0.01
// #define KD 0

#define KP 200.0
#define KI 4.2
#define KD 0.1


int V1;
const float R1 = 10000;
float logR2, R2, T, TC, Tf;
const float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

// PID variables
double input, output, setpoint;
PID pid(&input, &output, &setpoint, KP, KI, KD, DIRECT);
float temp_reading(int);

void setup() {
  // Initialize serial communication
  Serial.begin(BAUDRATE);
  //analogReadResolution(12);
  // Set up the thermistor pin
  pinMode(THERMISTOR_PIN, INPUT);

  // Set up the heating pin
  pinMode(HEATING_PIN, OUTPUT);

  pinMode(HEATER_PIN2, OUTPUT);
  pinMode(HEATER_PIN1, OUTPUT);


  digitalWrite(HEATER_PIN1, HIGH);
  digitalWrite(HEATER_PIN2, LOW);

  // Set the setpoint temperature
  setpoint = SETPOINT;

  // Set PID tuning parameters
  pid.SetMode(AUTOMATIC);
  pid.SetSampleTime(100);
  pid.SetOutputLimits(0, 255);
}

void loop()
 {
// Read the thermistor and convert to temperature
// int thermistorValue = analogRead(THERMISTOR_PIN);
// double resistance = THERMISTOR_SERIES_RESISTOR / ((1023.0 / thermistorValue) - 1.0);
// double temperature = 1.0 / ((log(resistance / 10000.0) / 3950.0) + (1.0 / 298.15)) - 273.15;
// input = temperature;
int V1 =analogRead(THERMISTOR_PIN);
 input = temp_reading(V1);
  // Compute the PID output and adjust the heating element
  pid.Compute();
  analogWrite(HEATING_PIN, output);

  // Print the temperature and PID output
 // Serial.print("Temperature: ");
 // Serial.print(temperature);
 // Serial.print("C, PID output: ");
//  Serial.println(output);

  // Delay to allow the PID to settle
  delay(100);
}


float temp_reading(int v)
{
  R2 = R1 * (1023.0 / (float)v - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  TC = T - 273.15;
  // Serial.println("Temperature"); 
  Serial.println(TC);
  Serial.print(" C  "); 
  return TC;

}