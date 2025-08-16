#define BLYNK_TEMPLATE_ID "TMPL6fy9Q1cGP"
#define BLYNK_TEMPLATE_NAME "Ornamental plant Caring devices"
#define BLYNK_AUTH_TOKEN "rEp9CS1CZw-szd3lOZvatsaKY7ZaWNIQ"

#include "DHT.h"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#ifndef BLYNK_TEMPLATE_ID
#error "Please specify id"
#endif

char auth[] = BLYNK_AUTH_TOKEN ;
char ssid[] = "Fresh" ;
char pass[] = "12345678" ;

#define DHTPIN  D3
#define DHTTYPE  DHT11 

#define Fanrelay  D0 
#define LEDrelay D1
#define Pumprelay D2

int val = 0;

#define analogPin  A0

int ControlLight_Action = 1024 ;
int ControlHumidity_Action = 51 ;
int checker = 0 ;
int tricker = 0 ;
bool flag = 0 ;
float humidity ;
float temperature ;

DHT dht(DHTPIN, DHTTYPE);

BLYNK_WRITE(V3){
  ControlLight_Action = param.asInt() ;
}

BLYNK_WRITE(V4){
  ControlHumidity_Action = param.asInt() ;
}

BLYNK_WRITE(V5){
  checker = param.asInt() ;
  if( checker == 1 && flag != 1 ){
    flag = 1 ;
    digitalWrite( Fanrelay ,LOW);
    digitalWrite( Pumprelay ,LOW);
    digitalWrite( LEDrelay ,LOW);
    Serial.print("Checking......") ;
    delay(3000) ;
    digitalWrite( Fanrelay ,HIGH);
    digitalWrite( Pumprelay ,HIGH);
    digitalWrite( LEDrelay ,HIGH);
    tricker = 0 ;
  }
}

void CheckWIFI(){
  if ( WiFi.status() != WL_CONNECTED ){  
    WiFi.begin(ssid, pass);
    delay(15000) ;
    tricker += 15000 ;
    Serial.print("\nNo WiFi active\n") ;
    Serial.println(WiFi.status()) ;
    Serial.println(WL_CONNECTED) ;
    Serial.println(tricker) ;
  }
  else{
    if( Blynk.connected() == false ){
      Serial.print("not connected\n") ;
      Blynk.begin( auth, ssid, pass ); 
      Blynk.run() ;
    }
    else{
      Serial.print("Connected\n") ;
      Blynk.run() ;
    }
  }
}

void setup() {
  Serial.begin(9600) ;
  pinMode( Fanrelay, OUTPUT) ; 
  digitalWrite( Fanrelay, HIGH) ;
  
  pinMode( LEDrelay, OUTPUT); 
  digitalWrite( LEDrelay, HIGH);
  
  pinMode( Pumprelay, OUTPUT); 
  digitalWrite( Pumprelay, HIGH);

  CheckWIFI() ;
  Serial.print("First take") ;
  dht.begin();
  delay(3000) ;
  if( WiFi.status() == WL_CONNECTED ){
    Blynk.virtualWrite(V3, ControlLight_Action ) ;
    Blynk.virtualWrite(V4, ControlHumidity_Action ) ; 
  }
  
}

void loop() {
  CheckWIFI() ; 
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  Serial.print("the temp = ") ;
  Serial.print(temperature) ;
  Serial.print("\nthe humidity = ") ;
  Serial.print(humidity) ;
  val = analogRead(analogPin);
  Serial.print("Resistance : ") ;
  Serial.print(val) ;
  if(tricker == 15000 ){
    digitalWrite( Fanrelay ,LOW);
    delay(5000) ;
    tricker += 5000 ;
    humidity = dht.readHumidity();
    temperature = dht.readTemperature();
    val = analogRead(analogPin);
    Serial.print("Resistance : ") ;
    Serial.print(val) ;
    Blynk.virtualWrite(V1, temperature ) ;
    Blynk.virtualWrite(V2, humidity ) ; 
    if ( humidity < ControlHumidity_Action){
      digitalWrite( Pumprelay ,LOW);
      delay(2000) ;
      digitalWrite( Pumprelay ,HIGH);
    }
    if ( val < ControlLight_Action){
      digitalWrite( LEDrelay ,LOW);
      Serial.print("\nLight is on\n") ;
    }
    digitalWrite( Fanrelay , HIGH);
  }
  tricker += 1000 ;
  delay(1000) ;
  if(tricker >= (1000 * 60 *60)){
    tricker = 0 ; 
    digitalWrite( LEDrelay ,HIGH);
  }
  flag = 0 ;
}

BLYNK_CONNECTED() {
  Serial.print("Using Blynk") ;
  Blynk.virtualWrite(V1, temperature ) ;
  Blynk.virtualWrite(V2, humidity ) ;
}
