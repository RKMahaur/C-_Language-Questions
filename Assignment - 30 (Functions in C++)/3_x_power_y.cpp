//Define a function to calculate x raised to the power y.

#include<iostream>
using namespace std;
float power(int,int);

float power(int a,int b)
{
    if(b>0)
        return a*power(a,b-1);
    else if(b<0)
        return 1/a*power(a,b+1);
    else 
        return 1;
}
int main()
{
    int x,y;
    float z;
    cout<<"Enter the values of x and y in (x^y) : ";
    cin>>x>>y;
    z=power(x,y);
    cout<<x<<"^"<<y<<" is "<<z;
    return 0;
}