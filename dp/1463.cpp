#include<iostream>
#include<algorithm>
using namespace std;
int mini(int*arr,int*arr1,int*arr2){
    int*temp=arr;
    *temp=min(*temp,*arr1);
    *temp=min(*temp,*arr2);
   
    return *temp;
}
int main(){
    int N;
    cin>>N;

    int*dp=new int[N+1];
    int arr[3]={1000001,1000001,1000001};
    dp[0]=0;
    dp[1]=0;dp[2]=1;dp[3]=1;
    for(int i=4;i<=N;i++){
        dp[i]=i-1;
    }
    for(int i=4;i<=N;i++){
        if(i%3==0){
            arr[2]=dp[i/3];
        }
        if(i%2==0){
            arr[1]=dp[i/2];
        }
        arr[0]=dp[i-1];
        dp[i]=mini(arr,arr+1,arr+2)+1;
        arr[0]=1000001;arr[1]=1000001;arr[2]=1000001;
    }
    cout<<dp[N];
}
