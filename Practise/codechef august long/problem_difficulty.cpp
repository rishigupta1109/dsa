#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
cin>>T;
vector<int> Answer;
while(T--){
int A[4];
for(int i=0;i<4;i++){
    cin>>A[i];
}
vector<int> check_repeat(4,0);

for(int i=0;i<4;i++){
  if(A[i]!=-1){ 
    for(int j=i;j<4;j++){
        if(A[i]==A[j]){
           if(i!=j){ A[j]=-1;}
            check_repeat[i]++;
        }
    }

    }
}
int counter=0;
int twos=0;
for(int i=0;i<check_repeat.size();i++){
if(check_repeat[i]!=0){
    counter++;
}
if(check_repeat[i]==2){
    twos++;
}
}
if(twos==2){
    Answer.push_back(2);
}
else{
switch (counter)
{
case 1:
    Answer.push_back(0);
    break;
case 2:
    Answer.push_back(1);
    break;
case 3:
    Answer.push_back(2);
    break;
case 4:
    Answer.push_back(2);
    break;

default:
    break;
}}


} 
for(int i=0;i<Answer.size();i++){
    cout<<Answer[i]<<endl;
}
}