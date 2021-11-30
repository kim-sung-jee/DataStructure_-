#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N,M;
int gsize;

vector<int> adjList[1001];
bool isVisited[1001]={false,};
queue<int> que;

void bfs(int V){
    
    que.push(V);

    while(!que.empty()){
        int cur=que.front();
        que.pop();
        
        if(isVisited[cur]){continue;}
        isVisited[cur]=true;
        
        
        for(int i=0;i<adjList[cur].size();i++){
            int next=adjList[cur][i];
            que.push(next);
            
        }
    }
    
}


int main(){
    cin>>N>>M;
    gsize=N;
    for(int i=0;i<M;i++){
        int s,e;
        cin>>s>>e;
        adjList[s-1].push_back(e-1);
        adjList[e-1].push_back(s-1);
    }

    for(int i=0;i<1001;i++){
        sort(adjList[i].begin(),adjList[i].end());
    }
    int count=0;
    fill_n(isVisited,1001,false);
    bfs(0);

    for(int i=0;i<gsize;i++){
        if(isVisited[i]==false){
            count+=1;
        }
        
    }
    cout<<N-count-1;
    return 0;
}
