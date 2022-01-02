#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX=10001;
vector<int> v1[MAX];
vector<int> arr;
vector<pair<int,int>> v;
bool isVisited[10001];
int c=1;
void dfs(int a){
    isVisited[a]=true;
    for(int i=0;i<v1[a].size();i++){
        int next=v1[a][i];
        
        if(isVisited[next]==false){
            
            dfs(next);
            c++;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,M;

    cin>>N>>M;
    int t1,t2;
    
    

    for(int i=0;i<M;i++){
        
        cin>>t1>>t2;
        v1[t2-1].push_back(t1-1);
    }
    int maxi=1;

    for(int i=0;i<N;i++){
        fill_n(isVisited,10001,false);
        dfs(i);
        v.push_back(make_pair(i,c));
        c=1;
    }
    int c=-1;
    for(int i=0;i<v.size();i++){
        if(v[i].second>c){
            c=v[i].second;
        }
    }
    for(int i=0;i<v.size();i++){
        if(v[i].second==c){
            cout<<v[i].first+1<<" ";
        }
    }
}
/*
void dfs(int a){
    if(v1[a].size()==0){
        return;
    }
    for(int i=0;i<v1[a].size();i++){
        int next=v1[a][i];
        
        dfs(next);
        c++;
    }
}
*/
