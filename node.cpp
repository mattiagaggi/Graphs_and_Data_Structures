//
//  graph.cpp
//  graph
//
//  Created by Mattia Gaggi on 1/10/18.
//  Copyright © 2018 Mattia Gaggi. All rights reserved.
// Defining the functions declared in the hpp file

#include "node.hpp"
#include <vector>
#include <iostream>


Node::Node(): k(0){} // this way you can initialise const otherwise use: this->k=0


unsigned short Node::find_degrees(void){return k;}

void Node::add_edge(const unsigned int edge,const float distance){
    this->k+=1;
    edges_list.push_back(edge);
    distances.push_back(distance);
    
}

int Node::check_edge_in_node(unsigned int edge){
    for (int e=0;e<edges_list.size(); e++){
        if (edges_list[e]==edge) return e;
    }
    return -1;
}



float Node::find_weight(unsigned int edge){
    int check=Node::check_edge_in_node(edge);
    if (check<0) return -1;
    return distances[check];
        
}



std::ostream& operator<<( std::ostream& osobj, const Node& n){
    //returns code number, degrees, edges with corresponding weight
    osobj << "the degrees are: "<< n.k << "\n" << "edges to: " ;
    for (int c=0;c<n.edges_list.size();c++){
        osobj <<"| "<< n.edges_list[c] << " (w=" << n.distances[c] <<
        ")  ";
    }
    osobj<< "\n";
    
    return osobj;
}
