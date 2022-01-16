#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<pair<int,int>> v[1001];
int s,e,c;
int n,m;
int dist[1001];
int p[1001];
vector<int> ans;
bool visited[1001];
void dijkstra(int S){
    priority_queue<pair<int,int>> pq;
    dist[S]=0;
    
    pq.push({0,S});
    while(!pq.empty()){
        int now=pq.top().second;
        int cost=-pq.top().first;
        if(now==e){return;}
        pq.pop();
        for(int i=0;i<v[now].size();i++){
            int next=v[now][i].second;
            int nc=v[now][i].first;
            if(dist[next]>cost+nc){
                p[next]=now;
                dist[next]=cost+nc;
                pq.push({-nc-cost,next});
            }
        }
    }
}


int main(){
    
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        cin>>s>>e>>c;
        v[s].push_back({c,e});

    }
    cin>>s>>e;
    fill_n(dist,1001,1e9);
    fill_n(visited,1001,false);
    dijkstra(s);
    
    cout<<dist[e]<<endl;
    int Temp=e;
    while(Temp!=0){
        ans.push_back(Temp);
        Temp=p[Temp];
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[ans.size()-i-1]<<" ";
    }
}
