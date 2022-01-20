#include<iostream>
#include<vector>

using namespace std;
vector<int> v[101];
int ans[101];
bool isVisited[101];
int N,M;
int count=0;
void dfs(int S,int t){
    
    
    if(v[S].size()==0){return;}
   
    for(int i=0;i<v[S].size();i++){
        int next=v[S][i];
        if(isVisited[next]==true){continue;}
        isVisited[next]=true;
        
        count+=1;
        ans[next]+=1;
        dfs(next,t);
    }
}
int main(){
   
    cin>>N>>M;
    int a,b;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        v[a].push_back(b);
    }
    fill_n(ans,101,0);
    for(int i=0;i<N;i++){
        fill_n(isVisited,101,false);
        dfs(i+1,i+1);
        ans[i+1]+=count;
        count=0;
    }
    for(int i=0;i<N;i++){
        cout<<N-ans[i+1]-1<<endl;
    }
}
