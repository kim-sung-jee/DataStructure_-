#include<iostream>
using namespace std;
int f(int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 1;
    } else {
        return f(n-1)+f(n-2);
    }
}
int f2(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return f2(n-1)+f2(n-2);
    }
}






int main(){

    int T;
    int N;
    cin>>T;
    
    int**arr=new int*[T];
    for(int i=0;i<T;i++){
        arr[i]=new int[2];
    }
    for(int i=0;i<T;i++){
        cin>>N;
        arr[i][0]=N;
    }
    
    for(int i=0;i<T;i++){
        int*dp=new int[arr[i][0]+1];
        int*dp2=new int[arr[i][0]+1];
        dp[0]=0;dp[1]=1;
        dp2[0]=1;dp2[1]=1;
        for(int t=2;t<=arr[i][0];t++){
            dp[t]=dp[t-1]+dp[t-2];
            dp2[t]=dp2[t-1]+dp2[t-2];
        }
        arr[i][1]=dp2[arr[i][0]]-dp[arr[i][0]];
        arr[i][2]=dp[arr[i][0]];
        
    }
   
    for(int i=0;i<T-1;i++){
        cout<<arr[i][1]<<" "<<arr[i][2]<<endl;
    }
    cout<<arr[T-1][1]<<" "<<arr[T-1][2];


    // int*dp=new int[T];
    // for(int i=0;i<T;i++){
    //     cin>>N;
    //     dp[i]=N;
    // }
    // for(int i=0;i<T-1;i++){
    //     cout<<f(dp[i])-f2(dp[i])<<" "<<f2(dp[i])<<endl;
    // }
    // cout<<f(dp[T-1])-f2(dp[T-1])<<" "<<f2(dp[T-1]);




}
