#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<char> g[500];
bool visited[500][500];
bool mem[500][500];
int N,M;
bool dfs(int X,int Y){
    if(visited[Y][X]==true){
        return mem[Y][X];
    }
    visited[Y][X]=true;
   
    
    if(g[Y][X]=='D'){
        
        int DX,DY;
        DX=X;DY=Y+1;
        if(DY>=N){return mem[Y][DX]=1;}
        if(visited[DY][DX]==true){
            return mem[Y][X]=mem[DY][DX];
        }else{
            
            return mem[Y][X]=dfs(DX,DY);
        }
    }else if(g[Y][X]=='R'){
        
        int DX,DY;
        DX=X+1;DY=Y;
        if(DX>=M){
        mem[DY][X]=1;
        return mem[DY][X];}
        if(visited[DY][DX]==true){
            return mem[Y][X]=mem[DY][DX];
        }else{
            
            mem[Y][X]=dfs(DX,DY);
            
            return mem[Y][X];
        }
    }else if(g[Y][X]=='U'){
        
        int DX,DY;
        DX=X;DY=Y-1;
        if(DY<0){return mem[Y][DX]=1;}
        if(visited[DY][DX]==true){
            return mem[Y][X]=mem[DY][DX];
        }else{
          
            return mem[Y][X]=dfs(DX,DY);
        }
    }else if(g[Y][X]=='L'){
        int DX,DY;
        
        DX=X-1;DY=Y;
        if(DX<0)
        {
            
            mem[DY][X]=1;
            
            return mem[DY][X];}
        if(visited[DY][DX]==true){
            
            return mem[Y][X]=mem[DY][DX];
        }else{
            
            return mem[Y][X]=dfs(DX,DY);
        }
    }
}
int main(){
    cin>>N>>M;
    char a;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>a;
            g[i].push_back(a);
        }
    }
    for(int i=0;i<N;i++){
        fill_n(visited[i],M,false);
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dfs(j,i);
        }
    }
    int counT=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            
            if(mem[i][j]==1){
                
                counT+=1;
            }
        }
        
    }
    cout<<counT;
}
