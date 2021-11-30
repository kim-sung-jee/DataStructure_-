#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int N, M, S;

vector<int> adjList[1001];
bool isVisited[1001]={false,};
stack<int> st;

void dfs(int V){
    cout<<"hi "<<V<<endl;
    if(isVisited[V]){return;}
    isVisited[V]=true;
    //cout<<V<<" ";
    
    for(int i=0;i<adjList[V].size();i++){
        int next=adjList[V][i];
        dfs(next);
    }
}


int main(){
    //N:노드 수 ,M:간선 수,S:시작 노드
    cin>>N>>M>>S;

    for(int i=0;i<M;i++){
        int s,e;
        cin>>s>>e;
        adjList[s].push_back(e);
        adjList[e].push_back(s);
    }
    
    // 가중치 제일 낮은거 찾기 위해
    for(int i=0;i<1001;i++){
        sort(adjList[i].begin(),adjList[i].end());
    }
    fill_n(isVisited,1001,false);
    dfs(S);

}
