#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> v[1000];
//          cost, index    y
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool isVisited[1000][1000];
int N,M;
vector<pair<int,int>> nXY;
vector<long long> ans[1000];
vector<pair<int,int>> save;
int counT=0;

void dfs(int X,int Y,int idx){
    for(int i=0;i<4;i++){
        int nextX=X+dx[i];
        int nextY=Y+dy[i];
        if(nextX<0||nextY<0||nextX>=M||nextY>=N){continue;}
        if(isVisited[nextY][nextX]==true){continue;}
        
        if(v[nextY][nextX].first!=0){continue;}
        isVisited[nextY][nextX]=true;
        counT+=1;
        
        save.push_back({nextX,nextY});
        
        dfs(nextX,nextY,idx);
    }
    if(save.size()==0){
        v[Y][X].first=1;
        v[Y][X].second=idx;
    }else{
    for(int i=0;i<save.size();i++){
        
        v[save[i].second][save[i].first].second=idx;
       
        v[save[i].second][save[i].first].first=counT;
    }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>N>>M;
    string temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        for(int t=0;t<M;t++){
            char a=temp.at(t);
            if(a-'0'==1){
                v[i].push_back({-1,0});
            }else{
                v[i].push_back({a-'0',0});
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            ans[i].push_back(0);
        }
    }
    for(int i=0;i<1000;i++){
        fill_n(isVisited[i],1000,false); 
    }
    int idx=1;
    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            if(v[i][t].first==0&&isVisited[i][t]==false){
                counT=0;
                save.clear();
                idx+=1;
                dfs(t,i,idx);
            }
        }
    }
    
    // for(int i=0;i<N;i++){
    //     for(int t=0;t<M;t++){
    //         cout<<v[i][t].first;
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            if(v[i][t].first==-1){
                nXY.clear();
                for(int z=0;z<4;z++){
                    int nextX=t+dx[z];
                    int nextY=i+dy[z];
                    if(nextX<0||nextY<0||nextX>=M||nextY>=N){continue;}
                    if(v[nextY][nextX].first==-1){continue;}
                    nXY.push_back({nextX,nextY});
                    ans[i][t]+=v[nextY][nextX].first;
                }
                for(int z=0;z<nXY.size();z++){
                    for(int a=z+1;a<nXY.size();a++){
                        int ox=nXY[z].first;
                        int oy=nXY[z].second;
                        int x=nXY[a].first;
                        int y=nXY[a].second;
                        if(v[oy][ox].second==v[y][x].second){
                            
                            ans[i][t]-=v[y][x].first;
                            break;
                        }
                    }
                }
                ans[i][t]+=1;

            }
        }
    }
    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            if(ans[i][t]==0){
                cout<<ans[i][t];
            }else{
                cout<<(ans[i][t])%10;
            }
        }
        cout<<endl;
    }
}



#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<set>
using namespace std;

int map[1000][1000];
bool visited[1000][1000];
int area[1000][1000];
int ans[1000][1000];
int idx=0;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int N,M;
vector<int> zerosize;
void bfs(int X,int Y){
    queue<pair<int,int>> q;
    q.push({X,Y});
    visited[Y][X]=true;
    area[Y][X]=idx;
    int cnt=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&ny>=0&&nx<M&&ny<N){
                if(map[ny][nx]==0&&visited[ny][nx]==false){
                    visited[ny][nx]=true;
                    area[ny][nx]=idx;
                    q.push({nx,ny});
                    cnt+=1;
                }
            }
        }
    }
    zerosize.push_back(cnt);
}

int main(){
    
    cin>>N>>M;
    string a;
    for(int i=0;i<N;i++){
        cin>>a;
        for(int t=0;t<M;t++){
            char c=a.at(t);
            map[i][t]=c-'0';
        }
        fill_n(visited[i],1000,false);
    }
    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            if(map[i][t]==0&&visited[i][t]==false){
                bfs(t,i);
                idx++;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            if(map[i][t]==1){
                set<int> s;// area idx 를 저장하는 set
                // set 중복없음 
                for(int z=0;z<4;z++){
                    int nx=t+dx[z];
                    int ny=i+dy[z];
                    if(nx>=0&&ny>=0&&nx<M&&ny<N){
                        if(map[ny][nx]==0){
                            // find는 없을때 s.end() 반환
                            if(s.find(area[ny][nx])==s.end()){
                                s.insert(area[ny][nx]);
                                ans[i][t]+=zerosize[area[ny][nx]];
                            }
                        }
                    }
                }
                ans[i][t]=ans[i][t]+1;
                ans[i][t]=ans[i][t]%10;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            cout<<ans[i][t];
        }
        cout<<endl;
    }
}
