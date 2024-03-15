#include "assignment2.h"
#include <iostream>

/*
This function accepts the index, x-cordinate, and y-cordinate of a fixation point, create a linkedList node of the fixation point
and appends the node to the linked list with respect to the ascending order of fixation points. 
This is done by comparing fixation points by x-cordinates first and in case similarity the program comapres the y-cordinates and even the indices.
*/
struct fp_node* AddInAscendingOrder(struct fp_node *head, int index, int x, int y){
    struct fp_node *new_fp = (struct fp_node *) malloc(sizeof(struct fp_node));
    new_fp->index = index;
    new_fp->x = x;
    new_fp->y = y;
    new_fp->link = nullptr;
    if(head == nullptr || x < head->x){
        new_fp->link = head;
        head = new_fp;
    }
    else if(x == head->x && y < head->y){
        new_fp->link = head;
        head = new_fp;
    }
    else if(x == head->x && y == head->y && index < head->index){
        new_fp->link = head;
        head = new_fp;
    }
    else{ 
       struct fp_node *ptr = head;
       while(ptr->link != nullptr){
        if(ptr->link->x < x)
            ptr = ptr->link;
        else if((ptr->link->x == x) && (ptr->link->y < y))
            ptr = ptr->link;
        else if((ptr->link->x == x) && (ptr->link->y == y) && (ptr->link->index < index))
            ptr = ptr->link;
        else
            break;
       }
       new_fp->link = ptr->link;
       ptr->link = new_fp;
    }
    return head;
}
