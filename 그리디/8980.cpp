#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<pair<int,pair<int,int>>> v;
int N,C;
int M;

int main(){
    cin>>N>>C;
    cin>>M;
    int s,e,c;
    for(int i=0;i<M;i++){
        cin>>s>>e>>c;
        v.push_back({e,{s,c}});
    }
    sort(v.begin(),v.end());
    vector<int> left(N+1,C);
    int ans=0;
    for(int i=0;i<v.size();i++){
        int start=v[i].second.first;
        int end=v[i].first;
        int cost=v[i].second.second;
        int mini=C;
        int idx=start;
        for(int t=start;t<end;t++){
            if(mini>=left[t]){
                mini=left[t];
                idx=t;
            }
        }
        if(left[idx]-cost<0){
            int a=left[idx];
            for(int t=start;t<end;t++){
                left[t]-=a;
            }
            ans+=a;
        }else{
        for(int t=start;t<end;t++){
            left[t]-=cost;
        }
        ans+=cost;
        }
        
    }
    cout<<ans;
}
