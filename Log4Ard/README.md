# Log4Ard a logging module for Arduino

This is a very lightweight logging class, intended to do what a normal 
logging class do, I mean process log messages depending on a trigger Log level.

For the moment only the SerialLogger is available, but is up to you to develop
other Logger depending on your needs. Just extends the Logger Abstract class 
and implement all the functions.

# Transfort this project in a Library

## Manualy 


Create a folder named Log4Ard and copy inside the following files :

** Logger.h
** SerialLogger.h
** SerialLogger.cpp
** Log4Hard.h 
** keyworkds.txt
** libraries.properties 

create a subfolder named examples and, inside, create another subfolder 
named basicUsage. Copy the basicUsage.ino file inside.

On Windows copy the Log4Ard folder to the C:/Users/<your username>/Documents/Arduino/libraries/ .
You may need to restart Arduino IDE to see the new Library. 

## using maven.

Lunch a command window and go to the root folder of Log4Ard.
in the same folder as the pom.xml type

> mvn package

after finish, go to subfolder target and uncompress the newly created zip file into the arduino 
libraries folder, on Windows C:/Users/<your username>/Documents/Arduino/libraries/, and restart
your Arduino IDE to see the new library.




 