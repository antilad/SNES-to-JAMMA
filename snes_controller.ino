/*
SNES -> JAMMA
antilad 2020
forked from Robin Edwards' SNES-to-NeoGeo project 2018
based on the code found at https://github.com/burks10/Arduino-SNES-Controller
*/

/* 

SNES Controller -> Arduino
  -----------------\
  | 1 2 3 4 | 5 6 7 |
  -----------------/
  
  Pin 1: +5V
  Pin 2: Clock -> Arduino A0
  Pin 3: Latch -> Arduino A1
  Pin 4: Serial -> Arduino A2
  Pin 7: GND
*/

int DATA_CLOCK    = A0;
int DATA_LATCH    = A1;
int DATA_SERIAL   = A2;

/* 

Arduino -> DB15
    1(=GND)        8(=5V)
  \-------------------/
   \ o o o o o o o o / [Viewed from front]
    \ o o o o o o o /
     --------------- 
      9          15

 DB15 Pin  ->  Arduino
 --------      -------
 1 (GND)       GND
 8 (+5V)       +5V
 3 (Coin)      D2
 11 (Start)    D3
 15 (Up)       D4
 7 (Down)      D5
 14 (Left)     D6
 6 (Right)     D7
 13 (1)        D8
 5 (2)         D9
 12 (3)        D10
 4 (4)         D11
 10 (5)        D12
 2 (6)         D13
*/

#define PIN_COIN    2
#define PIN_START   3
#define PIN_UP      4
#define PIN_DOWN    5
#define PIN_LEFT    6
#define PIN_RIGHT   7
#define PIN_BUT1    8
#define PIN_BUT2    9
#define PIN_BUT3    10
#define PIN_BUT4    11
#define PIN_BUT5    12
#define PIN_BUT6    13

int buttons_state[12];  // B,Y,Sel,Start,U,D,L,R,A,X,L,R
int output_pins[12] = { PIN_BUT4, PIN_BUT1, PIN_COIN, PIN_START, PIN_UP, PIN_DOWN,
                        PIN_LEFT, PIN_RIGHT, PIN_BUT5, PIN_BUT2, PIN_BUT3, PIN_BUT6 };
void setup ()
{
    pinMode(DATA_CLOCK, OUTPUT);
    digitalWrite (DATA_CLOCK, HIGH);
  
    pinMode(DATA_LATCH, OUTPUT);
    digitalWrite(DATA_LATCH, LOW);
    
    pinMode(DATA_SERIAL, INPUT_PULLUP);
}

void loop ()
{
    // Read from the SNES controller
    
    /* Latch for 12us */
    digitalWrite(DATA_LATCH, HIGH);
    delayMicroseconds(12);
    digitalWrite(DATA_LATCH, LOW);
    delayMicroseconds(6);
    
    /* Read data bit by bit from SR */
    for (int i = 0; i < 16; i++) {
        digitalWrite(DATA_CLOCK, LOW);
        delayMicroseconds(6);
        if (i <= 11)
            buttons_state[i] = digitalRead(DATA_SERIAL);
        digitalWrite(DATA_CLOCK, HIGH);
        delayMicroseconds(6);
    }
    
    // Output the state on our DB15 output pins
    // pulling them low if the equivalent SNES button
    // is pushed
    for (int i = 0; i <= 11; i++)
    {
        if (output_pins[i] != 0)
        {
            if (!buttons_state[i])
            {
                digitalWrite(output_pins[i], LOW);
                pinMode(output_pins[i], OUTPUT);
            }
            else
                pinMode(output_pins[i], INPUT);            
        }
    }
    
    delay(5);
}
