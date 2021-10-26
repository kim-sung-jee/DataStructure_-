#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

int main(){

    int N,K;
    cin>>N>>K;
    list<int> list1;
    int t=0;
    for(int i=2;i<N+1;i++){
        list1.push_back(i);
        t++;        
    }
    list<int>::iterator iter;
    iter=list1.begin();
    int count=0;
    int a=*min_element(list1.begin(),list1.end());
    
    int i=1;
    bool running = true;
    while(running){
    while(a*i<=N){
        if(binary_search(list1.begin(),list1.end(),a*i)){
            count+=1;
            if(K==count){
                cout<<a*i;
                return 0;
            }
            
            list1.remove(a*i);
        }

            i++;
        }
        i=1;
        
        a=*min_element(list1.begin(),list1.end());
        
    }
}
