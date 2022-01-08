#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int,int>> v[5001];
       //  도착점, 가중치,[시작점]



int dist[5001];
int n,m;
void dijstra(int S){
    priority_queue<pair<int,int>> pq;
                    // 가중치,시작점
   
    dist[S]=0;
    pq.push(pair<int,int>(0,S));
    
    while(!pq.empty()){
        
        int next=pq.top().second;
        
        pq.pop();
        for(int i=0;i<v[next].size();i++){
            int a=v[next][i].first; // a는 도착점
            
            
            if(dist[a]>dist[next]+v[next][i].second){
                
                dist[a]=dist[next]+v[next][i].second;
            }
        }
    }
}
int main(){

    
    cin>>n>>m;
    int s,w,d;
    for(int i=0;i<m;i++){
        cin>>s>>d>>w;
        v[d].push_back(pair<int,int>(s,w));
        v[s].push_back(pair<int,int>(d,w));
    }
    cin>>n>>m;
    
    fill_n(dist,5001,1e9);
    dijstra(n);
    cout<<dist[m];
}
