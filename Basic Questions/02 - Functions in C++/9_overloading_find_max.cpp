//Write functions using function overloading to find a maximum of two numbers and both the numbers can be intergers or real.

#include<iostream>
using namespace std;
int max(int,int);
double max(double,double);

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
double max(double a, double b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    return 0;
}