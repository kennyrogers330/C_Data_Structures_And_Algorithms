#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H

//Creating a fixation point structure that also contains a pointer attribute necessary to form a linked list
struct fp_node {
    int index;
    int x;
    int y;
    struct fp_node* link;
};

/*
This function accepts the index, x-cordinate, and y-cordinate of a fixation point, create a linkedList node of the fixation point
and appends the node to the linked list with respect to the ascending order of fixation points. 
This is done by comparing fixation points by x-cordinates first and in case similarity the program comapres the y-cordinates and even the indices.
*/
struct fp_node* AddInAscendingOrder(struct fp_node *head, int index, int x, int y);

#endif