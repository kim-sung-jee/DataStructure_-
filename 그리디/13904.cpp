#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<pair<int,int>> pq;

int main(){
    int N;
    int d,w;
    
    cin>>N;
    
    for(int i=0;i<N;i++){
        cin>>d>>w;
        
       
        pq.push({w,-d});
    }
    
    int ans[1001];
    fill_n(ans,1001,0);
    for(int i=0;i<N;i++){
        int Day=-pq.top().second;
        int W=pq.top().first;
        pq.pop();
        if(ans[Day]==0){
            
            ans[Day]=W;
        }else{
            while(ans[Day]!=0&&Day>=1){
                Day-=1;
            }
            ans[Day]=W;
        }
        
    }
    int sum=0;
    for(int i=1;i<=1000;i++){
        sum+=ans[i];
    }
    cout<<sum;
}
