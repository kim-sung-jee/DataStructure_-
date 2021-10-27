#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int N;
    cin>>N;
    int *dp=new int[N+1];

    dp[0]=0;
    for(int i=0;i<N+1;i++){
        dp[i]=i;
    }
    for(int i=1;i<=N;i++){
        for(int t=1;t*t<=i;t++){
            dp[i]=min(dp[i],dp[i-t*t]+1);
        }
    }
    cout<<dp[N];

}
