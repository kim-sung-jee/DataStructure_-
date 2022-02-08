#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int n,m,k;
long long cost[10001][21];
vector<pair<int,int>> w[10001];
priority_queue<pair<long long ,pair<int,int>>> pq;

long long dijkstra(int S){
   
    for(int i=1;i<=n;i++){
        for(int j=0;j<21;j++){
            cost[i][j]=-1;
        }
    }
    cost[S][0]=0;
    pq.push({0,{S,0}});
    while(!pq.empty()){
        long long nowC=-pq.top().first;
        int nowN=pq.top().second.first;
        int cnt=pq.top().second.second;
        pq.pop();
        if(nowC>cost[nowN][cnt]){
            continue;
        }
        for(int i=0;i<w[nowN].size();i++){
            int next=w[nowN][i].first;
            long long nextC=nowC+w[nowN][i].second;
            if(cnt<k){
                if(cost[next][cnt+1]==-1){
                    cost[next][cnt+1]=nowC;
                    pq.push({-nowC,{next,cnt+1}});
                }
                if(cost[next][cnt+1]>nowC){
                    cost[next][cnt+1]=nowC;
                    pq.push({-nowC,{next,cnt+1}});
                }
            }

            if(cost[next][cnt]>nextC||cost[next][cnt]==-1){
                cost[next][cnt]=nextC;
                pq.push({-nextC,{next,cnt}});
            }
        }
    }
    
    long long mini=cost[n][0];
    for(int i=1;i<=k;i++){
        if(mini>cost[n][i]&&cost[n][i]!=-1){
            mini=cost[n][i];
        }
    }
    return mini;


}
int main(){
    
    cin>>n>>m>>k;
    int s,e,c;
    for(int i=0;i<m;i++){
        cin>>s>>e>>c;
        w[s].push_back({e,c});
        w[e].push_back({s,c});
    }
    cout<<dijkstra(1);
}
