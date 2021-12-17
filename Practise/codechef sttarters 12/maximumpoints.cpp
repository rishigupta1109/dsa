#include<bits/stdc++.h>
using namespace std;
bool sorted(int a,int b){
    return a%2!=0;
}
int main(){
int t;
cin>>t;
while(t--){
    double Time[3],Points[3];
    for(int i=0;i<3;i++){
        cin>>Time[i];
    }
    for(int i=0;i<3;i++){
        cin>>Points[i];
    }
    priority_queue<pair<double,int>> pq;
    vector<pair<int,int>> pq1;
    bool flag=true;
    for(int i=0;i<3;i++){
        double z=(Points[i]/Time[i]);
       pq1.push_back(make_pair(Points[i],i));
        pq.push(make_pair(z,i));
        if(Points[i]!=Time[i]){flag=false;}
    }
    
    int TotalPoints=0;
    int TotalTime=240;
    if(!flag){
        for(int i=0;i<3;i++){
            int x=pq.top().second;
            pq.pop();
            int y=TotalTime/Time[x];
            if(y>20){
                y=20;
            }
            TotalPoints+=y*Points[x];
            TotalTime-=y*Time[x];
        }
    }
    else{
        sort(pq1.begin(),pq1.end(),[](pair<int,int> a,pair<int,int> b){return a.first%2!=0;});
         
            int x1=pq1[0].second;
            int x2=pq1[1].second;
            int x3=pq1[2].second;
            int y1=TotalTime/Time[0];
            if(y1>20){
                y1=20;
            }
            TotalPoints+=y1*Points[0];
            TotalTime-=y1*Time[0];
            int y2=TotalTime/Time[1];
            int y3=TotalTime/Time[2];
           if(y2>20){
                        y2=20;
                    }
            if(y3>20){
                        y3=20;
                    }
                int p2=y2*Points[1];
                int p3=y3*Points[2];

                if(p2>p3){
                    TotalPoints+=y2*Points[1];
                    TotalTime-=y2*Time[1];
                    y3=TotalTime/Time[2];
                    if(y3>20){
                        y3=20;
                    }
                    TotalPoints+=y3*Points[2];
                    TotalTime-=y3*Time[2];
                }
                else{
                    TotalPoints+=y3*Points[2];
                    TotalTime-=y3*Time[2];
                    y2=TotalTime/Time[1];
                     if(y2>20){
                        y2=20;
                    }
                    TotalPoints+=y2*Points[1];
                    TotalTime-=y2*Time[1];
                }
         
            
        
            
    }
    cout<<TotalPoints<<endl;
} 
}