## tetromino-msp430

A tetromino game on the msp430. This is a demo with no monetization strategy. Just for kicks.

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a>

This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.

### Makefile

The default task will:

- `lint` the source code via `cppcheck`
- Build the elf image for flashing
- Run the tests (contains in `/test`)

### Structure

The source is laid out like so:

- `/src`: All application source code is under here
- `/src/base`: non-msp430-specific application code. The code in this folder is included in the `test` target that is built with the host `gcc`, so it cannot include any msp430/embedded headers
- `/test`: All test source code is here

### Application Components

- A Texas Instruments MSP-EXP430F5529LP launchpad for the mcu/power supply/connectors
- A Nokia 5110 LCD screen
- A breadboard
- Some buttons
- Some jumper wires
