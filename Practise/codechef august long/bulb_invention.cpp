#include<bits/stdc++.h>
using namespace std;

int main(){
long long int T;
cin>>T;
vector <int> Answer;
while(T--){
    long int N,p,k;
   cin>>N>>p>>k;  
    long int day_counter=0;
    long int days_in_one=0;
    if(k==1){
        Answer.push_back(p+1);
    }
    else if(k==N){
        Answer.push_back(p+1);
    }
    else{
// for(int i=0;i<=(N-1)/k;i++){
//     ++days_in_one;
// }
days_in_one=((((N-1)/k)+1));
long int counter=p%k;  
// for(int i=0;i<counter;i++){
//     if(i<=(N-1)%k){day_counter=day_counter+days_in_one;}
//     else{
//         day_counter=day_counter+(days_in_one-1);
//     }
// }
if((N-1)%k<counter){
    day_counter=days_in_one*(((N-1)%k)+1);
    day_counter=day_counter+(days_in_one-1)*((counter-1)-((N-1)%k));
}
else{
    day_counter=days_in_one*(counter);
}
for(long int i=0;i<=(N-1)/k;i++){
    day_counter++;
    if(i*k+counter==p){
        break;
    }
} 
 Answer.push_back(day_counter);
    }

}
for(long int i=0;i<Answer.size();i++){
   cout<<Answer[i]<<endl;
}
}