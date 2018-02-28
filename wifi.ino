#include <SoftwareSerial.h>
//ground ka side wala rx h 
//aur software serial esp(9,10) mei humesha 10 pin rx se connect hogi esp k
SoftwareSerial esp(9,10);
int c=0;

void setup() {
  Serial.begin(115200);
  esp.begin(115200);
  esp.flush();




  
  connect_wifi();
  domain();
  send_data();
  domain();
  check_data();
  }

void loop() {
 
  }

void connect_wifi(){
  c=0;
  esp.flush();
  esp.print("AT+CWJAP=\"shubham jain\",\"shubham123\"\r\n");

  while(!esp.find("CONNECTED"))
  {
    c++;
    if(c>=20){
      break;
    }
  }
String got_ip=esp.readString();
Serial.println(got_ip);

if(c>=20)
Serial.println("TIMEOUT-1 !!");

esp.flush();

}

void domain(){

  esp.flush();
  esp.print("AT+CIPSTART=\"TCP\",\"locateurfamily.com\",80\r\n");
c=0;

  while(!esp.find("CONNECT")){
    c++;
    if(c>=20){
      break;
    }
  }

String j=esp.readString();
Serial.println(j);

if(c>=20)
Serial.println("timeout-2!");

esp.flush();}

void send_data(){

 c=0;
 esp.flush();
String send_wifi="GET http://locateurfamily.com/arduino1.php?temperature=80&humidity=70 HTTP/1.0\r\n\r\n";

 esp.print("AT+CIPSEND="+(String)send_wifi.length()+"\r\n");

 while(!esp.find("OK")){
  c++;
  if(c>=20){
    Serial.println("timeout-3a!");
    break;
  }
 }
 String k=esp.readString();
 Serial.println(k);
 esp.flush();

 int d=0;
 esp.print(send_wifi);

 while(!esp.find("IPD")){
  d++;
  if(d>=20){
    Serial.println("timeout-3b!");
    break;
  }
 }

 String m=esp.readString();
 Serial.println(m);
 esp.flush();
  
 }

void check_data(){
c=0;
esp.flush();

String check="GET http://locateurfamily.com/Home.php HTTP/1.0\r\n\r\n";
   esp.print("AT+CIPSEND="+(String)check.length()+"\r\n");

 while(!esp.find("OK")){
  c++;
  if(c>=20){
    Serial.println("timeout-4a!");
    break;
  }
 }
 String p=esp.readString();
 Serial.println(p);
 
 esp.flush();

 int d=0;
 esp.print(check);

 while(!esp.find("IPD")){
  d++;
  if(d>=20){
    Serial.println("timeout-4b!");
    break;
  }
 }

 String q=esp.readString();
 Serial.println(q);
 Serial.println(q.length());
 esp.flush();
  
 }


