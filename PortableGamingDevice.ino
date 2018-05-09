// Connect Four, Tetris, Snake, and Game of Life portable gaming device

// Code altered to work with touch sensors

/* 
  * Written by: Klaas De Craemer, Ing. David Hrbaty, Modified by: Mark Quinn
  * Method for common font style  
  * uTFT Font library 
  * http://www.henningkarlsen.com/electronics/r_fonts.php
*/

#ifndef  __FONT_H
#define  __FONT_H
const unsigned char font[760] =
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // <Space>
0x18,0x3C,0x3C,0x18,0x18,0x00,0x18,0x00, // !
0x66,0x66,0x24,0x00,0x00,0x00,0x00,0x00, // "
0x6C,0x6C,0xFE,0x6C,0xFE,0x6C,0x6C,0x00, // #
0x18,0x3E,0x60,0x3C,0x06,0x7C,0x18,0x00, // $
0x00,0xC6,0xCC,0x18,0x30,0x66,0xC6,0x00, // %
0x38,0x6C,0x38,0x76,0xDC,0xCC,0x76,0x00, // &
0x18,0x18,0x30,0x00,0x00,0x00,0x00,0x00, // '
0x0C,0x18,0x30,0x30,0x30,0x18,0x0C,0x00, // (
0x30,0x18,0x0C,0x0C,0x0C,0x18,0x30,0x00, // )
0x00,0x66,0x3C,0xFF,0x3C,0x66,0x00,0x00, // *
0x00,0x18,0x18,0x7E,0x18,0x18,0x00,0x00, // +
0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x30, // ,
0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00, // -
0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00, // .
0x06,0x0C,0x18,0x30,0x60,0xC0,0x80,0x00, // /
0x7C,0xC6,0xCE,0xD6,0xE6,0xC6,0x7C,0x00, // 0
0x18,0x38,0x18,0x18,0x18,0x18,0x7E,0x00, // 1
0x7C,0xC6,0x06,0x1C,0x30,0x66,0xFE,0x00, // 2
0x7C,0xC6,0x06,0x3C,0x06,0xC6,0x7C,0x00, // 3
0x1C,0x3C,0x6C,0xCC,0xFE,0x0C,0x1E,0x00, // 4
0xFE,0xC0,0xC0,0xFC,0x06,0xC6,0x7C,0x00, // 5
0x38,0x60,0xC0,0xFC,0xC6,0xC6,0x7C,0x00, // 6
0xFE,0xC6,0x0C,0x18,0x30,0x30,0x30,0x00, // 7
0x7C,0xC6,0xC6,0x7C,0xC6,0xC6,0x7C,0x00, // 8
0x7C,0xC6,0xC6,0x7E,0x06,0x0C,0x78,0x00, // 9
0x00,0x18,0x18,0x00,0x00,0x18,0x18,0x00, // :
0x00,0x18,0x18,0x00,0x00,0x18,0x18,0x30, // ;
0x06,0x0C,0x18,0x30,0x18,0x0C,0x06,0x00, // <
0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00, // =
0x60,0x30,0x18,0x0C,0x18,0x30,0x60,0x00, // >
0x7C,0xC6,0x0C,0x18,0x18,0x00,0x18,0x00, // ?
0x7C,0xC6,0xDE,0xDE,0xDE,0xC0,0x78,0x00, // @
0x38,0x6C,0xC6,0xFE,0xC6,0xC6,0xC6,0x00, // A
0xFC,0x66,0x66,0x7C,0x66,0x66,0xFC,0x00, // B
0x00,0x3C,0x66,0xC0,0xC0,0xC0,0x66,0x3C, // C
0xF8,0x6C,0x66,0x66,0x66,0x6C,0xF8,0x00, // D
0xFE,0x62,0x68,0x78,0x68,0x62,0xFE,0x00, // E
0xFE,0x62,0x68,0x78,0x68,0x60,0xF0,0x00, // F
0x3C,0x66,0xC0,0xC0,0xCE,0x66,0x3A,0x00, // G
0xC6,0xC6,0xC6,0xFE,0xC6,0xC6,0xC6,0x00, // H
0x3C,0x18,0x18,0x18,0x18,0x18,0x3C,0x00, // I
0x1E,0x0C,0x0C,0x0C,0xCC,0xCC,0x78,0x00, // J
0xE6,0x66,0x6C,0x78,0x6C,0x66,0xE6,0x00, // K
0xF0,0x60,0x60,0x60,0x62,0x66,0xFE,0x00, // L
0xC6,0xEE,0xFE,0xFE,0xD6,0xC6,0xC6,0x00, // M
0xC6,0xE6,0xF6,0xDE,0xCE,0xC6,0xC6,0x00, // N
0x7C,0xC6,0xC6,0xC6,0xC6,0xC6,0x7C,0x00, // O
0xFC,0x66,0x66,0x7C,0x60,0x60,0xF0,0x00, // P
0x7C,0xC6,0xC6,0xC6,0xC6,0xCE,0x7C,0x0E, // Q
0xFC,0x66,0x66,0x7C,0x6C,0x66,0xE6,0x00, // R
0x7C,0xC6,0x60,0x38,0x0C,0xC6,0x7C,0x00, // S
0x7E,0x7E,0x5A,0x18,0x18,0x18,0x3C,0x00, // T
0xC6,0xC6,0xC6,0xC6,0xC6,0xC6,0x7C,0x00, // U
0xC6,0xC6,0xC6,0xC6,0xC6,0x6C,0x38,0x00, // V
0xC6,0xC6,0xC6,0xD6,0xD6,0xFE,0x6C,0x00, // W
0xC6,0xC6,0x6C,0x38,0x6C,0xC6,0xC6,0x00, // X
0x66,0x66,0x66,0x3C,0x18,0x18,0x3C,0x00, // Y
0xFE,0xC6,0x8C,0x18,0x32,0x66,0xFE,0x00, // Z
0x3C,0x30,0x30,0x30,0x30,0x30,0x3C,0x00, // [
0xC0,0x60,0x30,0x18,0x0C,0x06,0x02,0x00, // <Backslash>
0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C,0x00, // ]
0x10,0x38,0x6C,0xC6,0x00,0x00,0x00,0x00, // ^
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF, // _
0x30,0x18,0x0C,0x00,0x00,0x00,0x00,0x00, // '
0x00,0x00,0x78,0x0C,0x7C,0xCC,0x76,0x00, // a
0xE0,0x60,0x7C,0x66,0x66,0x66,0xDC,0x00, // b
0x00,0x00,0x7C,0xC6,0xC0,0xC6,0x7C,0x00, // c
0x1C,0x0C,0x7C,0xCC,0xCC,0xCC,0x76,0x00, // d
0x00,0x00,0x7C,0xC6,0xFE,0xC0,0x7C,0x00, // e
0x3C,0x66,0x60,0xF8,0x60,0x60,0xF0,0x00, // f
0x00,0x00,0x76,0xCC,0xCC,0x7C,0x0C,0xF8, // g
0xE0,0x60,0x6C,0x76,0x66,0x66,0xE6,0x00, // h
0x18,0x00,0x38,0x18,0x18,0x18,0x3C,0x00, // i
0x06,0x00,0x06,0x06,0x06,0x66,0x66,0x3C, // j
0xE0,0x60,0x66,0x6C,0x78,0x6C,0xE6,0x00, // k
0x38,0x18,0x18,0x18,0x18,0x18,0x3C,0x00, // l
0x00,0x00,0xEC,0xFE,0xD6,0xD6,0xD6,0x00, // m
0x00,0x00,0xDC,0x66,0x66,0x66,0x66,0x00, // n
0x00,0x00,0x7C,0xC6,0xC6,0xC6,0x7C,0x00, // o
0x00,0x00,0xDC,0x66,0x66,0x7C,0x60,0xF0, // p
0x00,0x00,0x76,0xCC,0xCC,0x7C,0x0C,0x1E, // q
0x00,0x00,0xDC,0x76,0x60,0x60,0xF0,0x00, // r
0x00,0x00,0x7E,0xC0,0x7C,0x06,0xFC,0x00, // s
0x30,0x30,0xFC,0x30,0x30,0x36,0x1C,0x00, // t
0x00,0x00,0xCC,0xCC,0xCC,0xCC,0x76,0x00, // u
0x00,0x00,0xC6,0xC6,0xC6,0x6C,0x38,0x00, // v
0x00,0x00,0xC6,0xD6,0xD6,0xFE,0x6C,0x00, // w
0x00,0x00,0xC6,0x6C,0x38,0x6C,0xC6,0x00, // x
0x00,0x00,0xC6,0xC6,0xC6,0x7E,0x06,0xFC, // y
0x00,0x00,0x7E,0x4C,0x18,0x32,0x7E,0x00, // z
0x0E,0x18,0x18,0x70,0x18,0x18,0x0E,0x00, // {
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00, // |
0x70,0x18,0x18,0x0E,0x18,0x18,0x70,0x00, // }
0x76,0xDC,0x00,0x00,0x00,0x00,0x00,0x00, // ~
};
#endif
 
// LED field size 
 #define  FIELD_WIDTH      12
 #define  FIELD_HEIGHT     12
 const int NUM_LEDS=FIELD_WIDTH*FIELD_HEIGHT;
// Rotation of screen
 #define  ORIENTATION_HORIZONTAL
 #define  NUM_PIXELS    FIELD_WIDTH*FIELD_HEIGHT 

// LED strip type
 #define FAST_LED_CHIPSET WS2812B
// LED Screen 1 data pin
 #define LED_PIN_1        6
// LED Screen 2 data pin
 #define LED_PIN_2        7
// Brightness of LEDs
 #define MAX_BRIGHTNESS   150      // Full on is 255
 #define MIN_BRIGHTNESS   10       // Set to a minimum of 8%
 #define BRIGHTNESS       50       // Default
 const int brightnessInPin = A0;

// Touch sensor data pins for columns on connect four (across top)
 #define TOUCH_PIN_1   38
 #define TOUCH_PIN_2   40
 #define TOUCH_PIN_3   42
 #define TOUCH_PIN_4   44
 #define TOUCH_PIN_5   41
 #define TOUCH_PIN_6   43
 #define TOUCH_PIN_7   45
 
// Touch sensor for clearing and restarting connect four game
 #define TOUCH_PIN_8   28
 
// LED colors
 #define  GREEN  0x008000 
 #define  RED    0xFF0000 
 #define  BLUE   0x0000FF 
 #define  YELLOW 0xFFFF00 
 #define  LBLUE  0x00FFFF 
 #define  PURPLE 0xFF00FF 
 #define  WHITE  0XFFFFFF
 #define  AQUA   0x00FFFF
 #define  HOTPINK 0xFF69B4
 unsigned int long colorLib[9] = {RED, GREEN, BLUE, YELLOW, LBLUE, PURPLE, WHITE, AQUA, HOTPINK}; 
 
// Game commonly used defines
 #define  DIR_UP     1 
 #define  DIR_DOWN   2 
 #define  DIR_LEFT   3 
 #define  DIR_RIGHT  4 
 
// Controller button defines
 #define  BTN_NONE   0 
 #define  BTN_UP     1 
 #define  BTN_DOWN   2 
 #define  BTN_LEFT   3 
 #define  BTN_RIGHT  4 
 #define  BTN_START  5 
 #define  BTN_EXIT   6 

 #define TOUCH_PIN_UP     32
 #define TOUCH_PIN_DOWN   33
 #define TOUCH_PIN_RIGHT  34
 #define TOUCH_PIN_LEFT   35
 #define TOUCH_PIN_START  36
 #define TOUCH_PIN_SELECT 37

