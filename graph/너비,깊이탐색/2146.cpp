#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> v[100];
bool isVisitied[100][100];
int n;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void dfs(int x,int y,int cnt){
    isVisitied[y][x]=true;
    v[y][x]=cnt;
    for(int i=0;i<4;i++){
        int nextX=x+dx[i];
        int nextY=y+dy[i];
        if(nextX>=0&&nextY>=0&&nextX<n&&nextY<n){
            if(isVisitied[nextY][nextX]==false&&v[nextY][nextX]==1){
                dfs(nextX,nextY,cnt);
            }
        }
    }
}
int bfs(int cnt){
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]==cnt){
                isVisitied[i][j]=true;
                q.push({j,i});
            }
        }
    }
    //cout<<q.size()<<endl;
    int ret=0;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nextY=y+dy[i];
                int nextX=x+dx[i];

                if(nextY>=0&&nextX>=0&&nextY<n&&nextX<n){
                    if(v[nextY][nextX]!=cnt&&v[nextY][nextX]!=0){
                        //cout<<ret<<endl;
                        return ret;
                    }else if(v[nextY][nextX]==0&&isVisitied[nextY][nextX]==false){
                        isVisitied[nextY][nextX]=true;
                        q.push({nextX,nextY});
                    }
                }
            }
            
            
        }
        ret+=1;
    }


}
int main(){
    cin>>n;
    int t;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>t;
            v[i].push_back(t);
        }
    }
    int cnt=1;
    for(int z=0;z<100;z++){
        fill_n(isVisitied[z],100,false);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]==1&&isVisitied[i][j]==false){
                dfs(j,i,cnt);
                cnt+=1;
            }
        }
    }
    int result=1e9;
    
    for(int i=1;i<cnt;i++){
        for(int z=0;z<100;z++){
            fill_n(isVisitied[z],100,false);
            
            
        }
        result=min(result,bfs(i));
        
    }
    cout<<result;
}
