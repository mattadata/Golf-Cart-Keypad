# Golf-Cart-Keypad
Trigger a relay based on correct 4 digit code being entered. 
This runs on Arduino. List of supplies are:
Arduino Nano Clone - https://amzn.to/3n7YXjg
Relay module - https://amzn.to/3nc3yko
3X4 keypad - https://amzn.to/30p4rOa
2 5mm LEDs - https://amzn.to/3nbDJRQ
2 resitors - https://amzn.to/31XS783 (~68 to 150 ohm depending on how bright you want LEDs)
2 LED holders - https://amzn.to/3n9HtmD
Toggle switch - https://amzn.to/3F5onnQ

Theory of operation:
The toggle switch controls the 12V to the arduino board, so it must be flipped on to power the arduino. Once arduino boots up and is ready, the red LED will come on. It will flash once when each digit is entered as feedback. After 4 keys are pressed, red lights will flash many times if code is wrong....or is code is correct, red light will go off and green ligth will come on. After correct code, all user input is ignored. To turn the golf cart off, flip the toggle switch off which will remove all power from the arduino board and the relay will switch off also.

TODO: The 4 digit code is hardcoded in a variable. It needs to be set from the user interface.
