#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[500];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int dp[500][500];
int N;
int dfs(int x,int y){
    if(dp[y][x]==0){
    int DX,DY;
    dp[y][x]=1;
    int temp=0;
    for(int i=0;i<4;i++){
        DX=x+dx[i];
        DY=y+dy[i];
        if(DX<0||DY<0||DX>=N||DY>=N){
            continue;
        }
        if(v[DY][DX]<=v[y][x]){continue;}
        temp=max(temp,dfs(DX,DY));
    }
    dp[y][x]+=temp;// 증가하는 곳
    }
    return dp[y][x];
}
int main(){
    
    cin>>N;
    int temp;
    for(int i=0;i<N;i++){
        for(int t=0;t<N;t++){
            cin>>temp;
            v[i].push_back(temp);
        }
    }
    for(int i=0;i<500;i++){
        fill_n(dp[i],500,0);
    }
    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ans=max(ans,dfs(j,i));
        }
    }
    cout<<ans;
}
