//1. Define a class Complex to represent a complex number with instance variables a and b to store real and imaginary parts. Also 
//   define following member functions
//   a) void setData(int,int)
//   b) void showData()
//   c) Complex add(Complex)
//   d) Complex subtract(Complex)
//   e) Complex multiply(Complex)
//2. Define a class Time to represent a time with instance variables h,m and s to store hour, minute and second. Also define following 
//   member functions
//   a) void setTime(int,int,int)
//   b) void showTime()
//   c) void normalize()
//   d) Time add(Time)
//   e) bool is_greater(Time)
//3. Define a class TestResult with properties roll_no,right,wrong,net_score. Also define class properties right_weitage, wrong_weightage.
//   Provide methods to set and get all the properties.
//4. Write a driver function main() to use TestResult class(Question 3). Create an array to 5 TestResult object, set values to all the objects
//   and display the result in sorted order(by net_score).
//5. Define a class Matrix to represent a 3*3 order matrix. Provide appropriate methods and properties to the class. Also define following 
//   methods in the class.
//   a) Matrix add(Matrix)
//   b) Matrix sub(Matrix)
//   c) Matrix multiply(Matrix)
//   d) Matrix transpose()
//   e) bool is_singular() 
#include<iostream>
using namespace std;
class Complex
{
    private:
        int a,b;
    public: 
        void setData(int x,int y)
        {
            a=x;
            b=y;
        }
        void showData()
        {
            cout<<"Real="<<a<<"  Imaginary="<<b<<endl;
        }
        Complex add(Complex C)
        {
            Complex temp;
            temp.a=a+C.a;
            temp.b=b+C.b;
            return temp;
        }  
        Complex subtract(Complex C)
        {
            Complex temp;
            temp.a=a-C.a;
            temp.b=b-C.b;
            return temp;
        }  
        Complex multiply(Complex C)
        {
            Complex temp;
            temp.a=a*C.a-b*C.b;
            temp.b=a*C.b+b*C.a;
            return temp;
        }  
};
class Time 
{
    private:
        int h,m,s;
    public:
        void setTime(int a,int b,int c)
        {
            h=a;
            m=b;
            s=c;
        }
        void showTime()
        {
            cout<<"Hour="<<h<<", Minute="<<m<<", Second="<<s<<endl;
        }
        void normalize()
        {
            m=m+s/60;
            s=s%60;
            h=h+m/60;
            m=m%60;
        }
        Time add(Time t)
        {
            Time temp;
            temp.s=s+t.s;
            temp.m=m+t.m;
            temp.h=h+t.h;
            temp.normalize();
            return temp;
        }
        bool is_greater(Time t)
        {
            if(h>t.h)
                return true;
            else if(h<t.h)
                return false;
            else if(m>t.m)
                return true;
            else if(m<t.m)
                return false;
            else if(s>t.s)
                return true;
            else 
                return false;
        }
};
class TestResult
{
    private:
        int roll_no,right,wrong,net_score;
        static int right_weightage,wrong_weightage;
    public:
        void setRollNo(int r) {roll_no=r;}
        void setRight(int r) {right=r;}
        void setWrong(int w) {wrong=w;}
        void setNetScore(int n) {net_score=n;}
        int getRollNo() {return roll_no;}
        int getRight() {return right;}
        int getWrong() {return wrong;}
        int getNetScore() {return net_score;}
        static void setRightWeightage(int r) {right_weightage=r;}
        static void setWrongWeightage(int w) {wrong_weightage=w;}
        static int getRightWeightage() {return right_weightage;}
        static int getWrongWeightage() {return wrong_weightage;}
};
int TestResult::right_weightage=3;
int TestResult::wrong_weightage=1;
void setTestResult(TestResult tr, int a,int b,int c)
{
    tr.setRollNo(a);
    tr.setRight(b);
    tr.setWrong(c);
    tr.setNetScore(b*tr.getRightWeightage()-c*tr.getWrongWeightage());
}
void printTestResult(TestResult tr)
{
    cout<<"\n"<<tr.getRollNo()<<" "<<tr.getRight()<<" "<<tr.getWrong()<<" "<<tr.getNetScore();
}
void sortByNetScore(TestResult result[],int size)
{
    int r,i;
    TestResult temp;
    for(r=1;r<=size-1;r++)
    {
        for(i=0;i<=size-1-r;i++)
        {
            if(result[i].getNetScore()>result[i+1].getNetScore())
            {
                temp=result[i];
                result[i]=result[i+1];
                result[i+1]=temp;
            }
        }
    }
}
int main()
{
    TestResult result[5];
    setTestResult(result[0],100,80,20);
    setTestResult(result[1],101,70,10);
    setTestResult(result[2],103,90,0);
    setTestResult(result[3],104,60,15);
    setTestResult(result[4],105,50,12);
    sortByNetScore(result,5);
    for(int i=0;i<=4;i++)
        printTestResult(result[i]);
    cout<<endl;
    return 0;
}
class Matrix
{
    private:
        int A[3][3];
    public:
        void setMatrix(int a[][3])
        {
            for(int i=0;i<=2;i++)
                for(int j=0;j<=2;j++)
                    A[i][j]=a[i][j];
        }
        void printMatrix()
        {
            for(int i=0;i<=2;i++)
            {
                for(int j=0;j<=2;j++)
                    cout<<A[i][j]<<" ";
                cout<<endl;
            }
        }
        Matrix add(Matrix M)
        {
            Matrix temp;
            for(int i=0;i<=2;i++)
                for(int j=0;j<=2;j++)
                {
                    temp.A[i][j]=A[i][j]+M.A[i][j];
                }
            return temp;
        }
        Matrix subtract(Matrix M)
        {
            Matrix temp;
            for(int i=0;i<=2;i++)
                for(int j=0;j<=2;j++)
                {
                    temp.A[i][j]=A[i][j]-M.A[i][j];
                }
            return temp;
        }
        Matrix multiply(Matrix M)
        {
            Matrix temp;
            int i,j,s,k;
            for(i=0;i<=2;i++)
            {
                for(j=0;j<=2;j++)
                {
                    for(s=0,k=0;k<=2;k++)
                        s=s+A[i][k]*M.A[k][j];
                    temp.A[i][j]=s;
                }
            }
            return temp;
        }
        Matrix transpose()
        {
            Matrix temp;
            for(int i=0;i<=2;i++)
                for(int j=0;j<=2;j++)
                    temp.A[i][j]=A[j][i];
            return temp;
        }
        bool is_singular()
        {
            int d;
            d=A[0][0]*(A[1][1]*A[2][2]-A[2][1]*A[1][2])-A[0][1]*(A[1][0]*A[2][2]-A[2][0]*A[1][2])+A[0][2]*(A[1][0]*A[2][1]-A[2][0]*A[1][1]);
            return d==0;
        }
};