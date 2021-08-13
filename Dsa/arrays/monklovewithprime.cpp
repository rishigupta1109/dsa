#include<bits/stdc++.h>
using namespace std;
int convert_ascii(char c){
	if((int)c>=65&&(int)c<=90){
        cout<<(0-((int)c+32))<<endl;
		return (0-((int)c+32));
	}
	else{
           cout<<(((int)c-32))<<endl;
		return (((int)c-32));
	}
}
int main(){
	string s;
	getline(cin,s);
	int sum=0;
	for(int i=0;i<s.length();i++){
		sum=sum+convert_ascii(s[i]);

	}
    cout<<sum<<endl;
	bool isPrime=true;
    sum=abs(sum);
	for(int i=2;i*i<sum;i++){
		if(sum%i==0){
			isPrime=false;
			break;
		}
	}
	cout<<isPrime;

}