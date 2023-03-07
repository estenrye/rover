#include <Wire.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_L3GD20.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_BMP085_U.h>
#include <Adafruit_10DOF.h>

uint8_t LEFT_MOTOR_ENABLE_PIN = 5;
uint8_t LEFT_MOTOR_DRIVE_PIN = 6;
uint8_t RIGHT_MOTOR_ENABLE_PIN = 3;
uint8_t RIGHT_MOTOR_DRIVE_PIN = 4;


void rotate_forward(uint8_t drive_pin, uint8_t enable_pin) {
  digitalWrite(drive_pin, HIGH);
  digitalWrite(enable_pin, HIGH);
}

void rotate_reverse(uint8_t drive_pin, uint8_t enable_pin) {
  digitalWrite(drive_pin, LOW);
  digitalWrite(enable_pin, HIGH);
}

void rotate_stop(uint8_t drive_pin, uint8_t enable_pin) {

  digitalWrite(drive_pin, LOW);
  digitalWrite(enable_pin, LOW);
}

void drive_forward() {
  rotate_forward(LEFT_MOTOR_DRIVE_PIN, LEFT_MOTOR_ENABLE_PIN);
  rotate_forward(RIGHT_MOTOR_DRIVE_PIN, RIGHT_MOTOR_ENABLE_PIN);
}

void drive_backward() {
  rotate_reverse(LEFT_MOTOR_DRIVE_PIN, LEFT_MOTOR_ENABLE_PIN);
  rotate_reverse(RIGHT_MOTOR_DRIVE_PIN, RIGHT_MOTOR_ENABLE_PIN);
}

void drive_stop() {
  rotate_stop(LEFT_MOTOR_DRIVE_PIN, LEFT_MOTOR_ENABLE_PIN);
  rotate_stop(RIGHT_MOTOR_DRIVE_PIN, RIGHT_MOTOR_ENABLE_PIN);
}

void rotate_right() {
  rotate_forward(LEFT_MOTOR_DRIVE_PIN, LEFT_MOTOR_ENABLE_PIN);
  rotate_reverse(RIGHT_MOTOR_DRIVE_PIN, RIGHT_MOTOR_ENABLE_PIN);
}

void rotate_left() {
  rotate_reverse(LEFT_MOTOR_DRIVE_PIN, LEFT_MOTOR_ENABLE_PIN);
  rotate_forward(RIGHT_MOTOR_DRIVE_PIN, RIGHT_MOTOR_ENABLE_PIN);
}

void setup() {
  pinMode(LEFT_MOTOR_ENABLE_PIN, OUTPUT);\
  pinMode(LEFT_MOTOR_DRIVE_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_ENABLE_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_DRIVE_PIN, OUTPUT);
  
}

void loop() {
  drive_forward();
  delay(1000);
  drive_stop();
  delay(1000);
  rotate_left();
  delay(1000);
  drive_stop();
  delay(1000);
  drive_backward();
  delay(1000);
  drive_stop();
  delay(1000);
  rotate_right();
  delay(1000);
  drive_stop();
  delay(1000);
}
