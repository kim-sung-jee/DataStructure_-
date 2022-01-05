#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> v1[1001];
bool isVisited[1001];
int dis[1001][1001];
vector<int> ans;
queue<pair<int,int>> q;
int dist=0;
// first= node, second=distance
void bfs(int S,int D){
    q.push(pair<int,int>(S,0));
    
    while(!q.empty()){
        int a=q.front().first;
        if(isVisited[a]==true){
            q.pop();
            continue;
        }
        if(a==D){
            dist=q.front().second;
            
            ans.push_back(dist);
            return;
        }

        for(int i=0;i<v1[a].size();i++){
            int d=dis[a][v1[a][i]];
            q.push(pair<int,int>(v1[a][i],q.front().second+d));
            
        }
        isVisited[a]=true;
        q.pop();
    }

    ans.push_back(dist);

}
int main(){
    int N;
    int M;
    
    cin>>N>>M;
    int temp1,temp2;
    int ds;
    for(int i=0;i<1001;i++){
        fill_n(dis[i],1001,-1);
    }
    for(int i=0;i<N-1;i++){
        cin>>temp1;
        cin>>temp2;
        cin>>ds;
        v1[temp2].push_back(temp1);
        v1[temp1].push_back(temp2);
        dis[temp1][temp2]=ds;
        dis[temp2][temp1]=ds;
    }
    fill_n(isVisited,1001,false);
    int a,b;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        bfs(a,b);
        dist=0;
        fill_n(isVisited,1001,false);
        q=queue<pair<int,int>>();
    }
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<endl;
    }
    cout<<ans[M-1];
}
