Solution github web address: https://github.com/shortavius/2025-atldevcon-labs
Git clone link
    HTTP: https://github.com/shortavius/2025-atldevcon-labs.git
     SSH: git@github.com:shortavius/2025-atldevcon-labs.git

Arduino documentation web addresses
     General: https://docs.arduino.cc/
    Language: https://docs.arduino.cc/language-reference/



## Computer Setup

In order to do these labs, you will need to have the following software
installed on you computer

Arduino IDE: https://www.arduino.cc/en/software/#ide
This is the tool that will allow you to build and upload the code.

Git (or Git Bash on Windows): https://git-scm.com/downloads
This will allow you to clone and checkout the various solutions to the labs.

## Arduino IDE Setup

First off, you must install the board libraries for the Nano IoT 33 processor
board. This may be accomplished by opening the board manager and searching for
"SAMD". You are looking for the following item:

            Arduino SAMD Boards (32-bits ARM Cortex-M0+)

Select Version 1.8.14, and click install. This will download the libraries and
compiler for the Arduino Nano 33 IoT board.

## Lab 01

Using the easiest method that you come up with, write code that will blink the
Light Emitting Diode (LED) on the board forever. The IO pin that will be used
in this case is called 

See if you are able to adjust the rate of blinking of the LED.

## Lab 02

While the program you just wrote does perform the task of blinking the LED, it
isn't implemented in a good way. Since the processor we are using only has a
single thread of execution, it isn't able to do anything else whilst it is
executing the delay commands.

See if you are able to refactor the blinking LED program into one that doesn't
depend on the delay command.

## Lab 03

Now that we have a way to tell that our code is "alive", we want to expand it
such that it can communicate with us. This communication will be done via a
serial port (don't worry, no extra hardware is required). This serial port is
implemented via the USB cable that you have been using to program the board.

Create a new "console" module that initializes the serial port and prints out
a message.

Once you have your code loaded into the board, you may see it by monitoring the
serial port. This may be start by clicking on Tools > Serial Monitor.

## Lab 04

Now that we have a way for the you to send information to the Arduino Nano 33
IoT board, we will begin to create an interface that allows sending of commands
to the board.

### Lab 04-A

First off, we need to figure out what character will indicate that a command is
ready to processed. Typically, this is the <enter> or <return> (also known as a
carriage return) key on the keyboard. If we consult an ASCII chart, so show
here:
                        https://www.ascii-code.com/

We can find that the carriage return key is represented as a 13 (or 0x0D in
hexadecimal). Expand the program such that when the carriage return key is
pressed, the board with display a prompt character on a new line.

### Lab 04-B

Now that we have a key to signify when a command should be processed, we need
to build up the command string. In the old days, typically, the maximum number
of characters a command string could be was 80 characters. We will use the same
length in this lab.

Modify the program to capture an array of character up to 80 characters long.
Once the end of the string is found, don't allow anymore characters to be added
to the string. As each character is received, be sure to send it back to the
connected computer. When the carriage return is detected, display the command
string back. Be sure to only allow the alphabet (uppercase and lowercase),
numbers (0 - 9), and some symbols. Also, the string needs to be cleared each
time after the carriage return is detected.
