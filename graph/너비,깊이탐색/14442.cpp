#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> v[1000];
vector<int> temp[1000];
bool visited[1000][1000][11];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int N,M,K;
int bfs(){
    queue<pair<pair<int,int>,pair<int,int>>> q;
            //   벽개수,깊이,     x,y 좌표
    q.push({{0,1},{0,0}});
    visited[0][0][0]=true;
    
    int a=-1;
    while(!q.empty()){
        
        int wall=q.front().first.first;
        int depth=q.front().first.second;
        
        
        int nowX=q.front().second.first;
        int nowY=q.front().second.second;
        q.pop();
        if(nowX==M-1&&nowY==N-1){
            a=depth;
            break;
        }
        for(int i=0;i<4;i++){
            int Dx=nowX+dx[i];
            int Dy=nowY+dy[i];
            if(Dx<0||Dy<0||Dx>=M||Dy>=N){continue;}
            if(visited[Dy][Dx][wall]==true){continue;}
            if(v[Dy][Dx]==1){
                
                if(wall<K){
                    visited[Dy][Dx][wall]=true;
                    q.push({{wall+1,depth+1},{Dx,Dy}});
                }else{
                
                    continue;
                }
            }else{
                visited[Dy][Dx][wall]=true;
                q.push({{wall,depth+1},{Dx,Dy}});
            }
            
        }
    }
    
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M>>K;
    string a;
    for(int i=0;i<N;i++){
        cin>>a;
        
        for(int t=0;t<M;t++){
            char b=a.at(t);
            v[i].push_back(b-'0');
        }
    }
    


    for(int i=0;i<1000;i++){
        
        for(int t=0;t<1000;t++){
            fill_n(visited[i][t],11,false);
        }
    }
    
    int ans=bfs();
    cout<<ans;
}
