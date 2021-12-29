#define trigPin 9
#define echoPin 10
void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);

}
void front(){
  digitalWrite(12,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
}

void back(){
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(9,HIGH);}

void right(){
  digitalWrite(12,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,HIGH);}

void left(){
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);}

void stop(){
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
  float Time,distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  Time=pulseIn(echoPin,HIGH);
  distance=(Time/2)*0.0344;
  if(distance<=5 || distance>=400)
  {
    Serial.print("distance = ");
    Serial.println("Out of range");
    delay(100);
  }
  else{
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.print("cm");
    Serial.println(" ");
    delay(500);
  }
  delay(500);
 if(distance<=5)
 {
  back();
  right();
 }
 else
 {
  front();
 }

}
