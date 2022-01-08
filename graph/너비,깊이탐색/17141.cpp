#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> v[50];
vector<pair<int,int>> varius;
int N,M;
vector<int> ind;
queue<pair<pair<int,int>,int>> q;
vector<pair<int,int>> rv;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int bla=0;
int fc=0;
bool isVisited[50][50];
int d;
vector<int> ans;
void bfs(int m){
    for(int i=0;i<m;i++){
        q.push(pair<pair<int,int>,int>(rv[i],0));
        isVisited[rv[i].second][rv[i].first]=true;
    }
    int DX,DY;
    
    while(!q.empty()){
        pair<int,int> next=q.front().first;
        d=q.front().second;
       
        
        q.pop();
        int x=next.first;
        int y=next.second;
        
        //if(isVisited[y][x]==true){continue;}
        //isVisited[y][x]=true;
        
        
        for(int i=0;i<4;i++){
            DX=x+dx[i];
            DY=y+dy[i];
            if(DX<0||DY<0||DX>=N||DY>=N){continue;}
            if(isVisited[DY][DX]==true){continue;}
            if(v[DY][DX]==1){continue;}
            if(v[DY][DX]==2){fc-=1;}
            isVisited[DY][DX]=true;
            fc+=1;
            
            q.push(pair<pair<int,int>,int>(pair<int,int>(DX,DY),d+1));
           
            
        }
        
    }
    //fc 방문한 0의 개수
    //bla 총 0의 개수
    if((bla)!=fc){
        
        ans.push_back(-1);
    }else{
        
        ans.push_back(d);
    }
    //cout<<d<<endl;
}
int main(){
    cin>>N>>M;
    int temp;
    for(int i=0;i<N;i++){
        for(int t=0;t<N;t++){
            cin>>temp;
            v[i].push_back(temp);
            if(temp==2){
                varius.push_back(pair<int,int>(t,i));
            }
            if(temp==0){
                bla+=1;
            }
        }
    }
    
    //bla 는 0의 개수
    for(int i=0;i<N;i++){
        fill_n(isVisited[i],50,false);
    }
    int k=M;
    for(int i=0;i<k;i++){
        ind.push_back(1);
    }
    for(int i=0;i<varius.size()-k;i++){
        ind.push_back(0);
    }
    sort(ind.begin(),ind.end());
    do{
        for(int i=0;i<ind.size();i++){
            if(ind[i]==1){
                rv.push_back(varius[i]);
            }
        }
        bfs(k);
        
        rv.clear();
        for(int i=0;i<50;i++){
            fill_n(isVisited[i],50,false);
        }
        
    
        fc=0;
    
    }while(next_permutation(ind.begin(),ind.end()));
    sort(ans.begin(),ans.end());
    
    for(int i=0;i<ans.size();i++){
        if(ans[i]!=-1){
            cout<<ans[i];
            return 0;
        }
    }
    cout<<"-1";
}
