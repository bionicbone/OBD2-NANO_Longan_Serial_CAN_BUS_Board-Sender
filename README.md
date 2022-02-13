# ODB2_Longan_Serial_CAN_BUS_Test
NANO and the Serial CAN BUS Module from Cool Components

Cool Components

Serial CAN Bus Module (https://coolcomponents.co.uk/products/obd-ii-can-bus-development-kit?variant=14053842518077)
16Mhz Board

Needs the Longan-Labs library, needs to set the CAN Driver to 9600 baud !!  (https://github.com/Longan-Labs/Serial_CAN_Arduino)

Lots of examples on the GitHub library page, including setting the can bus speed

RED LEDs will light on the board if the CAN is working OK

Wiki Page Example (https://docs.longan-labs.cc/1030002/)  

No need to worry about the "AT" commands, the new Longan library seems to all setting of baud rates and filters

Looks like the board has an MCU that can be programmed, see https://docs.longan-labs.cc/1030001/ and the section "Working Standalone"

Check out this GitHub also, it has the firmware in (https://github.com/Longan-Labs/Serial_CAN_Bus)

This board is very small and could be the favourite board if I can get the above "standalone" option and Hardware Serial working !!!

It could be worth spending more time with this board

WARNING: Do not set the CAN baud rate higher than 38400 otherwise errors are presented on the bus that +8 to the ID number like this.

ADDED ability to change CAN Bus Speed in this example
