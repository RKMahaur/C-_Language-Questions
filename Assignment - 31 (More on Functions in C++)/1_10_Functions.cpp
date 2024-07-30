//1. Define a function to sort an array of integers in ascending or descending order depending on bool type argument
//   (true for ascending and false for descending). Use default argument to implement it.
//2. Define a function to sort an array of strings in ascending or descending order depending on bool type argument (true for 
//   ascending and false for descending). Use default argument to implement it.
//3. Define a function to rotate an array by n positions in the d direction. Implement position and direction using default arguments.
//   Argument n should be the last argument with default value 1.
//4. Define a function to calculate LCM of three numbers.
//5. Define a function to print all the prime factors of a given number.[for example num=36, prime factors are 2,3]
//6. Define a function to calculate HCF of two numbers.
//7. Define overloaded function to calculate volume of a cuboid, cone and sphere.
//8. Define a function to print a substring from startindex(inclusive) to endindex(exclusive). Define function in such a way that
//   if second argument is not provided, string will print till the last possible index.
//9. Define a function to swap two arrays.
//10. Define a function to merge two sorted arrays of same size.

#include<iostream>
#include<string.h>
using namespace std;
void sortarray(int[],int,bool asc=true);
void sortstring(char* [],int,bool asc=true);
void rotatearray(int [],int,int d=1,int n=1);
int lcm(int,int,int);
void primefactors(int);
int nextprime(int);
bool isprime(int);
int hcf(int,int);
float volume(int,int,int);
float volume(int,int);
float volume(int);
void printsubstring(char [],int,int=-1);
void swaparray(int [],int [],int);
void mergearray(int [],int [],int [],int);

void sortarray(int A[], int n, bool asc)
{
    int i,r,temp;
    if(asc)
    {
        for(r=1;r<=n-1;r++)
        {
            for(i=0;i<=n-1-r;i++)
            {
                if(A[i]>A[i+1])
                {
                    temp=A[i];
                    A[i]=A[i+1];
                    A[i+1]=temp;
                }
            }
        }
    }
    else
    {
        for(r=1;r<=n-1;r++)
        {
            for(i=0;i<=n-1-r;i++)
            {
                if(A[i]<A[i+1])
                {
                    temp=A[i];
                    A[i]=A[i+1];
                    A[i+1]=temp;
                }
            }
        }
    }
}
void sortstring(char* A[], int n, bool asc)
{
    int i,r;
    char temp[50];
    if(asc)
    {
        for(r=1;r<=n-1;r++)
        {
            for(i=0;i<=n-1-r;i++)
            {
                if(strcmp(A[i],A[i+1])>0)
                {
                    strcpy(temp,A[i]);
                    strcpy(A[i],A[i+1]);
                    strcpy(A[i+1],temp);
                }
            }
        }
    }
    else
    {
        for(r=1;r<=n-1;r++)
        {
            for(i=0;i<=n-1-r;i++)
            {
                if(strcmp(A[i],A[i+1])<0)
                {
                    strcpy(temp,A[i]);
                    strcpy(A[i],A[i+1]);
                    strcpy(A[i+1],temp);
                }
            }
        }
    }
}
void rotatearray(int A[],int N, int d, int n)
{
    int i,temp;
    if(d==1)
    {
        while(n)
        {
            temp=A[N-1];
            for(i=N-1;i>=1;i--)
            {
                A[i]=A[i-1];
            }
            A[0]=temp;
            n--;
        }
    }
    else
    {
        while(n)
        {
            temp=A[0];
            for(i=0;i<=N-2;i++)
            {
                A[i]=A[i+1];
            }
            A[N-1]=temp;
            n--;
        }
    }
}
int lcm(int a,int b,int c)
{
    int L;
    for(L=a>b?a>c?a:c:b>c?b:c;L<=a*b*c;L++)
        if(L%a==0 && L%b==0 && L%c==0)
            return L;
    return 1;
}
void primefactors(int n)
{
    int i;
    for(i=2;i<=n;i=nextprime(i))
        if(n%i==0)
            cout<<i<<endl;
}
int nextprime(int n)
{
    while(!isprime(++n))
    return n;
}
bool isprime(int n)
{
    for(int i=2;i<n;i++)
        if(n%i==0)
            return false;
    return true;
}
int hcf(int a,int b)
{
    int h;
    for(h=a<b?a:b;h>=1;h--)
        if(a%h==0 && b%h==0)
            return h;
    return 1;
}
float volume(int l,int b,int h) //cuboid
{
    return l*b*h;
}
float volume(int r,int h) //cone
{
    return 0.33*3.14*r*r*h;
}
float volume(int r) //sphere
{
    return 1.33*3.14*r*r*r;
}
void printsubstring(char str[],int startindex,int endindex)
{
    int i;
    if(endindex==-1)
        endindex=strlen(str);
    for(i=startindex;i<endindex;i++)
        cout<<str[i];
}
void swaparray(int a[],int b[],int n)
{
    int temp,i;
    for(i=0;i<n;i++)
    {
        temp=a[i];
        a[i]=b[i];
        b[i]=temp;
    }
}
void mergearray(int a[],int b[],int c[], int size)
{
    int i=0,j=0,k=0;
    for(i=0;i<size && j<size;k++)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
        }
        else
        {
            c[k]=b[j];
            j++;
        }
    }
    while(i<size)
    {
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<size)
    {
        c[k]=b[i];
        j++;
        k++;
    }
}
int main()
{
    return 0;
}