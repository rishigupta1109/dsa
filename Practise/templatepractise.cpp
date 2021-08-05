#include<bits/stdc++.h>
using namespace std;
    template <class t>
    class base
    {
    private:
    t a,b;
    public:
        base(t x,t y){
            a=x,b=y;
        };
        t sum(){
            cout<<a+b;
        }
       
    };
   
int main(){  
    base <int> hello(2,2);
    base <char> hii('a','b');
    hello.sum();
    hii.sum();
    
  
    
}