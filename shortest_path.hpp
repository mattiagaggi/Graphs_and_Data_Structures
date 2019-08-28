//
//  shortest_path.hpp
//  graph
//
//  Created by Mattia Gaggi on 1/23/18.
//  Copyright © 2018 Mattia Gaggi. All rights reserved.
//

#ifndef shortest_path_hpp
#define shortest_path_hpp

#include <stdio.h>
#include <vector>
#include "node.hpp"
#include "graph.hpp"
#include "priority_queue.hpp"

class ShortestPath{
public:
    
    ShortestPath(Graph &,unsigned int start_node=0); //initialise with graph reference and start node
    
    void run_Dijkstra(); // runs the algorithm
    
    float path_size(unsigned int nod, bool rerun=false); // if algorithm already run, finds shortest path size from node start to nod
    
    std::vector<int> path(unsigned int nod, bool rerun=false);// returns the history of the node
    
    float find_average_shortest_path(void); // average the average shortest path over all nodes
    
    
    
private:
    
    Graph graph; //stores graph
    Heap heap; //priority queue used
    vector<token> list_tokens_ordered;//after running the algorithm, here the tokens are stored with node i in slot i
    int node_start; // starting node
    
};



#endif /* shortest_path_hpp */
