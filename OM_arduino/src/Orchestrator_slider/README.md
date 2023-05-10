# Objective 
* To  test Z-Axis stepper motor and Belt Pully Stepper motor of Orchestrator using the TMC2208 stepper driver.
* This program is suitable for single stepper therefore we will test one stepper at a time.

# Setup

# Wiring 

## For Z- axis Stepper

| Motor Pin | TM2208 Pin |
| --------- | ---------- |
| BLUE      | M2B        |
| RED       | M2A        |
| GREEN     | M1A        |
| BLACK     | M1B        |

## For Belt Pully Stepper

| Motor Pin | TM2208 Pin |
| --------- | ---------- |
|GREEN      | M2B        |
| BLACK     | M2A        |
| RED     	| M1A        |
| BLUE    	| M1B        |

| Arduino DUE | TMC2208 Pin |
| ----------- | ----------- |
| 7           | STEP        |
| 6           | DIR         |
| 13          | EN          |
| GND         | GND         |
| +5V         | MS1         |
| +5V         | MS2         |
| +5V	 	  | VIO         |


* Connect 47uF ,50V( at least 10uF, 20 V or above) decoupling capacitor across VM and GND pin.
* Give voltage according to stepper() to VM from DC supply, current 0.5A max limit.
* Pin 3, 8 are digital interrupt pingenrally triggered at falling edge  
* Connect limit switches to Arduino Pin 3 and 8 and other terminal of switch to GND.
* Outward limit switch(away from stepper) to Pin 3, Inward limit switch(near the stepper) to Pin 8.
* External pullup is not required for interrupt pins.
![orchestrator](https://user-images.githubusercontent.com/86110190/140879789-e1691f78-2729-4304-b594-64528e43d7b9.jpeg)



# Programming the Due

* Open VS code
* Open `Genotyper Models\GenotyperToolbox\StandaloneArduinoPrograms` folder.
* ``` \src\Orchestrator_slider ```
* Set the ``` env: Orchestrator_sliders``` then upload
* To change the speed of the motor we have to change the ```MAXSPEED``` inside the ```Utils.h```
* Direction of the motor can be controlled from the input given through the serial monitor.
* Motor will stop as soon as it hits any of the limit switch.
* ![slider](https://user-images.githubusercontent.com/86110190/136330515-bc2e13d4-5e5f-489a-9bc7-a6ff0271e8ab.JPG)
* ![speed_change](https://user-images.githubusercontent.com/86110190/136331179-76107531-8331-40ce-99bf-ff82fb075626.JPG)

# Troubleshoot
* If powering on the motor makes the DC supply go to CC mode then try to adjust the current limit on the driver pcb by rotating the pot.
* Cross check the wiring of motor coils. Collour comibination may vary for steppers.
* Check the coils by checking the continuity of coils.

