#include<iostream>
using namespace std;

int main(){

    int M;

    cin>>M;

    
    int *real=new int[M];
    for(int i=0;i<M;i++){
        cin>>real[i];
    }
    
    int max=0;
    for(int i=0;i<M;i++){
        if(real[i]>=max){
            max=real[i];
        }
    }

    bool running=true;
    int count=0;
    int c_2=0;
    int i=2;
    int S;
    while(running){

        S=max*i;
        
        for(int i=2;i<S;i++){
            if(S%i==0){
                count+=1;
            }
        }
        
        if(count==M){
            for(int i=0;i<M;i++){
                if(S%real[i]==0){
                    c_2+=1;
                }
            }
            if(c_2==M){
                break;
            }else{
                count=0;
                c_2=0;
                i+=1;
            }
        }else{
            count=0;
            i+=1;
        }
    }

    cout<<S;



    // while(running){

    //     for(int i=0;i<M;i++){
    //         if(N%real[i]!=0){
    //             N+=1;
    //             continue;
    //         }
    //     }
        
    //     for(int i=2;i<N;i++){
    //         if(N%i==0){
    //             count+=1;
    //         }
    //     }                                     

    //     if(count==M){
    //         for(int i=0;i<M;i++){
    //             if(N%real[i]==0){
    //                 c_2+=1;
    //             }
    //         }
    //         if(c_2==M){
    //             break;
    //         }else{
    //             count=0;
    //             c_2=0;
    //             N++;
    //         }
    //     }else{
    //         count=0;
    //         N++;
    //     }
        
    // }
   
    
}
