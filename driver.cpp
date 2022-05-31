/*******************************************************************************
\file: driver.cpp
\author: Tan Yong Yuan Marcus
\par BigPay Exercise EX003: Development Trains
\date 30/05/2022
\brief
Driver files contains test implementations of Network and Train Class
*******************************************************************************/

#include <iostream>
#include <string>
// #include "nodesandedges.h"
#include "network.h"
#include "train.h"
using namespace std;

int main() {
    cout << "****************NETWORK******************" << endl;
    Network network;

    // Node Simple Test
    for(int i = 1; i < 5; i++) {
        network.AddNode("Node" + to_string(i));
    }
    // add nodes
    network.AddEdges("Node1", "Node2", 30);
    network.AddEdges("Node1", "Node3", 5);
    network.AddEdges("Node2", "Node3", 10);
    network.AddEdges("Node2", "Node5", 10);
    network.AddEdges("Node3", "Node4", 20);
    network.AddEdges("Node4", "Node5", 30);

    // Nodes Hard test
    /*for(int i = 1; i < 6; i++) {
        network.AddNode("Node" + to_string(i));
    }


    //node 1 edges
    network.AddEdges("Node1", "Node6", 11);
    network.AddEdges("Node1", "Node2", 13);
    network.AddEdges("Node1", "Node4", 29);
    // node 2 edges
    network.AddEdges("Node2", "Node3", 20);
    network.AddEdges("Node2", "Node4", 12);
    // node 3 edges
    network.AddEdges("Node3", "Node4", 5);
    network.AddEdges("Node3", "Node5", 4);
    // node 4 edges
    network.AddEdges("Node4", "Node5", 28);
    network.AddEdges("Node4", "Node6", 15);
    // node 5 edges
    network.AddEdges("Node5", "Node6", 24);*/

    auto nodes = network.GetNodes();

    for(auto pairs : nodes) {
        cout << "current Node : " << pairs.first << endl;
        for(auto node : pairs.second._linkedNodes) {
            cout << "Connected Nodes : " << node._destination 
                << ", with time taken of : " << node._time << endl;
        }
    }
    cout << endl;
    cout << endl;
    cout << "****************FIND PATHS******************" << endl;

    unordered_map<string, pair<int, vector<string>>> routes = network.GetRoutes("Node1");
    for(auto pairs : routes) {
        cout << "Path to Node: " << pairs.first << endl;
        cout << "With Cost of : " << pairs.second.first << endl;
        cout << "Route = ";
        for(auto str : pairs.second.second)
            cout << "->" << str;
        cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << "****************TRAIN TEST******************" << endl;

    Train train("Q1", 6, "Node2", network);
    int totalTimeTaken = 0;
    train.DeliverPackage("K1", 5, "Node1", "Node5", totalTimeTaken);
    cout << "Total Time Taken currently : "<< totalTimeTaken << endl;
    cout << endl;
    cout << endl;
    train.DeliverPackage("K2", 5, "Node3", "Node4", totalTimeTaken);
    cout << "Total Time Taken currently : "<< totalTimeTaken << endl;

}