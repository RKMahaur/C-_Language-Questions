//Write a C++ program to calculate the area of a circle.

#include<iostream>
using namespace std;
int main()
{
    int r;
    float y;
    cout<<"Enter radius of circle : ";
    cin>>r;
    y=3.14*r*r;
    cout<<"Area of Circle is "<<y;
    return 0;
}