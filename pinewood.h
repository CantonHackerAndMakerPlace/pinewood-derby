#pragma once

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

struct LASER_STATUS{
  int chan_a;
  int chan_b;
} stat;

const byte address[6] = "323132";

class PineWood{
  public:
  PineWood(const int CE,const int CSN){
    radio = new RF24(CE,CSN);
  }
  public:
    virtual void setup() = 0;
    virtual void loop() = 0;
  protected:
    RF24* radio = 0;
};

