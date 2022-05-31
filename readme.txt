Files that was implemented for the task:
driver.cpp
network.h
network.cpp
train.h
train.cpp

Compiled using c++14
"g++ -Wall -Werror -Wconversion -pedantic -std=c++14  driver.cpp network.cpp train.cpp -o train.exe"



/*Assumptions*/
The task was implemented assuming that user should pass in perfect information. (meaning it should give existing nodes names etc.)
It was also assume that all nodes were reachable but passing through other nodes.


/*What was implement*/
-Addition of nodes and edges to the network
-Find paths to all Node that exist in the network save the shortest path
-Train package delivery function
-Output printout
-Time calculation for delivery.
-Simple getters and setters that might be required


/*What can be added*/
-Best train for delivery
-Train that can handle multiple delivery


P.S.
I did some simple testing and the functionality of what was implemented seems correct. However, 
I think there is still more testing to be done but I felt that I should submit this version first.
I hope what was implemented is enough but if there are more things that I should add, please let me know.

