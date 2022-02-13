/*
 Name:		ODB2_Longan_Serial_CAN_BUS_Test.ino
 Created:	1/17/2022 8:21:40 AM
 Author:	Micro
*/

// SEND EXAMPLE OF SERIAL CAN MODULE
// unsigned char send(unsigned long id, uchar ext, uchar rtrBit, uchar len, const uchar *buf);
// SUPPORT: joney.sui@longan-labs.cc
#include <Serial_CAN_Module.h>
#include <SoftwareSerial.h>

Serial_CAN can;

#define can_tx  2           // tx of serial can module connect to D2
#define can_rx  3           // rx of serial can module connect to D3

void setup()
{
  Serial.begin(250000);
  delay(10);
  // NOTE: Maximum is 38400 otherwise I have detected errors in teh ID field
  can.begin(can_tx, can_rx, SERIAL_RATE_9600);      // tx, rx
  Serial.println("begin");

  //can.factorySetting();
  
  while (!Serial);

  if (can.baudRate(SERIAL_RATE_38400))
  {
    Serial.println("set baud rate ok");
  }
  else
  {
    Serial.println("set baud rate fail");
  }
  
  // Note BUS must be connected to successfully set CAN Rate
  if (can.canRate(CAN_RATE_125)) {
    Serial.println("set CAN rate ok");
  }
  else
  {
    Serial.println("set CAN rate fail");
  }
 
  
}

unsigned char dta[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
unsigned long dtaCounter = 0;

// send(unsigned long id, byte ext, byte rtrBit, byte len, const byte *buf);
void loop()
{
  // Create loop timer
  unsigned long timer = micros();
  
  // Increase the counter
  dtaCounter++;
  if (dtaCounter == 1099511627775) dtaCounter = 0;

  //Parse that dtaCounter into values
  dta[7] = dtaCounter;
  dta[6] = dtaCounter >> 8;
  dta[5] = dtaCounter >> 16;
  dta[4] = dtaCounter >> 24;
  dta[3] = dtaCounter >> 32;
  //dta[2] = dtaCounter >> 40;
  //dta[1] = dtaCounter >> 48;
  //dta[0] = dtaCounter >> 56;
  
  
  can.send(0x0145, 0, 0, 8, dta);   // SEND TO ID:0X55
  //Serial.print("Sending: ");
  //Serial.print(0x0145, HEX);
  //Serial.print(" ");
  //Serial.print("00 00 08 ");
  //for (int i = 0; i <8; i++) {
  //  Serial.print(dta[i]); Serial.print(" ");
  //}
  //Serial.println("");
  
  // Delay loop


  // It should take around 222uS to send a packet, the Nano can not run fast enough
  while (micros() - timer < 4000) {}

  // report loop time - if its more than 4000uS then the nano took longer to send the data
  unsigned long loopTime = micros() - timer;
  dta[2] = loopTime >> 0;
  dta[1] = loopTime >> 8;
  dta[0] = loopTime >> 16;

}

// END FILE