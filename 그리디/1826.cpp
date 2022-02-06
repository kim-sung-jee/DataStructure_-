#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    int a,b;
    
    vector<pair<int,int>> v;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        // a는 거리 b는 연료의 양
        v.push_back({a,b});
    }
    int L,P;
    cin>>L>>P;
    // L은 목표지점 P는 현재 연료
    sort(v.begin(),v.end());
    int idx=0;
    int ans=0;
    priority_queue<pair<int,int>> pq;
    int count=L;
    while(idx<L&&count>=0){
        int size=v.size();
        for(int i=0;i<size;i++){
            int a=v[0].first;
            int b=v[0].second;
            if(idx+P>=a){
                pq.push({b,a});
            
                v.erase(v.begin());
            }else{
                break;
            }
        }
        if(idx+P>=L){
            break;
        }
        if(!pq.empty()){
            //10-(5-0)==5
            P=P-(pq.top().second-idx);
            P+=pq.top().first;
            idx=pq.top().second;
            pq.pop();
            
            ans+=1;
        }
        count-=1;
    }
    if(count==-1){
        cout<<count;
        return 0;
    }
    cout<<ans;
}
