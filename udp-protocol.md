
first two bytes: Device ID

* 0x00 -- hub
* 0x01 -- orange stick
* 0x02 -- yellow stick
* 0x03 -- Pants
* 0x04 -- Belt

second byte: type

* 0x01 : command
* 0x01 : light
* 0x02 : sound
* 0x03 : color

3rd+ bytes: data

* commands:
  * 0x00: reboot
  * 0x01: darklight mode
    * second byte: 0x00 off, 0x01 on
  * 0x02: rainbow mode
    * second byte: 0x00 off, 0x01 on
* light
  * one byte of ambient light data
* sound
  * one byte of ambient sound levels
* color
  * three bytes: Red, green, blue   