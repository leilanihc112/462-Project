// Connect Four with touch sensors and two 12x12 LED screens
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

#include <FastLED.h>

// setting data pins for touch sensors and LED screens

// player 1's screen
#define LED_PIN_1     6
// player 2's screen
#define LED_PIN_2     7
#define NUM_LEDS      144
#define BRIGHTNESS    50
// touch sensors for columns
#define TOUCH_PIN_1   46
#define TOUCH_PIN_2   48
#define TOUCH_PIN_3   35
#define TOUCH_PIN_4   33
#define TOUCH_PIN_5   49
#define TOUCH_PIN_6   51
#define TOUCH_PIN_7   53
// touch sensors for ending connect four game
#define TOUCH_PIN_8   28

// array of touch sensors
byte touchPins[8] = { TOUCH_PIN_1, TOUCH_PIN_2, TOUCH_PIN_3, TOUCH_PIN_4, TOUCH_PIN_5, TOUCH_PIN_6, TOUCH_PIN_7, TOUCH_PIN_8 };

// array for previous state of each touch sensor
bool state_on[8] = {0, 0, 0, 0, 0, 0, 0, 0 };

// array to check next available LED to light in each column for stacking
int nextAvailable[7] = { 0, 0, 0, 0, 0, 0, 0 };

// matrix with LEDs for borders
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


// array for blinking winning pixels
int winningPixels[4] = { 0, 0, 0, 0 };
int winningPixels2[4] = { 0, 0, 0, 0 };
                               
bool player1Turn;
bool player2Turn;

// array for current state of each touch sensor
int touchSensorActivate[8];

