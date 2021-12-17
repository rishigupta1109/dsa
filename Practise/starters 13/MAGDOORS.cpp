#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    int flip_count=0;
    bool flipped=false;
    for(int i=0;i<s.length();i++){
        if(!flipped){
            if(s[i]=='0'){
                flip_count++;
                flipped=!flipped;
            }
        }
        else{
            if(s[i]=='1'){
                flip_count++;
                flipped=!flipped;
            }
        }
    }
    cout<<flip_count<<endl;
} 
}