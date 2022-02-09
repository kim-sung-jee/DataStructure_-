#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
vector<pair<int,int>> v[500];
int dist[500];

vector<int> parentt[500];
int idx=0;
void dijkstra(int S,int D){
    priority_queue<pair<int,int>> pq;
    pq.push({0,S});
    dist[S]=0;
  
    while(!pq.empty()){
        int now=pq.top().second;
        int nC=-pq.top().first;
        pq.pop();
        for(int i=0;i<v[now].size();i++){
            int next=v[now][i].first;
            int nextC=v[now][i].second;
            
            /*
            if(dist[next]>nC+nextC){
                //parent[next]=now;
                
             
                
                parentt[next].clear();    
                parentt[next].push_back(now);
                dist[next]=nC+nextC;
                pq.push({-dist[next],next});
            }else if(dist[next]==nC+nextC){
                parentt[next].push_back(now);
            }
            */
        }
    }
}
bool visited[500][500];
void bfs(int D){
    queue<int> q;
    q.push(D);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<parentt[now].size();i++){
            int next=parentt[now][i];
            if(visited[now][next]==true){
                continue;
            }
            visited[now][next]=true;
            for(int j=0;j<v[next].size();j++){
                if(v[next][j].first==now){
                    v[next].erase(v[next].begin()+j);
                    break;
                }
            }
            q.push(next);
        }
    }
}
int main(){
    int N,M;

    vector<int> ans;
    while(true){
        cin>>N>>M;
        if(N==0&&M==0){
            break;
        }
        int S,D;
        cin>>S>>D;
        int s,e,c;
        for(int i=0;i<500;i++){
            v[i].clear();
        }
        for(int i=0;i<M;i++){
            cin>>s>>e>>c;
            v[s].push_back({e,c});
        }
        fill_n(dist,500,1e9);
        
        for(int i=0;i<500;i++){
            parentt[i].clear();
        }
        

        dijkstra(S,D);
        for(int i=0;i<500;i++){
            fill_n(visited[i],500,false);
        }
        fill_n(dist,500,1e9);
        bfs(D);
        dijkstra(S,D); 
        
        ans.push_back(dist[D]);
        
    }
   
    for(int i=0;i<ans.size();i++){
        if(ans[i]==1e9){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<ans[i]<<endl;
    }
}
