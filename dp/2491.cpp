#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int N,t;

    cin>>N;
    int*T=new int[N];
    for(int i=0;i<N;i++){
        cin>>t;
        T[i]=t;
    }
    int maxi=0;
    int count=0;

    for(int i=0;i<N-1;i++){
        if(T[i]<=T[i+1]){
            count+=1;
        }else{
            maxi=max(maxi,count);
            count=0;
        }

        if(i==N-2){
            if(T[i]<=T[i+1]){
            
            maxi=max(maxi,count);
        }else{
            maxi=max(maxi,count);
            count=0;
        }
        }
        
    }
    int maxi2=0;count=0;
    for(int i=0;i<N-1;i++){
        
        if(T[i]>=T[i+1]){
            count+=1;
        }else{
            maxi2=max(maxi2,count);
            count=0;
        }
        
        if(i==N-2){
            if(T[i]>=T[i+1]){
            
            maxi=max(maxi,count);
        }else{
            maxi=max(maxi,count);
            count=0;
        }
        }
        



    }
    maxi+=1;maxi2+=1;
    maxi=max(maxi,maxi2);
    cout<<maxi;


}
