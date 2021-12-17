#include <iostream>
using namespace std;
char winner(char c,char s){
    if(c=='R'&&s=='P'){
        return s;
    }
    else if(c=='R'&&s=='S'){
        return c;
    }
    else if(c=='P'&&s=='S'){
        return s;
    }
    else if( c=='P'&&s=='R'){
        return c;
    }
    else if(c=='S'&&s=='R'){
        return s;
    }
    else if(c=='S'&&s=='P'){
        return c;
    }
    else {
        return c;
    }
}
int main() {
	long t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    char s[n+1];
	    for(int i=0;i<n;i++){
			cin>>s[i];
		}
	
	    char ans[n];
	    for(int i=n-1;i>=0;i--){
			if(i!=(n-1)&&winner(s[i],s[i+1])==s[i+1]){
				ans[i]=ans[i+1];
			}
			else if(i!=n-1&&winner(s[i],s[i+1])==s[i]){
				bool flag=false;
				for(int k=i+2;k<n;k++){
					if(winner(s[i],s[k])==s[k]){
						ans[i]=ans[k];
						flag=true;
					}
				}
				if(!flag){
					ans[i]=s[i];
				}
			}
			else{
				ans[i]=s[i];
	        	for(int j=i+1;j<n;j++){
	            	 ans[i]=winner(ans[i],s[j]); 
	        	}
		
			}
	    }
	
	    for(int i=0;i<n;i++){
	        cout<<ans[i];
	    }
	    cout<<endl;
	}
	return 0;
}
 