#include<iostream>
using namespace std;
int main(){
    int a;
    int b;
    cout<<"write value of a";
    cin>>a;   //a=3
    cout<<"write value of b";
    cin>>b;  //b=4

    a=a+b;  //a=7
    b=a-b;   //b=7-4=3
    a=a-b;    //a=7-3=4

    cout<<"after swapping value of a is "<<a
        <<"and value of b is"<<b;
}