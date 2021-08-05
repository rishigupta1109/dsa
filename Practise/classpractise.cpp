#include<bits/stdc++.h>
using namespace std;
class EMPLOYEE
{
private:
    int salary;
public:
    int id;
    EMPLOYEE(int s ){   cout<<"constructor called"<<endl;
    salary=s;
}
    ~EMPLOYEE(){
    cout<<"destructor called"<<endl;
}
    void showData(){
        cout<<"salary is : "<< salary<<endl;
        cout<<"id is : "<< id<<endl;
    }
};

class Complex
{
private:
   int a,b;
public:
friend Complex sumcomplex(Complex a,Complex b);
friend class calculator;
    Complex(int a,int b){
    this->a=a;
    this->b=b;}
    Complex(){
    this->a=0;
    this->b=0;}
   
    void showData(){
        cout<<"num is : "<<a<<"+"<<b<<'i'<<endl;
    }
    void sumComplex(Complex a, Complex b){
        this->a=a.a+b.a;
        this->b=a.b+b.b;
    }

    
};
Complex sumcomplex(Complex a,Complex b){
    Complex c;
    c.a=a.a+b.a;
    c.b=a.b+b.b;
    cout<<"C";
    c.showData();
    return c;
   
}
class calculator
{
private:
    int a,b;
public:
    calculator(int x=0,int y=0){
        a=x,b=y;
    };
    void sumcalculator(calculator a,calculator b){
        Complex x(a.a,a.b);
        Complex y(b.a,b.b);
        Complex z;
        z.sumComplex(x,y);
        z.showData();
    }
    
};






int main(){ 
    calculator x(1,2);
    calculator y(4,5);
    calculator z;
    z.sumcalculator(x,y);
    
}