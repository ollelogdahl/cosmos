# Cosmos
### Emulator for a fictional game console
Olle Logdahl, 19 August 2020

---
**Cosmos** is a simple gaming console. yada yada


## Installation / Getting Started
- Clone git repo and build yourself
> git clone https://github.com/ollelogdahl/cosmos.git

---

## Specs

- 128 * 96 1-bit display
- 

## Instruction set

- CLS					0x00A1
			Clears the screen
- DISP				0x00A2
			Updates screen (unused)
- RET					0x00FF
			Returns from a subroutine
- AWT					0x0EAA
			Halts cpu until any key is pressed
- QUIT				0x0FEF
			Quits the application

- JMP					0x1nnn
			Jumps to address 0x60 + nnn
- CALL				0x2nnn
			Calls subroutine at 0x60 + nnn
- MOV Vx, kk	0x2xkk
			Set value of register x to kk


---


## Notes
- Color palette limited to 16 colors in a single session *(this is an internal limitation, see [MDSN](https://docs.microsoft.com/en-us/windows/console/console-screen-buffer-infoex))*
- Only **ONE** reference to a `ConsoleEngine` is allowed per session
- Press *Delete Key* to close application if running in borderless
---

## Links

- [Repository](https://github.com/ollelogdahl/cosmos/)
- For reporting errors, visit [Issue Tracker](https://github.com/ollelogdahl/cosmos/issues)!
- Related Projects:
  - [Chip8 Emulator](http://github.com/ollelogdahl/chip8) by Me
- Special Thanks to:
  - yadayada

## Licensing

This project, and all code it contains, is licensed under *The Unlicense* and can be read [here](UNLICENSE).
