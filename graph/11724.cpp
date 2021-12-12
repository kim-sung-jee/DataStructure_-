#include<iostream>
#include<vector>
using namespace std;

vector<int> arr[1000];
int isVisited[1000];

void dfs(int s){
    if(isVisited[s]==1){return;}
    isVisited[s]=1;
    for(int i=0;i<arr[s].size();i++){
        
        int next=arr[s][i];
        dfs(next);
    }
}

int main(){
    //N은 노드 개수,M은 간선
    int N,M;
    cin>>N>>M;
    fill_n(isVisited,1000,0);
   // fill_n(arr,1000,0);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        arr[a-1].push_back(b-1);
        arr[b-1].push_back(a-1);
    }
    int count=0;
    for(int i=0;i<N;i++){
        if(isVisited[i]==0){
            count+=1;
            dfs(i);
            
        }
    }
    cout<<count;

}
