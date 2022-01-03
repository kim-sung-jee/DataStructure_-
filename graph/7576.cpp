#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> v1[1000];
vector<pair<int,int>> st;
queue<pair<int,pair<int,int>>> q;
int save;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
//once operate
void bfs(int M,int N){
    for(int i=0;i<st.size();i++){
        q.push(pair<int,pair<int,int>>(0,st.at(i)));
    }
    
    while(!q.empty()){
        
        pair<int,int> p=q.front().second;
        int ax,ay;
        for(int i=0;i<4;i++){
            
            ax=p.first+dx[i];
            ay=p.second+dy[i];
           
            if(ax<0||ay<0||ax>M-1||ay>N-1){
                continue;
            }
            if(v1[ay][ax]==-1||v1[ay][ax]==1){
                continue;
            }
            
            
            q.push(pair<int,pair<int,int>>(q.front().first+1,pair<int,int>(ax,ay)));
            v1[ay][ax]=1;
            
        }
        save=q.front().first;
        q.pop();
        

    }


}


int main(){

    int M,N;
    cin>>M>>N;
    int temp;
    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            cin>>temp;
            v1[i].push_back(temp);
            if(temp==1){
                st.push_back(make_pair(t,i));
            }
        }
    }
    bfs(M,N);
    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            if(v1[i][t]==0){
                cout<<"-1";
                return 0;
            }
            
        }
    }
    cout<<save;

}
