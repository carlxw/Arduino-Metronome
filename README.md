# Arduino-Metronome
![Diagram of circuit](https://github.com/carlxw/Arduino-Metronome/blob/main/Diagram.png?raw=true)

This is a metronome created using an Arduino because my family's physical metronome is broken and using an online metronome is boring. I prototyped this project in TinkerCAD.

[Schematic](Arduino_Metronome_Schematic.pdf)

[//]: <> (https://www.tablesgenerator.com/markdown_tables)
## Components Used
| Component               | Quantity |
|-------------------------|----------|
| Arduino UNO R3          | x1       |
| Push button             | x3       |
| Piezo buzzer (4-8v)     | x1       |
| 10k ohm resistor        | x3       |
| 100 ohm resistor        | x1       |
| LCD 16x2 (I2C)          | x1       |

## How To Use
* Increment or decrement BPM by 1 on button tap
* Increment or decrement BPM by 10 on button hold
* Reset to starting BPM (as defined by config.h) by pressing both increment and decrement buttons simultaneously
* Button to toggle metronome counting on and off
* Display informs user of the currently set BPM
* Display counts the "pulses" of the metronome

## Configurable Parameters
* GPIO pins for buttons and speaker
* Maximum BPM
* Minimum BPM
* Button hold time for incrementing or decrementing BPM by 10
* Default BPM
* Pulse character (on metronome beep)
* Button debounce time

## Demo
[Google Drive](https://drive.google.com/file/d/1ULIn-E9Hc5SD78-cg4Jfz9MGziXxmkPd/view?usp=sharing)