#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int,int>> v1[1001];
int ans[1001];

void dijkstra(int S){
    priority_queue<pair<int,int>>pq;

    pq.push(pair<int,int>(0,S));
    ans[S]=0;
 
    while(!pq.empty()){
        int dist=-pq.top().first;
        int now=pq.top().second;
        pq.pop();

        if(ans[now]<dist){
            continue;
        }
        for(int i=0;i<v1[now].size();i++){
            int cost=dist+v1[now][i].second;

            if(cost<ans[v1[now][i].first]){
                ans[v1[now][i].first]=cost;
                pq.push(pair<int,int>(-cost,v1[now][i].first));
            }
        }
    }
}
int main(){
    int N,M;
    cin>>N>>M;
    int a,b,c;
    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        v1[a].push_back(pair<int,int>(b,c));
    }
    fill_n(ans,1001,1e9);
    cin>>a>>b;
    dijkstra(a);
    cout<<ans[b];
}

