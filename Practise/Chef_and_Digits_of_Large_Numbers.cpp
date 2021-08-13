#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
    int factorial=n;
    for(int i=1;i<n;i++){
        factorial=factorial*i;
    }
    return factorial;
}
int main(){
 int t;
cin>>t;
vector <int> answer;
while(t--){
    int n;
    cin>>n;
    int count=0;
    for(int i=1;i<=n;i++){
        int digits=0;
        int number=i;
        int product_of_digits=1;
        while(number!=0){
            int x=number%10;
            product_of_digits=product_of_digits*x;
            number=number/10;
            ++digits;
        }
        if(product_of_digits>=factorial(digits)){
            ++count;
        }
    }
    answer.push_back(count);
}
for(int i=0;i<answer.size();i++){
    cout<<answer[i]<<endl;
}
}