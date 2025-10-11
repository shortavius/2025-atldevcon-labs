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
