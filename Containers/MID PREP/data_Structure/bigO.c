#include <stdio.h>
int fact(int n)
{
    if(n==1|| n==0)
        return 1;
    else
        return n*fact(n-1);

}
int main() {
  int a = 1, b = 1, c = 1,i;
    for (i = 0; i < 50; i++) {
	while(a <= 5) {
      	b = 1;
      	while(b <= 5) {
        	printf("%d ", b);
        	b++;
      	}
      	printf("\n");
      	a++;
    	}
    }
    while(b <= 5) {
        	printf("%d ", b);
        	b++;
      	}
  int v = fact(0);
  printf("%d", v);
  return 0;
}

