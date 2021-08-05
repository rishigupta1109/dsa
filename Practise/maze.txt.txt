#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    char direction_map[n][m];
    int tile_lock[n][m]={};
    int cost=0;
    int x=0,y=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>direction_map[i][j];
        }
    }
  
    while(true){
        tile_lock[x][y]=1;
        if(direction_map[x][y]=='U'){
            if(x-1>=0){
                if(tile_lock[x-1][y]==0){
                    x=x-1;
                }
                else{
                    if(x>y){
                        if(y+1<=m){y++;}
                        else if(x+1<=n){x++;}
                        }
                    else{if(x+1<=n){x++;}
                        else if(y+1<=m){y++;}}
                    ++cost;
                }
            }
            else{
                if(x>y){
                        if(y+1<=m){y++;}
                        else if(x+1<=n){x++;}
                        }
                    else{if(x+1<=n){x++;}
                        else if(y+1<=m){y++;}}
                    ++cost;
            }
        }
        else if(direction_map[x][y]=='D'){
            if(x+1<=n){
                if(tile_lock[x+1][y]==0){
                    x=x+1;
                }
                else{
                     if(x>y){
                        if(y+1<=m){y++;}
                        else if(x+1<=n){x++;}
                        }
                    else{if(x+1<=n){x++;}
                        else if(y+1<=m){y++;}}
                    ++cost;
                }
            }
            else{
               if(x>y){
                        if(y+1<=m){y++;}
                        else if(x+1<=n){x++;}
                        }
                    else{if(x+1<=n){x++;}
                        else if(y+1<=m){y++;}}
                    ++cost;
            }
        }
        else if(direction_map[x][y]=='R'){
            if(y+1>=m){
                if(tile_lock[x][y+1]==0){
                    y=y+1;
                }
                else{
                     if(x>y){
                        if(y+1<=m){y++;}
                        else if(x+1<=n){x++;}
                        }
                    else{if(x+1<=n){x++;}
                        else if(y+1<=m){y++;}}
                    ++cost;
                }
            }
            else{
                if(x>y){
                        if(y+1<=m){y++;}
                        else if(x+1<=n){x++;}
                        }
                    else{if(x+1<=n){x++;}
                        else if(y+1<=m){y++;}}
                    ++cost;
            }
        }
        else if(direction_map[x][y]=='L'){
            if(y-1>=m){
                if(tile_lock[x][y-1]==0){
                    y=y-1;
                }
                else{
                     if(x>y){
                        if(y+1<=m){y++;}
                        else if(x+1<=n){x++;}
                        }
                    else{if(x+1<=n){x++;}
                        else if(y+1<=m){y++;}}
                    ++cost;
                }
            }
            else{
                if(x>y){
                        if(y+1<=m){y++;}
                        else if(x+1<=n){x++;}
                        }
                    else{if(x+1<=n){x++;}
                        else if(y+1<=m){y++;}}
                    ++cost;
            }
        }
        if(x==n-1&&y==m-1){
            break;
        }
    }
    cout<<cost<<endl;
     
    
}