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

### Lab 04-C

Now that we are able to pass commands over to the board, we need to add the
code to process them. To start off, well implement the <help> command or the
<?> character. This will basically list all the available commands.

In order to accomplish this, we will need to add a new module for the
processing of the command string. The command that we are going to implement is
the <help> command. Ultimately, this command will display all the available
commands and a basic description of what they do. This module will need to
provide a way to copy the command string to be processed to it, and then
process it.

## Lab 05

Now that we have a way to process commands, we want to add a command to allow
the changing of the heartbeat blink rate. The commands will have the following
structure

    hrtbt set delay <integer>
    hrtbt get delay

The set command will allow us the capability to adjust the blink delay while
the program is running. The <integer> value in the set command indicates the
number of milliseconds that the heartbeat module will delay before adjusting
the LED state. And the get command will display the current number of
milliseconds that the heartbeat module will delay before adjusting the LED
state.

## Lab 05-A

First off, we are going to implement the help messages for the <hrtbt> command.
So when the <help> command is run the following needs to also be shown

    hrtbt   - sends commands to the heartbeat module add a <?> after the
              command to get more help (hrtbt ?)

## Lab 05-B

For the next help message, we are going to add a new module that handles the
processing the <hrtbt> commands and help. For starters, we'll have the new
module handle the processing of the following command
    hrtbt <? or hrtbt>
