# How to Re-flash the Bootloader on the Pro Trinket

**Important!**  
**The Pro Trinkets we're using are 3.3V, so remember to set the series resistors and use the right Arduino sketch to flash the bootloaders.**

* First, have a look at [this tutorial](https://learn.adafruit.com/introducing-pro-trinket/re-programming-bootloader).
* Build the circuit in a breadboard, and connect the Arduino Uno to your laptop.
* Flash the Arduino Uno.
* Then open the Serial Monitor of the Arduino, and choose the right baudrate (57600)
* On the top of the Serial Monitor, on the text field, type a G, and hit enter.
* The Pro Trinket should blink red now :)
* Now you can remove the Pro Trinket, and connect it to the USB/Serial adaptor.
* Install the Adafruit boards on the Arduino IDE, by simply following [this tutorial](https://learn.adafruit.com/adafruit-arduino-ide-setup/arduino-1-dot-6-x-ide).
* Important! To flash it, first you need to press the button on the Pro Trinket.
* If something goes wrong, verify that you have the following configuration on the Arduino IDE:
	* Board: Pro Trinket 3V/12MHz (FTDI)
	* Programmer: USBtinyISP
	* Port: `/dev/cu.SLAB_USBtoUART`
