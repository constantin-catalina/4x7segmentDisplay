# AVR Timer-Based Millisecond Counter with 4-Digit Display
## Overview

This AVR microcontroller project uses Timer1 with interrupts to count milliseconds since startup with a 10ms resolution, displaying the time in SS:MM format on a 4-digit 7-segment display.

* SS = Seconds (0-59)
  
* MM = Hundreds and tens of milliseconds

Timer automatically resets after 60 seconds.

## Hardware Setup
Connections:

* Segments (A–G, DP): Connected to PORTA

* Digit Select (Common Cathodes): Connected to PB0–PB3

| Segment | Port | Digit Select | Port |
|---------|------|---------------|------|
| A - DP    | PA0 - PA7 | Digit 1 - 4     | PB0 - PB3 |

## Project Structure

| File         | Description |
|--------------|-------------|
| `main.c`     | Main program loop: reads time via `get_millis()`, formats and displays it. |
| `timer.c`    | Timer1 setup with CTC mode and 10ms interrupt, tracks milliseconds with wrap at 60s. |
| `timer.h`    | Header for `timer.c` functions: `timer_init_interrupts()`, `get_millis()`, `timer_init()`, `timer_match()`, `reset_match()`. |
| `digit.c`    | Manages digit multiplexing and 7-segment output. |
| `digit.h`    | Header for digit control functions: `display_digit()`, `init_digit()`,  `clear_digit()`. |

## Building the Project
This project is designed for the ATmega16 microcontroller running at 14.7456 MHz.
To compile the source code using avr-gcc, run the following commands in your terminal:

```
avr-gcc -mmcu=atmega16 -Os -o main.elf main.c timer.c digit.c
avr-objcopy -O ihex main.elf main.hex
```

- mmcu=atmega16 specifies the target microcontroller.

- Os optimizes the code for size.

- main.hex is the final output file, ready to be flashed to the microcontroller.

## License
MIT License - free for educational and personal use
