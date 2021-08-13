#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
cin>>T;
vector<int> Answer;
while(T--){
    int G1,S1,B1,G2,S2,B2;
    cin>>G1>>S1>>B1>>G2>>S2>>B2;
    if(G1+S1+B1>G2+S2+B2){
        Answer.push_back(1);
    }
    else{
        Answer.push_back(2);
    }
} 
for(int i=0;i<Answer.size();i++){
    cout<<Answer[i]<<endl;
}
}