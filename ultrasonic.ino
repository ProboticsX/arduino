const int trigpin=12;
const int echopin=13;

long duration;
float distance;
int v1 = A0;
int g1 = A1;

void setup() {
 
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
Serial.begin(9600);  
  digitalWrite(g1, 0);
  digitalWrite(v1, 1);
  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
int cm;
digitalWrite(trigpin,LOW);

delayMicroseconds(2);

digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);

duration=pulseIn(echopin,HIGH);

distance=duration*0.034/2;

Serial.print("Distance: ");
Serial.println(distance);
delay(1000);


}
