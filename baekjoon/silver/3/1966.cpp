#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int findmax(int a1,pair<int,int> a2){
    if(a1>=a2.second){
        return a1;
    }else{
        return a2.second;
    }
}


int main(){

    int T;
    int N,M;
    int Z;
    cin>>T;
    int*ll=new int[T];
    int*print=new int[T];
    queue<pair<int,int>> q1[T];
    for(int i=0;i<T;i++){
        cin>>N;
        cin>>M;
        ll[i]=M;
        for(int t=0;t<N;t++){
            cin>>Z;
            q1[i].push(make_pair(t,Z));
        }
    }
    int max;
    queue<pair<int,int>> q2;
    // second 가 실제 값;
    for(int i=0;i<T;i++){
        int count=0;
        q2=q1[i];

        while(true){
            max=q2.front().second;
            for(int t=0;t<q2.size();t++){
                max=findmax(max,q2.back());
                pair<int,int> a=q2.front();
                q2.pop();
                q2.push(a);
                
            }
            max=findmax(max,q2.back());
            while(q2.front().second!=max){
                
                pair<int,int> a=q2.front();
                q2.pop();
                q2.push(a);
               
            }
            
            if(q2.front().first==ll[i]){
                
                count+=1;
                print[i]=count;
                break;
            }else{
                
                q2.pop();
                count+=1;
            }
            
            max=0;
        }

        count=0;
        max=0;

    }
    
    for(int i=0;i<T-1;i++){
        cout<<print[i]<<endl;
    }
    cout<<print[T-1];
}
