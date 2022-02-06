#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N,K;
    int M,V;
    cin>>N>>K;
    vector<pair<int,int>> v;
    for(int i=0;i<N;i++){
        cin>>M>>V;
        v.push_back({M,V});
    }
    sort(v.begin(),v.end());
    vector<int> bag;
    int C;
    for(int i=0;i<K;i++){
        cin>>C;
        bag.push_back(C);
    }
    sort(bag.begin(),bag.end());
    // 무게 낮은 순으로 무게가 낮은 가방에 넣을 수 있는 최대 가치
    int idx=0;
    priority_queue<int> pq;
    long long ans=0;
    for(int i=0;i<K;i++){
        while(idx<N&&bag[i]>=v[idx].first){
            pq.push(v[idx].second);
            idx+=1;
        }
        if(pq.size()!=0){
            ans+=pq.top();
            pq.pop();
        }
    }
    cout<<ans;
    //위에 껀 idx만큼만 한번만 비교하므로... 더 빠르다
    // 최대 가치먼저 넣는게 아니라
    //pq에 가치 정렬을 해줘가면서 무게가 허용하는 한 가장 큰 가치를 넣어줌
    // 무게가 항상 허용하는 이유는 bag[i]>=v[idx].first와 bag을 sort해줬기 때문에
    
    // 밑에 껀 이진탐색 이용해야함..
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // int N,K;
    // // N은 보석 개수 K는 가방 개수
    // int M,V;
    // priority_queue<pair<int,int>> pq;
    // cin>>N>>K;
    // //m은 무게 v는 가치
    // for(int i=0;i<N;i++){
    //     cin>>M>>V;
    //     pq.push({V,M});
    // }
    // vector<pair<int,int>> bag;
    // int C;
    // for(int i=0;i<K;i++){
    //     cin>>C;
    //     bag.push_back({C,0});
    // }
    // sort(bag.begin(),bag.end());
    
    
    // long long ans2=0;
    // for(int i=0;i<N;i++){
    //     int v=pq.top().first;
    //     int m=pq.top().second;
    //     int idx=0;
       
    //     pq.pop();
    //     while(bag[idx].first<m&&idx<K){
    //         idx+=1;
    //     }
    //     if(idx>=K){
    //         continue;
    //     }
    //     if(bag[idx].second==0){
            
    //         ans2+=v;
    //         bag[idx].second=1;
    //     }else{
    //         while(bag[idx].second!=0&&idx<K){
    //             idx+=1;
    //         }
    //         if(idx<K){
                
    //             bag[idx].second=1;
    //             ans2+=v;
    //         }
    //     }

    // }
    // cout<<ans2;
}
