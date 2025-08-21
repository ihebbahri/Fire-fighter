# Fire-fighter

## Overview
Fire-fighter is a robotics project designed to detect and extinguish fires autonomously. It combines mechanical design, electronics, and embedded programming to create a functional fire-fighting robot prototype.

## Features
- Autonomous fire detection using sensors
- Fire extinguishing mechanism
- Arduino-based control system
- Modular mechanical design (see `conception/` for CAD files)

## Hardware
- Arduino board
- Flame sensors
- Motors and actuators
- Fire extinguishing module (e.g., water pump or CO2)
- Chassis and mechanical parts (see `conception/Assemblage1.SLDASM`)

## Software
- Main control code: [`fire_fighter/fire_fighter.ino`](fire_fighter/fire_fighter.ino)
- Written in Arduino C++

## Setup
1. Assemble the robot using the CAD files in the `conception/` folder.
2. Connect all electronic components as described in the code comments.
3. Upload the code from `fire_fighter/fire_fighter.ino` to the Arduino board using the Arduino IDE.

## Usage
1. Power on the robot.
2. The robot will automatically scan for fire sources and attempt to extinguish them.
3. Monitor and maintain hardware as needed.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.