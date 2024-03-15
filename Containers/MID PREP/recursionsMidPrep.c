#include<stdio.h>
#include<string.h>
#define MAX 100
//1. Write a program in C to print first 50 natural numbers using recursion.
void printNaturalNumber(int n)
{
    if(n>50)
        return;
    printf("%d\n", n);
    printNaturalNumber(n+1);
}
//2. Write a program in C to calculate the sum of numbers from 1 to n using recursion.
int SumOfNumbers(int m, int n)
{
    if(m>n)
        return 0;
   return m + SumOfNumbers(m+1, n);
}
//3. Write a program in C to Print Fibonacci Series using recursion. Input number of terms for the Series
int fibonac(int n)
{
    if(n==1)
        return 0;
    if(n==2)
       return 1;
    return fibonac(n-1)+fibonac(n-2);
}
//4. Write a program in C to print the array elements using recursion.
void printAll(int* a, int i, int max)
{
    if(i>=max)
        return;
    printf("\n%d", *(a+i));
    printAll(a, i+1, max);
}

//5. Write a program in C to count the digits of a given number using recursion.
int countDigits(int num)
{
    if(num==0)
        return 0;
    return 1+countDigits(num/10);
}
// 6. Write a program in C to find the sum of digits of a number using recursion.
int SumOfDigits(int num)
{
    if(num==0)
        return 0;
    return (num%10)+SumOfDigits(num/10);
}
// 7. Write a program in C to find GCD of two numbers using recursion.
int FindGcd(int num1, int num2)
{
    if(num2 == 0)
        return num1;
    FindGcd(num2, (num1%num2));
}
//8. Write a program in C to get the largest element of an array using recursion.
int MaxElement(int* arr, int max, int i, int size)
{
    if(i>=size)
        return max;
    if(*(arr+i) > max)
        max = *(arr+i);
    MaxElement(arr, max, i+1, size);
}
// 9. Write a program in C to reverse a string using recursion.
char* ReverseStr(char* str)
{
    static char revArr[MAX];
    static int i=0;
    if(*str != '\0')
    {
     ReverseStr(str+1);
    revArr[i++] = *(str);
    }
    return revArr;
}
// 10. Write a program in C to find the Factorial of a number using recursion.
int factorial(int n)
{
    if(n==1 || n==0)
        return 1;
    return (n)*factorial(n-1);
}
// 11. Write a program in C to convert a decimal number to binary using recursion.
void DecToBin(int n)
{
    if(n==0)
        return;
   printf("%d ", n%2);
   DecToBin(n/2);
}
// 12. Write a program in C to check a number is a prime number or not using recursion.
int primeN(int n, int i)
{
    if(i>n)
        return 0;
    static int count = 0;
    if(n%i==0)
        count++;
    primeN(n, i+1);
    return count;
}
//  13. Write a program in C to input two numbers and find the LCM of those two numbers using recursion.
int LCM(int n, int m)
{
    static int temp;
    temp += m;
    if(temp %n == 0 && temp%m == 0)
        return temp;
    LCM(n, m);
}
// 14. Write a program in C to print even or odd numbers in given range using recursion.
void EvenOdd(int min, int max)
{
   if(min>max)
        return;
    if(min % 2 == 0)
        printf("%d is an Even number\n", min);
    else
        printf("%d is an Odd number\n", min);
    EvenOdd(min+1, max);
}
// 15. Write a program in C to calculate the power of any number using recursion.
int power(int n, int exp)
{
    if(exp==0)
        return 1;
    return n*power(n, exp-1);
}
int main()
{
    /*
// 15. Write a program in C to calculate the power of any number using recursion.
    int n, m;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Enter the exponent: ");
    scanf("%d", &m);
    printf("\n%d power %d = %d", n, m, power(n, m));
    */

    /*
// 14. Write a program in C to print even or odd numbers in given range using recursion.
    int n, m;
    printf("Enter the bigger number: ");
    scanf("%d", &n);
    printf("Enter the smaller number: ");
    scanf("%d", &m);
    if(n>m)
    {
        EvenOdd(m, n);
    }
    else
    {
         EvenOdd(n, m);
    }
    */

    /*
//  13. Write a program in C to input two numbers and find the LCM of those two numbers using recursion.
    int n, m, lcmVal=0;
    printf("Enter the bigger number: ");
    scanf("%d", &n);
    printf("Enter the smaller number: ");
    scanf("%d", &m);
    if(n>m)
    {
       lcmVal = LCM (n, m);
    }
    else
    {
        lcmVal = LCM (m, n);
    }

    printf("%d\n", lcmVal);
    */

    /*
// 12. Write a program in C to check a number is a prime number or not using recursion.

    int n;
    scanf("%d", &n);
    int p = primeN(n, 1);
    if(p>2)
        printf("The number is not a prime number");
    else
        printf("The number is a prime number");
*/

/*
// 11. Write a program in C to convert a decimal number to binary using recursion.
    int n;
    scanf("%d", &n);
    DecToBin(n);
*/

/*
// 10. Write a program in C to find the Factorial of a number using recursion.
    int n;
    scanf("%d", &n);
    printf("%d", n);
    int fact = factorial(n);
    printf("The factorial is %d \n", fact);
*/

/*

// 9. Write a program in C to reverse a string using recursion.
char str[MAX];
char *str2;
printf("Enter A String: ");
gets(str);
printf("The Original String == %s\n", str);
str2 = ReverseStr(str);
printf("The reversed String == %s\n", str2);

*/

/*

//8. Write a program in C to get the largest element of an array using recursion.
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int arr[size];
    int i;
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int max = MaxElement(arr, arr[1], 0, size);
    printf("max = %d\n", max);

*/
    /*

// 7. Write a program in C to find GCD of two numbers using recursion.
    int num1, num2;
    printf("Enter bigger numbers: ");
    scanf("\n%d", &num1);
    printf("Enter smaller numbers: ");
    scanf("\n%d", &num2);
    int gcd = (num1, num2);
    printf("The GCD is %d", gcd);

    */
/*
// 6. Write a program in C to find the sum of digits of a number using recursion.
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int sum = SumOfDigits(num);
    printf("%d", sum);
*/

/*
//5. Write a program in C to count the digits of a given number using recursion.
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int total = countDigits(num);
    printf("The number of digits is %d", total);
*/
       /*
//4. Write a program in C to print the array elements using recursion.
    int max;
    printf("Enter the number of elements: ");
    scanf("%d", &max);
    int arr[max];
    int i;
    for(i=0; i<max; i++)
    {
        scanf("%d", &arr[i]);
    }
    printAll(arr, 0, max);
       /*

    /*
//3. Write a program in C to Print Fibonacci Series using recursion. Input number of terms for the Series
     int c;
     printf("Enter the limit number: ");
     scanf("%d", &c);
    for(int i=1; i<=c; i++)
    {
       printf("%d\n", fibonac(i));
    }
    */

    /*
//2. Write a program in C to calculate the sum of numbers from 1 to n using recursion.
    int n;
    printf("Enter the limit number: ");
    scanf("%d", &n);
    int m=1;
    printf("%d is the sum of integers from 1 up to %d", SumOfNumbers(1, n), n);
    */

    /*
//1. Write a program in C to print first 50 natural numbers using recursion.
    printNaturalNumber(1);
    */

    return 0;
}
