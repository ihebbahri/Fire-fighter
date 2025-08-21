// Capteurs de flamme (digital)
const int flameLeft  = 5;   // D1
const int flameFront = 4;   // D2
const int flameRight = 0;   // D3

// Capteur ultrason
const int trigPin = 14;     // D5
const int echoPin = 12;     // D6

// Moteurs
const int motorLeftFwd  = 13; // D7
const int motorLeftBwd  = 15; // D8
const int motorRightFwd = 2;  // D4
const int motorRightBwd = 16; // D0

// Pompe
const int pumpPin = 0; // D3, changer si nécessaire

// Seuil distance obstacle
const int distanceStop = 20; // cm

void setup() {
  Serial.begin(9600);

  pinMode(flameLeft, INPUT);
  pinMode(flameFront, INPUT);
  pinMode(flameRight, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(motorLeftFwd, OUTPUT);
  pinMode(motorLeftBwd, OUTPUT);
  pinMode(motorRightFwd, OUTPUT);
  pinMode(motorRightBwd, OUTPUT);

  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);
}

long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

void stopMotors() {
  digitalWrite(motorLeftFwd, LOW);
  digitalWrite(motorLeftBwd, LOW);
  digitalWrite(motorRightFwd, LOW);
  digitalWrite(motorRightBwd, LOW);
}

void forward() {
  digitalWrite(motorLeftFwd, HIGH);
  digitalWrite(motorLeftBwd, LOW);
  digitalWrite(motorRightFwd, HIGH);
  digitalWrite(motorRightBwd, LOW);
}

void turnLeft() {
  digitalWrite(motorLeftFwd, LOW);
  digitalWrite(motorLeftBwd, LOW);
  digitalWrite(motorRightFwd, HIGH);
  digitalWrite(motorRightBwd, LOW);
}

void turnRight() {
  digitalWrite(motorLeftFwd, HIGH);
  digitalWrite(motorLeftBwd, LOW);
  digitalWrite(motorRightFwd, LOW);
  digitalWrite(motorRightBwd, LOW);
}

void loop() {
  int leftVal  = digitalRead(flameLeft);
  int frontVal = digitalRead(flameFront);
  int rightVal = digitalRead(flameRight);
  long distance = getDistance();

  Serial.print("L: "); Serial.print(leftVal);
  Serial.print(" | F: "); Serial.print(frontVal);
  Serial.print(" | R: "); Serial.print(rightVal);
  Serial.print(" | Dist: "); Serial.println(distance);

  if(distance < distanceStop){
    stopMotors();
    return;
  }

  if(leftVal == HIGH || frontVal == HIGH || rightVal == HIGH){
    digitalWrite(pumpPin, HIGH);
  } else {
    digitalWrite(pumpPin, LOW);
  }

  if(leftVal == HIGH && frontVal == LOW && rightVal == LOW){
    turnLeft();
  } else if(rightVal == HIGH && frontVal == LOW && leftVal == LOW){
    turnRight();
  } else {
    forward();
  }

  delay(100);
}
