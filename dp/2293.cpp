#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int coin[101];
   
    int dp[10001];

    fill_n(dp,10001,0);

    for(int i=1;i<=n;i++){
        cin>>coin[i];
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=coin[i];j<=k;j++){
            dp[j]=dp[j]+dp[j-coin[i]];
        }
        //coin[i]원으로 j원을 만들기 위해서는 기존 경우의 수에
        //j-coin[i]원을 만드는 경우의 수 만큼을 더해준다.

    }
    
    
 
    cout<<dp[k];
}
