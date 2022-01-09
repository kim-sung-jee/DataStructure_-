#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<pair<int,int>> v[801];
int dist[801];
void dijkstra1(int S){
    priority_queue<pair<int,int>> pq;
    pq.push(pair<int,int>(0,S));
    dist[S]=0;
    while(!pq.empty()){
        int next=pq.top().second;
        int nw=-pq.top().first;
        pq.pop();
        for(int i=0;i<v[next].size();i++){
            int a=v[next][i].first;
            if(dist[a]>nw+v[next][i].second){
                dist[a]=nw+v[next][i].second;
                pq.push(pair<int,int>(-dist[a],a));
            }
        }
    }
}


int main(){
    int N,T;
    cin>>N>>T;
    int a,b,c;
    for(int i=0;i<T;i++){
        cin>>a>>b>>c;
        v[a].push_back(pair<int,int>(b,c));
        v[b].push_back(pair<int,int>(a,c));
    }
    int v1,v2;
    cin>>v1>>v2;
    int A,B,C,D,E;
    
    fill_n(dist,801,1e9);
    dijkstra1(1);
    A=dist[v1];
    B=dist[v2];

    fill_n(dist,801,1e9);
    dijkstra1(v2);
    C=dist[v1];
    
    fill_n(dist,801,1e9);
    dijkstra1(v1);
    D=dist[N];

    fill_n(dist,801,1e9);
    dijkstra1(v2);
    E=dist[N];
    
    int ans1,ans2,ans3,ans4;
    
    ans1=A+C+E;
    ans2=B+C+D;
    ans3=A+C+C+D;
    ans4=B+C+C+E;
    int ans[4]={ans1,ans2,ans3,ans4};
    sort(ans,ans+4);
    if((A==1e9&&B==1e9)||C==1e9||(D==1e9&&E==1e9)){
        cout<<"-1";
    }else{
        cout<<ans[0];
    }
}
