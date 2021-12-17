#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int P,a,b,c,x,y;
    cin>>P>>a>>b>>c>>x>>y;
    int oA=b+(x*a);
    int oC=c+(y*a);
    int Max=0;
    if(oA<oC){
        Max=P/oA;
    }
    else{
        Max=P/oC;
    }
    cout<<Max<<endl;
} 
}