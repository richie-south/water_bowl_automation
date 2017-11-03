# water_bowl_automation

This is an automatic water refill:er for the cat water bowl.

## How it's built

The project consist of 3 main parts, 1 arduino uno rev 3 (will be replaced with an arduino micro), 1 water tank with servo controlled valve and one water level sensor.


## How it works

The program on the arduino checks the water level every 10sec. If the water level is below a certain level the program waits for 8 minutes then it checks again. This is to minimize the risk of the cat drinking water while the system refills the bowl. After the 8 min the program will open the valve to the tank and check the water level sensor untill the bowl is full. When the sensor detects that the bowl is full the program will close the valve and sleep for 5 hours then continue to check the water level every 10sec. If the valve has been open for 9 or more secs the valve will close and the program will "shutdown". this precaution is so that the system wont empty all the water on the floor if an error occurs.


## Part 1
Connect servo to water tank valve.

<img src="https://raw.githubusercontent.com/richie-south/water_bowl_automation/master/media/part_1.gif" width="320">

## Part 2

Read water level from seosor and open valve if low on water.

<img src="https://raw.githubusercontent.com/richie-south/water_bowl_automation/master/media/part_2.gif" width="320">

## Part 3

Connect the dots.. Read water level from sensor, if water level in bowl is to low, open valve, close valve when water is at fixed level.

<img src="https://raw.githubusercontent.com/richie-south/water_bowl_automation/master/media/part_3.gif" width="320">

## TODO / Future work

 - add countdown display, should display following.
   - Time left to refill.
   - Time left until program starts checking every 10 sec again.
   - If program has "shutdown" and needs a restart.
 - WIFI module that should send info to a rest api on every program event eg, refilling bowl, program "shutdown"...
