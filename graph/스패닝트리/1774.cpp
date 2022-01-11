#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
vector<pair<long long,long long>>  v;
vector<pair<long double,pair<long long,long long>>> d;
vector<pair<long long,long long>> ac;
long long p[1001];
long double findDist(long long x,long long y,long long x2,long long y2){
    long double a,b;
    a=pow((x-x2),2);
    b=pow((y-y2),2);
    return sqrt(a+b);
}
long long find(long long x){
    if(p[x]==x){
        return x;
    }else{
        return p[x]=find(p[x]);
    }
}
int main(){
    long long N,M;
    cin>>N>>M;
    long long x,y;
    for(int i=0;i<N;i++){
        cin>>x>>y;
        v.push_back({x,y});
    }
    long long a,b;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        ac.push_back({a,b});
    }
    
    for(int i=0;i<1001;i++){
        p[i]=i;
    }
    for(int i=0;i<ac.size();i++){
        a=find(ac[i].first); // 놓침
        b=find(ac[i].second); // 놓침
        if(a<b){
            p[b]=a;
        }else{
            p[a]=b;
        }
    }

    long long xx,yy;

    long double temp;
    for(int i=0;i<v.size();i++){
        for(int t=i+1;t<v.size();t++){
            temp=findDist(v[i].first,v[i].second,v[t].first,v[t].second);
            d.push_back({temp,{i+1,t+1}});// i=s t=e
            for(long long z=0;z<ac.size();z++){
                xx=ac[z].first;
                yy=ac[z].second;
                if(xx==i+1&&yy==t+1){
                  
                    d.pop_back();
                }else if(xx==t+1&&yy==i+1){
                   
                    d.pop_back();
                }
            }
        }
    }
    
    sort(d.begin(),d.end());
    
    long double sum=0;
    long long num=0;
    for(int i=0;i<d.size();i++){
        long double w=d[i].first;
        long long x=d[i].second.first;
        long long y=d[i].second.second;
        long long a=find(x);
        long long b=find(y);
        if(a==b){continue;}

        if(a>b){
            p[a]=b;
        }else{
            p[b]=a;
        }
        //cout<<x<<" "<<y;
        num+=1;
        sum+=w;
        if(N-1-M==num){
            break;
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout<<sum;
}
