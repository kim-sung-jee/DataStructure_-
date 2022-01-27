#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<pair<int,int>> g[1001];
int dist[1001];
int parent[1001];

void dijkstra(){
    priority_queue<pair<int,int>> pq;
    //                cost/start
    pq.push({0,1});
    dist[1]=0;
    while(!pq.empty()){
        int now=pq.top().second;
        int nC=-pq.top().first;
        
        pq.pop();
        for(int i=0;i<g[now].size();i++){
            int next=g[now][i].first;
            int nextCost=g[now][i].second;
            if(dist[next]>nC+nextCost){
                parent[next]=now;
                dist[next]=nC+nextCost;
                
                pq.push({-dist[next],next});
            }
        }
    }
}

int main(){
    int N,M;
    int s,e,c;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>s>>e>>c;
        g[s].push_back({e,c});
        g[e].push_back({s,c});
    }
    
    fill_n(dist,1001,1e9);
    for(int i=0;i<1001;i++){
        parent[i]=i;
    }
    dijkstra();
    cout<<N-1<<endl;
    
    for(int i=2;i<=N;i++){
        cout<<i<<" "<<parent[i]<<endl;
    }
    
 

}
