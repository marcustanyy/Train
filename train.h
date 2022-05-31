#ifndef TRAINH
#define TRAINH

#include "network.h"
using namespace std;
class Train {
public:
    // constructors
    Train();
    Train(string name, int maxLoad,  string startingNode, Network network);
    ~Train();
    
    // getters
    string GetName() const;
    int GetMaxLoad() const;
    string GetCurrentLocation() const;
    // setter
    void UpdateCurrentLoad(int load);
    void ChangeCurrentLocation(string newLocation);
    void UpdateRoutes(); // routes should be updated after every delivery
    // deliver function shoudl return total time taken
    void DeliverPackage(string packageName, int load, string startPoint, string endPoint, int& currentTime);


private:
    string _name;
    int _maximumLoad;
    int _currLoad;
    string _currLocation;
    Network _network;
    unordered_map<string, pair<int, vector<string>>> _routes;


};

#endif