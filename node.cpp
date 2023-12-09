// Blake W Hausafus 2023 bwhausafus@dmacc.edu

#include <iostream>
#include <string>
#include <random>
#include "shirt.cpp"

using namespace std;

class node{
public:
    node* inv_prev;// previous shirt
    shirt* inv_item;
    node* inv_next;// next shirt

    node(node* prev, shirt* item, node* next){// constructor
        this-> inv_prev = prev;
        this-> inv_item = item;
        this-> inv_next = next;
    }

    void add_invprev(node* s){// previous shirt
        this->inv_prev = s;
    }

    void add_invitem(shirt* s){
        this->inv_item = s;
    }

    void add_invnext(node* s){// next shirt
        this->inv_next = s;
    }
};
