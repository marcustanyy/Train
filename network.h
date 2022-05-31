#ifndef NETWORKH
#define NETWORKH

#include <unordered_map>
#include <utility> 
#include <string>
#include <unordered_set>
#include <queue>
#include <iostream>

using namespace std;

// edge holds the destination node and its weightage
struct Edge {
    Edge() : _destination(""), _time(0) {}
    Edge(string destination, int time) : _destination(destination), _time(time) {}
    string _destination;
    int _time;
};

struct Node {
    Node() : _name("") {}
    Node(string name) : _name(name) {}
    string _name;
    vector<Edge> _linkedNodes; // vector containing Edges that shows node's linked nodes
};


class Network {
public:
    Network(); // constructor
    ~Network(); // destructor
    void AddNode(string name); // add nodes
    void AddEdges(string source, string destination, int time); // add edges
    const unordered_map<string, Node>& GetNodes() const; // getter for all nodes in the network
    unordered_map<string, pair<int, vector<string>>> GetRoutes(string source); // get shortest path for all nodes in the network


private:
    unordered_map<string, Node> _nodeMap;
};


#endif
