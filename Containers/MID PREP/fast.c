#include<stdio.h>
#define max(a,b) a>b?a:b
main()
{
 int m,n;
 m=3+ (max(2,3));
 n=2*(max(3,2));
 printf("%d %d", m, n);
}
