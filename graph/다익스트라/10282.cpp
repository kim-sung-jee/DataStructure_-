#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int,int>> v[10001];

queue<int> q;
vector<pair<int,int>> ans;
int dist[10001];
bool isVisitied[10001];
int count=0;
void dijstra(int S,int a){
    priority_queue<pair<int,int>> pq;
    pq.push({0,S});
    dist[S]=0;
    while(!pq.empty()){
        int next=pq.top().second;
        int cost=-pq.top().first;
        if(isVisitied[next]==false){count+=1;isVisitied[next]=true;}
        pq.pop();
        for(int i=0;i<v[next].size();i++){
            int n=v[next][i].second;
            int c=v[next][i].first;
            if(dist[n]>cost+c){
                
                dist[n]=cost+c;
                pq.push({-dist[n],n});
            }
        }
    }
    int maxi=0;
    for(int i=1;i<=a;i++){
        if(isVisitied[i]==true){
            if(maxi<dist[i]){
                maxi=dist[i];
            }
        }
    }


    ans.push_back({count,maxi});

}
int main(){
    int t;
    cin>>t;
    int n,d,c;
    int a,b,s;
    for(int i=0;i<t;i++){
        cin>>n>>d>>c;
        
        for(int j=0;j<d;j++){
            cin>>a>>b>>s;
            v[b].push_back({s,a});
        }
        
        fill_n(dist,10001,1e9);
        fill_n(isVisitied,10001,false);
        count=0;
        dijstra(c,n);
        for(int j=0;j<10001;j++){
            v[j].clear();
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