CRGB leds[NUM_LEDS];
CRGB leds2[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN_1, GRB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812, LED_PIN_2, GRB>(leds2, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
  pinMode (TOUCH_PIN_1, INPUT);
  pinMode (TOUCH_PIN_2, INPUT);
  pinMode (TOUCH_PIN_3, INPUT);
  pinMode (TOUCH_PIN_4, INPUT);
  pinMode (TOUCH_PIN_5, INPUT);
  pinMode (TOUCH_PIN_6, INPUT);
  pinMode (TOUCH_PIN_7, INPUT);
  pinMode (LED_PIN_1, OUTPUT);
  pinMode (LED_PIN_2, OUTPUT);
  pinMode (TOUCH_PIN_8, INPUT);
  Serial.begin(9600);
  player1Turn = true;
  player2Turn = false;
}

void loop() {
  if (!decideWin())
  {
    borderDisplay();
    for (int i = 0; i <= 7; i++) 
    {
      touchSensorActivate[i] = digitalRead(touchPins[i]);
    }
    // get which touch sensor was activated
    for (int i = 0; i <= 7; i++)
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
          if (i == 7)
          {
            for (int j = 0; j < 6; j++)
            {
              for (int k = 0; k < 7; k++)
              {
                leds[player1PlayField[j][k]] = CRGB::Black;
                leds2[player2PlayField[j][k]] = CRGB::Black;
              }
              FastLED.show();
            }
            decideWin();
            for (int l = 0; l < 7; l++)
            {
                nextAvailable[l] = 0;
            }
          }
          else
          {
            if (player1Turn == true) 
            {
              if (nextAvailable[i] > 5)
              {
                // do nothing
              }
              else
              {
                for (int j = 5; j > nextAvailable[i]; j--)
                {
                  leds[player1PlayField[j][i]] = CRGB::Red; // lightLED (1, 1, i, j);
                  leds2[player2PlayField[j][6-i]] = CRGB::Red; // lightLED (2, 1, 6-i, j);
                  FastLED.show();
                  delay(50);
                  leds[player1PlayField[j][i]] = CRGB::Black; //lightLED (1, 0, i, j);
                  leds2[player2PlayField[j][6-i]] = CRGB::Black; //lightLED (2, 0, 6-i, j);
                  FastLED.show();
                }
                leds[player1PlayField[nextAvailable[i]][i]] = CRGB::Red; //lightLED (1, 1, i, nextAvailable[i]);
                leds2[player2PlayField[nextAvailable[i]][6-i]] = CRGB::Red; //lightLED (2, 1, 6-i, nextAvailable[i]);
                nextAvailable[i]++;
                player1Turn = false;
                player2Turn = true;
              }
              FastLED.show();
            }
            else
            {
              if (nextAvailable[i] > 5)
              {
                // do nothing
              }
              else
              {
                for (int j = 5; j > nextAvailable[i]; j--)
                {
                  leds[player1PlayField[j][i]] = CRGB::Yellow; //lightLED (1, 2, i, j);
                  leds2[player2PlayField[j][6-i]] = CRGB::Yellow; //lightLED (2, 2, 6-i, j);
                  FastLED.show();
                  delay(50);
                  leds[player1PlayField[j][i]] = CRGB::Black; //lightLED (1, 0, i, j);
                  leds2[player2PlayField[j][6-i]] = CRGB::Black; //lightLED (2, 0, 6-i, j);
                  FastLED.show();
                }
                leds[player1PlayField[nextAvailable[i]][i]] = CRGB::Yellow; //lightLED (1, 2, i, nextAvailable[i]);
                leds2[player2PlayField[nextAvailable[i]][6-i]] = CRGB::Yellow; //lightLED (2, 2, 6-i, nextAvailable[i]);
                nextAvailable[i]++;
                player1Turn = true;
                player2Turn = false;
              }
            FastLED.show();
            }
            // display for .5 second
            delay(300);
            
           }
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
      touchSensorActivate[7] = digitalRead(touchPins[7]);
        if (touchSensorActivate[7] == 1 and state_on[7] == 0) 
        {
            state_on[7] = 1;
            delay(50);
        } 
        else if (state_on[7] == 1 and touchSensorActivate[7] == 0) 
        {
            state_on[7] = 0;
            delay(50);
        }
        if (touchSensorActivate[7] == 1 && state_on[7] == 1)
         {
            for (int i = 0; i < 6; i++)
            {
              for (int j = 0; j < 7; j++)
              {
                leds[player1PlayField[i][j]] = CRGB::Black;
                leds2[player2PlayField[i][j]] = CRGB::Black;
              }
            }
            for (int i = 0; i < 7; i++)
            {
              nextAvailable[i] = 0;
            }
            player1Turn = true;
            player2Turn = false;
            FastLED.show();
            decideWin();
         }
         else
         {
          // do nothing
         }
         delay(30); // short pause between reads
      }
}

// find out if someone won
bool decideWin ()
{
  int Player1CurrentCount = 0;
  int Player2CurrentCount = 0;

  for (int k = 0; k < 4; k++)
  {
    winningPixels[k] = 0;
    winningPixels2[k] = 0;
  }
  // horizontally
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
  // vertically
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

  // diagonally from bottom left
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
  for (i = 0; i < 34; i++)  // display border
  {
    leds[border_1[i]] = CRGB::Blue;
    leds2[border_2[i]] = CRGB::Blue;
  }
  FastLED.show();
}

// set colors to pixels
//void lightLED (int screen, int color, int column, int row) 
//{ 
//  // color = 1 is Red, color = 2 is Yellow, color = 0 is Black
//  // screen = 1 is Player 1, screen = 2 is Player 2
//  if (screen == 1)
//  {
//    if (column == 0)
//    {
//      if (row == 0)
//      {
//        if (color == 1)
//        {
//         leds[98] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[98] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[98] = CRGB::Black;
//        }
//      }
//      else if (row == 1)
//      {
//        if (color == 1)
//        {
//          leds[93] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[93] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[93] = CRGB::Black;
//        }
//      }
//      else if (row == 2)
//      {
//        if (color == 1)
//        {
//          leds[74] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[74] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[74] = CRGB::Black;
//        }
//      }
//      else if (row == 3)
//      {
//        if (color == 1)
//        {
//          leds[69] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[69] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[69] = CRGB::Black;
//        }
//      }
//      else if (row == 4)
//      {
//        if (color == 1)
//        {
//          leds[50] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[50] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[50] = CRGB::Black;
//        }
//      }
//      else if (row == 5)
//      {
//        if (color == 1)
//        {
//          leds[45] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[45] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[45] = CRGB::Black;
//        }
//      }
//    }
//    else if (column == 1)
//    {
//      if (row == 0)
//      {
//        if (color == 1)
//        {
//         leds[99] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[99] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[99] = CRGB::Black;
//        }
//      }
//      else if (row == 1)
//      {
//        if (color == 1)
//        {
//          leds[92] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[92] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[92] = CRGB::Black;
//        }
//      }
//      else if (row == 2)
//      {
//        if (color == 1)
//        {
//          leds[75] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[75] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[75] = CRGB::Black;
//        }
//      }
//      else if (row == 3)
//      {
//        if (color == 1)
//        {
//          leds[68] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[68] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[68] = CRGB::Black;
//        }
//      }
//      else if (row == 4)
//      {
//        if (color == 1)
//        {
//          leds[51] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[51] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[51] = CRGB::Black;
//        }
//      }
//      else if (row == 5)
//      {
//        if (color == 1)
//        {
//          leds[44] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[44] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[44] = CRGB::Black;
//        }
//      }
//    }
//    else if (column == 2)
//    {
//      if (row == 0)
//      {
//        if (color == 1)
//        {
//         leds[100] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[100] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[100] = CRGB::Black;
//        }
//      }
//      else if (row == 1)
//      {
//        if (color == 1)
//        {
//          leds[91] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[91] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[91] = CRGB::Black;
//        }
//      }
//      else if (row == 2)
//      {
//        if (color == 1)
//        {
//          leds[76] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[76] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[76] = CRGB::Black;
//        }
//      }
//      else if (row == 3)
//      {
//        if (color == 1)
//        {
//          leds[67] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[67] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[67] = CRGB::Black;
//        }
//      }
//      else if (row == 4)
//      {
//        if (color == 1)
//        {
//          leds[52] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[52] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[52] = CRGB::Black;
//        }
//      }
//      else if (row == 5)
//      {
//        if (color == 1)
//        {
//          leds[43] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[43] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[43] = CRGB::Black;
//        }
//      }
//    }
//    else if (column == 3)
//    {
//      if (row == 0)
//      {
//        if (color == 1)
//        {
//         leds[101] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[101] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[101] = CRGB::Black;
//        }
//      }
//      else if (row == 1)
//      {
//        if (color == 1)
//        {
//          leds[90] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[90] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[90] = CRGB::Black;
//        }
//      }
//      else if (row == 2)
//      {
//        if (color == 1)
//        {
//          leds[77] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[77] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[77] = CRGB::Black;
//        }
//      }
//      else if (row == 3)
//      {
//        if (color == 1)
//        {
//          leds[66] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[66] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[66] = CRGB::Black;
//        }
//      }
//      else if (row == 4)
//      {
//        if (color == 1)
//        {
//          leds[53] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[53] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[53] = CRGB::Black;
//        }
//      }
//      else if (row == 5)
//      {
//        if (color == 1)
//        {
//          leds[42] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[42] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[42] = CRGB::Black;
//        }
//      }
//    }
//    else if (column == 4)
//    {
//      if (row == 0)
//      {
//        if (color == 1)
//        {
//         leds[102] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[102] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[102] = CRGB::Black;
//        }
//      }
//      else if (row == 1)
//      {
//        if (color == 1)
//        {
//          leds[89] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[89] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[89] = CRGB::Black;
//        }
//      }
//      else if (row == 2)
//      {
//        if (color == 1)
//        {
//          leds[78] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[78] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[78] = CRGB::Black;
//        }
//      }
//      else if (row == 3)
//      {
//        if (color == 1)
//        {
//          leds[65] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[65] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[65] = CRGB::Black;
//        }
//      }
//      else if (row == 4)
//      {
//        if (color == 1)
//        {
//          leds[54] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[54] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[54] = CRGB::Black;
//        }
//      }
//      else if (row == 5)
//      {
//        if (color == 1)
//        {
//          leds[41] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[41] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[41] = CRGB::Black;
//        }
//      }
//    }
//    else if (column == 5)
//    {
//      if (row == 0)
//      {
//        if (color == 1)
//        {
//         leds[103] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[103] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[103] = CRGB::Black;
//        }
//      }
//      else if (row == 1)
//      {
//        if (color == 1)
//        {
//          leds[88] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[88] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[88] = CRGB::Black;
//        }
//      }
//      else if (row == 2)
//      {
//        if (color == 1)
//        {
//          leds[79] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[79] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[79] = CRGB::Black;
//        }
//      }
//      else if (row == 3)
//      {
//        if (color == 1)
//        {
//          leds[64] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[64] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[64] = CRGB::Black;
//        }
//      }
//      else if (row == 4)
//      {
//        if (color == 1)
//        {
//          leds[55] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[55] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[55] = CRGB::Black;
//        }
//      }
//      else if (row == 5)
//      {
//        if (color == 1)
//        {
//          leds[40] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[40] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[40] = CRGB::Black;
//        }
//      }
//    }
//    else if (column == 6)
//    {
//      if (row == 0)
//      {
//        if (color == 1)
//        {
//         leds[104] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[104] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[104] = CRGB::Black;
//        }
//      }
//      else if (row == 1)
//      {
//        if (color == 1)
//        {
//          leds[87] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[87] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[87] = CRGB::Black;
//        }
//      }
//      else if (row == 2)
//      {
//        if (color == 1)
//        {
//          leds[80] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[80] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[80] = CRGB::Black;
//        }
//      }
//      else if (row == 3)
//      {
//        if (color == 1)
//        {
//          leds[63] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[63] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[63] = CRGB::Black;
//        }
//      }
//      else if (row == 4)
//      {
//        if (color == 1)
//        {
//          leds[56] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[56] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[56] = CRGB::Black;
//        }
//      }
//      else if (row == 5)
//      {
//        if (color == 1)
//        {
//          leds[39] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds[39] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds[39] = CRGB::Black;
//        }
//      }
//    }
//  }
//  if (screen == 2)
//  {
//    if (column == 0)
//    {
//      if (row == 0)
//      {
//        if (color == 1)
//        {
//         leds2[39] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[39] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[39] = CRGB::Black;
//        }
//      }
//      else if (row == 1)
//      {
//        if (color == 1)
//        {
//          leds2[56] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[56] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[56] = CRGB::Black;
//        }
//      }
//      else if (row == 2)
//      {
//        if (color == 1)
//        {
//          leds2[63] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[63] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[63] = CRGB::Black;
//        }
//      }
//      else if (row == 3)
//      {
//        if (color == 1)
//        {
//          leds2[80] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[80] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[80] = CRGB::Black;
//        }
//      }
//      else if (row == 4)
//      {
//        if (color == 1)
//        {
//          leds2[87] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[87] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[87] = CRGB::Black;
//        }
//      }
//      else if (row == 5)
//      {
//        if (color == 1)
//        {
//          leds2[104] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[104] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[104] = CRGB::Black;
//        }
//      }
//    }
//    else if (column == 1)
//    {
//      if (row == 0)
//      {
//        if (color == 1)
//        {
//         leds2[40] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[40] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[40] = CRGB::Black;
//        }
//      }
//      else if (row == 1)
//      {
//        if (color == 1)
//        {
//          leds2[55] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[55] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[55] = CRGB::Black;
//        }
//      }
//      else if (row == 2)
//      {
//        if (color == 1)
//        {
//          leds2[64] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[64] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[64] = CRGB::Black;
//        }
//      }
//      else if (row == 3)
//      {
//        if (color == 1)
//        {
//          leds2[79] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[79] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[79] = CRGB::Black;
//        }
//      }
//      else if (row == 4)
//      {
//        if (color == 1)
//        {
//          leds2[88] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[88] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[88] = CRGB::Black;
//        }
//      }
//      else if (row == 5)
//      {
//        if (color == 1)
//        {
//          leds2[103] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[103] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[103] = CRGB::Black;
//        }
//      }
//    }
//    else if (column == 2)
//    {
//      if (row == 0)
//      {
//        if (color == 1)
//        {
//         leds2[41] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[41] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[41] = CRGB::Black;
//        }
//      }
//      else if (row == 1)
//      {
//        if (color == 1)
//        {
//          leds2[54] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[54] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[54] = CRGB::Black;
//        }
//      }
//      else if (row == 2)
//      {
//        if (color == 1)
//        {
//          leds2[65] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[65] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[65] = CRGB::Black;
//        }
//      }
//      else if (row == 3)
//      {
//        if (color == 1)
//        {
//          leds2[78] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[78] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[78] = CRGB::Black;
//        }
//      }
//      else if (row == 4)
//      {
//        if (color == 1)
//        {
//          leds2[89] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[89] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[89] = CRGB::Black;
//        }
//      }
//      else if (row == 5)
//      {
//        if (color == 1)
//        {
//          leds2[102] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[102] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[102] = CRGB::Black;
//        }
//      }
//    }
//    else if (column == 3)
//    {
//      if (row == 0)
//      {
//        if (color == 1)
//        {
//         leds2[42] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[42] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[42] = CRGB::Black;
//        }
//      }
//      else if (row == 1)
//      {
//        if (color == 1)
//        {
//          leds2[53] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[53] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[53] = CRGB::Black;
//        }
//      }
//      else if (row == 2)
//      {
//        if (color == 1)
//        {
//          leds2[66] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[66] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[66] = CRGB::Black;
//        }
//      }
//      else if (row == 3)
//      {
//        if (color == 1)
//        {
//          leds2[77] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[77] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[77] = CRGB::Black;
//        }
//      }
//      else if (row == 4)
//      {
//        if (color == 1)
//        {
//          leds2[90] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[90] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[90] = CRGB::Black;
//        }
//      }
//      else if (row == 5)
//      {
//        if (color == 1)
//        {
//          leds2[101] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[101] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[101] = CRGB::Black;
//        }
//      }
//    }
//    else if (column == 4)
//    {
//      if (row == 0)
//      {
//        if (color == 1)
//        {
//         leds2[43] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[43] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[43] = CRGB::Black;
//        }
//      }
//      else if (row == 1)
//      {
//        if (color == 1)
//        {
//          leds2[52] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[52] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[52] = CRGB::Black;
//        }
//      }
//      else if (row == 2)
//      {
//        if (color == 1)
//        {
//          leds2[67] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[67] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[67] = CRGB::Black;
//        }
//      }
//      else if (row == 3)
//      {
//        if (color == 1)
//        {
//          leds2[76] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[76] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[76] = CRGB::Black;
//        }
//      }
//      else if (row == 4)
//      {
//        if (color == 1)
//        {
//          leds2[91] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[91] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[91] = CRGB::Black;
//        }
//      }
//      else if (row == 5)
//      {
//        if (color == 1)
//        {
//          leds2[100] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[100] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[100] = CRGB::Black;
//        }
//      }
//    }
//    else if (column == 5)
//    {
//      if (row == 0)
//      {
//        if (color == 1)
//        {
//         leds2[44] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[44] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[44] = CRGB::Black;
//        }
//      }
//      else if (row == 1)
//      {
//        if (color == 1)
//        {
//          leds2[51] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[51] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[51] = CRGB::Black;
//        }
//      }
//      else if (row == 2)
//      {
//        if (color == 1)
//        {
//          leds2[68] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[68] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[68] = CRGB::Black;
//        }
//      }
//      else if (row == 3)
//      {
//        if (color == 1)
//        {
//          leds2[75] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[75] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[75] = CRGB::Black;
//        }
//      }
//      else if (row == 4)
//      {
//        if (color == 1)
//        {
//          leds2[92] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[92] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[92] = CRGB::Black;
//        }
//      }
//      else if (row == 5)
//      {
//        if (color == 1)
//        {
//          leds2[99] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[99] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[99] = CRGB::Black;
//        }
//      }
//    }
//    else if (column == 6)
//    {
//      if (row == 0)
//      {
//        if (color == 1)
//        {
//         leds2[45] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[45] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[45] = CRGB::Black;
//        }
//      }
//      else if (row == 1)
//      {
//        if (color == 1)
//        {
//          leds2[50] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[50] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[50] = CRGB::Black;
//        }
//      }
//      else if (row == 2)
//      {
//        if (color == 1)
//        {
//          leds2[69] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[69] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[69] = CRGB::Black;
//        }
//      }
//      else if (row == 3)
//      {
//        if (color == 1)
//        {
//          leds2[74] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[74] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[74] = CRGB::Black;
//        }
//      }
//      else if (row == 4)
//      {
//        if (color == 1)
//        {
//          leds2[93] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[93] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[93] = CRGB::Black;
//        }
//      }
//      else if (row == 5)
//      {
//        if (color == 1)
//        {
//          leds2[98] = CRGB::Red;
//        }
//        else if (color == 2)
//        {
//          leds2[98] = CRGB::Yellow;
//        }
//        else if (color == 0)
//        {
//          leds2[98] = CRGB::Black;
//        }
//      }
//    }
//  }
//}

