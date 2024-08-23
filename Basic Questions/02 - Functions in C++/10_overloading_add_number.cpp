//Write functions using function overloading to add two numbers having different data types.

#include<iostream>
using namespace std;
int add(int,int);
double add(double,double);

int add(int a, int b)
{
    return a+b;
}
double add(double a, double b)
{
    return a+b;
}
int main()
{
    return 0;
}