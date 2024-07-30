//Define overloaded functions to calculate area of circle, area of rectangle and area of triangle.

#include<iostream>
#include<math.h>
using namespace std;
float area(int);
int area(int,int);
double area(int,int,int);

float area(int r)
{
    return 3.14*r*r;
}
int area(int l,int b)
{
    return l*b;
}
double area(int a, int b, int c)
{
    float s=(a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main()
{
    return 0;
}