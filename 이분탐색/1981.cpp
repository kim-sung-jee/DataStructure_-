#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int N;
int mini=200;
int maxi=0;
vector<int> g[100];
bool visited[100][100];
bool bfs(int S){
    queue<pair<int,int>> q;
    // mini ~ maxi 까지 다해본다.
    // 다해봤는데 없으면 false 반환.
    for(int i=mini;i<=maxi;i++){
        for(int j=0;j<100;j++){
            fill_n(visited[j],100,true);
        }
        for(int j=0;j<N;j++){
            for(int t=0;t<N;t++){
                //mid 값(S) 즉 차이를 유지한 채로 이동할 수 있는지
                if(i<=g[j][t]&&g[j][t]<=i+S){
                    visited[j][t]=false;
                }
            }
        }

        q.push({0,0});

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(visited[y][x]==true){
                continue;
            }
            visited[y][x]=true;
            if(x==N-1&&y==N-1){
                return true;
            }
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(0<=nx&&nx<N&&0<=ny&&ny<N){
                    q.push({nx,ny});
                }
            } 


        }

    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    int a;
    for(int i=0;i<N;i++){
        for(int t=0;t<N;t++){
            cin>>a;
            g[i].push_back(a);
            maxi=max(maxi,a);
            mini=min(mini,a);
        }
    }
    int Start=0;
    int End=maxi-mini;
    int Mid;
    while(Start<=End){
        Mid=(Start+End)/2;
        if(bfs(Mid)==true){
            End=Mid-1;
        }else{
            Start=Mid+1;
        }
    }
    cout<<Start;
    
    
}
