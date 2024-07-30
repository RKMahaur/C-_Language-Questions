//Define a function to swap data of two int variables using call by reference.

#include<iostream>
using namespace std;
void swap(int*, int*);

void swap (int *p,int *q)
{
    int t;
    t=*p;
    *p=*q;
    *q=t;
}
int main()
{
    int x,y;
    cout<<"Enter the values of x an y : ";
    cin>>x>>y;
    swap(&x,&y);
    cout<<"values of x and y after swapping is "<<x<<" and "<<y;
    return 0;
}