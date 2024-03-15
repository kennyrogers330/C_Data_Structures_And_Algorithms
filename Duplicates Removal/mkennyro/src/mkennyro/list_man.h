#ifndef LIST_MAN_H
#define LIST_MAN_H

/*

The structure of a fixation point made of index, x, and y coordinates, and a pointer to the address of the next
fixation point in the linked list. 

*/

struct fp_node {
    int index;
    int x;
    int y;
    struct fp_node* link;
};

/*
This is the function definition of the function that appends fixation point to a linked list data structure.
*/
bool append_node(struct fp_node* head, int index, int x, int y);

#endif // LIST_MAN_H