// Library for LED strip, used for Connect Four code since 
 #include <FastLED.h>

// Array of touch sensors for Connect Four
 byte touchPins[7] = { TOUCH_PIN_1, TOUCH_PIN_2, TOUCH_PIN_3, TOUCH_PIN_4, TOUCH_PIN_5, TOUCH_PIN_6, TOUCH_PIN_7 };

// Array for previous state of each touch sensor for Connect Four
 bool state_on[7] = {0, 0, 0, 0, 0, 0, 0 };

// Array to check next available LED to light in each column for stacking for Connect Four
 int nextAvailable[7] = { 0, 0, 0, 0, 0, 0, 0 };

// Matrix with LEDs for blue border for Connect Four
 int border_1[34] = { 25, 26, 27, 28, 29, 30, 31, 32, 33, 
                     38, 57, 62, 81, 86, 105, 
                     110, 111, 112, 113, 114, 115, 116, 117, 118, 
                     97, 94, 73, 70, 49, 46,
                     121, 129, 134, 142 };
                      
 int border_2[34] = { 25, 26, 27, 28, 29, 30, 31, 32, 33,
                     38, 57, 62, 81, 86, 105, 
                     110, 111, 112, 113, 114, 115, 116, 117, 118,
                     97, 94, 73, 70, 49, 46,
                     1, 9, 14, 22 };

                     
// Matrix for playing area for screens 
 int player1PlayField[6][7] = { { 98, 99, 100, 101, 102, 103, 104},
                               { 93, 92, 91, 90, 89, 88, 87},
                               { 74, 75, 76, 77, 78, 79, 80}, 
                               { 69, 68, 67, 66, 65, 64, 63}, 
                               { 50, 51, 52, 53, 54, 55, 56}, 
                               { 45, 44, 43, 42, 41, 40, 39} };
                               
 int player2PlayField[6][7] = { { 45, 44, 43, 42, 41, 40, 39},
                               { 50, 51, 52, 53, 54, 55, 56},
                               { 69, 68, 67, 66, 65, 64, 63}, 
                               { 74, 75, 76, 77, 78, 79, 80}, 
                               { 93, 92, 91, 90, 89, 88, 87}, 
                               { 98, 99, 100, 101, 102, 103, 104} };


// Array for blinking winning pixels
 int winningPixels[4] = { 0, 0, 0, 0 };
 int winningPixels2[4] = { 0, 0, 0, 0 };

// Keep track of whose turn it is on Connect Four                            
 bool player1Turn;
 bool player2Turn;

// Array of touch sensors for controller
 byte touch_sensors[6] = { TOUCH_PIN_UP, TOUCH_PIN_DOWN, TOUCH_PIN_RIGHT, TOUCH_PIN_LEFT, TOUCH_PIN_START, TOUCH_PIN_SELECT };

// Array for previous state of each touch sensor for controller
 bool state_on_1[6] = {0, 0, 0, 0, 0, 0 };

// Variable to keep control of control input
 uint8_t curControl = BTN_NONE;  

// Initiate array name for LED strips
 CRGB leds[NUM_PIXELS];
 CRGB leds2[NUM_PIXELS];

// Set states, will apply when first runs program
 void setup(){ 
   showPixels(); 
  // Make the touch sensor pins inputs
   pinMode(TOUCH_PIN_1, INPUT);
   pinMode(TOUCH_PIN_2, INPUT);
   pinMode(TOUCH_PIN_3, INPUT);
   pinMode(TOUCH_PIN_4, INPUT);
   pinMode(TOUCH_PIN_5, INPUT);
   pinMode(TOUCH_PIN_6, INPUT);
   pinMode(TOUCH_PIN_7, INPUT);
   pinMode(TOUCH_PIN_8, INPUT);
   pinMode(TOUCH_PIN_UP, INPUT);
   pinMode(TOUCH_PIN_DOWN, INPUT);
   pinMode(TOUCH_PIN_RIGHT, INPUT);
   pinMode(TOUCH_PIN_LEFT, INPUT);
   pinMode(TOUCH_PIN_START, INPUT);
   pinMode(TOUCH_PIN_SELECT, INPUT);
  // Make the LEDs output
   pinMode(LED_PIN_1, OUTPUT);
   pinMode(LED_PIN_2, OUTPUT);
  // Make arrays for LED strips
   FastLED.addLeds<FAST_LED_CHIPSET, LED_PIN_1, GRB>(leds, NUM_PIXELS);
   FastLED.addLeds<FAST_LED_CHIPSET, LED_PIN_2, GRB>(leds2, NUM_PIXELS);
  // Set brightness for LEDs
   FastLED.setBrightness(BRIGHTNESS);
  // Player 1 starts for Connect Four
   player1Turn = true;
   player2Turn = false;
 }

// Read input from touch sensor
 void readInput(int x){ 
    curControl = BTN_NONE; 
    
  // Array for current state of each touch sensor
   int touchSensorActivate_2[6]; 
   for (int i = 0; i < 6; i++) 
   {
     touchSensorActivate_2[i] = digitalRead(touch_sensors[i]);
   }
  // Get which touch sensor was activated
   for (int i = 0; i < 6; i++)
   {
      if (touchSensorActivate_2[i] == 1 and state_on_1[i] == 0) 
      {
          state_on_1[i] = 1;
          delay(50);
      } 
      else if (state_on_1[i] == 1 and touchSensorActivate_2[i] == 0) 
      {
          state_on_1[i] = 0;
          delay(50);
      }
      // Depending on which touch sensor was activated, do correct logic
      if (touchSensorActivate_2[i] == 1 && state_on_1[i] == 1)
       {
         switch(i) 
         {
            case 0:
              curControl = BTN_UP;
              break;
            case 1:
              curControl = BTN_DOWN;
              break;
            case 2:
              curControl = BTN_RIGHT;
              break;
            case 3:
              curControl = BTN_LEFT;
              break;
            case 4:
              curControl = BTN_START;
              break;
            case 5:
              curControl = BTN_EXIT;
              break;
          }
       }
       // Otherwise, do nothing
       else
       {
       }
    }
 // Short pause between reads
   delay(x);
 } 

// Initialize screen for menu, Tetris, Snake, and Game of Life
 void initPixels()
 {
      FastLED.addLeds<FAST_LED_CHIPSET, LED_PIN_1, GRB>(leds, NUM_PIXELS);
      FastLED.setBrightness(BRIGHTNESS);
 }
 
// Set certain pixel to be a specific color
 void setPixel(int n, int long color)
 { 
   leds[n] = CRGB(color); 
 } 
 
// Set pixel to be a specific RGB value 
 void setPixelRGB(int n, int long r,int long g, int long b)
 {
   leds[n] = CRGB(r,g,b); 
 } 
 
// Set delay
 void setDelay(int duration) 
 { 
   FastLED.delay(duration); 
 } 

// Retur specific pixel number
 int getPixel(int n)
 { 
   return (leds[n].r << 16) + (leds[n].g << 8) + leds[n].b;   
 } 
 
// Show all pixels, constrain brightness 
 void showPixels()
 { 
   int mappedValue = map(analogRead(brightnessInPin), 0, 1023, 0, MAX_BRIGHTNESS);
   FastLED.setBrightness(constrain(mappedValue, MIN_BRIGHTNESS, MAX_BRIGHTNESS));
   FastLED.show(); 
 } 

// Set orientation and then pixel
 void setScreenPixel(int x, int y, int long color)
 { 
   #ifdef ORIENTATION_HORIZONTAL 
   setPixel(y%2 ? y*FIELD_WIDTH + (11-x) : y*FIELD_WIDTH + ((FIELD_HEIGHT-1)-(11-x)),color); 
   #endif 
 }

// Set specific RGB value to pixel
 void setScreenPixelRGB(int x, int y, int long r,int long g, int long b)
 { 
   #ifdef ORIENTATION_HORIZONTAL 
   setPixelRGB(y%2 ? y*FIELD_WIDTH + x : y*FIELD_WIDTH + ((FIELD_HEIGHT-1)-x),r,g,b); 
   #endif 
 } 

// Make screen black
 void clearTablePixels()
 { 
   for (int n=0; n<FIELD_WIDTH*FIELD_HEIGHT; n++)
   { 
     setPixel(n,0); 
   } 
 } 

// Fade to black
 void fadeOut()
 { 
   for (int i=0; i<100; i++)
   { 
     dimLeds(0.97); 
     showPixels(); 
     delay(10); 
   }  
 } 
 
// Dim LEDs 
 void dimLeds(float factor)
 { 
   // Reduce brightness of all LEDs, typical factor is 0.97 
    for (int n=0; n<(FIELD_WIDTH*FIELD_HEIGHT); n++)
    { 
       int curColor = getPixel(n); 
      // Derive the tree colors 
       int r = ((curColor & 0xFF0000)>>16); 
       int g = ((curColor & 0x00FF00)>>8); 
       int b = (curColor & 0x0000FF); 
      // Reduce brightness 
       r = r*factor; 
       g = g*factor; 
       b = b*factor; 
      // Pack into single variable again 
       curColor = (r<<16) + (g<<8) + b; 
      // Set led again 
       setPixel(n,curColor); 
   } 
 } 
 
// Run through menu, then to specific game if game is selected, then back to menu if game is exited 
 void loop()
 { 
    mainLoop();
 } 

/* Written by: Klaas De Craemer, Ing. David Hrbaty
 * 
 * Common code and defines for the Tetris game
 */ 
// Maximum size of bricks. Individual bricks can still be smaller (eg 3x3)
#define  MAX_BRICK_SIZE    4
#define  BRICKOFFSET       -1 // Y offset for new bricks

#define  INIT_SPEED        1000 // Initial delay in ms between brick drops
#define  SPEED_STEP        50  // Factor for speed increase between levels, default 10
#define  LEVELUP           5   // Number of rows before levelup, default 5

// Playing field
struct Field
{
  uint8_t pix[FIELD_WIDTH][FIELD_HEIGHT+1];//Make field one larger so that collision detection with bottom of field can be done in a uniform way
  unsigned long color[FIELD_WIDTH][FIELD_HEIGHT];
};

Field field;

// Structure to represent active brick on screen
 struct Brick
 {
   boolean enabled;  // Brick is disabled when it has landed
   int xpos,ypos;
   int yOffset;  // Y-offset to use when placing brick at top of field
   uint8_t siz;
   uint8_t pix[MAX_BRICK_SIZE][MAX_BRICK_SIZE];

  unsigned int long col;
 };
 
 Brick activeBrick;

// Struct to contain the different choices of blocks
 struct AbstractBrick{
   int yOffset; // Y-offset to use when placing brick at top of field
   uint8_t siz;
   uint8_t pix[MAX_BRICK_SIZE][MAX_BRICK_SIZE];
   unsigned int long col;
 };

