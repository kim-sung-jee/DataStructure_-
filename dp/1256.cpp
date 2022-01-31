#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int N,M,K;
int MAXI=1000000000+100;
int bino[201][201];
int skip;
void calcBino(){
    memset(bino,0,sizeof(bino));
    for(int i=0;i<=200;i++){
        bino[i][0]=bino[i][i]=1;
        for(int j=1;j<i;j++){
            bino[i][j]=min(MAXI,bino[i-1][j-1]+bino[i-1][j]);
        }
    }
}
void generate3(int n,int m,string a){
    if(skip<0){return;}
    if(n==0&&m==0){
        if(skip==0){
            cout<<a;
            exit(0);
        }
        --skip;
        return;
    }

    if(bino[n+m][n]<=skip){
        skip-=bino[n+m][n];
        return;
    }
    if(n>0){
        generate3(n-1,m,a+'a');
    }
    if(m>0){
        generate3(n,m-1,a+'z');
    }
}   
int main(){
    cin>>N>>M>>K;
    calcBino();
    skip=K-1;
    generate3(N,M,"");
    cout<<"-1";
} 
