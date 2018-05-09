// led parameters
#include <FastLED.h>
#define LED_PIN_1     6
#define NUM_LEDS      144
#define BRIGHTNESS    30
CRGB leds[NUM_LEDS];

// touch sensor pins
byte touch_sense_0 = 46; 
byte touch_sense_1 = 48;
byte touch_sense_2 = 50;
byte touch_sense_3 = 52;
byte touch_sense_4 = 49;
byte touch_sense_5 = 51;
byte touch_sense_6 = 53;

// array of touch sensors for FOR loops
byte touch_sensors[7] = { touch_sense_0, touch_sense_1, touch_sense_2, touch_sense_3, touch_sense_4, touch_sense_5, touch_sense_6};

// array for previous state of each touch sensor
bool state_on[7] = {0, 0, 0, 0, 0, 0, 0};

void setup() {
  FastLED.addLeds<WS2812, LED_PIN_1, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness( BRIGHTNESS );
  // make the touch sensor pins an input
  pinMode(touch_sense_0, INPUT);
  pinMode(touch_sense_1, INPUT);
  pinMode(touch_sense_2, INPUT);
  pinMode(touch_sense_3, INPUT);
  pinMode(touch_sense_4, INPUT);
  pinMode(touch_sense_5, INPUT);
  pinMode(touch_sense_4, INPUT);
  // make the LEDs output
  pinMode(LED_PIN_1, OUTPUT);
}

void loop() 
{
  // array for current state of each touch sensor
  int touchSensorActivate[7];
  for (int i = 0; i < 7; i++) 
  {
    touchSensorActivate[i] = digitalRead(touch_sensors[i]);
  }
  // get which touch sensor was activated
  for (int i = 0; i < 7; i++)
  {
      if (touchSensorActivate[i] == 1 and state_on[i] == 0) 
      {
          state_on[i] = 1;
          delay(50);
      } 
      else if (state_on[i] == 1 and touchSensorActivate[i] == 0) 
      {
          state_on[i] = 0;
          delay(50);
      }
      // depending on which touch sensor was activated, light specific LED in matrix
      if (touchSensorActivate[i] == 1 && state_on[i] == 1)
       {
         switch(i) 
         {
            case 0:
              leds[0] = CRGB::Red;
              break;
            case 1:
              leds[1] = CRGB::Orange;
              break;
            case 2:
              leds[2] = CRGB::Yellow;
              break;
            case 3:
              leds[3] = CRGB::Green;
              break;
            case 4:
              leds[4] = CRGB::Blue;
              break;
            case 5:
              leds[5] = CRGB::Purple;
              break;
            case 6:
              leds[6] = CRGB::White;
              break;
          }
          // display for .5 second
          FastLED.show();
          delay(500);
       }
       // reset to off if no touch sensor activated
       else
       {
          leds[0] = CRGB::Black;
          leds[1] = CRGB::Black;
          leds[2] = CRGB::Black;
          leds[3] = CRGB::Black;
          leds[4] = CRGB::Black;
          leds[5] = CRGB::Black;
          leds[6] = CRGB::Black;
          FastLED.show();
       }
    }
  delay(30); // short pause between reads
}
