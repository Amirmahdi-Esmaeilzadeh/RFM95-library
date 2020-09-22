#include "RFM95.h"
#include <SPI.h>
#include <LoRa.h>
RFM95::RFM95(bool sure){
  msg=sure;
}
void RFM95::begin(int boad){
   Serial.begin(9600);

  if(msg==true){
  Serial.println("LoRa RFM95 module library is for easy working with it");
  Serial.println("made by Amirmahdi Esmailzadeh");
  Serial.print("boad rate: ");
  Serial.println(boad);

  }
}
void RFM95::pin(int ss, int rst, int dio0){
   LoRa.setPins(ss, rst, dio0);
   LoRa.begin(866E6);
   if(msg==true){
    Serial.print("ss pin: ");
    Serial.println(ss);
    Serial.print("rst pin: ");
    Serial.println(ss);
    Serial.print("dio0 pin: ");
    Serial.println(ss);    
   }
}
void RFM95::sendString(String message){
  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();
  if(msg==true){
  Serial.print(message);
  Serial.println(" message sent");
}}
void RFM95::sendNumber(int message){
  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();
  if(msg==true){
  Serial.print(message);
  Serial.println(" message sent");
}
}
void RFM95::sendFloat(float message){
  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();
  if(msg==true){
  Serial.print(message);
  Serial.println(" message sent");
}
}
void RFM95::recive(){
   int packetSize = LoRa.parsePacket();
       while (LoRa.available()) {
      String LoRaData = LoRa.readString();
      Serial.print(LoRaData); 
      Serial.println(" message recived");
    }
}
