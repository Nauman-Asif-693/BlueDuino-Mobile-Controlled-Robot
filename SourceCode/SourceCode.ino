#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); // RX, TX pins for Bluetooth

int motor1Pin1 = 8; // Motor 1 control pin 1
int motor1Pin2 = 9; // Motor 1 control pin 2
int motor2Pin1 = 10; // Motor 2 control pin 1
int motor2Pin2 = 11; // Motor 2 control pin 2

void setup() {
  // Define motor control pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Set up communication with Bluetooth module
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available() > 0) {
    char command = bluetooth.read();
    
    
    // Perform actions based on the received command
    switch (command) {
      case 'F':
          moveForward();
        break;
      case 'B':
          moveBackward();
        break;
      case 'L':
          turnLeft();
        break;
      case 'R':
          turnRight();
        break;
      case 'S':
          stopMotors();
        break;
    }
    
  }
}

void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void moveBackward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);

}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
