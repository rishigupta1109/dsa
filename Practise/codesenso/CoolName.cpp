#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    int sum=0;
    for(int i=1;i<=s.length();i++){
        int z=(int(s[i-1])-int('a')+1);
        sum+= z*i;
    }
    cout<<sum<<endl;
} 
}