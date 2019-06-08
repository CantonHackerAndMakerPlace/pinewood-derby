#include "pinewood.h"


class PineWood_Client : public PineWood{
   void setup(){
    pinMode(TRACKSENS_A,INPUT);
    pinMode(TRACKSENS_B,INPUT);
    radio->begin();
    radio->setRetries(AP_RETRYS,AP_RETRYS);
    radio->setPALevel(AP_LEVEL);
    radio->setDataRate(AP_RATE);
    radio->setChannel(AP_CHANNEL);
    radio->setPayloadSize(AP_PAYLD);
    radio->openWritingPipe(address);
    radio->stopListening();
  }

  void loop() {
    stat.chan_a = analogRead(TRACKSENS_A);
    stat.chan_b = analogRead(TRACKSENS_B);
    radio->write(&stat, sizeof(stat));
  }
};

