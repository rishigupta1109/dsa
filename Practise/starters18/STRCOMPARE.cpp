#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int ans=0;
        for(int i=0;i<s1.length();i++){
           string ss1=s1.substr(i,s1.length()-i);
           string ss2=s2.substr(i,s1.length()-i);
           if(ss1<ss2){
               ans++;
           }
        }
        cout<<ans<<endl;
    }
	return 0;
}
