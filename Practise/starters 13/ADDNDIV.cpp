#include<iostream>
#include<cmath>
using namespace std;
int main(){
unsigned long long int t;
cin>>t;
while(t--){
    long double a,b;
    cin>>a>>b;
    long double x=0;
    long double y=((a/10)-floor(a/10))*10;
    while(y==0){
        a=a/10;
        y=((a/10)-floor(a/10))*10;
    }
    y=((b/10)-floor(b/10))*10;
    while(y==0&&(b/10)>a){
        b=b/10;
        y=((b/10)-floor(b/10))*10;
    }
    x=b/a;
    x=x*b;
    x=(x)-floor(x);
    if(x==0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    cout<<endl;
} 
}