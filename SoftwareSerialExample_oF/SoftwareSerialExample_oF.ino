/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */
#include "Adafruit_Thermal.h"

#include <SoftwareSerial.h>

#define TX_PIN 1 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 0 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first

Adafruit_Thermal printer(&mySerial);
//Adafruit_Thermal printer(&Serial, 4);     // Pass addr to printer constructor

void setup() {
  // Open serial communications and wait for port to open:
  mySerial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


//  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
//  mySerial.println("Hello, world?");
}

void loop() { // run over and over
  if (mySerial.available()) {
    mySerial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(mySerial.read());
  }
}

