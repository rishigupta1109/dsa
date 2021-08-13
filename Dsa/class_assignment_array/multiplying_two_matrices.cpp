#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int Array1[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>Array1[i][j];
        }
    }
    int o,p;
    cin>>o>>p;
    if(m!=o){
        cout<<"column of 1st should be equal to row of 2nd";
        return 0;
    }
    int Array2[o][p];
    for(int i=0;i<o;i++){
        for(int j=0;j<p;j++){
            cin>>Array2[i][j];
        }
    }
    int product_array[n][p];
    for(int i=0;i<o ;i++){
        for(int j=0;j<p;j++){
            int sum=0;
            for(int k=0;k<m;k++){
                sum =sum +Array1[i][k]*Array2[k][j];
            }  
            product_array[i][j]=sum;
        }

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            cout<<product_array[i][j]<<" ";
        }
        cout<<endl;
    }
   
  
 
}