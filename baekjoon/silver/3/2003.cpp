#include<iostream>

using namespace std;

int main(){

    int N;
    int t;
    int sum;
    int M;
    int count=0;
    cin>>N>>M;
    int*A=new int[N];
    for(int i=0;i<N;i++){
        cin>>t;
        A[i]=t;
    }

    for(int i=0;i<N-1;i++){
        sum=A[i];
        for(int z=i+1;z<N+1;z++){
            if(sum==M){
                count+=1;
                break;
            }else if(sum>M){
                break;
            }
            sum+=A[z];
        }
    }
    if(A[N-1]==M){
        count+=1;
    }
    cout<<count;

}
