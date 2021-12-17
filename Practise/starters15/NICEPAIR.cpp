#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
    if(n==1)return 1;
    return n*factorial(n-1);
}
int nCtwo(int n){
    return factorial(n)/(factorial(n-2)*2);
}
int main(){
int T;
cin>>T;
while(T--){
    int n;
    cin>>n;
    int count=0;
    char string[n+2];
    bool allsame=true;
    bool adjequal=true;
    for(int i=1;i<=n;i++){
        cin>>string[i];
        if(i!=1&&string[i]!=string[i-1]) adjequal=false;
        if(i!=string[i]) allsame=false;
    }
    if(adjequal){
         cout<<count<<endl;
        continue;
    }
    if(allsame){
        count=nCtwo(n);
        cout<<count<<endl;
        continue;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int x=string[i]-'0';
            int y=string[j]-'0';
            int z=abs(x-y);
            if(j-i==z){
                count++;
            }
        }
    }
    cout<<count<<endl;
} 
}