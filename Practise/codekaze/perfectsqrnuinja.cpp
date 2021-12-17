#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        unsigned long long int l,r;
        cin>>l>>r;
        unsigned long long int count=0;
        for(unsigned int long long i=l;i<=r;i++){
            unsigned long long int sum=0;
             unsigned long long int x=i;
            unsigned long long int y;
            while(x!=0){
                 y=x%10;
                sum+=y;
                x/=10;
            }
           
            if(sum%9==1||sum%9==4||sum%9==0||sum%9==7){
                if(sqrt(sum)*sqrt(sum)==sum){
                    count++;
                }
            }
        }
        cout<<count<<endl;
        
    }
}