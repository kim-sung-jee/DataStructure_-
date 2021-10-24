#include<iostream>
using namespace std;
int main(){

    int E,S,M;

    cin>>E>>S>>M;
    int count=1;
    
    while(E!=1||S!=1||M!=1){
        E-=1;
        S-=1;
        M-=1;
        if(E==0){E=15;}
        if(S==0){S=28;}
        if(M==0){M=19;}

        count+=1;
    }
    cout<<count;
}
