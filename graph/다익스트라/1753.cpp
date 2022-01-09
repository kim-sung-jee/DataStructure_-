#include<iostream>
#include<vector>
#include<queue>

          //도착점,가중치, 시작점
using namespace std;
vector<pair<int,int>> v[20001];
int dist[20001];
void dijkstra(int S){
    priority_queue<pair<int,int>> pq;
                    //가중치,시작점;
    pq.push(pair<int,int>(0,S));
    dist[S]=0;
    while(!pq.empty()){
        int next=pq.top().second;
        int now=-pq.top().first;//
       
        pq.pop();
        for(int i=0;i<v[next].size();i++){
            
            int a=v[next][i].first;
            
            if(dist[a]>now+v[next][i].second){
                dist[a]=now+v[next][i].second;
                pq.push(pair<int,int>(-dist[a],a));
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V,E;
    cin>>V>>E;
    int S;
    cin>>S;
    int s,d,w;
    for(int i=0;i<E;i++){
        cin>>s>>d>>w;
        v[s].push_back(pair<int,int>(d,w));
    }
    fill_n(dist,20001,1e9);
    dijkstra(S);
    
    for(int i=1;i<V+1;i++){
        if(dist[i]==1e9){
            cout<<"INF"<<endl;
        }else{
            cout<<dist[i]<<endl;
        }
    
    }
}
