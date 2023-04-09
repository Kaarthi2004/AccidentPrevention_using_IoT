int trigPin = 5;
int echoPin = 6;
int buzzerPin = 9;
int distance1=0;
int distance2=0;
float measured_speed = 0;
long duration = 0;
int distance = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance1 = ultrasonicRead();
  delay(3000);
  distance2 = ultrasonicRead();
  measured_speed = abs(distance2 - distance1)/1.0;
  if(measured_speed > 185.00)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9,HIGH);
    delay(500);
  }
  Serial.print("Speed in cm/s :");
  Serial.println(measured_speed);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  delay(20);
}

float ultrasonicRead()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
