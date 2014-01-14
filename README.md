Arduibq
=======

Author
------

kcgolden (github)

License
-------

This project is licensed under a standard MIT license. See the License file for further details.

About
-----

Arduibq is an arduino based, automated bbq bellows that regulates air to the bbq firebox in order to maintain a target temperature in the pit. It is a lot more simplistic in design and electronics than some much more extensive projects out there, such as the [heatermeter] (https://github.com/CapnBry/HeaterMeter/wiki) which incorporates many more features, including a raspberry pi for web-based reporting. The goal of Arduibq is to simply provide the ability to control the bbq pit temperature within reasonable parameters while requiring as few hardware and electronic components as possible.

General Parts Required
----------------------

  1. 1M Ohm Resistor
  2. [Maverick BBQ Probe ET-732](http://www.amazon.com/Maverick-ET732-Replacement-Chamber-Probe/dp/B006XLWL7K/ref=sr_1_4?ie=UTF8&qid=1389661984&sr=8-4&keywords=ET-732)
  3. 10 uF Capacitor
  4. 3/32" Mono Jack for the probe
  5. 5v Relay Module for arduino. I used: [SunFounder 2 Channel 5V Relay Shield Module](http://www.amazon.com/gp/product/B00E0NTPP4/ref=oh_details_o01_s00_i01?ie=UTF8&psc=1)
  6. 12v case blower fan, such as: [Rosewill RFX-100 90mm Case Fan](http://www.amazon.com/gp/product/B00552Q7SC/ref=oh_details_o08_s00_i00?ie=UTF8&psc=1)
  7. A power jack with a matching solderable connector for the fan
  8. A small prototyping board for wiring the components together
  9. 12v Power supply for arduino
  10. An electronics project case (Recommended)
  11. The [Sainsmart LCD shield](http://www.amazon.com/SainSmart-Keypad-Arduino-Mega2560-Duemilanove/dp/B006OVYI1G)
  
Schematic Notes
---------------

I'm not really an electronics guy and not that interested in figuring out schematic software, allthough I'm sure it's easy enough. I'll instead describe the assembly in plain enough english/pseudo schematic below:

### The Thermometer Input Circuit:
5v Arduino Pin -> 1 M Ohm Resistor -> (Probe +/Arduino Analog Input Pin #1/10uF Capacitor +) -> (Probe -/Capacitor -) -> GRND

In other words, the 5v pin through a 1M Ohm Resistor and the probe in series, with the capacitor in parallel to the probe, with the arduino's Analog #1 taking its input from between the 1M Ohm Resistor and the probe. The purpose of the capacitor in this circuit is to keep the signal from the probe stable. It will go all over the place without it.

### Fan Control Circuit:

The relay is controlled by digital pin #2 and uses the arduino's 5v pin for the relay's Vin Pin. For the fan's voltage, it uses the VIN pin of the arduino (should be 12v if using a 12v supply) as the power for the fan, which is what the relay switches on/off. The ground can go to the arduino's ground, obviously.

### Summary:

There may be a better electronics design and you're welcome to whatever. The software will work as is simply with Analog In #1 as input for the thermistor and Digital #2 for the fan relay control. If you desire to use a different probe than the one listed, know that you will need to change a number of things in the code including the value of the resistor and some tuning values, all of which can be found in Thermometer.cpp.

Attaching the blower to your pit
--------------------------------

The blower goes whereever your damper goes. There are a number of different ways to attach it and you'll have to get creative or use google for ideas. Roof Flashing makes a good material to work with and remember that heat melts plastic so it would be good to keep your fan far enough away from the fire to keep it from melting. Also make sure that the fan is the only source of air for the fire, sealing all but the chimney of the smoker as best you can for best results.

Results to Expect/Hope For
--------------------------

In the tests I've run with this thing, I've attempted to keep my pit temperature at 225. This has generally been the case, with a range of 220 - 235 degrees throughout the cook. This is a far better result than I got when I had to manually adjust the damper all the time, which would result in anything from wild flare-ups above 400 degrees to temperature drops way below target. You will still have to play with the fuel you're adding and when to add it but the automated air control will save you a lot of effort.
