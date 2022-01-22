#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[32001];
int indegree[32001];
int result[32001];
int N,M;
void topologySort(){
    //greater은 오름차순
    //less는 내림차순

    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=N;i++){
        if(indegree[i]==0){
            pq.push(i);}
    }
    while(!pq.empty()){


        int x=pq.top();
    
        pq.pop();
        cout<<x<<" ";
        for(int t=0;t<v[x].size();t++){
            int y=v[x][t];
            if(--indegree[y]==0){
                pq.push(y);
            }
        }
    
    }
    
}


int main(){

    
    cin>>N>>M;
    int s,e;
    fill_n(indegree,32001,0);
    for(int i=0;i<M;i++){
        cin>>s>>e;
        v[s].push_back(e);
        indegree[e]++;
    }
    topologySort();
}
