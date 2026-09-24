## project title
Real-Time User-Interactive Wireless Dot-Matrix Display System
## Overview
This project is a wireless, user-interactive embedded display system developed using the LPC2148 ARM7 Microcontroller. It allows users to customize and control display patterns on four multiplexed 8×8 dot-matrix LED displays wirelessly using the HC-05 Bluetooth module. The system also integrates real-time temperature monitoring using the LM35 sensor and provides time/date display using the on-chip RTC.
The user interacts with the system through a Bluetooth terminal application on an Android mobile phone, eliminating the need for a wired PC-based HyperTerminal interface. Display modes, text data, and system settings can be stored in EEPROM for future use.

## Features
Wireless control of four 8×8 dot-matrix LED displays using HC-05 Bluetooth module.
Fixed string display.
Fixed string display with blinking.
Scrolling text display.
Real-time time display.
RTC date and time scrolling display.
Real-time temperature display using LM35.
Text editing through Bluetooth.
Time and date editing through Bluetooth.
EEPROM storage for display data and mode status.
Four multiplexed 8×8 dot-matrix LED displays.
Uses 74HC164 serial-in/parallel-out shift registers.
Uses 74HC573 D-type transparent latch.
Wireless communication through UART.
Real-time interaction through an Android Bluetooth terminal application.

The PDF specifies that EEPROM stores the current RUN/EDIT mode, fixed four-character string data, and scrolling string data.

## 📊 Project Block Diagram
![Project Block Diagram](Screenshot%202026-09-24%20170110.png)

The system consists of:

LPC2148 ARM7 Microcontroller as the main controller, connected to:

AT25LC512 EEPROM through SPI
LM35 temperature sensor through ADC
HC-05 Bluetooth module through UART
RTC
Four 74HC164 shift registers
Four 8×8 dot-matrix displays
74HC573 latch

The block diagram in page 1 of the PDF shows the LPC2148 at the center, with EEPROM, LM35, HC-05, RTC, 74HC164 shift registers, 74HC573 latch, and four dot-matrix displays connected around it.

## Hardware Components Used
LPC2148 ARM7 Microcontroller
Four 8×8 Dot Matrix Displays
74HC573 D-Type Transparent Latch
74HCT164 8-bit Serial-In/Parallel-Out Shift Registers
AT25LC512 EEPROM
HC-05 Bluetooth Module
LM35 Temperature Sensor
USB-to-UART Converter
RTC
Android Mobile Phone with Bluetooth Terminal Application

These hardware requirements are listed in the PDF on page 4.

## Software Used
Embedded C Programming
Keil-C Compiler
Flash Magic
Bluetooth Terminal Application
LPC2148 ARM7 Microcontroller development environment

The PDF specifically lists Embedded C Programming, Keil-C Compiler, and Flash Magic as the software requirements.

## Working of the Project
## Step 1: System Initialization

When the LPC2148 system is powered ON, the application initializes the required peripherals and display hardware.

The system prepares:

Dot-matrix display interface.
UART communication for HC-05 Bluetooth.
EEPROM interface.
RTC.
ADC for LM35 temperature measurement.

The application then reads the previously stored RUN/EDIT mode from EEPROM and performs the corresponding operation.

## Step 2: Bluetooth Communication

The HC-05 Bluetooth module provides wireless communication between the LPC2148 and an Android mobile phone.

Instead of using a PC and HyperTerminal, the user operates the system through a Bluetooth terminal application.

The user can send commands and menu selections wirelessly to the LPC2148 through the UART interface.

## Step 3: Display Menu

The system waits for the special character '!' from the Bluetooth terminal.

When the character is received, the following menu is displayed:

1.FIXED STRING
2.FIXED STRING WITH BLINKING
3.STRING WITH SCROLLING
4.TIME DISPLAY
5.RTC DISPLAY WITH SCROLLING
6.TEMPERATURE DISPLAY
7.TEXT EDIT MODE
8.TIME EDIT MODE
9.EXIT

The user selects an option through the Bluetooth terminal, and the corresponding operation is executed on the dot-matrix display.

## Step 4: Fixed String Display

The system can display a fixed four-character string across the four 8×8 dot-matrix displays.

For example:

HELP

Each character can be displayed on a separate dot-matrix module.

The implementation sequence in the PDF first requires displaying one character and then extending it to a four-character string.

 ## Step 5: Blinking String Display

The system can display the stored fixed string with a blinking effect.

The first three display options use the string information stored in EEPROM and display it on the four 8×8 dot-matrix LED modules.

## Step 6: Scrolling String Display

The system supports scrolling text longer than four characters.

Example:

PROJECT SUCCESSFULLY COMPLETED

The text moves across the four dot-matrix displays to create a scrolling effect.

The PDF specifies that the scrolling implementation should support a string of more than 10 characters.

