#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> v[501];
int indegree[501];
vector<int> ans;
void topoloySort(int n){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
    for(int i=1;i<=n;i++){
        if(q.empty()){
            cout<<"IMPOSSIBLE";
            return;
        }else if(q.size()>1){
            cout<<"?";
        }
        int x=q.front();
        q.pop();
        ans.push_back(x);
        for(int z=0;z<v[x].size();z++){
            int next=v[x][z];
            
            if(--indegree[next]==0){
                q.push(next);
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    ans.clear();
}
int main(){
    int T;
    int temp[501];
    cin>>T;
    for(int i=0;i<T;i++){
        int n;int m;
        cin>>n;

        for(int t=0;t<n;t++){
            cin>>temp[t];
        }
        int a=n;
        for(int t=0;t<n;t++){
            for(int z=0;z<a-1;z++){
                v[temp[t]].push_back(temp[t+z+1]);
                indegree[temp[t+z+1]]+=1;
            }
        
            a-=1;
        }
        cin>>m;
        int s,e;
        int c1,c2;
        for(int z=0;z<m;z++){
            cin>>c1>>c2;
            bool ok=false;
            for(int t=0;t<v[c1].size();t++){
                if(v[c1][t]==c2){
                    ok=true;
                }
            }
            if(ok==true){
                for(int t=0;t<v[c1].size();t++){
                    if(v[c1][t]==c2){
                        v[c1].erase(v[c1].begin()+t);
                    }
                }
                v[c2].push_back(c1);
                indegree[c1]+=1;
                indegree[c2]-=1;
            }else{
                
                for(int t=0;t<v[c2].size();t++){
                    if(v[c2][t]==c1){
                        v[c2].erase(v[c2].begin()+t);
                    }
                }
                v[c1].push_back(c2);
                indegree[c1]-=1;
                indegree[c2]+=1;
            }

        }
        
        topoloySort(n);
        for(int i=0;i<501;i++){
            v[i].clear();
        }
        cout<<endl;
        
        for(int i=1;i<501;i++){
            indegree[i]=0;
        }
        fill_n(temp,501,0);
    }   
}

//// 이상 기존 코드
