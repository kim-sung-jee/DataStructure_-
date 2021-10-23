#include<iostream>

using namespace std;

int main(){


    char *N;
    N=new char[11];
    cin>>N;
    
    int i=0;
    while(N[i]!=NULL){
        i++;
    }
    i=i-1; 
    int temp2;
    for(int t=0;t<i;t++){
        for(int k=t+1;k<i+1;k++){
            if(N[t]<=N[k]){
                temp2=N[k];
                N[k]=N[t];
                N[t]=temp2;
            }
        }
    }
    for(int z=0;z<i+1;z++){
        cout<<N[z];
    }
    return 0;
}
