//
//  priority_queue.hpp
//  graph
//
//  Created by Mattia Gaggi on 1/21/18.
//  Copyright © 2018 Mattia Gaggi. All rights reserved.
//

#ifndef priority_queue_hpp
#define priority_queue_hpp

#include <stdio.h>
#include <vector>
#include <iostream>


using namespace std;



//in this file we create a min-priority heap which will be used as a priority queue to store the node elements.


// this is the token we will be using in the heap.
//each token has node (index of the graph node), priority (where we store the shortest path),
// previous set at default -1 (where we will store the previous node in the shortest path sequence.
typedef struct heap_el{
    unsigned int node;
    int previous=-1;
    float priority;
} token;

class Heap {

    
    void bubbleUp(int starting_index); //heap method bubble up
    
    void bubbleDown(); // heap method bubble down
    
    void swap(int child, int parent); // swap two tokens givem their position in the heap list
    
    int getLeftChild(int parent); //get left child given a position in heap
    
    int getRightChild(int parent);//-----right-------
    
    int getParent(int child); //get parent given position in heap

public:
    //our heap as a vector:
    vector<token> list;
    
    void insert(token); // insert a token
    void changePriority(int ind,float priority,int prev); // change priority of a token
    
    token remove(); // remove top token
    
    int getSize(); // size of heap
    
    int search(unsigned int); // search an element given graph node value
    
    // initialise heap for the algorithm.
    //this means all nodes are in the heap with priority infinity( in this implementation the max of float), except the starting node that has priority zero.
    void initialise_heap_for_Dijkstra(unsigned int graph_size, unsigned int starting_node);
    
    void print(); //visualise the heap with its node numbers
    
    void fill_heap_for_checking(); // fills heap uo to check everything works

    
    
};


#endif /* priority_queue_hpp */
