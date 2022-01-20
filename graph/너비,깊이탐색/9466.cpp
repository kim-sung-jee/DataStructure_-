#include<iostream>
#include<vector>
using namespace std;
vector<int> s[100001];
bool isVisited[100001];
vector<int> ans;
bool done[100001];
int count=0;
void dfs(int S){
    isVisited[S]=true;
    int next=s[S][0];
    if(!isVisited[next]){
        dfs(next);
    }
    else if(!done[next]){
        for(int i=next;i!=S;i=s[i][0]){
            count+=1;
            done[next]=true;
        }
        count+=1;
    }
    done[S]=true;
}
int main(){
    int T;
    cin>>T;
    int n;
    int temp;
    for(int i=0;i<T;i++){
        cin>>n;
        for(int t=0;t<n;t++){
            cin>>temp;
            s[t+1].push_back(temp);
        }
        count=0;
        fill_n(isVisited,100001,false);
        fill_n(done,100001,false);
        for(int t=0;t<n;t++){
            if(!isVisited[t+1]){
                dfs(t+1);
            }
        }
        ans.push_back(n-count);
        for(int i=0;i<n;i++){
            s[i+1].clear();
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

}
