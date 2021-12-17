#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    string s;
    int a=0,b=0,c=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        switch (s[i])
        {
        case 'A':
            a++;
            break;
        case 'B':
            b++;
            break;
        case 'C':
            c++;
            break;
        
        default:
            break;
        }
    }
    if(a>b||c>b){
        cout<<"NO"<<endl;
    }
    else{
        b-=a;
        if(b==0&&c>0){
            cout<<"NO"<<endl;
        }
        else if(b==0&&c==0){
            cout<<"YES"<<endl;
        }
        else{
            b-=c;
            if(b==0){cout<<"YES"<<endl;}
            else{
                cout<<"NO"<<endl;
            }
        }
    }

} 
}