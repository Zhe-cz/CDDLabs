# Project Licence 
GNU general public license v3.0
# Authors of Project 
Zhe and Joe
# How to install project
```
make
./barrier
```
# List of any required Libraries, platform issues, etc.
```
make
g++
```
# TO DO section listing items that need to be completed (errors, missing features etc.)
implement the Producers and Consumers
# List of files and what they contain
* Barrier.cpp
* Barrier.h
* Event.cpp
* Event.h
* SafeBuffer.cpp
* SafeBuffer.h
* main.cpp
* Semaphore.cpp
* Semaphore.h
# Any other relevent information
Create a program that has two parts. A producer and a consumer.\
The producer generates random characters from ‘a’ to ‘z’ at random
intervals (between 0 and 1 second in length). It adds these to a thread
safe buffer that has a finite holding capacity of N characters. It generates
a preset number of characters (determined at runtime) and when it has
finished it add an ‘X’ character to the buffer and exits.\
The consumer takes these letters from the buffer at random time
intervals (between 0 and 1 second in length) and records how many of each
letter it consumes. Once it sees an ‘X’ in the buffer it adds its character
count to a central buffer and exits.\
The main file should demonstrate your producer consumer implementation
in action by creating a number of consumers and producers and showing them in
action. All files must include suitable documentation. The Makefile must contain a rule (‘doc’) that runs the Doxygen program and generates the documentation. Edit your emacs settings so that it now automatically generates headers for
your code files. e.g. see https://www.emacswiki.org/emacs/AutomaticFileHeaders