// Brick "library"
 AbstractBrick brickLib[7] = 
 {
  {
      1,//yoffset when adding brick to field
      4,
      { {0,0,0,0},
        {0,1,1,0},
        {0,1,1,0},
        {0,0,0,0}
      },
      WHITE
  },
  {
      0,
      4,
      { {0,1,0,0},
        {0,1,0,0},
        {0,1,0,0},
        {0,1,0,0}
      },
      GREEN
  },
  {
      1,
      3,
      { {0,0,0,0},
        {1,1,1,0},
        {0,0,1,0},
        {0,0,0,0}
      },
      BLUE
  },
  {
      1,
      3,
      { {0,0,1,0},
        {1,1,1,0},
        {0,0,0,0},
        {0,0,0,0}
      },
      YELLOW
  },
  {
      1,
      3,
      { {0,0,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {0,0,0,0}
      },
      LBLUE
  },
  {
      1,
      3,
      { {0,1,1,0},
        {1,1,0,0},
        {0,0,0,0},
        {0,0,0,0}
      },
      HOTPINK
  },
  {
      1,
      3,
      { {1,1,0,0},
        {0,1,1,0},
        {0,0,0,0},
        {0,0,0,0}
      },
      RED
  }
 };


/* Written by: Klaas De Craemer, Ing. David Hrbaty
 *
 * Main code for the Tetris game
 */
 uint16_t brickSpeed;
 unsigned long nbRowsThisLevel;
 unsigned long nbRowsTotal;

// indicate end of game
 boolean tetrisGameOver;

 void clearField() 
 {
   uint8_t x, y;
   for (y = 0; y < FIELD_HEIGHT; y++) {
     for (x = 0; x < FIELD_WIDTH; x++) {
       field.pix[x][y] = 0;
       field.color[x][y] = 0;
     }
   }
   for (x = 0; x < FIELD_WIDTH; x++) { //This last row is invisible to the player and only used for the collision detection routine
     field.pix[x][FIELD_HEIGHT] = 1;
   }
 }

// Initial conditions for Tetris
 void tetrisInit() 
 {
   clearField();
   brickSpeed = INIT_SPEED;
   nbRowsThisLevel = 0;
   nbRowsTotal = 0;
   tetrisGameOver = false;

   newActiveBrick();
 }

 boolean tetrisRunning = false;
 void runTetris(void) 
 {
   tetrisInit();

   unsigned long prevUpdateTime = 0;

   tetrisRunning = true;
   while (tetrisRunning) {
     unsigned long curTime;
     do 
     {
       readInput(200);
       if (curControl != BTN_NONE) 
       {
         playerControlActiveBrick();
         printField();
       }
       if (tetrisGameOver) break;

       curTime = millis();
     } 
     while ((curTime - prevUpdateTime) < brickSpeed); // Once enough time  has passed, proceed. The lower this number, the faster the game is
     prevUpdateTime = curTime;

    if (tetrisGameOver) 
    {
      fadeOut();
      tetrisRunning = false;
      break;
    }

   // If brick is still "on the loose", then move it down by one
    if (activeBrick.enabled) 
    {
      shiftActiveBrick(DIR_DOWN);
    } 
    else 
    {
      // Active brick has "crashed", check for full lines
      // and create new brick at top of field
       checkFullLines();
       newActiveBrick();
       prevUpdateTime = millis();//Reset update time to avoid brick dropping two spaces
    }
     printField();
   }
   fadeOut();
 }

// Action taken based on input on controller
 void playerControlActiveBrick() 
 {
    switch (curControl) 
    {
      // Code if opposite logic horizontally, so must define as opposite
       case BTN_LEFT:
         shiftActiveBrick(DIR_RIGHT);
         break;
       case BTN_RIGHT:
         shiftActiveBrick(DIR_LEFT);
         break;
       case BTN_DOWN:
         shiftActiveBrick(DIR_DOWN);
         break;
       case BTN_UP:
         rotateActiveBrick();
         break;
       case BTN_EXIT:
         tetrisRunning = false;
         break;
     }
 }

 void printField() 
 {
    int x, y;
    for (x = 0; x < FIELD_WIDTH; x++) 
    {
      for (y = 0; y < FIELD_HEIGHT; y++) 
      {
        uint8_t activeBrickPix = 0;
        if (activeBrick.enabled) // Only draw brick if it is enabled
        { 
          // Now check if brick is "in view"
           if ((x >= activeBrick.xpos) && (x < (activeBrick.xpos + (activeBrick.siz)))
            && (y >= activeBrick.ypos) && (y < (activeBrick.ypos + (activeBrick.siz)))) 
           {
             activeBrickPix = (activeBrick.pix)[x - activeBrick.xpos][y - activeBrick.ypos];
           }
        }
        if (field.pix[x][y] == 1) 
        {
          setScreenPixel(x, y, field.color[x][y]);
        } 
        else if (activeBrickPix == 1) 
        {
          setScreenPixel(x, y, activeBrick.col);
        } 
        else 
        {
          setScreenPixel(x, y, 0x000000);
        }
      }
   }
   showPixels();
}

// Game functions
 void newActiveBrick() 
 {
     randomSeed(analogRead(5) / millis());
     uint8_t selectedBrick = random(7);
     unsigned int long selectedCol = brickLib[selectedBrick].col;
    // Set properties of brick
     activeBrick.siz = brickLib[selectedBrick].siz;
     activeBrick.yOffset = brickLib[selectedBrick].yOffset;
     activeBrick.xpos = FIELD_WIDTH / 2 - activeBrick.siz / 2;
     activeBrick.ypos = BRICKOFFSET - activeBrick.yOffset;
     activeBrick.enabled = true;

    // Set color of brick
     activeBrick.col = selectedCol;

    // Copy pix array of selected Brick
     uint8_t x, y;
     for (y = 0; y < MAX_BRICK_SIZE; y++) 
     {
        for (x = 0; x < MAX_BRICK_SIZE; x++) 
        {
          activeBrick.pix[x][y] = (brickLib[selectedBrick]).pix[x][y];
        }
      }

   // Check collision, if already, then game is over
    if (checkFieldCollision(&activeBrick)) 
    {
      tetrisGameOver = true;
    }
 }

// Check collision between bricks in the field and the specified brick
 boolean checkFieldCollision(struct Brick* brick) 
 {
   uint8_t bx, by;
   uint8_t fx, fy;
   for (by = 0; by < MAX_BRICK_SIZE; by++) 
   {
     for (bx = 0; bx < MAX_BRICK_SIZE; bx++) 
     {
       fx = (*brick).xpos + bx;
       fy = (*brick).ypos + by;
       if (( (*brick).pix[bx][by] == 1)
        && ( field.pix[fx][fy] == 1)) 
       {
         return true;
       }
      }
    }
  return false;
 }

// Check collision between specified brick and all sides of the playing field
 boolean checkSidesCollision(struct Brick* brick) 
 {
   // Check vertical collision with sides of field
    uint8_t bx, by;
    uint8_t fx, fy;
    for (by = 0; by < MAX_BRICK_SIZE; by++) 
    {
      for (bx = 0; bx < MAX_BRICK_SIZE; bx++) 
      {
        if ( (*brick).pix[bx][by] == 1) 
        {
          fx = (*brick).xpos + bx; // Determine actual position in the field of the current pix of the brick
          fy = (*brick).ypos + by;
          if (fx < 0 || fx >= FIELD_WIDTH) 
          {
            return true;
          }
        }
      }
    }
   return false;
 }

 Brick tmpBrick;

// Rotate brick
 void rotateActiveBrick() 
 {
   // Copy active brick pix array to temporary pix array
    uint8_t x, y;
    for (y = 0; y < MAX_BRICK_SIZE; y++) 
    {
      for (x = 0; x < MAX_BRICK_SIZE; x++) 
      {
        tmpBrick.pix[x][y] = activeBrick.pix[x][y];
      }
    }
    tmpBrick.xpos = activeBrick.xpos;
    tmpBrick.ypos = activeBrick.ypos;
    tmpBrick.siz = activeBrick.siz;

   // Depending on size of the active brick, we will rotate differently
    if (activeBrick.siz == 3) 
    {
      // Perform rotation around center pix
       tmpBrick.pix[0][0] = activeBrick.pix[0][2];
       tmpBrick.pix[0][1] = activeBrick.pix[1][2];
       tmpBrick.pix[0][2] = activeBrick.pix[2][2];
       tmpBrick.pix[1][0] = activeBrick.pix[0][1];
       tmpBrick.pix[1][1] = activeBrick.pix[1][1];
       tmpBrick.pix[1][2] = activeBrick.pix[2][1];
       tmpBrick.pix[2][0] = activeBrick.pix[0][0];
       tmpBrick.pix[2][1] = activeBrick.pix[1][0];
       tmpBrick.pix[2][2] = activeBrick.pix[2][0];
      // Keep other parts of temporary block clear
       tmpBrick.pix[0][3] = 0;
       tmpBrick.pix[1][3] = 0;
       tmpBrick.pix[2][3] = 0;
       tmpBrick.pix[3][3] = 0;
       tmpBrick.pix[3][2] = 0;
       tmpBrick.pix[3][1] = 0;
       tmpBrick.pix[3][0] = 0;
    }
    else if (activeBrick.siz == 4) 
    {
      // Perform rotation around center "cross"
       tmpBrick.pix[0][0] = activeBrick.pix[0][3];
       tmpBrick.pix[0][1] = activeBrick.pix[1][3];
       tmpBrick.pix[0][2] = activeBrick.pix[2][3];
       tmpBrick.pix[0][3] = activeBrick.pix[3][3];
       tmpBrick.pix[1][0] = activeBrick.pix[0][2];
       tmpBrick.pix[1][1] = activeBrick.pix[1][2];
       tmpBrick.pix[1][2] = activeBrick.pix[2][2];
       tmpBrick.pix[1][3] = activeBrick.pix[3][2];
       tmpBrick.pix[2][0] = activeBrick.pix[0][1];
       tmpBrick.pix[2][1] = activeBrick.pix[1][1];
       tmpBrick.pix[2][2] = activeBrick.pix[2][1];
       tmpBrick.pix[2][3] = activeBrick.pix[3][1];
       tmpBrick.pix[3][0] = activeBrick.pix[0][0];
       tmpBrick.pix[3][1] = activeBrick.pix[1][0];
       tmpBrick.pix[3][2] = activeBrick.pix[2][0];
       tmpBrick.pix[3][3] = activeBrick.pix[3][0];
    } 
    else 
    {
    }

  // Now validate by checking collision.
  // Collision possibilities:
  //      -Brick now sticks outside field
  //      -Brick now sticks inside fixed bricks of field
  // In case of collision, we just discard the rotated temporary brick
   if ((!checkSidesCollision(&tmpBrick)) && (!checkFieldCollision(&tmpBrick))) 
   {
     // Copy temporary brick pix array to active pix array
      for (y = 0; y < MAX_BRICK_SIZE; y++) 
      {
        for (x = 0; x < MAX_BRICK_SIZE; x++) 
        {
          activeBrick.pix[x][y] = tmpBrick.pix[x][y];
        }
      }
    }
 }

// Shift brick left/right/down by one if possible
 void shiftActiveBrick(int dir) 
 {
   // Change position of active brick (no copy to temporary needed)
    if (dir == DIR_LEFT) 
    {
      activeBrick.xpos--;
    } 
    else if (dir == DIR_RIGHT) 
    {
      activeBrick.xpos++;
    } 
    else if (dir == DIR_DOWN) 
    {
      activeBrick.ypos++;
    }

  // Check position of active brick
  // Two possibilities when collision is detected:
  //    -Direction was LEFT/RIGHT, just revert position back
  //    -Direction was DOWN, revert position and fix block to field on collision
  // When no collision, keep activeBrick coordinates
  if ((checkSidesCollision(&activeBrick)) || (checkFieldCollision(&activeBrick))) 
  {
    if (dir == DIR_LEFT) 
    {
      activeBrick.xpos++;
    } 
    else if (dir == DIR_RIGHT)
    {
      activeBrick.xpos--;
    } 
    else if (dir == DIR_DOWN) 
    {
      activeBrick.ypos--; // Go back up one
      addActiveBrickToField();
      activeBrick.enabled = false; // Disable brick, it is no longer moving
    }
   }
 } 

// Copy active pixels to field, including color
 void addActiveBrickToField() 
 {
   uint8_t bx, by;
   uint8_t fx, fy;
   for (by = 0; by < MAX_BRICK_SIZE; by++) 
   {
     for (bx = 0; bx < MAX_BRICK_SIZE; bx++) 
     {
       fx = activeBrick.xpos + bx;
       fy = activeBrick.ypos + by;

       if (fx >= 0 && fy >= 0 && fx < FIELD_WIDTH && fy < FIELD_HEIGHT && activeBrick.pix[bx][by]) 
       { //Check if inside playing field
         field.pix[fx][fy] = activeBrick.pix[bx][by];
         field.color[fx][fy] = activeBrick.col;
       }
     }
   }
 }

// Move all pix from te field above startRow down by one. startRow is overwritten
 void moveFieldDownOne(uint8_t startRow) 
 {
   if (startRow == 0) 
   { // Topmost row has nothing on top to move...
      return;
   }
   uint8_t x, y;
   for (y = startRow - 1; y > 0; y--) 
   {
      for (x = 0; x < FIELD_WIDTH; x++) 
      {
        field.pix[x][y + 1] = field.pix[x][y];
        field.color[x][y + 1] = field.color[x][y];
      }
    }
  }

// Check if row is full
 void checkFullLines() 
 {
   int x, y;
   int minY = 0;
   for (y = (FIELD_HEIGHT - 1); y >= minY; y--) 
   {
      uint8_t rowSum = 0;
      for (x = 0; x < FIELD_WIDTH; x++) 
      {
        rowSum = rowSum + (field.pix[x][y]);
      }
      if (rowSum >= FIELD_WIDTH) 
      {
        // Found full row, animate its removal
        for (x = 0; x < FIELD_WIDTH; x++) 
        {
          field.pix[x][y] = 0;
          printField();
          delay(100);
        }
        // Move all upper rows down by one
        moveFieldDownOne(y);
        y++; 
        minY++;
        printField();
        delay(100);

        nbRowsThisLevel++; nbRowsTotal++;
        if (nbRowsThisLevel >= LEVELUP) 
        {
          nbRowsThisLevel = 0;
          brickSpeed = brickSpeed - SPEED_STEP;
          if (brickSpeed < 200) 
          {
            brickSpeed = 200;
          }
        }
      }
    }
  }

/* Snake
 */
 int curLength; // Current length of snake
 int xs[127]; // Array containing all snake segments,
 int ys[127]; // Max snake length is array length
 int dir; // Current Direction of snake
 int score;
 #define SNAKEWIDTH  1 // Snake width

 boolean snakeGameOver;

 int ax = 0; // Apple x position
 int ay = 0; // Apple y position
 int acolor = BLUE;

 void snakeInit()
 {
   // Snake start position and direction & initialise variables
    curLength = 3;
    xs[0]=3; xs[1]=2; xs[2]=1;
    ys[0]=FIELD_HEIGHT/2; ys[1]=FIELD_HEIGHT/2; ys[2]=FIELD_HEIGHT/2;
    dir = DIR_RIGHT;
    score = 0;
   // Generate random apple position
   ax = random(FIELD_WIDTH-1);
   ay = random(FIELD_HEIGHT-1);
  
   snakeGameOver = false;
 }

// Collision detection function
 boolean collide(int x1, int x2, int y1, int y2, int w1, int w2, int h1, int h2)
 {
    if ((x1+w1>x2) && (x1<x2+w2) && (y1+h1>y2) && (y1<y2+h2))
    {
      return true;
    } 
    else 
    {
      return false;
    }
 }

// Ending, show score 
 void die()
 {
    snakeGameOver = true;
 }

// Set direction from current button state
 void setDirection()
 {
   switch(curControl)
   {
     case BTN_LEFT:
      if(dir==DIR_RIGHT)
      {
        break;
      } 
      else
      {
        dir = DIR_LEFT;
        break;
      }
     case BTN_RIGHT:
      if(dir==DIR_LEFT)
      {
        break;
      } 
      else
      {
        dir = DIR_RIGHT;
        break;   
      }
    case BTN_DOWN:
      if(dir==DIR_UP)
      {
        break;
      }
      else
      {
        dir = DIR_DOWN;
        break;
      }
    case BTN_UP:
      if(dir==DIR_DOWN)
      {
        break;
      }
      else
      {
        dir = DIR_UP;
        break;
      }
    case BTN_START:
      break;
   }
 }

 void runSnake()
 {
    snakeInit();
    unsigned long prevUpdateTime = 0;
    boolean snakeRunning = true;
    while(snakeRunning)
    {    
      // Check self-collision with snake
      int i=curLength-1;
    while (i>=2)
    {
      if (collide(xs[0], xs[i], ys[0], ys[i], SNAKEWIDTH, SNAKEWIDTH, SNAKEWIDTH, SNAKEWIDTH))
      {
        die();
      }
      i = i-1;
    }
    
    if (snakeGameOver){
      snakeRunning = false;
      break;
    }

    // Check collision of snake head with apple
    if (collide(xs[0], ax, ys[0], ay, SNAKEWIDTH, SNAKEWIDTH, SNAKEWIDTH, SNAKEWIDTH))
    {
      // Increase score and snake length;
       score = score +1;
       curLength = curLength +1;
      // Add snake segment with temporary position of new segments
       xs[curLength-1] = 255;
       ys[curLength-1] = 255;
      
      // Generate new apple position
       ax = random(FIELD_WIDTH-1);
       ay = random(FIELD_HEIGHT-1);
      // Generate apple color
       acolor = colorLib[random(1)];

       int i=curLength-1;
       for(int i=0; i<curLength; i++) 
       {
          if (collide(ax, xs[i], ay, ys[i], SNAKEWIDTH, SNAKEWIDTH, SNAKEWIDTH, SNAKEWIDTH))
          {
            ax = random(FIELD_WIDTH-1);
            ay = random(FIELD_HEIGHT-1);
            i=0;
          }
        }
      }
    
    // Shift snake position array by one
     i = curLength-1;
     while (i>=1)
     {
       xs[i] = xs[i-1];
       ys[i] = ys[i-1];
       i = i-1;
     }
    // Determine new position of head of snake
     if (dir == DIR_RIGHT)
     {
       xs[0] = xs[0] + SNAKEWIDTH;
     } 
     else if (dir == DIR_LEFT)
     {
       xs[0] = xs[0] - SNAKEWIDTH;
     } 
     else if (dir == DIR_UP)
     {
       ys[0] = ys[0] - SNAKEWIDTH;
     } 
     else 
     { //DOWN
       ys[0] = ys[0] + SNAKEWIDTH;
     }
    
    // Check if outside playing field
     if ((xs[0]<0) || (xs[0]>=FIELD_WIDTH) || (ys[0]<0) || (ys[0]>=FIELD_HEIGHT))
     {
       if (xs[0]<0) 
       {
         xs[0] =FIELD_WIDTH -1;
       }
       else if (xs[0]>=FIELD_WIDTH) 
       {
          xs[0] = 0;
       }      
       else if (ys[0]<0) 
       {
          ys[0] =FIELD_HEIGHT -1;
       }
       else if (ys[0]>=FIELD_HEIGHT) 
       {
          ys[0] = 0;
       }    
     }
    
    clearTablePixels();
   
    // Draw apple
     setScreenPixel (ax,ay,RED);

    // Draw snake
     for (int i=0; i<curLength; i++)
     {
       setScreenPixel(xs[i], ys[i], GREEN);
     }
    
     showPixels();

    // Check buttons and set snake movement direction while we are waiting to draw the next move
     unsigned long curTime;
     boolean dirChanged = false;
     do
     {
       readInput(100);
       if (curControl == BTN_EXIT)
       {
         snakeRunning = false;
         break;
       }
       if (curControl != BTN_NONE && !dirChanged)
       { // Can only change direction once per loop
         dirChanged = true;
         setDirection();
       }
       curTime = millis();
     } 
     while ((curTime - prevUpdateTime) <250); //Once enough time  has passed, proceed. The lower this number, the faster the game is
     prevUpdateTime = curTime;
   }
  
   fadeOut();
 }

/* Game of Life
 */
 int gameoflifedelay = 125;
 boolean GameofLiferunning = false;
 long density = 50;
 int generation = 0;

 int births = 0;
 int deaths = 0;
// Blur between each frame of the simulation
 boolean blur = false;

// Adjust the amount of blur
 float blurAmount = 0.01;

 boolean randomBlur = false;

// Alternate between blurred and not blurred each time a new world is filled
 boolean alternateBlur = false;

// Switch to a random palette each time a new world is filled
 boolean switchPalette = true;

 CRGBPalette16 currentpalette_gof = PartyColors_p;

 class Cell 
 {
   public:
     byte alive =  1;
     byte prev =  1;
     byte hue = 6;
     byte brightness;
 };
 
 Cell world[FIELD_WIDTH][FIELD_HEIGHT];

// Game of life Functions

 void randomFillWorld() 
 {
   for (int i = 0; i < FIELD_WIDTH; i++) 
   {
     for (int j = 0; j < FIELD_HEIGHT; j++) 
     {
       if (random(100) < (unsigned long)density) 
       {
         world[i][j].alive = 1;
         world[i][j].brightness = 255;
       }
       else 
       {
         world[i][j].alive = 0;
         world[i][j].brightness = 0;
       }
       world[i][j].prev = world[i][j].alive;
       world[i][j].hue = 0;
     }
   }
 }

 void chooseNewPalette() 
 {
   switch (random(0, 8)) 
   {
     case 0:
       currentpalette_gof = CloudColors_p;
       break;

     case 1:
       currentpalette_gof = ForestColors_p;
       break;

     case 2:
       currentpalette_gof = HeatColors_p;
       break;

     case 3:
       currentpalette_gof = LavaColors_p;
       break;

     case 4:
       currentpalette_gof = OceanColors_p;
       break;

     case 5:
       currentpalette_gof = PartyColors_p;
       break;

     case 6:
       currentpalette_gof = RainbowColors_p;
       break;

     case 7:
     default:
       currentpalette_gof = RainbowStripeColors_p;
       break;
   }
 }

 uint16_t XY( uint8_t x, uint8_t y) 
 {
   return (y * FIELD_WIDTH) + x;
 }

 int neighbours(int x, int y) 
 {
   return (world[(x + 1) % FIELD_WIDTH][y].prev) +
          (world[x][(y + 1) % FIELD_HEIGHT].prev) +
          (world[(x + FIELD_WIDTH - 1) % FIELD_WIDTH][y].prev) +
          (world[x][(y + FIELD_HEIGHT - 1) % FIELD_HEIGHT].prev) +
          (world[(x + 1) % FIELD_WIDTH][(y + 1) % FIELD_HEIGHT].prev) +
          (world[(x + FIELD_WIDTH - 1) % FIELD_WIDTH][(y + 1) % FIELD_HEIGHT].prev) +
          (world[(x + FIELD_WIDTH - 1) % FIELD_WIDTH][(y + FIELD_HEIGHT - 1) % FIELD_HEIGHT].prev) +
          (world[(x + 1) % FIELD_WIDTH][(y + FIELD_HEIGHT - 1) % FIELD_HEIGHT].prev);
 }

 void initGameofLife() 
 {
   GameofLiferunning = true;

   initPixels();
   showPixels();
 }

 void runGameofLife() 
 {
   initGameofLife();
   runGameofLifecode();
 }

void runGameofLifecode() 
{
  while (GameofLiferunning) 
  {
    if (generation == 0) 
    {
      randomFillWorld();

      if (alternateBlur)
        blur = !blur;

      if (switchPalette)
        chooseNewPalette();

      if (randomBlur)
        blurAmount = ((float)random(50, 90)) / 100.0;
    }

  // Display current generation
   for (int i = 0; i < FIELD_WIDTH; i++) 
   {
     for (int j = 0; j < FIELD_HEIGHT; j++) 
     {
       if (blur) 
       {
         leds[XY(i, j)] = ColorFromPalette(currentpalette_gof, world[i][j].hue * 4, world[i][j].brightness);
       }
       else if (world[i][j].alive == 1) 
       {
         leds[XY(i, j)] = ColorFromPalette(currentpalette_gof, world[i][j].hue * 4, world[i][j].brightness);
       }
       else 
       {
         leds[XY(i, j)] = (CRGB)CRGB::Black;
       }
     }
   }

  // Reorder pixels based on Even rows
   for (int currentrow = 0; currentrow < FIELD_HEIGHT  ;  currentrow++)
   {
     // Even
      int rowstart = currentrow * FIELD_WIDTH; // calculate the row start position in the snake of LEDs
      if ( (currentrow % 2) == 1) { // only work on even rows
        for (int i = 0, j = FIELD_WIDTH - 1; i < FIELD_WIDTH / 2; i++, j--)
        {
          CRGB temp = leds[i + rowstart]; // take temporary value from start of row
          leds[i + rowstart] = leds[j + rowstart]; // put value from end of row at start
          leds[j + rowstart] = temp; // put temporary value at the end of the row
        }
      }
    }


      
  FastLED.show();
  delay(gameoflifedelay);

  // Birth and death cycle
   births=0;
   deaths=0;
   for (int x = 0; x < FIELD_WIDTH; x++) 
   {
     for (int y = 0; y < FIELD_HEIGHT; y++) 
     {
      // Default is for cell to stay the same
       if (world[x][y].brightness > 0 && world[x][y].prev == 0)
         world[x][y].brightness *= blurAmount;
       int count = neighbours(x, y);
       if (count == 3 && world[x][y].prev == 0) 
       {
         // A new cell is born
         world[x][y].alive = 1;
         world[x][y].hue += 2;
         world[x][y].brightness = 255;
         births++;
       } 
       else if ((count < 2 || count > 3) && world[x][y].prev == 1) 
       {
         // Cell dies
         deaths++;
         world[x][y].alive = 0;
       }
     }
   }

    // Copy next generation into place
     for (int x = 0; x < FIELD_WIDTH; x++)
     {
       for (int y = 0; y < FIELD_HEIGHT; y++)
       {
         world[x][y].prev = world[x][y].alive;
       }
     }

    generation++;
    if (generation >= 256) 
    {
      delay(1000);
      generation = 0;
      // Fade out by swiping from left to right with ruler
       const int ColumnDelay = 10;
       int curColumn = 0;
       for (int i = 0; i < FIELD_WIDTH * ColumnDelay; i++) 
       {
         dimLeds(0.97);
         if (i % ColumnDelay == 0)
         {
          // Draw vertical line
           for (int y = 0; y < FIELD_HEIGHT; y++) 
           {
             setScreenPixel(curColumn, y, AQUA);
           }
           curColumn++;
         }
         showPixels();
         delay(5);
       }
      // Sweep complete, keep dimming leds for short time
       for (int i = 0; i < 100; i++) 
       {
         dimLeds(0.9);
         showPixels();
         delay(5);
       }
    } 
    else if (births == 0 & deaths == 0) 
    {
       generation = 0;
       delay(1000);
      // Fade out by swiping from left to right with ruler
       const int ColumnDelay = 10;
       int curColumn = 0;
       for (int i = 0; i < FIELD_WIDTH * ColumnDelay; i++)
       {
         dimLeds(0.97);
         if (i % ColumnDelay == 0) 
         {
           //Draw vertical line
            for (int y = 0; y < FIELD_HEIGHT; y++) 
            {
              setScreenPixel(curColumn, y, GREEN);
            }
            curColumn++;
          }
          showPixels();
          delay(5);
        }
      //Sweep complete, keep dimming leds for short time
       for (int i = 0; i < 100; i++) 
       {
         dimLeds(0.9);
         showPixels();
         delay(5);
       }
     }

     readInput(200);
     if (curControl == BTN_EXIT) 
     {
       GameofLiferunning = false;
       break;
     }
   }
 }

 uint8_t charBuffer[8][8]; 
 
 
 void printText(char* text, unsigned int textLength, int xoffset, int yoffset, int long color)
 { 
    uint8_t curLetterWidth = 0; 
    int curX = xoffset; 
    clearTablePixels(); 
   
   // Loop over all the letters in the string 
    for (int i=0; i<textLength; i++)
    { 
      // Determine width of current letter and load its pixels in a buffer 
       curLetterWidth = loadCharInBuffer(text[i]); 
      // Loop until width of letter is reached 
       for (int lx=0; lx<curLetterWidth; lx++)
       { 
         // Now copy column per column to field (as long as within the field 
          if (curX>=FIELD_WIDTH)
          { // If we are to far to the right, stop loop entirely 
             break; 
          } 
          else if (curX>=0)
          { // Draw pixels as soon as we are "inside" the drawing area 
             for (int ly=0; ly<8; ly++)
             { // Finally copy column 
               setScreenPixel(curX,yoffset+ly,charBuffer[lx][ly]*color); 
             } 
           } 
         curX++; 
        } 
      } 
    
    showPixels(); 
 } 

 
// Load char in buffer and return width in pixels 
 uint8_t loadCharInBuffer(char letter)
 { 
    uint8_t* tmpCharPix; 
    uint8_t tmpCharWidth; 
   
    int letterIdx = (letter-32)*8; 
    
    int x=0; 
    int y=0; 
    for (int idx=letterIdx; idx<letterIdx+8; idx++)
    { 
      for (int x=0; x<8; x++)
      { 
        charBuffer[x][y] = ((font[idx]) & (1<<(7-x)))>0; 
      } 
      y++; 
    } 
   
    tmpCharWidth = 8; 
    return tmpCharWidth; 
  }  

/* Written by: Klaas De Craemer, Ing. David Hrbaty  Modified by: Mark Quinn
 * 
 * Menu system for the LED table
 */

// Select options for menu
 #define MINSELECTION  1
 #define MAXSELECTION  4
 unsigned int curSelection = MINSELECTION;

 #define TEXTSPEED 30 // lower is faster

 void mainLoop(void)
 {
   char* curSelectionText;
   int curSelectionTextLength;
   unsigned long prevUpdateTime = 0;
  
   while(true)
   {
    //Show menu system and wait for input
     clearTablePixels();
     switch (curSelection)
     {
       case 1:
         curSelectionText = "1 Connect Four";
         curSelectionTextLength = 14;
         break;
       case 2:
         curSelectionText = "2 Tetris";
         curSelectionTextLength = 8;
         break;
       case 3:
         curSelectionText = "3 Snake";
         curSelectionTextLength = 7;      
         break;
       case 4:
         curSelectionText = "4 Game of Life"; 
         curSelectionTextLength = 14;
         break;  
    }
    
     boolean selectionChanged = false;
     boolean runSelection = false;
    // Scroll current selection text from right to left;
     for (int x=FIELD_WIDTH; x>-(curSelectionTextLength*8); x--)
     {
       printText(curSelectionText, curSelectionTextLength, x, (FIELD_HEIGHT-8)/2, AQUA);
       // Read buttons
       unsigned long curTime;
       do
       {
         readInput(200);
         if (curControl != BTN_NONE)
         {
           if (curControl == BTN_LEFT)
           {
             curSelection--;
             selectionChanged = true;
           } 
           else if (curControl == BTN_RIGHT)
           {
             curSelection++;
             selectionChanged = true;
           } 
           else if (curControl == BTN_START)
           {
             runSelection = true;
           }
           checkSelectionRange();
         }
        curTime = millis();
      } 
      while (((curTime - prevUpdateTime) < TEXTSPEED) && (curControl == BTN_NONE)); // Once enough time  has passed, proceed
      prevUpdateTime = curTime;
      
       if (selectionChanged || runSelection)
         break;
     }
    
    // If we are here, it means a selection was changed or a game started, or user did nothing
    if (selectionChanged)
    {
      // For now, do nothing
    } 
    else if (runSelection)
    {
     //Start selected game
      switch (curSelection)
      {
        case 1:
          runConnectFour();
          break;
        case 2:
          runTetris();
          break;   
        case 3:
          runSnake();
          break;
        case 4:
          runGameofLife();
          break;    
       }
     } 
     else 
     {
      // If we are here, no action was taken by the user, so we will move to the next selection automatically
       curSelection++;
       checkSelectionRange();
     }
   }
 }

 void checkSelectionRange()
 {
   if (curSelection>MAXSELECTION)
   {
     curSelection = MINSELECTION;
   }
   else if (curSelection<MINSELECTION)
   {
     curSelection = MAXSELECTION;
   }
 }

/*Connect Four with touch sensors and two 12x12 LED screens
 * Written by Leilani Horlander-Cruz
 */
// LED matrix Player 1:
//             1   2   3   4   5   6   7
//   { X   X   X   X   X   X   X   X   X   X   X   X }
//   { X   X   X   X   X   X   X   X   X   X   X   X }
//   { X  25  26  27  28  29  30  31  32  33   X   X }
//   { X  46  45  44  43  42  41  40  39  38   X   X }
//   { X  49  50  51  52  53  54  55  56  57   X   X }
//   { X  70  69  68  67  66  65  64  63  62   X   X }
//   { X  73  74  75  76  77  78  79  80  81   X   X }
//   { X  94  93  92  91  90  89  88  87  86   X   X }
//   { X  97  98  99 100 101 102 103 104 105   X   X }
//   { X 118 117 116 115 114 113 112 111 110   X   X }
//   { X 121   X   X   X   X   X   X   X 129   X   X }
//   { X 142   X   X   X   X   X   X   X 134   X   X }
//
// LED matrix Player 2:
//                 7   6   5   4   3   2   1   
//   { X   X   X   X   X   X   X   X   X   X   X   X }
//   { X   X   X   X   X   X   X   X   X   X   X   X }
//   { X   X 110 111 112 113 114 115 116 117 118   X }
//   { X   X 105 104 103 102 101 100  99  98  97   X }
//   { X   X  86  87  88  89  90  91  92  93  94   X }
//   { X   X  81  80  79  78  77  76  75  74  73   X }
//   { X   X  62  63  64  65  66  67  68  69  70   X }
//   { X   X  57  56  55  54  53  52  51  50  49   X }
//   { X   X  38  39  40  41  42  43  44  45  46   X }
//   { X   X  33  32  31  30  29  28  27  26  25   X }
//   { X   X  14   X   X   X   X   X   X   X  22   X }
//   { X   X   9   X   X   X   X   X   X   X   1   X }

 boolean connectFourRunning = false;

 void runConnectFour() 
 {
   clearTablePixels();
   connectFourRunning = true;
   curControl = BTN_NONE;
   int touchSensorActivate[7] = { 0, 0, 0, 0, 0, 0, 0 };
   while (connectFourRunning)
   {
     int inc = 0;
     // If no win has occurred yet, continue adding pieces to game as touch sensors as activated
      if (!decideWin())
      {
        borderDisplay();
        for (int i = 0; i <= 6; i++) 
        {
          touchSensorActivate[i] = digitalRead(touchPins[i]);
        }
       // Get which touch sensor was activated
        for (int i = 0; i <= 6; i++)
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
//           if (i == 7)
//           {
//             for (int j = 0; j < 6; j++)
//             {
//               for (int k = 0; k < 7; k++)
//               {
//                 leds[player1PlayField[j][k]] = CRGB::Black;
//                 leds2[player2PlayField[j][k]] = CRGB::Black;
//               }
//               FastLED.show();
//             }
//             decideWin();
//             for (int l = 0; l < 7; l++)
//             {
//                nextAvailable[l] = 0;
//             }
//           }
//           else
//          {
            if (player1Turn == true) 
            {
              // If player attempts to fill full column, do not do anything
               if (nextAvailable[i] > 5)
               {
                 // do nothing
               } 
               else
               {
                // Dropping animation
                 for (int j = 5; j > nextAvailable[i]; j--)
                 {
                   leds[player1PlayField[j][i]] = CRGB::Red;
                   leds2[player2PlayField[j][6-i]] = CRGB::Red;
                   FastLED.show();
                   delay(50);
                   leds[player1PlayField[j][i]] = CRGB::Black;
                   leds2[player2PlayField[j][6-i]] = CRGB::Black;
                   FastLED.show();
                 }
                 // End at next available row in column
                  leds[player1PlayField[nextAvailable[i]][i]] = CRGB::Red;
                  leds2[player2PlayField[nextAvailable[i]][6-i]] = CRGB::Red;
                  nextAvailable[i]++;
                  player1Turn = false;
                  player2Turn = true;
                }
                FastLED.show();
              }
             // Player 2 is yellow
              else
              {
                // If player attempts to fill full column, do not do anything
                 if (nextAvailable[i] > 5)
                 {
                   // do nothing
                 }
                 else
                 {
                  // Dropping animation
                   for (int j = 5; j > nextAvailable[i]; j--)
                   {
                     leds[player1PlayField[j][i]] = CRGB::Yellow;
                     leds2[player2PlayField[j][6-i]] = CRGB::Yellow;
                     FastLED.show();
                     delay(50);
                     leds[player1PlayField[j][i]] = CRGB::Black;
                     leds2[player2PlayField[j][6-i]] = CRGB::Black;
                     FastLED.show();
                   }
                   // End at next available row in column
                    leds[player1PlayField[nextAvailable[i]][i]] = CRGB::Yellow;
                    leds2[player2PlayField[nextAvailable[i]][6-i]] = CRGB::Yellow;
                    nextAvailable[i]++;
                    player1Turn = true;
                    player2Turn = false;
                  }
                  FastLED.show();
                }
              // display for .5 second
               delay(300);
 //          }
           }
           // reset to off if no touch sensor activated
            else
            {
              // do nothing
            } 
          }
         delay(30); // short pause between reads
         decideWin();
      }
      else
      {
         inc++;
         if(inc = 4) 
         {
           connectFourRunning = false;
           break;
         }
      }
   }
   fadeOut();
 }

 // Find out if someone won
 bool decideWin ()
 {
   // Keep increment of how many in a row
    int Player1CurrentCount = 0;
    int Player2CurrentCount = 0;

   // Array for keeping track of pixels that won to blink them 
    for (int k = 0; k < 4; k++)
    {
      winningPixels[k] = 0;
      winningPixels2[k] = 0;
    }
   // Horizontally
    for (int i = 0; i < 6; i++)
    {
      Player1CurrentCount = 0;
      Player2CurrentCount = 0;
      for (int j = 0; j < 7; j++)
      {
        if (leds[player1PlayField[i][j]].green == 0 && leds[player1PlayField[i][j]].red == 255)
        {
          Player1CurrentCount++;
          if (Player1CurrentCount > 0 && Player1CurrentCount < 5)
          {
            winningPixels[Player1CurrentCount-1] = player1PlayField[i][j];
            winningPixels2[Player1CurrentCount-1] = player2PlayField[i][j];
          }
          Player2CurrentCount = 0;
          if (Player1CurrentCount >= 4)
          {
            for (int k = 0; k < 4; k++)
            {
              leds[winningPixels[k]] = CRGB::Black;
              leds2[winningPixels2[k]] = CRGB::Black;
            }
            FastLED.show();
            delay(300);
            for (int k = 0; k < 4; k++)
            {
              leds[winningPixels[k]] = CRGB::Red;
              leds2[winningPixels2[k]] = CRGB::Red;
            }
            FastLED.show();
            delay(300);
           return 1;
          }
        }
        else if (leds[player1PlayField[i][j]].green == 255)
        {
          Player1CurrentCount = 0;
          Player2CurrentCount++;
          if (Player2CurrentCount > 0 && Player2CurrentCount < 5)
          {
            winningPixels[Player2CurrentCount-1] = player1PlayField[i][j];
            winningPixels2[Player2CurrentCount-1] = player2PlayField[i][j];
          }
          if (Player2CurrentCount >= 4)
          {
             for (int k = 0; k < 4; k++)
             {
               leds[winningPixels[k]] = CRGB::Black;
               leds2[winningPixels2[k]] = CRGB::Black;
             }
             FastLED.show(); 
             delay(300);
             for (int k = 0; k < 4; k++)
             {
               leds[winningPixels[k]] = CRGB::Yellow;
               leds2[winningPixels2[k]] = CRGB::Yellow;
             }
             FastLED.show();
             delay(300);
            return 1;
          }
        }
        else
        {
          Player1CurrentCount = 0;
          Player2CurrentCount = 0;
        }
      }
    }
 
    for (int k = 0; k < 4; k++)
    {
      winningPixels[k] = 0;
      winningPixels2[k] = 0;
    }
   // Vertically
    for (int i = 0; i < 7; i++)
    {
      Player1CurrentCount = 0;
      Player2CurrentCount = 0;
     for (int j = 0; j < 6; j++)
     {
        if (leds[player1PlayField[j][i]].green == 0 && leds[player1PlayField[j][i]].red == 255)
        {
          Player1CurrentCount++;
          if (Player1CurrentCount > 0 && Player1CurrentCount < 5)
          {
            winningPixels[Player1CurrentCount-1] = player1PlayField[j][i];
            winningPixels2[Player1CurrentCount-1] = player2PlayField[j][i];
          }
          Player2CurrentCount = 0;
          if (Player1CurrentCount >= 4)
          {
            for (int k = 0; k < 4; k++)
            {
              leds[winningPixels[k]] = CRGB::Black;
              leds2[winningPixels2[k]] = CRGB::Black;
            }
            FastLED.show(); 
            delay(300);
             for (int k = 0; k < 4; k++)
             {
               leds[winningPixels[k]] = CRGB::Red;
               leds2[winningPixels2[k]] = CRGB::Red;
             }
            FastLED.show(); 
            delay(300);
           return 1;
         }
        }
        else if (leds[player1PlayField[j][i]].green == 255)
        {
           Player1CurrentCount = 0;
           Player2CurrentCount++;
           if (Player2CurrentCount > 0 && Player2CurrentCount < 5)
           {
             winningPixels[Player2CurrentCount-1] = player1PlayField[j][i];
             winningPixels2[Player2CurrentCount-1] = player2PlayField[j][i];
           }
           if (Player2CurrentCount >= 4)
           {
              for (int k = 0; k < 4; k++)
              {
                leds[winningPixels[k]] = CRGB::Black;
                leds2[winningPixels2[k]] = CRGB::Black;
              }
              FastLED.show(); 
              delay(300);
              for (int k = 0; k < 4; k++)
              {
                leds[winningPixels[k]] = CRGB::Yellow;
                leds2[winningPixels2[k]] = CRGB::Yellow;
              }
              FastLED.show(); 
              delay(300);
            return 1;
           }
         }
         else
         {
           Player1CurrentCount = 0;
           Player2CurrentCount = 0;
         }
       }
     }

    // Diagonally from bottom left
     for (int k = 0; k < 4; k++)
     {
       winningPixels[k] = 0;
       winningPixels2[k] = 0;
     }
     Player1CurrentCount = 0;
     Player2CurrentCount = 0;
     for (int i = 0; i < 4; i++)
     {
        if (leds[player1PlayField[i+1][i]].green == 0 && leds[player1PlayField[i+1][i]].red == 255)
        {
           Player1CurrentCount++;
           if (Player1CurrentCount > 0 && Player1CurrentCount < 5)
           {
             winningPixels[Player1CurrentCount-1] = player1PlayField[i+1][i];
             winningPixels2[Player1CurrentCount-1] = player2PlayField[i+1][i];
           }
           Player2CurrentCount = 0;
           if (Player1CurrentCount >= 4)
           {
              for (int k = 0; k < 4; k++)
              {
                leds[winningPixels[k]] = CRGB::Black;
                leds2[winningPixels2[k]] = CRGB::Black;
              }
              FastLED.show(); 
              delay(300);
              for (int k = 0; k < 4; k++)
              {
                 leds[winningPixels[k]] = CRGB::Red;
                 leds2[winningPixels2[k]] = CRGB::Red;
              }
              FastLED.show(); 
              delay(300);
            return 1;
          }
        }
        else if (leds[player1PlayField[i+1][i]].green == 255)
        {
           Player1CurrentCount = 0;
           Player2CurrentCount++;
           if (Player2CurrentCount > 0 && Player2CurrentCount < 5)
           {
             winningPixels[Player2CurrentCount-1] = player1PlayField[i+1][i];
             winningPixels2[Player2CurrentCount-1] = player2PlayField[i+1][i];
           }
           if (Player2CurrentCount >= 4)
           {
              for (int k = 0; k < 4; k++)
              {
                leds[winningPixels[k]] = CRGB::Black;
                leds2[winningPixels2[k]] = CRGB::Black;
              }
              FastLED.show(); 
              delay(300);
              for (int k = 0; k < 4; k++)
              {
                leds[winningPixels[k]] = CRGB::Yellow;
                leds2[winningPixels2[k]] = CRGB::Yellow;
               }
               FastLED.show(); 
               delay(300);
            return 1;
          }
        }
        else
        {
           Player1CurrentCount = 0;
           Player2CurrentCount = 0;
        }
     }
  
      for (int k = 0; k < 4; k++)
      {
        winningPixels[k] = 0;
        winningPixels2[k] = 0;
      }
      Player1CurrentCount = 0;
      Player2CurrentCount = 0;
      for (int i = 0; i < 4; i++)
      {
        if (leds[player1PlayField[i+2][i]].green == 0 && leds[player1PlayField[i+2][i]].red == 255)
        {
          Player1CurrentCount++;
          if (Player1CurrentCount > 0 && Player1CurrentCount < 5)
          {
            winningPixels[Player1CurrentCount-1] = player1PlayField[i+2][i];
            winningPixels2[Player1CurrentCount-1] = player2PlayField[i+2][i];
          }
          Player2CurrentCount = 0;
          if (Player1CurrentCount >= 4)
          {
             for (int k = 0; k < 4; k++)
             {
               leds[winningPixels[k]] = CRGB::Black;
               leds2[winningPixels2[k]] = CRGB::Black;
             }
             FastLED.show(); 
             delay(300);
             for (int k = 0; k < 4; k++)
             {
               leds[winningPixels[k]] = CRGB::Red;
               leds2[winningPixels2[k]] = CRGB::Red;
             }
             FastLED.show(); 
             delay(300);
            return 1;
          }
        }
        else if (leds[player1PlayField[i+2][i]].green == 255)
        {
          Player1CurrentCount = 0;
          Player2CurrentCount++;
          if (Player2CurrentCount > 0 && Player2CurrentCount < 5)
          {
            winningPixels[Player2CurrentCount-1] = player1PlayField[i+2][i];
            winningPixels2[Player2CurrentCount-1] = player2PlayField[i+2][i];
          }
          if (Player2CurrentCount >= 4)
          {
            for (int k = 0; k < 4; k++)
            {
              leds[winningPixels[k]] = CRGB::Black;
              leds2[winningPixels2[k]] = CRGB::Black;
            }
            FastLED.show(); 
            delay(300);
             for (int k = 0; k < 4; k++)
            {
              leds[winningPixels[k]] = CRGB::Yellow;
              leds2[winningPixels2[k]] = CRGB::Yellow;
            }
            FastLED.show(); 
            delay(300);
          return 1;
          }
        }
        else
        {
          Player1CurrentCount = 0;
          Player2CurrentCount = 0;
        }
      }

      for (int k = 0; k < 4; k++)
      {
        winningPixels[k] = 0;
        winningPixels2[k] = 0;
      }
      Player1CurrentCount = 0;
      Player2CurrentCount = 0;
      for (int i = 0; i < 6; i++)
      {
        if (leds[player1PlayField[i][i]].green == 0 && leds[player1PlayField[i][i]].red == 255)
        {
          Player1CurrentCount++;
          if (Player1CurrentCount > 0 && Player1CurrentCount < 5)
          {
            winningPixels[Player1CurrentCount-1] = player1PlayField[i][i];
            winningPixels2[Player1CurrentCount-1] = player2PlayField[i][i];
          }
          Player2CurrentCount = 0;
          if (Player1CurrentCount >= 4)
          {
              for (int k = 0; k < 4; k++)
              {
                leds[winningPixels[k]] = CRGB::Black;
                leds2[winningPixels2[k]] = CRGB::Black;
              }
              FastLED.show(); 
              delay(300);
               for (int k = 0; k < 4; k++)
              {
                leds[winningPixels[k]] = CRGB::Red;
                leds2[winningPixels2[k]] = CRGB::Red;
              }
              FastLED.show(); 
              delay(300);
            return 1;
          }
        }
        else if (leds[player1PlayField[i][i]].green == 255)
        {
          Player1CurrentCount = 0;
          Player2CurrentCount++;
          if (Player2CurrentCount > 0 && Player2CurrentCount < 5)
           {
            winningPixels[Player2CurrentCount-1] = player1PlayField[i][i];
            winningPixels2[Player2CurrentCount-1] = player2PlayField[i][i];
          }
          if (Player2CurrentCount >= 4)
          {
            for (int k = 0; k < 4; k++)
            {
              leds[winningPixels[k]] = CRGB::Black;
              leds2[winningPixels2[k]] = CRGB::Black;
            }
            FastLED.show(); 
            delay(300);
             for (int k = 0; k < 4; k++)
            {
              leds[winningPixels[k]] = CRGB::Yellow;
              leds2[winningPixels2[k]] = CRGB::Yellow;
            }
            FastLED.show(); 
            delay(300);
            return 1;
          }
        }
      else
      {
        Player1CurrentCount = 0;
        Player2CurrentCount = 0;
      }
    }

    for (int k = 0; k < 4; k++)
    {
      winningPixels[k] = 0;
      winningPixels2[k] = 0;
    }
    Player1CurrentCount = 0;
    Player2CurrentCount = 0;
    for (int i = 1; i < 7; i++)
    {
      if (leds[player1PlayField[i-1][i]].green == 0 && leds[player1PlayField[i-1][i]].red == 255)
      {
        Player1CurrentCount++;
        if (Player1CurrentCount > 0 && Player1CurrentCount < 5)
        {
          winningPixels[Player1CurrentCount-1] = player1PlayField[i-1][i];
          winningPixels2[Player1CurrentCount-1] = player2PlayField[i-1][i];
        }
        Player2CurrentCount = 0;
        if (Player1CurrentCount >= 4)
        {
          for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Black;
            leds2[winningPixels2[k]] = CRGB::Black;
          }
          FastLED.show(); 
          delay(300);
           for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Red;
            leds2[winningPixels2[k]] = CRGB::Red;
          }
          FastLED.show(); 
          delay(300);
          return 1;
        }
      }
      else if (leds[player1PlayField[i-1][i]].green == 255)
      {
        Player1CurrentCount = 0;
        Player2CurrentCount++;
        if (Player2CurrentCount > 0 && Player2CurrentCount < 5)
        {
          winningPixels[Player2CurrentCount-1] = player1PlayField[i-1][i];
          winningPixels2[Player2CurrentCount-1] = player2PlayField[i-1][i];
        }
        if (Player2CurrentCount >= 4)
        {
          for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Black;
            leds2[winningPixels2[k]] = CRGB::Black;
          }
          FastLED.show(); 
          delay(300);
           for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Yellow;
            leds2[winningPixels2[k]] = CRGB::Yellow;
          }
          FastLED.show(); 
          delay(300);
          return 1;
        }
      }
      else
      {
        Player1CurrentCount = 0;
        Player2CurrentCount = 0;
      }
    }

    for (int k = 0; k < 4; k++)
    {
      winningPixels[k] = 0;
      winningPixels2[k] = 0;
    }
    Player1CurrentCount = 0;
    Player2CurrentCount = 0;
    for (int i = 2; i < 7; i++)
    {
      if (leds[player1PlayField[i-2][i]].green == 0 && leds[player1PlayField[i-2][i]].red == 255)
      {
        Player1CurrentCount++;
        if (Player1CurrentCount > 0 && Player1CurrentCount < 5)
        {
          winningPixels[Player1CurrentCount-1] = player1PlayField[i-2][i];
          winningPixels2[Player1CurrentCount-1] = player2PlayField[i-2][i];
        }
        Player2CurrentCount = 0;
        if (Player1CurrentCount >= 4)
        {
            for (int k = 0; k < 4; k++)
            {
              leds[winningPixels[k]] = CRGB::Black;
              leds2[winningPixels2[k]] = CRGB::Black;
            }
            FastLED.show(); 
            delay(300);
             for (int k = 0; k < 4; k++)
            {
              leds[winningPixels[k]] = CRGB::Red;
              leds2[winningPixels2[k]] = CRGB::Red;
            }
            FastLED.show(); 
            delay(300);
          return 1;
        }
      }
      else if (leds[player1PlayField[i-2][i]].green == 255)
      {
        Player1CurrentCount = 0;
        Player2CurrentCount++;
        if (Player2CurrentCount > 0 && Player2CurrentCount < 5)
      {
        winningPixels[Player2CurrentCount-1] = player1PlayField[i-2][i];
        winningPixels2[Player2CurrentCount-1] = player2PlayField[i-2][i];
      }
        if (Player2CurrentCount >= 4)
        {
          for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Black;
            leds2[winningPixels2[k]] = CRGB::Black;
          }
          FastLED.show(); 
          delay(300);
           for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Yellow;
            leds2[winningPixels2[k]] = CRGB::Yellow;
          }
          FastLED.show(); 
          delay(300);
          return 1;
        }
      }
      else
      {
        Player1CurrentCount = 0;
        Player2CurrentCount = 0;
      }
   }

   for (int k = 0; k < 4; k++)
   {
     winningPixels[k] = 0;
     winningPixels2[k] = 0;
   }
   Player1CurrentCount = 0;
   Player2CurrentCount = 0;
   for (int i = 3; i < 7; i++)
   {
     if (leds[player1PlayField[i-3][i]].green == 0 && leds[player1PlayField[i-3][i]].red == 255)
     {
       Player1CurrentCount++;
       if (Player1CurrentCount > 0 && Player1CurrentCount < 5)
       {
         winningPixels[Player1CurrentCount-1] = player1PlayField[i-3][i];
         winningPixels2[Player1CurrentCount-1] = player2PlayField[i-3][i];
       }
       Player2CurrentCount = 0;
       if (Player1CurrentCount >= 4)
       {
        for (int k = 0; k < 4; k++)
        {
          leds[winningPixels[k]] = CRGB::Black;
          leds2[winningPixels2[k]] = CRGB::Black;
        }
        FastLED.show(); 
        delay(300);
         for (int k = 0; k < 4; k++)
        {
          leds[winningPixels[k]] = CRGB::Red;
          leds2[winningPixels2[k]] = CRGB::Red;
        }
        FastLED.show(); 
        delay(300);
        return 1;
      }
    }
    else if (leds[player1PlayField[i-3][i]].green == 255)
    {
      Player1CurrentCount = 0;
      Player2CurrentCount++;
      if (Player2CurrentCount > 0 && Player2CurrentCount < 5)
      {
        winningPixels[Player2CurrentCount-1] = player1PlayField[i-3][i];
        winningPixels2[Player2CurrentCount-1] = player2PlayField[i-3][i];
      }
      if (Player2CurrentCount >= 4)
      {
        for (int k = 0; k < 4; k++)
        {
          leds[winningPixels[k]] = CRGB::Black;
          leds2[winningPixels2[k]] = CRGB::Black;
        }
        FastLED.show(); 
        delay(300);
         for (int k = 0; k < 4; k++)
        {
          leds[winningPixels[k]] = CRGB::Yellow;
          leds2[winningPixels2[k]] = CRGB::Yellow;
        }
        FastLED.show(); 
        delay(300);
        return 1;
       }
     }
     else
     {
       Player1CurrentCount = 0;
       Player2CurrentCount = 0;
     }
   }

  // diagonally from bottom right
   for (int k = 0; k < 4; k++)
   {
      winningPixels[k] = 0;
      winningPixels2[k] = 0;
   }
   Player1CurrentCount = 0;
   Player2CurrentCount = 0;
   for (int i = 6; i > 2; i--)
   {
     if (leds[player1PlayField[8-i][i]].green == 0 && leds[player1PlayField[8-i][i]].red == 255)
     {
       Player1CurrentCount++;
       if (Player1CurrentCount > 0 && Player1CurrentCount < 5)
       {
          winningPixels[Player1CurrentCount-1] = player1PlayField[8-i][i];
          winningPixels2[Player1CurrentCount-1] = player2PlayField[8-i][i];
       }
       Player2CurrentCount = 0;
       if (Player1CurrentCount >= 4)
       {
          for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Black;
            leds2[winningPixels2[k]] = CRGB::Black;
          }
          FastLED.show(); 
          delay(300);
           for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Red;
            leds2[winningPixels2[k]] = CRGB::Red;
          }
          FastLED.show(); 
          delay(300);
          return 1;
       }
     }
     else if (leds[player1PlayField[8-i][i]].green == 255)
     {
        Player1CurrentCount = 0;
        Player2CurrentCount++;
        if (Player2CurrentCount > 0 && Player2CurrentCount < 5)
        {
           winningPixels[Player2CurrentCount-1] = player1PlayField[8-i][i];
           winningPixels2[Player2CurrentCount-1] = player2PlayField[8-i][i];
        }
        if (Player2CurrentCount >= 4)
        {
          for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Black;
            leds2[winningPixels2[k]] = CRGB::Black;
          }
          FastLED.show(); 
          delay(300);
           for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Yellow;
            leds2[winningPixels2[k]] = CRGB::Yellow;
          }
          FastLED.show(); 
          delay(300);
          return 1;
        }
      }
      else
      {
        Player1CurrentCount = 0;
        Player2CurrentCount = 0;
      }
   }

    for (int k = 0; k < 4; k++)
    {
      winningPixels[k] = 0;
      winningPixels2[k] = 0;
    }
    Player1CurrentCount = 0;
    Player2CurrentCount = 0;
    for (int i = 6; i > 1; i--)
    {
      if (leds[player1PlayField[7-i][i]].green == 0 && leds[player1PlayField[7-i][i]].red == 255)
      {
        Player1CurrentCount++;
        if (Player1CurrentCount > 0 && Player1CurrentCount < 5)
        {
          winningPixels[Player1CurrentCount-1] = player1PlayField[7-i][i];
          winningPixels2[Player1CurrentCount-1] = player2PlayField[7-i][i];
        }
        Player2CurrentCount = 0;
        if (Player1CurrentCount >= 4)
        {
            for (int k = 0; k < 4; k++)
            {
              leds[winningPixels[k]] = CRGB::Black;
              leds2[winningPixels2[k]] = CRGB::Black;
            }
            FastLED.show(); 
            delay(300);
             for (int k = 0; k < 4; k++)
            {
              leds[winningPixels[k]] = CRGB::Red;
              leds2[winningPixels2[k]] = CRGB::Red;
            }
            FastLED.show(); 
            delay(300);
          return 1;
        }
      }
      else if (leds[player1PlayField[7-i][i]].green == 255)
      {
        Player1CurrentCount = 0;
        Player2CurrentCount++;
        if (Player2CurrentCount > 0 && Player2CurrentCount < 5)
        {
          winningPixels[Player2CurrentCount-1] = player1PlayField[7-i][i];
          winningPixels2[Player2CurrentCount-1] = player2PlayField[7-i][i];
        }
        if (Player2CurrentCount >= 4)
        {
          for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Black;
            leds2[winningPixels2[k]] = CRGB::Black;
          }
          FastLED.show(); 
          delay(300);
           for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Yellow;
            leds2[winningPixels2[k]] = CRGB::Yellow;
          }
          FastLED.show(); 
          delay(300);
           return 1;
        }
      }
      else
      {
        Player1CurrentCount = 0;
        Player2CurrentCount = 0;
      }
   }

   for (int k = 0; k < 4; k++)
   {
      winningPixels[k] = 0;
      winningPixels2[k] = 0;
   }
   Player1CurrentCount = 0;
   Player2CurrentCount = 0;
   for (int i = 6; i > 0; i--)
   {
      if (leds[player1PlayField[6-i][i]].green == 0 && leds[player1PlayField[6-i][i]].red == 255)
      {
        Player1CurrentCount++;
        if (Player1CurrentCount > 0 && Player1CurrentCount < 5)
        {
           winningPixels[Player1CurrentCount-1] = player1PlayField[6-i][i];
           winningPixels2[Player1CurrentCount-1] = player2PlayField[6-i][i];
        }
        Player2CurrentCount = 0;
        if (Player1CurrentCount >= 4)
        {
          for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Black;
            leds2[winningPixels2[k]] = CRGB::Black;
          }
          FastLED.show(); 
          delay(300);
          for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Red;
            leds2[winningPixels2[k]] = CRGB::Red;
          }
          FastLED.show(); 
          delay(300);
         return 1;
       }
      }
      else if (leds[player1PlayField[6-i][i]].green == 255)
      {
        Player1CurrentCount = 0;
        Player2CurrentCount++;
        if (Player2CurrentCount > 0 && Player2CurrentCount < 5)
        {
          winningPixels[Player2CurrentCount-1] = player1PlayField[6-i][i];
          winningPixels2[Player2CurrentCount-1] = player2PlayField[6-i][i];
        }
        if (Player2CurrentCount >= 4)
        {
          for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Black;
            leds2[winningPixels2[k]] = CRGB::Black;
          }
          FastLED.show(); 
          delay(300);
           for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Yellow;
            leds2[winningPixels2[k]] = CRGB::Yellow;
          }
          FastLED.show(); 
          delay(300);
          return 1;
        }
      }
      else
      {
        Player1CurrentCount = 0;
        Player2CurrentCount = 0;
      }
   }

   for (int k = 0; k < 4; k++)
   {
     winningPixels[k] = 0;
     winningPixels2[k] = 0;
   }
   Player1CurrentCount = 0;
   Player2CurrentCount = 0;
   for (int i = 5; i >= 0; i--)
   {
     if (leds[player1PlayField[5-i][i]].green == 0 && leds[player1PlayField[5-i][i]].red == 255)
     {
       Player1CurrentCount++;
       if (Player1CurrentCount > 0 && Player1CurrentCount < 5)
       {
         winningPixels[Player1CurrentCount-1] = player1PlayField[5-i][i];
         winningPixels2[Player1CurrentCount-1] = player2PlayField[5-i][i];
       }
       Player2CurrentCount = 0;
       if (Player1CurrentCount >= 4)
       {
        for (int k = 0; k < 4; k++)
        {
          leds[winningPixels[k]] = CRGB::Black;
          leds2[winningPixels2[k]] = CRGB::Black;
        }
        FastLED.show(); 
        delay(300);
        for (int k = 0; k < 4; k++)
        {
          leds[winningPixels[k]] = CRGB::Red;
          leds2[winningPixels2[k]] = CRGB::Red;
        }
        FastLED.show(); 
        delay(300);
        return 1;
      }
     }
     else if (leds[player1PlayField[5-i][i]].green == 255)
     {
        Player1CurrentCount = 0;
        Player2CurrentCount++;
        if (Player2CurrentCount > 0 && Player2CurrentCount < 5)
        {
          winningPixels[Player2CurrentCount-1] = player1PlayField[5-i][i];
          winningPixels2[Player2CurrentCount-1] = player2PlayField[5-i][i];
        }
        if (Player2CurrentCount >= 4)
        {
           for (int k = 0; k < 4; k++)
           {
              leds[winningPixels[k]] = CRGB::Black;
              leds2[winningPixels2[k]] = CRGB::Black;
           }
           FastLED.show(); 
           delay(300);
           for (int k = 0; k < 4; k++)
           {
              leds[winningPixels[k]] = CRGB::Yellow;
              leds2[winningPixels2[k]] = CRGB::Yellow;
           }
           FastLED.show(); 
           delay(300);
           return 1;
       }
     }
     else
     {
        Player1CurrentCount = 0;
        Player2CurrentCount = 0;
     }
  }

  for (int k = 0; k < 4; k++)
  {
    winningPixels[k] = 0;
    winningPixels2[k] = 0;
  }
  Player1CurrentCount = 0;
  Player2CurrentCount = 0;
  for (int i = 4; i >= 0; i--)
  {
    if (leds[player1PlayField[4-i][i]].green == 0 && leds[player1PlayField[4-i][i]].red == 255)
    {
      Player1CurrentCount++;
      if (Player1CurrentCount > 0 && Player1CurrentCount < 5)
      {
        winningPixels[Player1CurrentCount-1] = player1PlayField[4-i][i];
        winningPixels2[Player1CurrentCount-1] = player2PlayField[4-i][i];
      }
      Player2CurrentCount = 0;
      if (Player1CurrentCount >= 4)
      {
        for (int k = 0; k < 4; k++)
        {
          leds[winningPixels[k]] = CRGB::Black;
          leds2[winningPixels2[k]] = CRGB::Black;
        }
        FastLED.show(); 
        delay(300);
         for (int k = 0; k < 4; k++)
        {
          leds[winningPixels[k]] = CRGB::Red;
          leds2[winningPixels2[k]] = CRGB::Red;
        }
        FastLED.show(); 
        delay(300);
        return 1;
      }
    }
    else if (leds[player1PlayField[4-i][i]].green == 255)
    {
       Player1CurrentCount = 0;
       Player2CurrentCount++;
       if (Player2CurrentCount > 0 && Player2CurrentCount < 5)
       {
         winningPixels[Player2CurrentCount-1] = player1PlayField[4-i][i];
         winningPixels2[Player2CurrentCount-1] = player2PlayField[4-i][i];
       }
       if (Player2CurrentCount >= 4)
       {
          for (int k = 0; k < 4; k++)
          {
             leds[winningPixels[k]] = CRGB::Black;
             leds2[winningPixels2[k]] = CRGB::Black;
          }
          FastLED.show(); 
          delay(300);
          for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Yellow;
            leds2[winningPixels2[k]] = CRGB::Yellow;
          }
          FastLED.show(); 
          delay(300);
          return 1;
        }
      }
      else
      {
        Player1CurrentCount = 0;
        Player2CurrentCount = 0;
      }
   }

   for (int k = 0; k < 4; k++)
   {
      winningPixels[k] = 0;
      winningPixels2[k] = 0;
   }
   Player1CurrentCount = 0;
   Player2CurrentCount = 0;
   for (int i = 3; i >= 0; i--)
   {
     if (leds[player1PlayField[3-i][i]].green == 0 && leds[player1PlayField[3-i][i]].red == 255)
     {
       Player1CurrentCount++;
       if (Player1CurrentCount > 0 && Player1CurrentCount < 5)
       {
         winningPixels[Player1CurrentCount-1] = player1PlayField[3-i][i];
         winningPixels2[Player1CurrentCount-1] = player2PlayField[3-i][i];
       }
       Player2CurrentCount = 0;
       if (Player1CurrentCount >= 4)
       {
          for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Black;
            leds2[winningPixels2[k]] = CRGB::Black;
          }
          FastLED.show(); 
          delay(300);
           for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Red;
            leds2[winningPixels2[k]] = CRGB::Red;
          }
          FastLED.show(); 
          delay(300);
          return 1;
        }
      }
      else if (leds[player1PlayField[3-i][i]].green == 255)
      {
        Player1CurrentCount = 0;
        Player2CurrentCount++;
        if (Player2CurrentCount > 0 && Player2CurrentCount < 5)
        {
          winningPixels[Player2CurrentCount-1] = player1PlayField[3-i][i];
          winningPixels2[Player2CurrentCount-1] = player2PlayField[3-i][i];
        }
        if (Player2CurrentCount >= 4)
        {
          for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Black;
            leds2[winningPixels2[k]] = CRGB::Black;
          }
          FastLED.show(); 
          delay(300);
           for (int k = 0; k < 4; k++)
          {
            leds[winningPixels[k]] = CRGB::Yellow;
            leds2[winningPixels2[k]] = CRGB::Yellow;
          }
          FastLED.show(); 
          delay(300);
          return 1;
        }
      }
      else
      {
        Player1CurrentCount = 0;
        Player2CurrentCount = 0;
      }
   }
   return 0;
 }

 void borderDisplay () 
 {
   int i = 0;
   for (i = 0; i < 34; i++)  // Display border
   {
     leds[border_1[i]] = CRGB::Blue;
     leds2[border_2[i]] = CRGB::Blue;
   }
   FastLED.show();
 }
