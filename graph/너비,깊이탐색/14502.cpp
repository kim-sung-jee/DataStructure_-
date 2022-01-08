#include<iostream>
#include<vector>

using namespace std;

vector<int> v[8];
vector<int> v3[8];
vector<pair<int,int>> vairus;
vector<pair<int,int>> v2;
bool isVisited[8][8];
int count=0;
int dcount=100;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int N,M;
void dfs(int X,int Y){
    if(isVisited[Y][X]==true){
        return;
    }
    isVisited[Y][X]=true;
    if(v[Y][X]==0){
        count+=1;
    }
    int DX,DY;
    for(int i=0;i<4;i++){
        DX=X+dx[i];
        DY=Y+dy[i];
        if(DX<0||DY<0||DX>=M||DY>=N){
            continue;
        }
        if(v[DY][DX]==1){
            continue;
        }
        dfs(DX,DY);
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin>>N>>M;
    int size=N*M;
   
    int temp;
    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            cin>>temp;
            v[i].push_back(temp);
            v3[i].push_back(temp);
            if(temp==0){
                v2.push_back(pair<int,int>(t,i));
            }
            if(temp==2){
                vairus.push_back(pair<int,int>(t,i));
            }
        }
    }
    
    for(int i=0;i<8;i++){
        fill_n(isVisited[i],8,false);
    }
    for(int i=0;i<v2.size()-2;i++){
        for(int t=i+1;t<v2.size()-1;t++){
            for(int z=t+1;z<v2.size();z++){
                
                pair<int,int> a=v2[i];
                pair<int,int> b=v2[t];
                pair<int,int> c=v2[z];
                v[a.second][a.first]=1;
                v[b.second][b.first]=1;
                v[c.second][c.first]=1;
                
                for(int k=0;k<vairus.size();k++){
                    dfs(vairus[k].first,vairus[k].second);
                }
                if(dcount>count){
                    dcount=count;
                }
                for(int k=0;k<8;k++){
                    fill_n(isVisited[k],8,false);
                }
                
                for(int k=0;k<N;k++){
                    for(int am=0;am<M;am++){
                        v[k][am]=v3[k][am];
                    }
                }
                
                count=0;

            }
        }
    }
    
    cout<<v2.size()-dcount-3;

}
