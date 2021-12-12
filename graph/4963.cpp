#include<iostream>
#include<vector>
using namespace std;

int arr[50][50]={0,};
int isvisited[50][50]={0,};
int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,-1,1,1,-1};
void dfs(int y,int x,int w,int h){
    for(int i=0;i<8;i++){
        int fy=y+dy[i];
        int fx=x+dx[i];
        if(fx<0||fx>=w||fy<0||fy>=h){continue;}

        if(isvisited[fy][fx]==0&&arr[fy][fx]==1){
            isvisited[fy][fx]=1;
            dfs(fy,fx,w,h);
        }
    }
}

int main(){
    vector<int> answer;
    int w,h;
    while(true){
        cin>>w>>h;
        int ans=0;
        if(w==0&&h==0){
            break;
        }

        for(int i=0;i<50;i++){
            fill_n(arr[i],50,0);
        }
        for(int i=0;i<50;i++){
            fill_n(isvisited[i],50,0);
        }

        for(int i=0;i<h;i++){
            for(int t=0;t<w;t++){
                cin>>arr[i][t];
            }
        }
      
        for(int i=0;i<h;i++){
            for(int t=0;t<w;t++){
                if(arr[i][t]==1&&isvisited[i][t]==0){
                    ans+=1;
                    dfs(i,t,w,h);
                }
            }
        }
        answer.push_back(ans);

    }
    for(int i=0;i<answer.size()-1;i++){
        cout<<answer[i]<<endl;
    }
    cout<<answer[answer.size()-1];


}
