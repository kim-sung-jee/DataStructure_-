#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int count=0;
int N,K;
int ans[100001];
int tel(int X){
    return X*2;
}
int walkP(int X){
    return X+1;
}
int walkM(int X){
    return X-1;
}
void dijstra(int S){
    priority_queue<pair<int,int>> pq;
    pq.push(pair<int,int>(0,S));
    ans[S]=0;
    while(!pq.empty()){
        
        int a,b,c;
        int abc=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        a=tel(abc);
        b=walkP(abc);
        c=walkM(abc);
        if(abc==K){
            cout<<cost;
            return;
        }
        if(b<=100000){
            if(ans[b]>cost+1){
            ans[b]=cost+1;
            pq.push(pair<int,int>(-ans[b],b));
            }
        }
        if(c>-1){
            if(ans[c]>cost+1){
                 ans[c]=cost+1;
            pq.push(pair<int,int>(-ans[c],c));
            }
            
        }
        if(a<=100000){
            if(ans[a]>cost){
                ans[a]=cost;
                pq.push(pair<int,int>(-ans[a],a));
            }
        }
        
    }
}
int main(){
    fill_n(ans,100001,1e9);

    cin>>N>>K;
    
    dijstra(N);
    
}
