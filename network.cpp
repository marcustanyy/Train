/*******************************************************************************
\file: network.cpp
\author: Tan Yong Yuan Marcus
\par BigPay Exercise EX003: Development Trains
\date 30/05/2022
\brief
Contains the implementations of the Network class.

Functions inside the class include:
Network() default constructor
~Network() destructor
AddNode()
AddEdges()
GetNodes()
GetRoutes()
*******************************************************************************/

#include "network.h"
const unsigned INFINITY_ = static_cast<unsigned>(-1);

/******************************************************************************/
/*!
*\fn       Network::Network()

*\brief    Default Constructor Network class, but does nothing
*/
/******************************************************************************/
Network::Network() {}

/******************************************************************************/
/*!
*\fn       Network::~Network()
*\brief    Destructor for Network class, but does nothing
*/
/******************************************************************************/
Network::~Network() {}

/******************************************************************************/
/*!
*\fn       Network::AddNode(string name)
*\brief    Adds a node to the network
*\param name   
string that contains the name of the node
*/
/******************************************************************************/
void Network::AddNode(string name) {
    _nodeMap[name] = Node(name); 
}

/******************************************************************************/
/*!
*\fn       Network::AddNode(string name)
*\brief    Adds a edge to both the source node and destination node
*\param source   
string that contain the first node of the edge
*\param destination   
string that contains the second node of the edge
*\param time
int value of the time taken for this edge
*/
/******************************************************************************/
void Network::AddEdges(string source, string destination, int time) {
    // add edge to source node 
    _nodeMap[source]._linkedNodes.push_back(Edge(destination, time));
    // since directions are undirected
    // add the edge for both nodes
    _nodeMap[destination]._linkedNodes.push_back(Edge(source, time));
}

/******************************************************************************/
/*!
*\fn       Network::GetNodes() const
*\brief    Destructor for Network class, but does nothing

*\param source   
string that contain the first node of the edge
*\param destination   
string that contains the second node of the edge
*\param time
int value of the time taken for this edge

*\return 
return all nodes in the network
*/
/******************************************************************************/
const unordered_map<string, Node>& Network::GetNodes() const {
    return _nodeMap;
}

/******************************************************************************/
/*!
*\fn       Network::GetRoutes()
*\brief    Perform dijkstra algorithm on the source nodes to find the lowest
time taken to each node and its path

*\param source   
string that contain the first node of the edge

*\return 
return the map the contains all the leading out from the source node and 
its corresponding time taken
*/
/******************************************************************************/
unordered_map<string, pair<int, vector<string>>> Network::GetRoutes(string source) {
    unordered_map<string, pair<int, vector<string>>> routes; // pairs stores the visited node with its corresponding cost and path
    for(auto pairs : _nodeMap) { // initializing their route cost to INT_MAX
        routes[pairs.first] = make_pair(INFINITY_, vector<string>{});
    }

    routes[source].first = 0; // set route to itself to 0;

    auto cmp = [](Edge lhs, Edge rhs) { // lambda function to compare edges time
        return lhs._time > rhs._time;
    };

    // use priority_queue to go through all nodes
    priority_queue<Edge, vector<Edge>, decltype(cmp)> pq(cmp);
    pq.push(Edge( source, 0)); // push itself as the first node to begain with.

    while(!pq.empty()) {
        Edge currNode = pq.top();
        pq.pop();
        // loop node's adjacent nodes
        for(auto edges: _nodeMap[currNode._destination]._linkedNodes) {
            string currEdge = edges._destination;
            int currTime = edges._time;
            // if route not yet found or current route takes less time than previous route
            if(static_cast<unsigned>(routes[currEdge].first) == INFINITY_ || 
                currTime + routes[currNode._destination].first < routes[currEdge].first) {
                routes[currEdge].second = routes[currNode._destination].second; // take the route of current node
                routes[currEdge].second.push_back(currEdge); // add the resulting destination 
                routes[currEdge].first = routes[currNode._destination].first + currTime; // update route time
                pq.push(Edge(currEdge, routes[currEdge].first)); // current edge to pq
            }
        }
        
    }
    return routes;
}




