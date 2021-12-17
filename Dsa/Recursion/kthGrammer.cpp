#include<bits/stdc++.h>
using namespace std;
int solve(int n,int k){
    if(n==1){
        return 0;
    }
    bool compliment=false;
    if(k>pow(2,n-2)){
        k=k-pow(2,n-2);
        compliment=true;
    }
    int x=solve(n-1,k);
    return compliment?1-x:x;
}
int main(){
    cout<<solve(4,8);
}