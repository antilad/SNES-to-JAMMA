SNES to JAMMA
=============

This is an Arduino project which allows you to interface a SNES or Super Famicom controller
(or a clone) to a Neo Geo style DB15 connector.

This is a fork of Robin Edwards' SNES to Neo Geo project that was modified to allow the
use of the SNES controller in 6 button games such as Street Fighter II and others.

![Image](ProMini.jpg?raw=true)

This shows a completed project on a cheap Arduino Pro Mini (5v) clone wired up to a SNES female
socket and female DB15 for easy connections.

SNES female controller sockets are available on eBay for a couple of pounds, and a Pro Mini
clone costs about the same, so the total cost of the project is only about five pounds.

SNES Controller -> Arduino
--------------------------

```
  -----------------\
  | 1 2 3 4 | 5 6 7 |
  -----------------/
  
  Pin 1: +5V
  Pin 2: Clock -> Arduino A0
  Pin 3: Latch -> Arduino A1
  Pin 4: Serial -> Arduino A2
  Pin 7: GND
```

Arduino -> DB15
---------------

```
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
```

3d printed case
---------------

I am using this integrated into the wiring of my supergun but Robin has designed a simple
box for the device that can be 3d printed. It fits the Pro Mini inside along with the SNES
socket and a cable grip for a DB15 cable.

The case is designed to fit a cable grip extracted from a UK mains plug (with 16mm spacing between
the grip screws).

The STL files are included here along with the source SCAD files if you need to make any tweaks to
the design.

![Image](3dPrint.jpg?raw=true)

![Image](3dPrint2.jpg?raw=true)

