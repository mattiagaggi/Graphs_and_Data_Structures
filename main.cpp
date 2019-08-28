//
//  main.cpp
//  graph
//
//  Created by Mattia Gaggi on 1/10/18.
//  Copyright © 2018 Mattia Gaggi. All rights reserved.

//import basic modules
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

/* include four files as classes.
 Node.hpp contains the node object used by the graph.
 Graph.hpp contains the graph.
 Priority_queue.hpp contains the heap used by the algorithm.
 Shortest_path.hpp contains the class object which runs the algorithm and stores the results*/

#include "node.hpp"
#include "graph.hpp"
#include "priority_queue.hpp"
#include "shortest_path.hpp"

using namespace std;

// standard error formula
inline float standard_error(vector<float> v, float average){
    float error=0;
    for (int i=0;i<v.size();i++){
        error+=powf(v[i]-average, 2);
    }
    error=sqrtf(error);
    error/=(float)v.size();
    return error;
    
}



void obtain_all_results(int N_graphs,int number_of_nodes,float density){

 
    float averaged_shortest_path=0;
    float error=0;
    vector<float> error_v;
    cout << "shortest paths:\n";
    for (int e=0; e<N_graphs;e++){
        Graph n(number_of_nodes,density, e); //e as argument is for the random number generator has to be reset
        ShortestPath o(n, 0);
        float sh_path=o.find_average_shortest_path();
        averaged_shortest_path+=sh_path;
        cout <<sh_path<<", ";
        error_v.push_back(sh_path);
    }
    cout<<"\n\n\n";
    averaged_shortest_path/=N_graphs;
    error=standard_error(error_v, averaged_shortest_path);
    
    cout << "averaged over "<<
    N_graphs<< " graphs\n"<<"for a density of: "<<
    density << "\n"<<"mean shortest path over all nodes is: "<<
    averaged_shortest_path <<"\nerror over all graphs is: "<<
    error <<"\n\n";

    
}




int main(int argc, const char * argv[]) {
    // reduce number of graphs for quicker result
    int N_graphs=50;
    int n_nodes=100;
    obtain_all_results(N_graphs,n_nodes,1); // change density!
    
    return 0;
}
