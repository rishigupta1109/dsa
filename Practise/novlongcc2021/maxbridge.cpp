#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<n;i++){
            if(m){
                cout<<i<<" "<<i+1<<endl;
                m--;
            }
        }
        for(int i=3;i<=n;i++){
            for(int j=1;j<i-1;j++){
               if(m){ cout<<j<<" "<<i<<endl;m--;}
            }
        }
        
        
    }
	return 0;
}
