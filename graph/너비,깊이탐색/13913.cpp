#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N,K;
queue<pair<int,int>> q;
int ans[100001];
int parent[100001];
int walkP(int S){
    return S+1;
}
int walkM(int S){
    return S-1;
}
int tel(int S){
    return S*2;
}
vector<int> v;
vector<int> path;
int dijstra(int S){
    priority_queue<pair<int,int>> pq;
    pq.push(pair<int,int>(0,S));
    ans[S]=0;
    while(!pq.empty()){
        
        int a,b,c;
        int abc=pq.top().second;
        int cost=-pq.top().first;
        v.push_back(abc);
        pq.pop();
        a=tel(abc);
        b=walkP(abc);
        c=walkM(abc);
        if(abc==K){
            
            int idx=abc;
            while(idx!=N){
                path.push_back(idx);
                idx=parent[idx];
            }
            path.push_back(N);
        
            cout<<cost<<endl;
            for(int i=0;i<path.size();i++)
            {
                cout<<path[path.size()-i-1]<<" ";
            }
            return 0;
        }
        if(b<=100000){
            if(ans[b]>cost+1){
            ans[b]=cost+1;
            pq.push(pair<int,int>(-ans[b],b));
            parent[b]=b-1;
            }
        }
        if(c>-1){
            if(ans[c]>cost+1){
                 ans[c]=cost+1;
            pq.push(pair<int,int>(-ans[c],c));
            parent[c]=c+1;
            }
            
        }
        if(a<=100000){
            if(ans[a]>cost+1){
                ans[a]=cost+1;
                pq.push(pair<int,int>(-ans[a],a));
                parent[a]=a/2;
            }
        }
        
    }
}

int main(){
    
    cin>>N>>K;
    fill_n(ans,100001,1e9);
    dijstra(N);

    
    return 0;
    
}
