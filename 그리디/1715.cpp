#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int N;
priority_queue<int> pq;
int main(){
    cin>>N;
    int t;
    for(int i=0;i<N;i++){
        cin>>t;
        pq.push(-t);
    }
    int ans=0;
    for(int i=0;i<N-1;i++){
        int a=-pq.top();
        pq.pop();
        int b=-pq.top();
        pq.pop();
        ans+=a+b;
        pq.push(-(a+b));
    }
    cout<<ans;
}
