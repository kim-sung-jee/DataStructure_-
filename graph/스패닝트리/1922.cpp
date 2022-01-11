#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
vector<pair<int,pair<int,int>>> graph;
int p[1001];
int find(int x){
    if(p[x]==x){return x;}
    else{
        return p[x]=find(p[x]);
    }
}
int main(){
    int N,M;
    cin>>N>>M;
    int s,e,w;
    for(int i=0;i<M;i++){
        cin>>s>>e>>w;
        graph.push_back({w,{s,e}});
    }
    sort(graph.begin(),graph.end());
    for(int i=0;i<1001;i++){
        p[i]=i;
    }
    int sum=0;
    int num=0;
    for(int i=0;i<graph.size();i++){
        int weight=graph[i].first;
        int start=graph[i].second.first;
        int end=graph[i].second.second;

        int x=find(start);
        int y=find(end);
        if(x==y){continue;}
        if(y>x){
            p[x]=y;
        }else{
            p[y]=x;
        }
        sum+=weight;
        num++;
        if(N-1==num){
            break;
        }
    }
    cout<<sum;
}
