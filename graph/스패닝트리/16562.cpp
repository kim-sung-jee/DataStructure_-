#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N,M,K;
vector<pair<int,pair<int,int>>> v;
int p[10001];
int find(int x){
    if(x==p[x]){
        return x;
    }else{
        return p[x]=find(p[x]);
    }
}

int main(){
    cin>>N>>M>>K;
    int a,b;
    int c;
    for(int i=1;i<=N;i++){
        cin>>c;
        v.push_back({c,{0,i}});
    }
    for(int i=0;i<M;i++){
        cin>>a>>b;
        v.push_back({0,{a,b}});
    }
    for(int i=0;i<10001;i++){
        p[i]=i;
    }
    sort(v.begin(),v.end());
    int sum=0;
    int counT=0;
    int idx=0;
    while(true){
        int cost=v[idx].first;
        int x=v[idx].second.first;
        int y=v[idx].second.second;
        idx+=1;
        int a=find(x);
        int b=find(y);
        if(a==b){

            continue;
        }
        if(a>b){
            p[a]=b;
        }else{
            p[b]=a;
        }
        
        counT+=1;
        sum+=cost;
        if(counT==N){
            
            break;
        }


    }
    if(sum>K){
        cout<<"Oh no";
        return 0;
    }
    cout<<sum<<endl;
}
