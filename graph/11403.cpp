#include<iostream>
#include<vector>
using namespace std;

vector<int> v1[100];
int ans[100][100];
void dfs(int FX,int D){
    if(ans[FX][D]==true){
        return;
    }
    if(FX!=D){
        ans[FX][D]=1;
    }
    
    for(int i=0;i<v1[D].size();i++){
        int next=v1[D][i];
        if(next==FX){
            ans[FX][next]=1;
        }
        dfs(FX,next);
    }
}


int main(){

    int N;
    cin>>N;
    int temp;
    for(int i=0;i<N;i++){
        for(int t=0;t<N;t++){
            cin>>temp;
            if(temp==1){
                v1[i].push_back(t);
            }
        }
    }
    
    
    
    for(int i=0;i<100;i++){
        fill_n(ans[i],100,0);
    }

    for(int i=0;i<N;i++){
        dfs(i,i);
    }

    for(int i=0;i<N;i++){
        for(int t=0;t<N;t++){
            cout<<ans[i][t]<<" ";
        }
        cout<<endl;
    }
}
