#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<char> v[100];
vector<pair<int,int>> sp;
bool isVisited[100][100];
int W,H;
int ans[100][100];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void bfs(int sx,int sy){
    queue<pair<int,int>> q;
    q.push(pair<int,int>(sx,sy));
    ans[sy][sx]=0;
    isVisited[sy][sx]=true;
    while(!q.empty()){
        
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            while(nx>=0&&nx<W&&ny>=0&&ny<H){
                if(v[ny][nx]=='*'){break;}
                if(isVisited[ny][nx]==false){
                    isVisited[ny][nx]=true;
                    ans[ny][nx]=ans[y][x]+1;
                    
                    q.push(make_pair(nx,ny));
                }
                nx+=dx[i];
                ny+=dy[i];
            }
        }
    }
   
}


int main(){
    
    cin>>W>>H;
    char a;
    for(int i=0;i<H;i++){
        for(int t=0;t<W;t++){
            cin>>a;
            v[i].push_back(a);
            if(a=='C'){
                sp.push_back(pair<int,int>(t,i));
            }
        }
    }
    for(int i=0;i<100;i++){
        fill_n(isVisited[i],100,false);
    }
    bfs(sp.at(0).first,sp.at(0).second);
    
    cout<<ans[sp.at(1).second][sp.at(1).first]-1;
}
