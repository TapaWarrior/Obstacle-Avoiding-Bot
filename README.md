This bot uses an Ultrasound sensor for real time distance detection. 
The sensor is mounted on a servo motor which rotates from 0 to 180 degrees.
By using motor drivers, two DC motors power the main driving wheels. 
All components are connected to an Arduino Nano.
The primary power source for this project are two 3.7V batteries.
By default, the bot is set to move forward. However, when an obstacle is detected in a 20cm radius, the bot stops, moves slightly backwards to create space for a turn, and then turns until the obstacle can be safely avoided. 
The direction of the turn (left or right) is decided using the angle which the servo motor is at when the obstacle is detected. If this angle is greater than 90 degrees, it implies the obstacle is in the second quadrant, and so the bot turns right. Similarly for angle less than 90 degrees, the bot turns left.
