# Dalas Semiconductor Dual Digital Potentiometer Chip DS1868 driver

This is a c++ driver for the component above mentioned, datasheet @ http://pdfserv.maximintegrated.com/en/ds/DS1868.pdf.

# Transfort this project in a Library

## Manualy 

Create a folder named Log4Ard and copy inside the following files :

** DS1868.h
** DS1868.cpp
** keyworkds.txt
** libraries.properties 

create a subfolder named examples and, inside, create another subfolder 
named basicUsage. Copy the basicUsage.ino file inside.

On Windows copy the Log4Ard folder to the C:/Users/your username/Documents/Arduino/libraries/ .
You may need to restart Arduino IDE to see the new Library. 

## using maven.

Lunch a command window and go to the root folder of DS1868.
in the same folder as the pom.xml type

> mvn package

after finish, go to subfolder target and uncompress the newly created zip file into the arduino 
libraries folder, on Windows C:/Users/<your username>/Documents/Arduino/libraries/, and restart
your Arduino IDE to see the new library.




 