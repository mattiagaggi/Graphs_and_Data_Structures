//
//  shortest_path.cpp
//  graph
//
//  Created by Mattia Gaggi on 1/23/18.
//  Copyright © 2018 Mattia Gaggi. All rights reserved.
//

#include "shortest_path.hpp"
#include <limits>

ShortestPath::ShortestPath( Graph & graph_in,unsigned int starting_node): graph(graph_in),node_start(starting_node){
    
    list_tokens_ordered.reserve(graph.N()); //reserve number of nodes slots in vector
}




void ShortestPath::run_Dijkstra(){
    heap.initialise_heap_for_Dijkstra(graph.N(),node_start);
   
    while (heap.getSize()>0){
        token explored_token=heap.remove(); // remove token with min priority
        Node explored_node=graph.return_node(explored_token.node); //associate token with corresponding node in graph
        //searched all the edges and if priority is lower, updates the priority of the adjacent nodes
        for (unsigned short i=0; i<explored_node.find_degrees();i++){
            unsigned int edge=explored_node.edges_list[i];
            float distance=explored_node.distances[i];
            int search_result= heap.search(edge); // gives -1 if the argument not in the heap (already explored)
            if (search_result>=0)
                heap.changePriority(search_result, distance+explored_token.priority, explored_token.node);
        }
        list_tokens_ordered[explored_token.node]=explored_token; //stores the explored node
    }
}

float ShortestPath::path_size(unsigned int nod, bool rerun){
    

    if(rerun) ShortestPath::run_Dijkstra(); // run everything
    // rememeber that for infinite priority there was no path between node start and that node
    if (heap.list[nod].priority==std::numeric_limits<float>::max()){
        std::cout << "no path";
        return -1;
    }
    else{
        return list_tokens_ordered[nod].priority;
    }
}

std::vector<int> ShortestPath::path(unsigned int nod, bool rerun){
    
    if(rerun) ShortestPath::run_Dijkstra();
    
    token starting_node=list_tokens_ordered[nod];
    std::vector<int> history;
    //finds the history and stops when the previous node is -1 (only set for node start as all the others had updated priority)
    while (starting_node.previous !=-1){
        history.push_back(starting_node.previous);
        starting_node=list_tokens_ordered[starting_node.previous];
    }
    history.push_back(node_start); //add starting node
    std::reverse(history.begin(), history.end()); // reverse the list
    return history;
}


float ShortestPath::find_average_shortest_path(void){
    
    float nodes_to_average= static_cast<float>(graph.N()-1);
    float total=0;
    
    ShortestPath::run_Dijkstra();
    for (int i=0; i<graph.N(); i++){
        if (i!=node_start){
            float current_path=ShortestPath::path_size(i);
            //remember if there is no path path_size gives -1
            //so we need to exclude that node
            if (current_path<0) nodes_to_average--;
            else total+=current_path;
        }
    }
    return total/nodes_to_average;
}

