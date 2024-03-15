#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int f=-1;
int r=-1;
int f2=-1;
int r2=-1;

char arr[MAX];
char arr2[MAX];

int isFull()
{
    if(r==MAX-1)
        return 1;
    return 0;
}

int isFull2()
{
    if(r2==MAX-1)
        return 1;
    return 0;
}

void Enqueue(char n)
{
    if(isFull())
    {
        printf("Queues Overflow\n");
    }
    else if(f==-1 && r==-1)
    {
        f++;
        r++;
        arr[r]=n;
    }
    else{
        r++;
        arr[r]=n;
    }
}

void Enqueue2(char n)
{
     if(isFull2())
    {
        printf("Queues Overflow\n");
    }

    else
    {
          if(f2==-1 && r2==-1)
    {
        f2++;
        r2++;
        arr2[r2]=n;
    }
        else{
            r2++;
            arr2[r2]=n;
        }
    }

}

int isEmpty()
{
    if(f==-1 && r==-1)
        return 1;
    return 0;
}

int isEmpty2()
{
    if(f2==-1 && r2==-1)
        return 1;
    return 0;
}

void printAll()
{
    if(isEmpty())
    {
        printf("Queue Empty\n");
    }
    else
    {
    for(int i=f; i<=r; i++)
    {
        printf("%c", arr[i]);
    }
    }
    printf("\n");
}

void printAll2()
{
    if(isEmpty2())
    {
        printf("Queue Empty\n");
    }

    else
    {
          for(int i=f2; i<=r2; i++)
        {
            printf("%c\t", arr2[i]);
        }
    }
printf("\n");
}
//
//void Dequeue()
//{
//    if(isEmpty()|| f==-1)
//    {
//        printf("Queue underflow\n");
//    }
//    else{
//        int n = arr[f];
//        f++;
//        printf("%d dequeued\n", n);
//    }
//    if(f>r)
//        f=r=-1;
//}

int main()
{
    char expr[MAX];
    printf("Enter Your name: \n");
    //scanf(" %s", expr);
    gets(expr);
    //printf("%s\n", expr);

    int i=0;
    while(expr[i]!='\0')
    {
        Enqueue(expr[i]);
        if( ((expr[i])=='a') || ((expr[i])=='e') || ((expr[i])=='i') || ((expr[i])=='o') || ((expr[i])=='u') || ((expr[i])=='A') || ((expr[i])=='I') || ((expr[i])=='U') || ((expr[i])=='O' || ((expr[i])=='E')) )
        {
            //printf("%c enqueued \n", expr[i]);
            Enqueue2(expr[i]);
        }
        i++;
    }

    //a.
    printf("\nCurrent Name displayed in a Queue\n\n");
    printAll();


    //b.
    printf("\n\nThe vowels are:\n");
    printAll2();
    return 0;
}
