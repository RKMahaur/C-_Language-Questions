//Write a function using default argument that is able to add 2 or 3 numbers.

#include<iostream>
using namespace std;
inline int add(int,int,int=0);

int add(int x,int y,int z=0)
{
    return x+y+z;
}
int main()
{
    return 0;
}