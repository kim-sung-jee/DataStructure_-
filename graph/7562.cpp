#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
vector<int> v;
int dX[8]={1,1,-1,-1,2,2,-2,-2};
int dY[8]={2,-2,2,-2,1,-1,1,-1};
bool isVisited[300][300];
vector<int> answer;
queue<pair<int,pair<int,int>>> que;


void bfs(int X,int Y,int FX,int FY,int l){
    
    
    que.push(make_pair(0,make_pair(X,Y)));

    while(!que.empty()){
        
        
        int curX=que.front().second.first;
        int curY=que.front().second.second;
        int depth=que.front().first;
        que.pop();

        if(isVisited[curX][curY]){continue;}
        
        isVisited[curX][curY]=true;
        if(curX==FX&&curY==FY){
            answer.push_back(depth);
            return;
        }
        for(int i=0;i<8;i++){
            int dx=curX+dX[i];
            int dy=curY+dY[i];
            if(dx<0||dy<0||dx>l-1||dy>l-1){
                continue;
            }
            
            que.push(make_pair(depth+1,make_pair(dx,dy)));
        }
        
    }
}
int main(){

    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int l;
        cin>>l;
        for(int t=0;t<300;t++){
            fill_n(isVisited[t],300,false);
        }
        que=queue<pair<int,pair<int,int>>>();
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        bfs(x1,y1,x2,y2,l);
        
    }

    for(int i=0;i<answer.size()-1;i++){
        cout<<answer[i]<<endl;
    }
    cout<<answer[answer.size()-1];

}
