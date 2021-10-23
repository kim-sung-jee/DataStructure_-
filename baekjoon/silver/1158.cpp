#include<iostream>
#include<queue>
using namespace std;

int main(){
    int N;
    int K;
    cin>>N>>K;
    queue<int> queue;
    for(int i=1;i<N+1;i++){
        queue.push(i);
    }
    cout<<"<";
    int t=0;
    while(N!=t){
        
        for(int i=0;i<K-1;i++){
            queue.push(queue.front());
            queue.pop();
        }
        if(t<=N-2){
        cout<<queue.front()<<", ";
        queue.pop();
        }else{
            cout<<queue.front();
        }
        t+=1;
    }

    cout<<">";





















    // int N;
    // cin>>N;
    // int*list=new int[N];
    // int K;
    // cin>>K;
    // int asd=0;
    // for(int i=1;i<N+1;i++){
    //     list[i-1]=i;
    // }
    
    // int*list2=new int[N];
    // int T=K-1;
    // int i=0;
    // while(asd<N){     

    //     if(T<=N-1){
    //         if(list[T]!=-1){
    //             list2[i]=list[T];
    //             list[T]=-1;
    //             if(i==N-1){
    //                 break;
    //             }
    //             i++;
                
    //         }
    //         for(int t=0;t<K;t++){
    //             T++;
    //             if(T>N-1){
    //                 T=T-N;  
    //             }

                
    //             if(list[T]==-1){
                    
    //                 t-=1;
                    
    //             }
                
    //         }
            
            
    //     }
        
    //     asd++;
    // }
    // cout<<"<";
    // for(int t=0;t<N-1;t++){
    //     cout<<list2[t]<<", ";
    // }
    // cout<<list2[N-1]<<">";
}
