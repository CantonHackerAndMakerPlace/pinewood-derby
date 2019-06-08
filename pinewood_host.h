#include "pinewood.h"
#include <LiquidCrystal.h>
//Includes &Defines for the host controler.

class PineWood_Host : public PineWood{
  public:
  PineWood_Host(const int CE,const int CSN,const int SERVO_PIN,const int LCD_RS,const int LCD_EN,const int LCD_D4,const int LCD_D5,const int LCD_D6,const int LCD_D7,const int BTN) : PineWood(CE,CSN),BTN_RST(BTN){
    lcd = new LiquidCrystal(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
  }
  void setup() {
    lcd->begin(16, 2);
    lcd->clear();
    pinMode(BTN_RST,INPUT);
    radio->begin();
    radio->setRetries(AP_RETRYS,AP_RETRYS);
    radio->setPALevel(AP_LEVEL);
    radio->setDataRate(AP_RATE);
    radio->setChannel(AP_CHANNEL);
    radio->setPayloadSize(AP_PAYLD);
    radio->openReadingPipe(0, address);
    radio->startListening();
  }

  void loop() {
    if (!radio->available()){
      lcd->print("Wainting For Pair");
    }
    /*
     * if(!gotNetwork){
     *  lcd: Searching for network.
     * }
     * if running:
     *  if(timera.running() && stat.chan_a > threshold)
     *    timera.stop();
     *  if(timerb.running() && stat.chan_b > threshold)
     *    timerb.stop();
     *  if(!timera.running() && !timerb.running())
     *    running = false;
     *    update lcd with time
     *    raise gate
     * else:
     *  if(button press)
     *    start timer
     *    drop gate
     *    running = true
     *  else:
     *    update lcd with time
     *    delay(1)
     */
    radio->read(&stat, sizeof(stat));
    lcd->print("hello, world!");
    if(digitalRead(BTN_RST) == LOW){
      lcd->setCursor(0, 1);
      lcd->print("Goodbye Moon");
    }
     if (radio->available()) {
      char text[32] = "";
      radio->read(&text, sizeof(text));
      Serial.println(text);
    }
  }

  private:
  LiquidCrystal* lcd;
  const int BTN_RST;
};

