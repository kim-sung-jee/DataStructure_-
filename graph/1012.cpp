#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int arr[50][50]={0,};
bool visited[50][50]={0,};
int fx[4]={1,-1,0,0};
int fy[4]={0,0,1,-1};
void dfs(int y,int x,int M,int N){
   
    for(int i=0;i<4;i++){
        int dx=x+fx[i];
        int dy=y+fy[i];
        if(dy<0||dx<0||dx>=M||dy>=N){
            continue;
        }
        if(visited[dy][dx]==0&&arr[dy][dx]==1){
            visited[dy][dx]=1;
           
            dfs(dy,dx,M,N);
        }

    }


}
int main(){
    
    int T;
    //M 가로길이 N 세로길이 K 노드 개수
    int M,N,K;

    cin>>T;

    vector<int> answer;

    for(int i=0;i<T;i++){
        int ans=0;
        cin>>M>>N>>K;
        
        for(int t=0;t<50;t++){
            fill_n(arr[t],50,0);
        }
        for(int t=0;t<50;t++){
            fill_n(visited[t],50,0);
        }
        
        for(int t=0;t<K;t++){
            int x,y;
            cin>>x>>y;
            arr[y][x]=1;
        }
        for(int t=0;t<N;t++){
            for(int z=0;z<M;z++){
                if(arr[t][z]==1&&visited[t][z]==0){
                    ans++;
                    //cout<<t<<z<<endl;
                    visited[t][z]=1;
                    dfs(t,z,M,N);
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
