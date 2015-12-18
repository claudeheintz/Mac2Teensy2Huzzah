/* 
 *  Mac2Teensy2HuzzahSerialBridge
 *  by Claude Heintz 2015
 *
 *  This sketch allows a Teensy 2.0++ to be used as a serial
 *  connection between a Mac running OS X 10.11 and an
 *  Adafruit ESP8266 Huzzah so that a program can be uploaded
 *  from the Arduino IDE.
 *  
 *  The Teensy is connected to the Huzzah serial header using 4
 *  jumpers:
 *  
 *  Teensy GND to Huzzah serial header pin 1 (GND)
 *  Teensy +5v to Huzzah serial header pin 3 (Vcc)
 *  Teensy D2 (RX) to Huzzah serial header pin 5 (TX)
 *  Teensy D3 (TX) to Huzzah serial header pin 4 (RX)
 *  
 *  For uploading also make the following connections with jumpers:
 *      connect Huzzah GPIO2 to V+ 
 *      connect Huzzah GPIO0 to GND
 *      
 *  After making these connections on a breadboard, plug the Teensy
 *  into the Mac with a USB cable.  The Teensy will act as a serial
 *  bridge so that a program can be uploaded to the Huzzah.
 *  
 *  After flash upload is complete, disconnect
 *  the GPIO2 & GPIO0 jumpers.
 */

uint8_t abite;
int led = 6;	//built-in LED on Teensy 2.0++

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  if ( Serial.available() ) {
    abite = Serial.read();
    Serial1.write(abite);
    digitalWrite(led, HIGH);
  }
  if ( Serial1.available() ) {
    abite = Serial1.read();
    Serial.write(abite);
    digitalWrite(led, LOW);
  }
}
