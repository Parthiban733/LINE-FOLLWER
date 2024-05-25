// Define the motor control pins
const int leftMotor1 = 2;
const int leftMotor2 = 3;
const int rightMotor1 = 4;
const int rightMotor2 = 5;

// Define the IR sensor pins
const int leftIRSensor1 = 6;
const int leftIRSensor2 = 7;
const int centerIRSensor = 8;
const int rightIRSensor1 = 9;
const int rightIRSensor2 = 10;

void setup() {
  // Initialize motor control pins as outputs
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);

  // Initialize IR sensor pins as inputs
  pinMode(leftIRSensor1, INPUT);
  pinMode(leftIRSensor2, INPUT);
  pinMode(centerIRSensor, INPUT);
  pinMode(rightIRSensor1, INPUT);
  pinMode(rightIRSensor2, INPUT);
}

void loop() {
  // Read the sensor values
  int left1 = digitalRead(leftIRSensor1);
  int left2 = digitalRead(leftIRSensor2);
  int center = digitalRead(centerIRSensor);
  int right1 = digitalRead(rightIRSensor1);
  int right2 = digitalRead(rightIRSensor2);

  // Define the line-following logic
  if (center == HIGH) {
    forward();
  } else if (left1 == HIGH && left2 == LOW) {
    turnLeft();
  } else if (right1 == HIGH && right2 == LOW) {
    turnRight();
  } else if (left1 == LOW && right1 == HIGH) {
    hardRight();
  } else if (left1 == HIGH && right1 == LOW) {
    hardLeft();
  } else {
    stop();
  }
}

void forward() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

void stop() {
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
}

void turnLeft() {
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

void turnRight() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
}

void hardLeft() {
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

void hardRight() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
}
