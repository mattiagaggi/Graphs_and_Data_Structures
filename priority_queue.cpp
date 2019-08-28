//
//  priority_queue.cpp
//  graph
//
//  Created by Mattia Gaggi on 1/21/18.
//  Copyright © 2018 Mattia Gaggi. All rights reserved.
//

#include "priority_queue.hpp"
#include <math.h>

using namespace std;



int Heap:: getSize(){
    return list.size();
}



    
void Heap::swap(int child, int parent) {
    token temp;
    temp = list[child];
    list[child] = list[parent];
    list[parent] = temp;
}

int Heap:: getParent(int child) {
    if (child % 2 == 0)
        return (child /2 ) -1;
    else
        return child/2;
    
}


int Heap:: getLeftChild(int parent){
    return 2*parent +1;
}


int Heap:: getRightChild(int parent){
    return 2 * parent + 2;
}


void Heap:: insert(token value) {
    
    list.push_back(value);
    bubbleUp(list.size() - 1);
    
}


void Heap:: bubbleUp(int starting_node) {
    int child = starting_node;
    int parent = getParent(child);
    
    while (list[child].priority < list[parent].priority && child >=0 && parent >= 0) {
        //while the priority of the child is smaller, swap with parent.
        swap(child, parent);
        child = parent;
        parent = getParent(child);
        
    }
    
    
}



token Heap:: remove() {
    //heap method to remove elements from heap O(1)
    int child = list.size()  - 1;
    swap(child, 0);
    token value = list.back();
    list.pop_back();
    
    bubbleDown();
    
    return value;
    
    
}



void Heap::bubbleDown() {
    int parent = 0;
    
    while (1) {
        int left = getLeftChild(parent);
        int right = getRightChild(parent);
        int length = list.size();
        int largest = parent;
        
        if (left < length && list[left].priority < list[largest].priority)
            largest = left;
        
        if (right < length && list[right].priority < list[largest].priority)
            largest = right;
        
        if (largest != parent) {
            swap(largest, parent);
            parent = largest;
        }
        else 
            break;
        
        
    }
    
}

 int Heap::search(unsigned int node_value){
     //search method O(N)
    for (int e=0; e< list.size(); e++){
        if (list[e].node==node_value)
            return e;
    }
     return -1;
}

void Heap::changePriority(int index,float new_priority,int previous){
    //change priority O(logN)
    if (index>=0)
        if (new_priority < list[index].priority){
            list[index].priority=new_priority;
            list[index].previous=previous;
            Heap::bubbleUp(index);
        }
    
}

void Heap::initialise_heap_for_Dijkstra(unsigned int graph_size,unsigned int starting_node){
    list.clear();
    for (unsigned int i=0; i<graph_size;i++){
        token token_init;
        token_init.node=i;
        if (i==starting_node)
            token_init.priority=0;
        else
            token_init.priority=std::numeric_limits<float>::max();
        insert(token_init);
        
    }
}

void Heap::print(void){
    int power=0;
    int level=0;
    for (int i=0; i<list.size(); i++){
        cout << "node is " << list[i].node << " priority " << list[i].priority << "\n";
        // the next instructions are to separate heap levels in output
        if (i+1==power + pow(2,level)){
            cout<<"\n";
            power+=pow(2,level);
            level++;
        }
        
    }
}

void Heap::fill_heap_for_checking(){
    for (int e=0; e<10;e++){
        token u;
        u.priority=10-e;
        u.node=e;
        Heap::insert(u);
    }
        
}
