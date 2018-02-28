String voice="";

int led1 = 7;
int led2 = 3;
int led3 = 4;

void allon() {
  digitalWrite (led1, HIGH);
  digitalWrite (led2, HIGH);
  digitalWrite (led3, HIGH);

}

void alloff() {
  digitalWrite (led1, LOW);
  digitalWrite (led2, LOW);
  digitalWrite (led3, LOW);
}

void setup() {
  Serial.begin(38400);
  pinMode(led1, OUTPUT);
  digitalWrite (led1, HIGH);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  while(Serial.available()) {
    delay(10);
    char c=Serial.read();
    Serial.println(c);
    if(c=='#')
    {break; }
    voice += c;
}

if (voice.length() > 0) {
  Serial.println(voice);
  if (voice == "*LED on"||voice == "*lights on" )
  {allon() ; }
  else if (voice == "*LED of" || voice == "*LED off" || voice == "*lights of" || voice == "*lights off")
  {alloff() ; }
  
voice="";
}
}


