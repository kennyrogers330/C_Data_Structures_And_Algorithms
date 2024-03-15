#include<stdio.h>
#include<stdlib.h>
struct que
{
    int dt;
    struct que* next;
};

struct que* f = NULL;
struct que* r = NULL;

void Enqueue(int n)
{
    struct que* temp = (struct que*) malloc(sizeof(struct que));
    temp->dt = n;
    temp->next = NULL;
    if(r==NULL)
    {
        r=temp;
        f=temp;
    }
    else
        {
        r->next = temp;
        r=r->next;
    }
}

int isEmpty()
{
    if(f==NULL && r==NULL)
        return 1;
    return 0;
}

void display()
{
    if(isEmpty())
        printf("Queue underflow\n");
    else{
        struct que* ptr = f;
        while(ptr!=NULL)
        {
            printf("%d\n", ptr->dt);
            ptr = ptr->next;
        }
    }
}

void Dequeue()
{
    if(isEmpty())
        printf("Queue underflow\n");
    else{
        printf("%d dequeued\n", f->dt);
        struct que* temp = f;
        f=f->next;
        temp = NULL;
        free(temp);
    }
    if(f==NULL)
    {
        f=r=NULL;
    }
}
int peek()
{
    if(isEmpty())
        printf("Queue underflow\n");
    else
    return f->dt;
}
//==============================Function start===================================
struct que* prev = NULL;
struct que* next = NULL;
void reverseQue()
{
	static struct que* temp;
	temp = f;
		if(f==NULL)
			{
				f=prev;
				r=temp;
				return;
			}
	next = f->next;
	f->next = prev;
	prev = f;
	f = next;
	reverseQue(f);
}
int main()
{
    int c, b, o;
    printf("How many node: ");
    scanf("%d", &c);

    for(o=0; o<c; o++)
    {
        printf("Enter node %d: ", o+1);
        scanf("%d", &b);
        Enqueue(b);
    }
    display();
    reverseQue();
    printf("Revered Queue\n");
    display();
    return 0;
}
