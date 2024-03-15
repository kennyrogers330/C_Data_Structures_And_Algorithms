#include<stdio.h>
#include<stdlib.h>
struct crc
{
    int data;
    struct crc* next;
};
struct crc* addAtBeg(struct crc* tail, int dt)
{
 struct crc* temp = (struct crc*)malloc(sizeof(struct crc));
 temp->data = dt;
 temp->next = tail->next;
 tail->next = temp;
 return tail;
}

struct crc* addAtEnd(struct crc* tail, int dt)
{
 struct crc* temp =(struct crc*)malloc(sizeof(struct crc));
 temp->data = dt;
 temp->next = tail->next;
 tail->next = temp;
 tail = temp;
 return tail;
}
struct crc* addAtPos(struct crc* tail, int pos, int dt)
{
 struct crc* temp = (struct crc*)malloc(sizeof(struct crc));
 temp->data = dt;
 temp->next = NULL;
 if(pos==1)
 {
     tail = addAtBeg(tail, dt);
     return tail;
 }
 pos--; int i;
 struct crc* ptr = tail->next;
 for(i=1; i<pos; i++)
 {
     ptr = ptr->next;
 }
 temp->next = ptr->next;
 ptr->next = temp;
 return tail;
}
struct crc* delFirst(struct crc* tail)
{
 struct crc* ptr = tail->next;
 tail->next = tail->next->next;
 ptr = NULL;
 free(ptr);
 return tail;
}
struct crc* delLast(struct crc* tail)
{
 struct crc* ptr = tail->next;
 struct crc* ptr2 = NULL;
 while(ptr!=tail)
 {
     ptr2 = ptr;
     ptr = ptr->next;
 }
 ptr2->next = ptr->next;
 tail = ptr2;
 ptr = NULL;
 free(ptr);
 return tail;
}
struct crc* delPos(struct crc* tail, int pos)
{
 struct crc* ptr = tail->next;
 int i; pos--;
 for(i=1; i<pos; i++)
 {
     ptr = ptr->next;
 }
 ptr->next = ptr->next->next;
 return tail;
}
int main()
{
    struct crc* tail = (struct crc*)malloc(sizeof(struct crc));
    tail->data = 1;
    tail->next = tail;
   // tail = addAtBeg(tail, 2);
    tail = addAtEnd(tail, 2);
    tail = addAtEnd(tail, 3);
    tail = addAtEnd(tail, 4);
    tail = addAtEnd(tail, 5);
    tail = addAtPos(tail, 4,7);
    tail = delFirst(tail);
    tail = delLast(tail);
    tail = delPos(tail, 2);
    struct crc* ptr = tail->next;
    do{
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    while(ptr!=tail->next);
    return 0;
}