## Step 7: RTC Time Display

The LPC2148 on-chip RTC is used to display the current time.

The application reads the required RTC values and converts the minutes and seconds into a string before displaying them on the dot-matrix LEDs.

Example:

MIN SEC
45 42
45 43
45 44

The time can also be displayed in a scrolling format.

## Step 8: RTC Date and Time Scrolling

The complete RTC information can be converted into a string and displayed as scrolling text.

Example format:

TIME: HH:MM:SS DATE: DD/MM/YY DAY: SUN

Example:

TIME: 09:30:23 DATE:17/04/2015 DAY: FRIDAY

The system reads the required RTC registers and creates the complete date/time string before sending it to the existing scrolling display function.

## Step 9: Temperature Measurement Using LM35

The LM35 temperature sensor is connected to the LPC2148.

The sensor provides an analog temperature signal, which is read using the on-chip ADC of the LPC2148.

The application:

Reads the LM35 sensor.
Converts the ADC reading into temperature.
Updates the temperature periodically.
Displays the temperature on the dot-matrix display.

Example:30°C

The PDF specifies that the temperature value should be updated periodically, such as every one second.

## Step 10: Text Editing

The user can edit display text through the Bluetooth terminal application.

Two types of text are supported:

Fixed Text

Maximum:

4 characters

Scrolling Text

Maximum:

20 characters

The two types of strings are stored at different EEPROM memory locations.

## Step 11: Time and Date Editing

The user can also update the RTC time and date through the Bluetooth terminal.

The specified input format is:

SS:MM:HH DAY DD/MM/YY

Example:

22:10:09 01 27/02/15

Day values are:

01 - SUN
02 - MON
03 - TUE
04 - WED
05 - THU
06 - FRI
07 - SAT

The valid ranges specified in the PDF are:

Seconds : 00-59
Minutes : 00-59
Hours   : 00-23
Day     : 01-07
Date    : 01-31
Month   : 01-12
Year    : 00-99

The updated values are stored in the corresponding RTC registers.

Dot Matrix Display Interface

The four 8×8 dot-matrix displays use 74HC164 shift registers for column control and a 74HC573 latch for row control.

74HC164 Connections
Display	DSA	CP
Display 1	P0.8	P0.9
Display 2	P0.10	P0.11
Display 3	P0.12	P0.13
Display 4	P0.14	P0.15

The Q0–Q7 outputs of each 74HC164 are connected to COL1–COL8 of the corresponding dot-matrix display.

74HC573 Connections

The 74HC573 receives its data from LPC2148 Port 0:

D0 → P0.0
D1 → P0.1
D2 → P0.2
D3 → P0.3
D4 → P0.4
D5 → P0.5
D6 → P0.6
D7 → P0.7

Its Q0–Q7 outputs control ROW8 through ROW1 of the dot-matrix display.

EEPROM Storage

EEPROM is used to store important user configuration data.

The system stores:

Current mode status — RUN / EDIT
Fixed 4-character string
Scrolling string

When the system is powered ON, the application reads the stored mode from EEPROM and continues operation according to the saved mode.

This flow follows the project sequence described in the PDF.

## Project Implementation Sequence

The PDF recommends implementing the project step by step:

Create the project folder.
Display one character on a single dot-matrix LED.
Display a four-character string.
Implement scrolling text.
Develop UART Bluetooth communication using HC-05.
Handle Bluetooth transmit and receive using serial interrupts.
Display the menu on the Bluetooth terminal.
Implement fixed, blinking and scrolling string options.
Implement time display.
Implement RTC scrolling display.
Implement LM35 temperature display.
Implement text editing.
Implement time/date editing.
Integrate all functions into the final project.

## Hardware Project Output
![Project Block Diagram](Screenshot%202026-09-24%20170441.png)

## The system provides the following outputs:

Wireless control through Bluetooth.
Fixed four-character display.
Blinking text display.
Scrolling text display.
Real-time time display.
Real-time date and time scrolling.
Temperature display using LM35.
Editable fixed and scrolling text.
Editable RTC time and date.
EEPROM-based storage of configuration and display data.
Real-time user interaction through an Android Bluetooth terminal.

## Applications

Based on the project capabilities, possible applications include:

Digital information display systems
Wireless notice boards
Industrial display systems
Public information displays
Temperature monitoring displays
Educational embedded display systems
Wireless programmable LED displays
Real-time clock displays

## Future Improvements

Upgrade Bluetooth communication to Wi-Fi or IoT-based cloud connectivity.
Enable remote control through a web or mobile application.
Interconnect multiple display units to create larger scalable display boards.
Add sensors such as humidity, gas and light sensors.
Develop mobile application-based GUI control.
Add password-protected secure access.
Add real-time data logging to cloud servers.
Add voice-controlled display updates.
Integrate the system with smart-city infrastructure.
