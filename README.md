
Simple project that aims to turn on electronic devices.

Requirements:
- IDE Arduino
- RTClib library
- RTC ZS-042
-	Arduino
- PC817C
-	Resistance

Connection diagram:
- Arduino -> RTC
  * 5V -> VCC
  * GND -> GND
  * SCL -> SCL
  * SDA -> SDA
- Arduino -> PC817C
  * PIN 7 -> resistance -> anode
  * GND -> cathode
- PC817C -> electronic device
