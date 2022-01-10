#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> v[125];
         //도착점,가중치,시작점;
int dist[125][125];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void dijkstra(int N){
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push(pair<int,pair<int,int>>(-v[0][0],pair<int,int>(0,0)));
    dist[0][0]=v[0][0];
    while(!pq.empty()){
        pair<int,int> next=pq.top().second;
        int now=-pq.top().first;
        pq.pop();
        int DX,DY;
        for(int i=0;i<4;i++){
            DX=next.first+dx[i];
            DY=next.second+dy[i];
            if(DX<0||DY<0||DX>=N||DY>=N){
                continue;
            }
            if(dist[DY][DX]>now+v[DY][DX]){
                dist[DY][DX]=now+v[DY][DX];
                pq.push(pair<int,pair<int,int>>(-dist[DY][DX],pair<int,int>(DX,DY)));
            }
        }
    }
}
vector<int> ans;
int main(){
    int N;
    int temp;
    while(true){
        for(int i=0;i<125;i++){
            fill_n(dist[i],125,1e9);
        }
        for(int i=0;i<125;i++){
            v[i].clear();
        }
        
        cin>>N;
        if(N==0){
            break;
        }
        for(int i=0;i<N;i++){
            for(int t=0;t<N;t++){
                cin>>temp;
                v[i].push_back(temp);
            }
        }
        
        dijkstra(N);
        ans.push_back(dist[N-1][N-1]);
    
    }

    for(int i=0;i<ans.size()-1;i++){
        cout<<"Problem "<<i+1<<": "<<ans[i]<<endl;
    }
    cout<<"Problem "<<ans.size()<<": "<<ans[ans.size()-1];
}
