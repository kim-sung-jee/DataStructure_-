#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[1000];
int mx,my;
bool isVisited[1000][1000];
int ans[1000][1000];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int X,Y;
void bfs(int mx,int my){
    queue<pair<int,int>> q;
    q.push(pair<int,int>(mx,my));
    isVisited[my][mx]=true;
    ans[my][mx]=0;
    int DX,DY;      
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        ///**********
        //isVisited[y][x]=true;
        //******/////
        q.pop();
        for(int i=0;i<4;i++){
            DX=x+dx[i];
            DY=y+dy[i];
            if(DX<0||DY<0||DX>=X||DY>=Y){
                continue;
            }
            if(v[DY][DX]==0){
                continue;}
            if(isVisited[DY][DX]==true){continue;}
            q.push(pair<int,int>(DX,DY));
            ans[DY][DX]=ans[y][x]+1;
            isVisited[DY][DX]=true;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>X>>Y;
    int a;
    for(int i=0;i<Y;i++){
        for(int t=0;t<X;t++){
            cin>>a;
            v[i].push_back(a);
            if(a==2){
                my=i;
                mx=t;
            }
        }
    }
    for(int i=0;i<1000;i++){
        fill_n(isVisited[i],1000,false);
    }
   
    bfs(mx,my);
    for(int i=0;i<Y;i++){
        for(int t=0;t<X;t++){
            if(isVisited[i][t]==false&&v[i][t]==1){
                cout<<"-1"<<" ";
            }else{
                cout<<ans[i][t]<<" ";
            }
        }
        cout<<endl;
    }
}
