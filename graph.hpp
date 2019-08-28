//
//  graph.hpp
//  graph
//
//  Created by Mattia Gaggi on 1/11/18.
//  Copyright © 2018 Mattia Gaggi. All rights reserved.
//in this file the graph object is greated. Functions are in the cpp file.

#ifndef graph_hpp
#define graph_hpp

// import libraries
#include <stdio.h>
#include <vector>
#include <iostream>
#include "node.hpp"
//define max lenght of an edge.
const short MAXDISTANCE = 10, MINDISTANCE= 1;


class Graph{
    // undirected graph class. Each link between two nodes counts as an edge.
    //This edgelist representation is good for sparse graphs, even though it is slighly slower when looking up edges.
public:
    
    Graph(void); // interface to create graph by inserting manually nodes and edges
    
    Graph(unsigned int starting_nodes,float edges_density, int random_seed); // constructor for the graph given number of starting edgenodes and edge_density
    ~Graph();
    
    unsigned int N();
    
    void initialise_nodes(void); // initialises nodes by adding n number of nodes to the graph vector
    
    void initialise_edges(void); // runs through all possible edges and creates a connection according to the starting density
    
    Node& return_node(unsigned int i); // given an index, it returns the reference of the node at that index
    
    void connect_nodes(unsigned int,unsigned int,float);
    
    void add_node(void); //adds a node to the back of the graph vector NOT USED
    
    void add_nodes(unsigned short); //adds multiple nodes NOT USED
    
    void print_degrees(void); //prints the degree of each node of the graph
    
    friend std::ostream& operator<<( std::ostream&, const Graph&); // to print graph
    
    
    
    
private:
    
    // We have three variables: number of nodes, total number of edges, starting edges density and the graph vector.
    // the graph is contained in a vector where each element is a node object (defined in the node.hpp file). Because of the way vector works, the nodes object with all the information are actually stored on the heap, avoiding stack overflow.
    //The vector itself is kept private and accessed through the functions defined in public
    // We use as a convention that every time a new node is created, it will be added to the back of the vector and its node number will be the index it occupies in the vector. This makes node look-up given the index O(1)
    
    unsigned int num_nodes=0;
    
    unsigned int num_edges=0;
    
    float starting_density;
    
    std::vector<Node> graph;
    
};



#endif /* graph_hpp */
