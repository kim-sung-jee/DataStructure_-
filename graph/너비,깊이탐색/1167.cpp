#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int degree[100001];// 리프노드인지 검사하는 배열
int ans=0;
vector<pair<int,int>> v[100001];
bool isVisited[100001];
vector<int> leaf;
int far=1;
int maxCost=0;
// s는 시작 c는 현재 비용
void dfs(int S,int C){
    
    isVisited[S]=true;
    for(int i=0;i<v[S].size();i++){
        int next=v[S][i].first;
        int cost=v[S][i].second;
        if(isVisited[next]==true){
            if(maxCost<C){
                
                
                far=S;
                maxCost=C;
            }
            continue;
        }
        isVisited[next]=true;
        dfs(next,cost+C);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int s,e,c;
    fill_n(degree,100001,0);
    //입력받는부분
    for(int i=0;i<n;i++){
        cin>>s;
        while(true){
            cin>>e;
            if(e==-1){
                break;
            }
            cin>>c;
            v[s].push_back({e,c});
            degree[i+1]+=1;
        }
    }
    fill_n(isVisited,100001,false);
    dfs(1,0);
    fill_n(isVisited,100001,false);
    
    dfs(far,0);
    cout<<maxCost;



}
