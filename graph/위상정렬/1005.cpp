#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int cost[100001];
int degree[100001];
vector<int> node[100001];
int N,K;
int W;
vector<int> ans;
void potoly(){
    
    priority_queue<pair<int,int>> q;
   
    
    for(int i=1;i<=N;i++){
        if(degree[i]==0){
            q.push({-cost[i],i});
        }
    }
    int maxi=0;
    while(!q.empty()){
        int now=q.top().second;
        int nSum=-q.top().first;
        q.pop();
        
        if(now==W){
            
            ans.push_back(nSum);
            break;
        }

      
        for(int i=0;i<node[now].size();i++){
            int next=node[now][i];
           
            if(--degree[next]==0){
                
                q.push({-(nSum+cost[next]),next});  
            }
           
            
        }
        
    }
    

}
int main(){
    int T;
    cin>>T;
    int c;
    for(int q=0;q<T;q++){
        cin>>N>>K;
        fill_n(degree,100001,0);
        fill_n(cost,100001,-1);
       
        for(int i=1;i<=N;i++){
            node[i].clear();
        }


        for(int i=0;i<N;i++){
            cin>>cost[i+1];
        }
        int s,e;
        for(int i=0;i<K;i++){
            cin>>s>>e;
            node[s].push_back(e);
            degree[e]+=1;
        }
        cin>>W;  
        potoly();

    }
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}
