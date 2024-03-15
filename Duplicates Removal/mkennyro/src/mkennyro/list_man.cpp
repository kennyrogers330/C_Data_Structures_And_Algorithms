#include "list_man.h"
#include <iostream>
#include <cstdlib>

/*
This function serves to add a fixation point at the end of a linked list. 
It returns a boolean variable indicating that a fixation point was added if true is returned or 
that the fixation point is already existing in the linked list in case false is returned. 
It takes a pointer of type struct fp_node which is the reference of the first node, index, x, and y coordinates
of the fixation point.
*/
bool append_node(struct fp_node* head, int index, int x, int y) {
    struct fp_node* ptr = head;
    
    // This loop serves to detect duplicated in the linked list
    while (ptr != nullptr) {
        if ((ptr->x == x) && (ptr->y == y)) {
            return false;
        }
        ptr = ptr->link;
    }
    
    // Create a node to add at the end of the fixation point
    struct fp_node* temp = new struct fp_node;
    temp->index = index;
    temp->x = x;
    temp->y = y;
    temp->link = nullptr;
    
    // Adding the fixation point at the end of the lined list
    ptr = head;
    
    while (ptr->link != nullptr) {
        ptr = ptr->link;
    }

    ptr->link = temp;
    
    return true;
}