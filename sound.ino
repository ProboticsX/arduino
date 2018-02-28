int sensor=2;
int led=3;

void setup() {
//Serial.begin(9600);

pinMode(sensor,INPUT);
pinMode(led,OUTPUT);  
// put your setup code here, to run once:

}

void loop() {
int pin=digitalRead(sensor);

if(pin==1)
digitalWrite(led,HIGH);
else
digitalWrite(led,LOW);

//delay(1000);
//Serial.print("Sound in Hz:");
//Serial.println(pin);

//delay(1000);
  
  // put your main code here, to run repeatedly:

}
