#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;


int main(){
    
    int N,M;
    cin>>N>>M;
    

    vector<string> v1;
    vector<string> v2;
    string a;
    for(int i=0;i<N;i++){
        cin>>a;
        v1.push_back(a);
    }
    sort(v1.begin(),v1.end());    
    
    string b;
    vector<string>::iterator iter,iter2;
    iter=v1.begin();
    iter2=v1.end();
    bool torf;
     for(int i=0;i<M;i++){
        cin>>b;
        if(binary_search(iter,iter2,b)){
            v2.push_back(b);
        }
    }
    int t=v2.size();
    
    sort(v2.begin(),v2.end());
    if(t==0){
        cout<<"0";
    }else{
        cout<<t<<endl;
    }

    string c[t];
    for(int i=0;i<t;i++){
        c[t-i-1]=v2.back();
        v2.pop_back();
    }
    for(int i=0;i<t-1;i++){
        cout<<c[i]<<endl;
    }
    cout<<c[t-1];
}
 
