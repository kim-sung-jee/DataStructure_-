#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first<b.first){
        return false;
    }else if(a.first>b.first){
        return true;
    
    }
    return a.second>b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<pair<int,int>> v;
    int d,c;
    for(int i=0;i<N;i++){
        cin>>d>>c;
        v.push_back({d,c});
    }
    sort(v.begin(),v.end());
    
    priority_queue<int> pq;
    int idx=N-1;
    int ans=0;
   
    for(int i=N;i>0;i--){
        for(;idx>=0&&v[idx].first==i;idx--){
            
            pq.push(v[idx].second);
        }
        if(!pq.empty()){
            ans+=pq.top();
           
            pq.pop();
        }

    }
    cout<<ans;

    // int N;
    // cin>>N;
    // int deadline,cupRamen;
    // int day[200001];
    // fill_n(day,200001,0);
    // priority_queue<pair<int,int>> pq;
    
    // for(int i=0;i<N;i++){
    //     cin>>deadline>>cupRamen;
    //     pq.push({cupRamen,deadline});
        
    // }
    // long long ans=0;
    // for(int i=0;i<N;i++){
    //     int nowD=pq.top().second;
    //     int nC=pq.top().first;
    //     pq.pop();
    //     if(day[nowD]==0){
    //         day[nowD]=nC;
    //         ans+=nC;
    //         continue;
    //     }
    //     while(0<nowD&&day[nowD]!=0){
    //         nowD-=1;
    //     }
    //     day[nowD]=nC;
    //     if(nowD!=0){
    //         ans+=nC;
    //     }
        
    // }
    // cout<<ans;
}
