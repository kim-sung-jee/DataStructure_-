#include<iostream>
#include<vector>
using namespace std;

vector<int> v1[50];

int ans=0;
void dfs(int S,int STOP,int AS){
    if(S==STOP){
        if(v1[AS].size()==1){
            ans+=1;
        }
        return;
    }
    if(v1[S].size()==0){
        ans+=1;
        return;
    }
    for(int i=0;i<v1[S].size();i++){
        int next=v1[S][i];
        dfs(next,STOP,S);
    }
}
int main(){
    int count=0;
    int N;
    int c[50];
    cin>>N;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        if(temp!=-1){
            v1[temp].push_back(i);
        }else{
            c[count]=i;
            count+=1;
        }
    }
    
    int stop;
    cin>>stop;
    for(int i=0;i<count;i++){
        dfs(c[i],stop,c[i]);
    }
    
    cout<<ans;

}
