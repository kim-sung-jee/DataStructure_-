#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int n,d,p;
    cin>>n;
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<n;i++){
        cin>>p>>d;
        pq.push({p,d});
    }
    int ans[10001];
    fill_n(ans,10001,0);
    for(int i=0;i<n;i++){
        int W=pq.top().first;
        int day=pq.top().second;
        pq.pop();
        if(ans[day]==0){
            ans[day]=W;
        }else{
            while(ans[day]!=0&&day>=1){
                day-=1;
            }
            ans[day]=W;
        }
    }
    int sum=0;
    for(int i=1;i<10001;i++){
        sum+=ans[i];
    }
    cout<<sum;
}
