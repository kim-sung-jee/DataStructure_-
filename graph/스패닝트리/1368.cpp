#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<pair<int,pair<int,int>>> graph;
            //w        // x,y

int p[301];
int find(int x){
    if(p[x]==x){return x;}else{
        return find(p[x]);
    }
}
int main(){
    int N;
    cin>>N;
    int a;
    for(int i=0;i<N;i++){
        cin>>a;
        graph.push_back({a,{0,i+1}});
    }
    int w;
    for(int i=0;i<N;i++){
        for(int t=0;t<N;t++){
            cin>>w;
            if(i<t&&t!=0){             //e     //s
                graph.push_back({w,{t+1,i+1}});
                
            }
        }
    }

    for(int i=0;i<301;i++){
        p[i]=i;                                                                   
    }
    sort(graph.begin(),graph.end());
    int sum=0;
    int count=0;
    for(int i=0;i<graph.size();i++){
        int start=graph[i].second.first;
        int end=graph[i].second.second;
        int cost=graph[i].first;
        
        int x=find(start);
        int y=find(end);
        if(x==y){
            continue;
        }
        if(x>y){
            p[x]=y;
        }else{
            p[y]=x;
        }
       
        count+=1;
        sum+=cost;
        
        if(N==count){
            cout<<sum;
            return 0;
        }

    }
}
