#include<iostream>
#include<queue>
#include<list>
using namespace std;



int main(){

    
    string s;
    int N;
    cin>>N;
    deque<char> dq[N];
    for(int i=0;i<N;i++){
        cin>>s;
        for(int t=0;t<s.size();t++){
            dq[i].push_back(s[t]);
        }
    }

    list<int> lenght;
    for(int i=0;i<N;i++){
        lenght.push_back(dq[i].size());
    }
    lenght.unique();

    int size=lenght.size();
    int count=N;
    for(int i=0;i<N;i++){
        for(int t=i+1;t<N;t++){

            if(dq[i].size()==dq[t].size()){

                int size=dq[i].size();
                char c;
                
                while(size!=0){
                    if(dq[i]==dq[t]){
                        
                        count=count-1;
                        
                        dq[t].clear();
                        break;
                    }
                    c=dq[i].front();
                    dq[i].push_back(c);
                    dq[i].pop_front();
                    size-=1;
                }
            }

        }
    }
    cout<<count;

}
