const int trigPin = 11;
const int echoPin = 12;
const int redPin = 5;
const int greenPin = 4;
long duration;
int distanceCm, distanceInch;
long range;

void setup() {
  // put your setup code here, to run once:

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);

distanceCm = duration * (.017);
distanceInch = duration * (.0067);
Serial.print("Distance: ");
Serial.print(distanceCm);
Serial.print(" cm/");
Serial.print(distanceInch);
Serial.println(" in");
delay(1000);

if (distanceCm < 10)
{
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
}
else {
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, HIGH);
}

}

