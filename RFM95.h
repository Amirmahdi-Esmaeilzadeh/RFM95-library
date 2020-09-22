#ifndef tl
#define tl

#if(ARDUINO>=100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
class RFM95{
  public:
    RFM95(bool sure);
    void begin(int boad);
    void sendString(String message);
    void pin(int ss, int rst, int dio0);
    void sendNumber(int message);
    void sendFloat(float message);
    void recive();
  private:
    bool msg;
};
#endif
