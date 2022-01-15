#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int p[1001];
vector<int> p2;
vector<pair<int,pair<int,int>>> v;
int find(int x){
    if(x==p[x]){return x;}
    else{
        return p[x]=find(p[x]);
    }
}
int main(){
    int N,M,K;
    cin>>N>>M>>K;
    int t;
    for(int i=0;i<1001;i++){
        p[i]=i;
    }
    for(int i=0;i<K;i++){
        cin>>t;
        p2.push_back(t);
        p[t]=t;
    }
    
    for(int i=0;i<p2.size()-1;i++){
        int s=p2[i];
        int e=p2[i+1];
        int x=find(s);
        int y=find(e);
        if(x>y){
            p[x]=y;
        }else{
            p[y]=x;
        }
    }
    int a,b,c;
    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        v.push_back({c,{a,b}});
    }
    int count=0;
    int sum=0;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        int start=v[i].second.first;
        int end=v[i].second.second;
        int cost=v[i].first;
        int x=find(start);
        int y=find(end);
        if(x==y){continue;}
        if(x>y){
            p[x]=y;
        }else{
            p[y]=x;
        }
        count++;
        sum+=cost;
        
        if(N-K==count){
            cout<<sum;
            return 0;
        }


    }
}
