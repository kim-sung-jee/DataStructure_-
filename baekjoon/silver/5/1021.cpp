#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

void leftside(deque<int> q){
    int n=q.front();
    q.pop_front();
    q.push_back(n);
}
void rightside(deque<int> q){
    int n=q.back();
    q.pop_back();
    q.push_front(n);
}

int main(){
    
    deque<int> q;
    int N;  //N은 크기 M은 개수
    int M;
    cin>>N>>M;
    int *T=new int[M];
    for(int i=1;i<N+1;i++){
        q.push_back(i);
    }
    
    for(int i=0;i<M;i++){
        cin>>T[i];
    }
    int count=0;
    for(int i=0;i<M;i++){
        for(int t=0;t<N;t++){

            if(q.at(t)==T[i]){
                
                
                if(N/2>=t){
                    for(int z=0;z<t;z++){
                        int n=q.front();
                        q.pop_front();
                        q.push_back(n);
                        count+=1;
                    }
                    q.pop_front();
                    N=N-1;
                    
                }else{
                    //cout<<t<<endl;
                    for(int z=0;z<N-t;z++){
                        int n=q.back();
                        q.pop_back();
                        q.push_front(n);
                        count+=1;
                    }
                    q.pop_front();
                    N=N-1;
                    
                }

            }

        }
    }
    // deque<int>::iterator iter;
    // for(iter=q.begin();iter!=q.end();iter++){
    //     cout<<*iter;
    // }
    cout<<count;
}
