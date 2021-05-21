#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "0geLxYW-ubecd9EoBk7kh3aJPNt1DRzd";
char ssid[] = "mecha";
char pass[] = "mechatronic";

int Potentiometer = A0;
int LED = D7;

BlynkTimer timer;
float volt = 0.0;

void sensor1(){
  int value = analogRead(Potentiometer);
  analogWrite(LED,value);
  volt = (value/1023.0)*3.3;
  Blynk.virtualWrite(V3,volt);  
}
void setup()
{
  pinMode(Potentiometer,INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  timer.setInterval(300L,sensor1);
}
void loop()
{
  Blynk.run();
  timer.run();
}
