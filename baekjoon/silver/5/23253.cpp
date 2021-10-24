#include<iostream>
#include<stack>
using namespace std;

int main(){

    int N,M;  //N은 교과서 개수 M은 더미의 개수
    
    cin>>N>>M;
    
    int ki;
    
    stack<int> stack1[M];
    for(int i=0;i<M;i++){
        int k;
        cin>>k;
        for(int z=0;z<k;z++){
            cin>>ki;
            stack1[i].push(ki);
        }
    }

    int count=N;
    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            if(stack1[t].empty()==0){
                if(stack1[t].top()==i+1){
                    stack1[t].pop();
                    count-=1;
                    break;
                }
            }else{
                continue;
            }
        }
    }   
    
    
    if(count==0){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}
