
# GR1_maygapgaubong - Crane Machine

## Introduction 

This repository contains the code and hardware design for a graduation research project titled "Rebuilding and Simulating a Crane Machine using ESP32". The project focuses on the development of software and hardware to recreate the functionality of a traditional claw machine.

## Objective

Create Crane machine simulation using ESP32 which is compatible with real system.

## Functionality

There are 6 movements: 
- Front and back - one DC motor (X-axis)
- Left and right - one DC motor (y-axis)
- Up, grab and down, spit out - one DC motor (z-axis) 

## System Architecture

### Hardware Components:

- Microcontroller: ESP32
- 3 DC Motors: For X, Y, and Z-axis movements.
- 6 buttons: For 6 movements.
- 2 TestBoard: For testing and debugging hardware
- Wires and headers 2.0 and headers 2.5
- Power Supply and Drivers: Motor drivers (), 5V and 10V power supplies as required.

### Software Components:

- Language: C/C++ in the Arduino IDE.
- Libraries: ESP32 Core for Arduino: 
    - Required board support package.
    - Wi-Fi/Bluetooth Libraries (Optional): For wireless control updates.

## Installation Guide
### Development Environment Setup:

- Install Arduino IDE.
- Add the ESP32 Board using the Boards Manager (Instructions: ESP32 Arduino Core).

### Library Installation:

- Open Arduino IDE and go to Sketch > Include Library > Manage Libraries...
- Search and install the required libraries (optionally) Wi-Fi/Bluetooth.

### Flashing the Firmware:

- Connect the ESP32 via USB.
- In Tools > Board, select your ESP32 board (e.g., "ESP32 Dev Module").
- In Tools > Port, select the appropriate COM port.
- Click Upload to flash the code.

## Usage
- After uploading the firmware and powering the system, the claw machine will initialize.
- Use buttons to move the claw to the desired position.

## Maintenance & Upgrades
- Regularly inspect wiring, tighten screws and bolts.
- Adjust motor driver settings (normally the input voltage or supplying voltage) if torque or speed optimization is needed.

## Troubleshooting
- ESP32 Connection Issues: Check USB cable, drivers, and COM port settings.
- Motor Not Running: Verify power supply, wiring, and pin configurations.

## Acknowledgements

 - [Schematic of ESP32](https://docs.espressif.com/projects/esp-hardware-design-guidelines/en/latest/esp32c3/schematic-checklist.html)
 - [Arduino IDE for ESP32](https://randomnerdtutorials.com/projects-esp32/)
 - [ESP32-C3 pinouts](https://docs.espressif.com/projects/esp-idf/en/v5.0/esp32c3/hw-reference/esp32c3/user-guide-devkitm-1.html) 
