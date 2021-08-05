#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

void Butterfly(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<'*';
        }
        for(int j=0;j<2*(n-i)-2;j++){
            cout<<" ";
        }
         for(int j=0;j<=i;j++){
            cout<<'*';
        }
        cout<<endl;

        
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<'*';
        }
        for(int j=0;j<2*(i+1)-2;j++){
            cout<<" ";
        }
         for(int j=0;j<n-i;j++){
            cout<<'*';
        }
        cout<<endl;

        
    }
}
void pallindromicpattern(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<2*(n-i)-2;j++){
            cout<<" ";
        }
        for(int j=i+1;j>0;j--){
            cout<<j<<' ';
        }
        for(int j=2;j<=i+1;j++){
            cout<<j<<' ';
        }
        cout<<endl;
    }

}
void zigzagpattern(){
    int n;
    cin>>n;
    int m=3;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           if(i==0){
               if((j%4==2||j==2)){
                   cout<<'*';
               }
               else{
                   cout<<' ';
               }
           }
           else if(i==1){
               if(j%2==1){cout<<'*';}
               else{cout<<' ';}
           }
           else{
               if(j%4==0){cout<<'*';}
               else{cout<<' ';}
           }
        }
    cout<<endl;
    }
}
int digits(int n){
    int digits=0;
    while(n>0){
        n=n/10;
        ++digits;
    }
    return digits;
}
void binaryTodecimal(){
    int n;
    cin>>n;
    int digit=digits(n);
    // cout<<digit<<" ";
    int answer=0;
    int counter=0;
    while(n>0){
        int x=n%10;
        answer =answer+ x*pow(2,counter);
        // cout<<answer<<' ';
        ++counter;
        n =n/10;
    }
    cout<<answer;

}
void decimalTobinary(){
    int n;
    cin>>n;
    vector<int> v;
    while(n>0){
        int x=n%2;
        // cout<<x<<" ";
        v.push_back(x);
        n=n/2;
    }
     for (auto i = v.begin(); i != v.end(); ++i)
        {cout << *i ;}
}

int main(){
//    Butterfly();
// pallindromicpattern();
// zigzagpattern();
// binaryTodecimal();
decimalTobinary();
}