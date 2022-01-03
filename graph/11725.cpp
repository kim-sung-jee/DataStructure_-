#include<iostream>
#include<vector>
using namespace std;

vector<int> v1[100001];
bool isVisited[100001];
int Ans[100001];
void dfs(int S){
    if(isVisited[S]==true){return;}
    isVisited[S]=true;
    for(int i=0;i<v1[S].size();i++){
        int next=v1[S][i];
        if(isVisited[next]==false){
            Ans[next]=S;
        }
        dfs(next);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int a,b;
    cin>>N;
    for(int i=0;i<N-1;i++){
        cin>>a>>b;
        v1[a].push_back(b);
        v1[b].push_back(a);
    }
    fill_n(isVisited,100001,false);
    dfs(1);
    for(int i=2;i<N;i++){
        cout<<Ans[i]<<"\n";
    }
    cout<<Ans[N];
}
