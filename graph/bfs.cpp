#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N,M,S;

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

        cout<<cur<<" ";

        for(int i=0;i<adjList[cur].size();i++){
            int next=adjList[cur][i];
            que.push(next);
        }
    }
}


int main(){
    for(int i=0;i<M;i++){
        int s,e;
        cin>>s>>e;
        adjList[s].push_back(e);
        adjList[e].push_back(s);
    }

    for(int i=0;i<1001;i++){
        sort(adjList[i].begin(),adjList[i].end());
    }

    fill_n(isVisited,1001,false);
    bfs(S);

    return 0;
}
