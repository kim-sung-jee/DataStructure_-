#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> v[1001];
int indegree[1001];
int N,M;
vector<int> result;
void topoloySort(){
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int x=q.front();
        q.pop();
        result.push_back(x);
        for(int i=0;i<v[x].size();i++){
            int next=v[x][i];
            if(--indegree[next]==0){
                q.push(next);
            }
        }
    }
    if(result.size()!=N){
        cout<<"0";
    }else{
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<endl;
        }
    }
}
int main(){
    int temp[1001];
    
    cin>>N>>M;
    int size;
    fill_n(indegree,1001,0);
    for(int i=0;i<M;i++){
        cin>>size;
        for(int t=0;t<size;t++){
            cin>>temp[t];
        }
        for(int t=0;t<size-1;t++){
            v[temp[t]].push_back(temp[t+1]);
            indegree[temp[t+1]]+=1;
        }

    }
    topoloySort();
}
