#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n,a,b;
    cin>>n>>a>>b;
    int divisor=2;
    int pts=0;
    while(n!=1){
        if(divisor%2==0&&n%divisor==0){
            if(divisor==n){
                n=1;
                pts+=a;
            }
            if(a>0||a>b){
                pts+=a;
                n/=divisor;
                divisor=2;
            }
            
        }
        else if(divisor%2!=0&&n%divisor==0){
            if(divisor==n){
                n=1;
                pts+=b;
            }
            if(b>0||b>a){
                pts+=b;
                n/=divisor;
                divisor=2;
            }
            
        }
        
    }
    cout<<pts<<endl;

}
}