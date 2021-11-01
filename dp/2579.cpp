#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int N;
    cin>>N;
    int *arr=new int[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int *dp=new int[N];
    dp[0]=arr[0];// 1번
    dp[1]=max(arr[1],arr[0]+arr[1]);//2번
    dp[2]=max(arr[0]+arr[2],arr[1]+arr[2]);

    for(int i=3;i<N;i++){
        dp[i]=max(arr[i]+dp[i-2],arr[i]+arr[i-1]+dp[i-3]);
    }

    cout<<dp[N-1];


















    // while(i!=N){

    //     if(i==N-1){
    //         if(count==2){
    //             cout<<sum;
    //             return 0;
    //         }
    //         sum+=dp[0];
    //         cout<<sum;
    //         return 0;
    //     }
        
    //     if(dp[N-1-i]<=dp[N-2-i]){
    //         sum+=dp[N-2-i];
            
    //         i+=2;
    //     }else if(count<2){
            
    //         sum+=dp[N-1-i];
    //         i+=1;
    //         count+=1;
    //     }else if(count==2){
            
    //         sum+=dp[N-2-i];
    //         i+=2;
    //         count=1;
    //     }
        
       
    // }
   
    // cout<<sum;


}
