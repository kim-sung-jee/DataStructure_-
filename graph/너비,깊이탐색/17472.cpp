#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int N,M;
bool visited[100][100];
vector<pair<int,int>> graph[10];
int idx=1;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<pair<int,pair<int,int>>> graph2;
int parent[6];
void bfs(int X,int Y){
    queue<pair<int,int>> q;
    q.push({X,Y});
    visited[Y][X]=true;
    while(!q.empty()){
        int nowX=q.front().first;
        int nowY=q.front().second;
        q.pop();
        graph[nowY][nowX].second=idx;
        for(int i=0;i<4;i++){
            int nx=nowX+dx[i];
            int ny=nowY+dy[i];
            if(0<=nx&&nx<M&&0<=ny&&ny<N){
                if(visited[ny][nx]==false&&graph[ny][nx].first==1){
                    q.push({nx,ny});
                    visited[ny][nx]=true;
                }
            }
        }
    }
}
void dfs(int X,int Y){
    
    for(int i=0;i<4;i++){
        int depth=0;
        int nx=X+dx[i];
        int ny=Y+dy[i];
        if(nx<0||nx>=M||ny<0||ny>=N){
            continue;
        }
        
        if(graph[ny][nx].first==1&&graph[ny][nx].second==graph[Y][X].second){
            continue;
        }
        while(graph[ny][nx].first!=1){

            depth+=1;
            nx=nx+dx[i];
            ny=ny+dy[i];
            if(nx<0||nx>=M||ny<0||ny>=N){
                break;
            }
            if(graph[ny][nx].first==1&&graph[ny][nx].second!=graph[Y][X].second){
                if(depth==1){
                    break;
                }else{
                graph2.push_back({depth,{graph[ny][nx].second,graph[Y][X].second}});
                break;
                }
            }
        }
        depth=0;
    }
}
int find(int X){
    if(X==parent[X]){
        return X;
    }else{
        return parent[X]=find(parent[X]);
    }
}


int main(){

    cin>>N>>M;
    int a;
    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            cin>>a;
            graph[i].push_back({a,-1});
        }
    }
    for(int i=0;i<100;i++){
        fill_n(visited[i],100,false);
    }
    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            if(graph[i][t].first!=0&&visited[i][t]==false){
                bfs(t,i);
                idx+=1;
            }
        }
    }
    
    for(int i=0;i<6;i++){
        parent[i]=i;
    }
   
    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            if(graph[i][t].first==1){
                dfs(t,i);
                
            }
        }
    }
    
    sort(graph2.begin(),graph2.end());
    int counT=0;
    int sum=0;
    int rC=0;
    
    int size=graph2.size();

    while(true){
        if(size<=counT){
            cout<<"-1";
            return 0;
        }

        int s=graph2[counT].second.first;
        int e=graph2[counT].second.second;
        int nC=graph2[counT].first;
        counT+=1;
        int x=find(s);
        int y=find(e);
        if(x==y){
            continue;
        }
        if(x>y){
            parent[x]=y;
        }else{
            parent[y]=x;
        }
        sum+=nC;
        
        rC+=1;
        if(rC==idx-2){
            cout<<sum;
            break;
        }



    }
    
}
