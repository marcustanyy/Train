/*******************************************************************************
\file: train.cpp
\author: Tan Yong Yuan Marcus
\par BigPay Exercise EX003: Development Trains
\date 30/05/2022
\brief
Contains the implementations of the Train class.

Functions inside the class include:
Train() default constructor
Train() constructor
~Train() destructor
GetName() const
GetMaxLoad() const
GetCurrentLocation() const
UpdateCurrentLoad(int load)
ChangeCurrentLocation(string newLocation)
UpdateRoutes()
DeliverPackage(string packageName, int load, string startPoint, 
                    string endPoint, int& currentTime)
*******************************************************************************/
#include "train.h"
using namespace std;

/******************************************************************************/
/*!
*\fn       Train::Train()

*\brief    Default Constructor Train class, intialise values to 0 or empty string
*/
/******************************************************************************/
Train::Train() : _name(""), _maximumLoad(0), _currLoad(0), _currLocation("") {}

/******************************************************************************/
/*!
*\fn       Train::Train()
*\brief    Constructor Train class, intialise values with the corresponding param

*\param name   
string that contains the name of the train
*\param maxLoad
int value that contains train's maxLoad
*\param startingNode   
string that states the train's starting location
*\param network
Train's current Network
*/
/******************************************************************************/
Train::Train(string name, int maxLoad, string startingNode, Network network) : _name(name),
                _maximumLoad(maxLoad), _currLoad(0), 
                _currLocation(startingNode), _network(network) {
                    UpdateRoutes(); // update route base of its starting position
}

/******************************************************************************/
/*!
*\fn       Train::~Train()
*\brief    Destructor Train class, does nothing
*/
/******************************************************************************/
Train::~Train() {}

/******************************************************************************/
/*!
*\fn       Train::GetName() const
*\brief    Getter for Train's name

*\return   
returns the name of the train
*/
/******************************************************************************/
string Train::GetName() const {
    return _name;
}

/******************************************************************************/
/*!
*\fn       Train::GetMaxLoad() const
*\brief    Getter for Train's name

*\return   
returns the maximum load of the train
*/
/******************************************************************************/
int Train::GetMaxLoad() const {
    return _maximumLoad;
}

/******************************************************************************/
/*!
*\fn       Train::GetCurrentLocation() const
*\brief    Getter for Train's name

*\return   
returns the current location of the train
*/
/******************************************************************************/
string Train::GetCurrentLocation() const {
    return _currLocation;
}

/******************************************************************************/
/*!
*\fn       Train::UpdateCurrentLoad(int load) 
*\brief    setter to update train's current load

*\param load 
int value of load to be updated to
*/
/******************************************************************************/
void Train::UpdateCurrentLoad(int load) {
    _currLoad += load;
}

/******************************************************************************/
/*!
*\fn       Train::ChangeCurrentLocation(string newLocation) 
*\brief    setter to update train's current location

*\param newLocation 
string value that contains the new location of the string
*/
/******************************************************************************/
void Train::ChangeCurrentLocation(string newLocation) {
    _currLocation = newLocation;
}

/******************************************************************************/
/*!
*\fn       Train::UpdateRoutes() 
*\brief    Update Train's route according to its current location
*/
/******************************************************************************/
void Train::UpdateRoutes() {
    _routes = _network.GetRoutes(_currLocation);
}


/******************************************************************************/
/*!
*\fn       Train::DeliverPackage() 
*\brief    
Deliver Package function that will do the output printout.
does simple checks to make sure that train can carry load.
Move to starting point of the package point if current location is not at 
the starting point.

*\param packageName
string value of package name
*\param load
int value for the load of the package.
*\param startingPoint
string value that states the starting point of the delivery
*\param endPoint
string value that states the end point of the delivery
*\param currentTime
int reference to the current existing time.
*/
/******************************************************************************/
void Train::DeliverPackage(string packageName, int load, string startPoint, string endPoint, int& currentTime) {
    if(load + _currLoad > _maximumLoad) {
        cout << "Unable as its maximum load has been reach" << endl;
        return;
    }

    if(_currLocation != startPoint) { // go to pick up location
        DeliverPackage("", 0, _currLocation, startPoint, currentTime);
    }

    int totalTime = currentTime + _routes[endPoint].first;
    int prevTime = 0;
    UpdateCurrentLoad(load);
    cout << "K1 has current load of : "<< _currLoad << endl;
    for(string destination : _routes[endPoint].second) {
        cout << "W=" << currentTime
            << ", T=" << _name 
            << ", N1=" << _currLocation
            << ", P1=[" << (destination != endPoint ? packageName : "")
            << "], N2=" << destination
            << ", P2=[" << (destination == endPoint ? packageName : "") << "]" 
            << endl;
        currentTime += _routes[destination].first - prevTime;
        prevTime =_routes[destination].first;
        ChangeCurrentLocation(destination);
    }
    UpdateRoutes(); // update routes from current location after completing task.
    UpdateCurrentLoad(-load);
    cout << "K1 has current load of : "<< _currLoad << endl;
    currentTime = totalTime;
}