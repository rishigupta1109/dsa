#include<bits/stdc++.h>
using namespace std;
void solve(int N,int s,int d,int h){
    if(N==1){
         cout<<"Moving disc "<<N<<" from "<<s<<" to "<<d<<endl;
         return ;
    }
    solve(N-1,s,h,d);
    cout<<"Moving disc "<<N<<" from "<<s<<" to "<<d<<endl;
    solve(N-1,h,d,s);
}
int main(){
    int N;
    cin>>N;
    solve(N,1,3,2);
}