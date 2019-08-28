//
//  graph.cpp
//  graph
//
//  Created by Mattia Gaggi on 1/11/18.
//  Copyright © 2018 Mattia Gaggi. All rights reserved.
//

#include "graph.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;


Graph::Graph(void){
    cout << "what is the number of nodes?";
    cin >> num_nodes;
    Graph::initialise_nodes();
    for (int i=0; i<num_nodes; i++){
        for (int i2=0; i2<num_nodes; i2++){
            if (i != i2){
                if (Graph::return_node(i).check_edge_in_node(i2)<0){
                    cout << "edge between "<< i << " and "<<i2 << "\n";
                    float ed;
                    cin >> ed;
                    if (ed>=0)
                        Graph::connect_nodes(i, i2, ed);
                }
            }
        }
    }
}


Graph::Graph(const unsigned int starting_nodes,const float edges_density,int random_seed) : num_nodes(starting_nodes),starting_density(edges_density) {
    srand(time(0)+random_seed);
    Graph::initialise_nodes();
    Graph::initialise_edges();
    
}

Graph::~Graph(){}

unsigned int Graph::N(void){
    return num_nodes;
}


Node& Graph::return_node(unsigned int i){
    // returns the referenc to a node in the vector of nodes.
    //NB our convention is at index i there is node i
    return graph[i];
}

void Graph::connect_nodes(unsigned int node1,unsigned int node2,float weight ){
    //connects two nodes if not already connected
    if (node1 == node2) throw logic_error("the two nodes are identical");
    int check1,check2;
    check1=Graph::return_node(node1).check_edge_in_node(node2);
    check2=Graph::return_node(node2).check_edge_in_node(node1);
    // remember that checks return -1 if node not found, otherwise return the index
    if (check1 <0 && check2 < 0){
        Graph::return_node(node1).add_edge(node2, weight);
        Graph::return_node(node2).add_edge(node1, weight);
        num_edges+=1;
    };
}

void Graph::initialise_nodes(void){
    for (int n=0; n<num_nodes; n++){
        Node nod;
        graph.push_back(nod);
    }
}


void Graph::initialise_edges(void){
    // for all edges (i,i2) with i!=i2, makes a connection if a random number generators returns
    // a value smaller than the density
    for (int i=0 ;i <num_nodes; i++){
        for (int i2=0; i2<num_nodes; i2++){
            if (i!=i2){
                float random0to1=static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                if (random0to1 < starting_density){
                    //create random weight with MINDISTANCE<=random_weight<=MAXDISTANCE
                    float random_weight= static_cast <float> (rand()) / static_cast <float> (RAND_MAX) *  (MAXDISTANCE-MINDISTANCE) + MINDISTANCE;
                    Graph::connect_nodes(i,i2, random_weight);
                }
            }
        }
    }
    
    
}


void Graph::add_node(void){
    Node i;
    graph.push_back(i);
    num_nodes++;
}


void Graph::add_nodes(const unsigned short n){
    for (unsigned short i=0; i<n ; i++){
        Graph::add_node();
    }
}



void Graph::print_degrees(void){
    for (int e=0;e<num_nodes;e++)
        cout << Graph::return_node(e).find_degrees() << " ";
    cout << "\n";
}



ostream& operator<<( ostream& osobj, const Graph& g){
    //returns graph representation;
       osobj << "Current number of nodes: " << g.num_nodes << "\n"
    "Starting density: "<< g.starting_density << "\n" << "Current number of edges: "
    << g.num_edges << "\n";
    if (g.starting_density==1) osobj << "Maximum number of edges";
    osobj<< "\n \n";
    
    return osobj;
}







