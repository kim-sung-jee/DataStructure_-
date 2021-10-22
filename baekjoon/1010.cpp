#include<iostream>
using namespace std;

long long chop(long long N,long long M){
    if(N==0||M==1||M==N){
        return 1;
    }else if(N==1){
        return M*N;
    }else if(M-N==1){
        return M*(M-N);
    }else if(N==2){
        return M*(M-1)/N;
    }else if(N==3){
        return M*(M-1)*(M-2)/(N*2);
    }
    else{
        return chop(N,M-1)+chop(N-1,M-1);
    }
}
int main(){
    
    long long T;
    long long temp;
    cin>>T;
    long long *N=new long long[T]; 
    long long *M=new long long[T];
    for(int i=0;i<T;i++){
        cin>>N[i]>>M[i];
    }
    for(int i=0;i<T;i++){
        cout<<chop(N[i],M[i])<<endl;
    }
    
}
