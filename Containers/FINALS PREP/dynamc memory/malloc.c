#include<stdio.h>
#include<stdlib.h>
struct st{
	 int id;
    char name[50];
    }*ptr;

//int main()
//{
//    int *ip;
//    ip = (int*)malloc(100 * sizeof(int));
//
//    if(ip == NULL){
//	printf("out of memory\n");
//    }else{
//	printf("memory reserved");
//    }
//
//    ptr=(struct st*)malloc(sizeof(struct st));
//    scanf("%d%s",&ptr->id,&ptr->name);
//    printf("\n%d\t%s",ptr->id,ptr->name);
//
//    return 0;
//}
int main() {
  int *ptr, i , n1, n2;
  printf("Enter size: ");
  scanf("%d", &n1);
  ptr = (int*) malloc(n1 * sizeof(int));
  printf("Addresses of previously allocated memory:\n");
  for(i = 0; i < n1; ++i)
    printf("%pc\n",ptr + i);
  printf("\nEnter the new size: ");
  scanf("%d", &n2);
ptr = realloc(ptr, n2 * sizeof(int));
  printf("Addresses of newly allocated memory:\n");
  for(i = 0; i < n2; ++i)
    printf("%pc\n", ptr + i);
  free(ptr); }


