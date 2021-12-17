#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
for(int j =1;j<=t;j++){
    int N,A;
    cin>>N>>A;
    if(N==3){
        int b=0,h=0;
        for(int i=2;i<A;i++){
            if(A%i==0){
                b=i;
                h=A/b;
                break;
            }
        }
        if(b!=0){
            cout<<"Case #"<<j<<": POSSIBLE"<<endl;
            cout<<"0 0"<<endl<<b<<" 0"<<endl<<b/2<<" "<<h<<endl;
        }
        else{
             cout<<"Case #"<<j<<": IMPOSSIBLE"<<endl;
        }
    }
    else if(N==4){
        A/=2;
        if(pow(int(sqrt(A)),2)==A){
            int b=sqrt(A);
            cout<<"Case #"<<j<<": POSSIBLE"<<endl;
            cout<<"0 0"<<endl<<b<<" 0"<<endl<<"0 "<<b<<endl<<b<<" "<<b<<endl;
        }
        else{
            int b=0,h=0;
            for(int i=2;i<A;i++){
                if(A%i==0){
                    b=i;
                    h=A/b;
                    break;
                }
            }
            if(b!=0){
                 cout<<"Case #"<<j<<": POSSIBLE"<<endl;
                   cout<<"0 0"<<endl<<b<<" 0"<<endl<<"0 "<<h<<endl<<b<<" "<<h<<endl;
            }
            else{
                  cout<<"Case #"<<j<<": IMPOSSIBLE"<<endl;
            }
        }
    }
    else if(N==5){
       
        A/=2;
        int base=0,height=0,h=0;
        for(int i=A-1;i>=2;i--){
            if(A%i==0){
                base=i;
                height=A/base;
                break;
            }
        }
        if(base!=0){
            if(pow(int(sqrt(base)),2)==base){
            int b=sqrt(base);
            h=(height*2)/b;
            if((height*2)/b==floor((height*2)/b))
            {
            cout<<"Case #"<<j<<": POSSIBLE"<<endl;
            cout<<"0 0"<<endl<<b<<" 0"<<endl<<"0 "<<b<<endl<<b<<" "<<b<<endl<<b/2<<" "<<b+h<<endl;
            }
            else{
                  cout<<"Case #"<<j<<": IMPOSSIBLE"<<endl;
            }
        }
        else{
                int l=0,w;
            for(int i=2;i>base;i++){
            if(base%i==0){
                l=i;
                w=base/i;
                break;
            }

            }
            if(l==0){
                  cout<<"Case #"<<j<<": IMPOSSIBLE"<<endl;
            }
            else
        { if((height*2)/w==floor((height*2)/w))
            {
            h=(height*2)/w;
            cout<<"Case #"<<j<<": POSSIBLE"<<endl;
            cout<<"0 0"<<endl<<w<<" 0"<<endl<<"0 "<<l<<endl<<w<<" "<<l<<endl<<w/2<<" "<<l+h<<endl;
            }
             else{
                  cout<<"Case #"<<j<<": IMPOSSIBLE"<<endl;
            }}
            
        }
       
        
        }
         else{
                  cout<<"Case #"<<j<<": IMPOSSIBLE"<<endl;
            }
       
    }
    
      
} 
}