// Define a function to print a Pascal Triangle up to N lines.

#include<iostream>
using namespace std;
void pascal(int);
int comb(int,int);
int fact(int);

void pascal(int n)
{
    int i,j,k,y;
    for(i=1;i<=n;i++)
    {
        y=0;
        for(j=1,k=1;j<=2*n-1;j++)
        {
            if(j>=n+1-i && j<=n-1+i)  
            {  
                if(k)
                    cout<<comb(i-1,y++);
                else
                    cout<<" ";
                k=1-k;
            }
            else
                cout<<" ";
        }
        cout<<endl;
    }
}
int comb(int x,int y)
{
    int z;
    z=fact(x)/(fact(x-y)*fact(y));
    return z;
}
int fact(int a)
{
    int fact=1,i;
    while(a)
    {
        fact=fact*a;
        a--;
    }
    return fact;
}
int main()
{
    int x;
    cout<<"Enter number of line for pascal triangle : ";
    cin>>x;
    pascal(x);
    return 0;
}