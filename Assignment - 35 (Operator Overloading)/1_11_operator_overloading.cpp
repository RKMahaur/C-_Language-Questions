/*
1. Define a class Complex with appropriate instance variables and member functions. Define following operators in the class:
   a) +
   b) -
   c) *
   d) ==
2. Create a class Time which contains hour, min and second as fields. Overload greater than.(>) operator to compare two time objects.
3. In Question-2, overload pre-increment and post-increment operator to increment Time object value by one second.
4. In Question-2, overload operator+ to add two Time objects.
5. Define a class matrix to represent 3x3 matrix. Provide appropriate instance methods. Also define operator+ , operator- ,operator* to 
   perform addition, subtraction and multiplication operations respectively.
6. Consider following class Numbers
   class Number
   {
        int x,y,z;
        public:
            //methods
   };
   Overload the operator unary minus(-) to negate the numbers.
7. Define a C++ class fraction
   class fraction
   {
        long numerator;
        long denominator;
        public:
            fraction(long n=0, long d=0);
   };
   Define an operator+ to add two fraction object.
8. In Question-7, define an operator < to compare two fraction objects.
9. Consider a class Distance 
   class Distance
   {
    int km,m,cm;
    public:
        //methods;
   };
   Overload the operator+ to add two distance objects.
10. In Question-9, define operator pre decrement and post decrement to decrease distance by 1 cm.
11. Consider the following class Array
    class Array
    {
        int *p;
        int size;
        public:
            //methods;
    };
    Define constructor to allocate an array of given size (size is given through parameter).
    Define a subscript operator to access element at given index. Define destructor to deallocate the memory of array.
*/

#include<iostream>
using namespace std;
#define ARRAY_INDEX_OUT_OF_BOUND 1
class Complex
{
    private: 
        int r,i;
    public:
        void setComplex(int a, int b)
        {
            r=a;
            i=b;
        }
        void showComplex()
        {
            cout<<"Real="<<r<<"  Imaginary="<<i<<endl;
        }
        Complex operator+(Complex C)
        {
            Complex temp;
            temp.r=r+C.r;
            temp.i=i+C.i;
            return temp;
        }
        Complex operator-(Complex C)
        {
            Complex temp;
            temp.r=r-C.r;
            temp.i=i-C.i;
            return temp;
        }
        Complex operator*(Complex C)
        {
            Complex temp;
            temp.r=r*C.r-i*C.i;
            temp.i=r*C.i+i*C.r;
            return temp;
        }
        bool operator==(Complex C)
        {
            if(r==C.r && i==C.i)
                return true;
            else
                return false;
        }
};
class Time 
{
    private:
        int hour,min,seconds;
    public:
        void setTime(int h,int m,int s)
        {
            hour=h;
            min=m;
            seconds=s;
        }
        void showTime()
        {
            cout<<"\n"<<hour<<":"<<min<<":"<<seconds<<endl;
        }
        bool operator>(Time T)
        {
            if(hour>T.hour)
                return true;
            else if(hour<T.hour)
                return false;
            else if(min>T.min)
                return true;
            else if(min<T.min)
                return false;
            else if(seconds>T.seconds)
                return true;
            else 
                return false;
        }
        Time operator++()//pre increment
        {
            seconds++;
            min=min+seconds/60;
            seconds=seconds%60;
            hour=hour+min/60;
            min=min%60;
            return *this;
        } 
        Time operator++(int)//post increment
        {
            Time temp=*this;
            seconds++;
            min=min+seconds/60;
            seconds=seconds%60;
            hour=hour+min/60;
            min=min%60;
            return temp;
        }
        Time operator+(Time T)
        {
            Time temp;
            temp.seconds=seconds+T.seconds;
            temp.min=min+T.min+temp.seconds/60;
            temp.seconds=temp.seconds%60;
            temp.hour=hour+T.hour+temp.min/60;
            temp.min=temp.min%60;
            return temp;
        }
};
class Matrix
{
    private:
        int M[3][3];
    public:
        void setMatrix()
        {
            cout<<"Enter 9 numbers for the matrix : ";
            for(int i=0;i<=2;i++)
                for(int j=0;j<=2;j++)
                    cin>>M[i][j];
        }
        void showMatrix()
        {
            for(int i=0;i<=2;i++)
            {
                for(int j=0;j<=2;j++)
                    cout<<M[i][j]<<"  ";
                cout<<endl;
            }
        }
        Matrix operator+(Matrix A)
        {
            Matrix result;
            for(int i=0;i<=2;i++)
                for(int j=0;j<=2;j++)
                   result.M[i][j]=M[i][j]+A.M[i][j]; 
            return result;
        }
        Matrix operator-(Matrix A)
        {
            Matrix result;
            for(int i=0;i<=2;i++)
                for(int j=0;j<=2;j++)
                    result.M[i][j]=M[i][j]-A.M[i][j]; 
            return result;
        }
        Matrix operator*(Matrix A)
        {
            Matrix result;
            int s;
            for(int i=0;i<=2;i++)
            {
                for(int j=0;j<=2;j++)
                {
                    for(int k=0;k<=2;k++)
                        s=s+M[i][k]*A.M[k][j]; 
                    result.M[i][j]=s;
                }
            }
            return result;
        }
};
class Numbers
{
    private:
        int x,y,z;
    public:
        Numbers operator-()
        {
            Numbers N;
            N.x=-x;
            N.y=-y;
            N.z=-z;
            return N;
        }
};
class Fraction
{
    private:
        long num;
        long den;
    protected:
        long lcm(int x,int y)
        {
            int L;
            for(L=x>y?x:y;L<=x*y;L++)
                if(L%x==0&&L%y==0)
                    return L;
        }
    public:
        Fraction(long n=0,long d=0):num(n),den(d)
        {}
        Fraction operator+(Fraction x)
        {
            Fraction temp;
            long L=lcm(den,x.den);
            temp.den=L;
            temp.num=((L/den*num)+(L/x.den*x.num));
            return temp;
        }
        bool operator<(Fraction x)
        {
            if((num*x.den)<(x.num*den))
                return true;
            else
                return false;
        }
};
class Distance
{
    private:
        int km,m,cm;
    public:
        void setDistance(int x,int y,int z)
        {
            km=x;
            m=y;
            cm=z;
        }
        void showDistance()
        {
            cout<<"\n"<<km<<" km, "<<m<<" m, "<<cm<<" cm."<<endl;
        }
        Distance operator+(Distance D)
        {
            Distance temp;
            temp.cm=cm+D.cm;
            temp.m=m+D.m+temp.cm/100;
            temp.cm%=100;
            temp.km=km+D.km+temp.m/1000;
            temp.m%=1000;
            return temp;
        }
        Distance operator--()//pre increment
        {
            if(cm>0)
                cm--;
            else
            {
                cm=99;
                if(m>0)
                    m--;
                else
                {
                    m=999;
                    km--;
                }
            }
            return *this;
        } 
        Distance operator--(int)//post increment
        {
            Distance temp=*this;
            if(cm>0)
                cm--;
            else
            {
                cm=99;
                if(m>0)
                    m--;
                else
                {
                    m=999;
                    km--;
                }
            }
            return temp;
        }
};
class Array
{
    private: 
        int *p;
        int size;
    public:
        Array(int s)
        {
            size=s;
            p=new int[size];
        }
        ~Array()
        {
            delete []p;
        }
        int& operator[](int index)
        {
            if(index <0 || index>=size)
            {
                cout<<"Array index out of bound.";
                throw ARRAY_INDEX_OUT_OF_BOUND;
            }
            return p[index];
        }
};