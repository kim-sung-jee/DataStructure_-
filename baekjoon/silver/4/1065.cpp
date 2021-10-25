#include<iostream>
#include<cstdlib>
using namespace std;


int main(){

    int N;
    cin>>N;
    int count=0;
    int A[3];
    for(int i=1;i<N+1;i++){
        if(i<=10){
            count+=1;
        }else if(i<=100){
            if(i==100){
                continue;
            }else{
                count+=1;
            }
        }else if(i<=1000){
            if(i==1000){
                continue;
            }
            int z=100;
            int temp=i;
            for(int t=0;t<3;t++){
                A[t]=temp/z;
                temp=temp%z;
                z=z/10;
                
            }
            
            if(A[2]-A[1]==A[1]-A[0]){
                count+=1;
            }
        }
    }
    cout<<count;
}
