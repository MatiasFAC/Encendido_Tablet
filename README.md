
Simple project that aims to turn on electronic devices.

Requirements:
- IDE Arduino
- RTClib library
- RTC ZS-042
-	Arduino
- PC817C

Connection diagram:
- Arduino -> RTC
  * 5V -> VCC
  * GND -> GND
  * SCL -> SCL
  * SDA -> SDA
- Arduino -> PC817C
  * PIN 7 -> anode
  * GND -> cathode
- PC817C -> electronic device
