#include<SoftwareSerial.h>
SoftwareSerial gsm(3,4);
//tx:9 rx:10


void setup() {
  Serial.begin(9600);
  gsm.begin(9600);
 // delay(1000);
  
  gsm.println("ATD+919910077157;"); //AT command to call from GSM
  delay(20000);
  gsm.println("ATH");
Serial.print("hi");  
  // put your setup code here, to run once:

}

void loop() {
  
   //if (gsm.available())
   //Serial.write(gsm.read());
  // put your main code here, to run repeatedly:
  
}
