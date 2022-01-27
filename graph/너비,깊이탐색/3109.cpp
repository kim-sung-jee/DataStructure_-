#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<char> v[10000];
int dx[3]={1,1,1};
int dy[3]={-1,0,1};
bool visited[10000][500];
int R,C;
int counT=0;
bool isfind=false;
void dfs(int X,int Y,int depth){
    if(depth==C-1){
        counT+=1;
       
        isfind=true;
        return;
    }
    for(int i=0;i<3;i++){
        if(isfind==true){
            return;
        }
        int nextX=X+dx[i];
        int nextY=Y+dy[i];
        if(0<=nextX&&nextX<C&&0<=nextY&&nextY<R){
            if(v[nextY][nextX]=='.'){
                if(visited[nextY][nextX]==false){
                    
                    visited[nextY][nextX]=true;
                    dfs(nextX,nextY,depth+1);
                    /*
                        bool flag=dfs(...);
                        if(flag==true){
                            return flag;
                        }


                    */
                }
            }
        }
    }
}

int main(){
    
    cin>>R>>C;
    // 열, 행
    char a;
    for(int i=0;i<R;i++){
        for(int t=0;t<C;t++){
            cin>>a;
            v[i].push_back(a);
        }
    }
    for(int i=0;i<R;i++){
        fill_n(visited[i],C,false);
    }
    for(int i=0;i<R;i++){
        visited[i][0]=true;
        isfind=false;
        dfs(0,i,0);
        
    }
    cout<<counT;
}
