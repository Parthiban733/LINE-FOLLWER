// Define motor control pins
#define ENA 10  // Enable pin for Motor A
#define IN1 9   // Input 1 for Motor A
#define IN2 8   // Input 2 for Motor A

void setup() {
  // Set motor control pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Motor A moves forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255); // Full speed
  
  // Wait for 2 seconds
  delay(2000);
  
  // Motor A stops
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  
  // Wait for 1 second
  delay(1000);
  
  // Motor A moves backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255); // Full speed
  
  // Wait for 2 seconds
  delay(2000);
  
  // Motor A stops
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  
  // Wait for 1 second
  delay(1000);
}
