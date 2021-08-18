#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    vector<int> Answer;
    for(int j=0;j<T;j++){
        int N;
        scanf("%d",&N);
        int Array[N];
        for(int i=0;i<N;i++ ){
            Array[i]=0;
        }
        int O;
        scanf("%d",&O);
        map<int,int> m;
        for(int c=0;c<O;c++){
            int a,b;
            scanf("%d",&a);
            scanf("%d",&b);
            m[a]=b;
        }
        
       vector<pair<int,int>> p;
        for(auto m:m){
           p.push_back(make_pair(m.first,m.second));
        }
        for(int d=(p.size()-1);d>=0;d--){
            
            for(int e=0;e<N;e++){
                if((e+1)%p[d].second!=0){
                if(Array[e]==0){Array[e]=p[d].first;}
                }
            }
        }
        int sum=0;
        for(int f=0;f<N;f++){
            sum = sum +Array[f];
        }
        Answer.push_back(sum);
    }
    for(int g=0;g<Answer.size();g++){
        printf("%d \n",Answer[g]);
    }

}