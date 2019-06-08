#include "pinewood.h"



//#define HOST
#define AP_RETRYS 15
#define AP_LEVEL RF24_PA_MAX
#define AP_RATE RF24_1MBPS
#define AP_CHANNEL 108
#define AP_PAYLD 5
#define AP_CE 7
#define AP_CSN 8

//Setup instance for pinwood object
PineWood* pinewood = nullptr;

#ifdef HOST
  #define SERVO_PIN = A1;   //White
  #define LCD_RS = 10;      //Blue
  #define LCD_EN = A2;      //Brown
  #define LCD_D4 = 2;       //Green
  #define LCD_D5 = 3;       //Green
  #define LCD_D6 = 4;       //Green
  #define LCD_D7 = 5;       //Green
  #define BTN_RST = A4;     //Yellow
  
  #include "pinewood_host.h"
  pinewood = new PineWood_Host(AP_CE,AP_CSN,SERVO_PIN,LCD_RS,LCD_EN,LCD_D4,LCD_D5,LCD_D6,LCD_D7,BTN_RST);
  
#else
  //Includes &Defines for the client controler.
  const int TRACKSENS_A = A4;
  const int TRACKSENS_B = A3;

 #include "pinewood_client.h"
 pinewood = new PineWood_Client(TRACKSENS_A,TRACKSENS_B);
#endif

void setup(){
  pinewood->setup();
}

void loop(){
  pinewood->loop();
}



