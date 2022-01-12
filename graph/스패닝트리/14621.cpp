#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,pair<int,int>>> v;
vector<char> sex;
// int compare(pair<pair<char,int>,pair<int,int>> v1,pair<pair<char,int>,pair<int,int>> v2){
//     int a=v1.first.second;
//     int b=v2.first.second;
//     return b<a;
// }
bool isVisited[1001];
int p[1001];
int find(int x){
    if(p[x]==x){
        return x;
    }else{
        return find(p[x]);
    }
}
int main(){
    int N,M;
    cin>>N>>M;
    char a;
    int s,e,w;
    for(int i=0;i<N;i++){
        cin>>a;
        sex.push_back(a);
    }
    for(int i=0;i<M;i++){
        cin>>s>>e>>w;
        if(sex[s-1]!=sex[e-1]){
            v.push_back({w,{s,e}});
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<1001;i++){
        p[i]=i;
    }
    fill_n(isVisited,1001,false);
    isVisited[0]=true;
    int sum=0;
    int num=0;
    for(int i=0;i<v.size();i++){
        int dist=v[i].first;
        int start=v[i].second.first;
        int end=v[i].second.second;

        int x=find(start);
        int y=find(end);
        if(x==y){continue;}
        if(x>y){
            p[x]=y;
        }else{
            p[y]=x;
        }
        sum+=dist;
        num++;
        isVisited[start]=true;
        isVisited[end]=true;
        if(N-1==num){
            cout<<sum;
            return 0;
        }
    }
    
    
    cout<<"-1";
}
