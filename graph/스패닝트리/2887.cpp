#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int N;
vector<pair<int,pair<int,int>>> v;
vector<pair<int,int>> x;
vector<pair<int,int>> y;
vector<pair<int,int>> z;
int p[300000];
int find(int X){
    if(X==p[X]){
        return X;
    }else{
        return find(p[X]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    int a,b,c;

    for(int i=0;i<N;i++){
        cin>>a>>b>>c;
        x.push_back({a,i});
        y.push_back({b,i});
        z.push_back({c,i});
    }
    vector<int> s;
    vector<int> temp;

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    sort(z.begin(),z.end());
    for(int i=0;i<N-1;i++){
        int a=abs(x[i].first-x[i+1].first);
        int b=x[i].second;
        int c=x[i+1].second;
        v.push_back({a,{b,c}});
    }
    for(int i=0;i<N-1;i++){
        int a=abs(y[i].first-y[i+1].first);
        int b=y[i].second;
        int c=y[i+1].second;
        v.push_back({a,{b,c}});
    }
    for(int i=0;i<N-1;i++){
            int a=abs(z[i].first-z[i+1].first);
            int b=z[i].second;
            int c=z[i+1].second;
            v.push_back({a,{b,c}});
        }

    // for(int i=0;i<N;i++){
    //     s.push_back(i);
    //     if(i<2){
    //         temp.push_back(1);
    //     }else{
    //         temp.push_back(0);
    //     }
    // }
    // do{
    //     vector<int> t;
    //     for(int i=0;i<s.size();i++){
    //         if(temp[i]==1){
    //             t.push_back(i);
    //         }
    //     }
    //     int a1=min({abs(x[t[0]]-x[t[1]]),abs(y[t[0]]-y[t[1]]),abs(z[t[0]]-z[t[1]])});
    //     v.push_back({a1,{t[1],t[0]}});
    //     t.clear();
        
    // }while(prev_permutation(temp.begin(),temp.end()));
    
    for(int i=0;i<N;i++){
        p[i]=i;
    }
    sort(v.begin(),v.end());
    int counT=0;
    int counT2=0;
    int sum=0;
    while(true){
        
        int now=v[counT].first;
        int s=v[counT].second.first;
        int e=v[counT].second.second;
        counT+=1;
        int a=find(s);
        int b=find(e);
        if(a==b){
            continue;
        }
        if(a>b){
            p[a]=b;
        }else{
            p[b]=a;
        }
        sum+=now;
        counT2+=1;
        if(counT2==N-1){
            cout<<sum;
            return 0;
        }
    


    }

}
