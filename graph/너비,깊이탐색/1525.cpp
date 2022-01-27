#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int board[3][3];
int count=0;
map<int,int> visited;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int start=0;
void bfs(){
    queue<int> q;
    // map의 key는 그래프, value는 방문횟수;
    q.push(start);
    visited[start]=0;
    while(!q.empty()){
        int cur=q.front();
        string s=to_string(cur);
        q.pop();
        if(cur==123456789){
            break;
        }
        int z=s.find('9');
        // y는 y좌표
        //x는 x좌표...
        int y=z/3;
        int x=z%3;
        for(int i=0;i<4;i++){
            int nextY=y+dy[i];
            int nextX=x+dx[i];

            if(0<=nextX&&nextX<3&&0<=nextY&&nextY<3){
                string temp=s;
                swap(temp[y*3+x],temp[nextY*3+nextX]);

                int next=stoi(temp);
                if(visited.count(next)==0){
                    visited[next]=visited[cur]+1;
                    
                    q.push(next);
                }
            }
        }
    }
}

int main(){
    int x,y;
    
    int num;
    for(int i=0;i<3;i++){
        for(int t=0;t<3;t++){
            cin>>num;
            if(num==0){
                num=9;
            }
            start=start*10+num;
        }
    }
    bfs();
    if(visited.count(123456789)==0){
        cout<<"-1";
    }else{
        cout<<visited[123456789];
    }
    return 0;
}
