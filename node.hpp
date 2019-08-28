//
//  graph.hpp
//  graph
//
//  Created by Mattia Gaggi on 1/10/18.
//  Copyright © 2018 Mattia Gaggi. All rights reserved.
// This files creates the class node.
// The functions for this class are in the cpp file

#ifndef node_hpp
#define node_hpp

#include <stdio.h>
#include <vector>



class Node {
    
public:
    
    std::vector<unsigned int> edges_list;
    std::vector<float> distances;

    Node(); // node initialisation
    
    unsigned short find_degrees(void);  //returns degrees of node
    
    void add_edge(const unsigned int,const float); // adds edge to the node with a float weight
    
    int check_edge_in_node(unsigned int); //checks if edge is in edge list of node returns -1 if not found
    
    float find_weight(unsigned int); // finds the weight associated with edge, returns -1 if edge not found
    
    friend std::ostream& operator<<( std::ostream&, const Node&); // new print function for node
    
    
private:
    
    //each Node is characterised by:
    // k: degrees
    // edge_list: list of edges in edgelist representation
    //distances : weight of each edge
    
    unsigned short k;

};

#endif /* graph_hpp */
