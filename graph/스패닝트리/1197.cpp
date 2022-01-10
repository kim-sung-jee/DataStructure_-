#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int V,E;
vector<pair<int,pair<int,int>>> v;
int p[10001];

int find(int x){
    if(p[x]==x){
        return x;
    }else{
        return p[x]=find(p[x]);
    }
}

int main(){
    cin>>V>>E;

    for(int i=0;i<E;i++){
        int s,e,d;
        cin>>s>>e>>d;
        v.push_back({d,{s,e}});
    }
    sort(v.begin(),v.end());

    for(int i=0;i<=V;i++){
        p[i]=i;
    }
    int sum=0;
    int num=0;
    for(int i=0;i<E;i++){
        int w=v[i].first;
        int start=v[i].second.first;
        int end=v[i].second.second;

        int x=find(start);
        int y=find(end);

        if(x==y){continue;}

        if(x<y){
            p[y]=x;
        }else{
            p[x]=y;
        }
        sum+=w;
        num++;
        if(num==V-1){
            cout<<sum;
            return 0;
        }
    }
}
