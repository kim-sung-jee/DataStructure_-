#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int n;
    int S;
    cin>>n;
    int *dp=new int[n];
    
    int t;
    for(int i=0;i<n;i++){
        cin>>t;
        dp[i]=t;
        
    }

    int maxi;
    maxi=dp[0];

    
    int sum=dp[0];

    for(int i=1;i<n;i++){
        // dp[i]=max(dp[i],dp[i-1]+dp[i]);
        // if(dp[i]>sum){
        //     sum=dp[i];
        // }
    


    }
    cout<<sum;
}
