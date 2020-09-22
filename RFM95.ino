#include "RFM95.h"
RFM95 lora(1);
void setup() {
  // put your setup code here, to run once:
lora.begin(9600);
lora.pin(1,3,4);
lora.sendString("RFM95 library");
lora.sendString("number of libraries: ");
lora.sendNumber(3);
lora.sendFloat(3.1);
lora.recive();
}

void loop() {
  // put your main code here, to run repeatedly:

}
