#include<iostream>
#include<list>
using namespace std;

bool SizeComp(const string&a,const string&b){
    if(a.size()>b.size()){
        return false;
    }else if(a.size()<b.size()){
        return true;
    }else if(a.size()==b.size()){
        if(a<b){
            return true;
        }else{
            return false;
        }
    }
}


int main(){
    int N;
    cin>>N;
    string a;
    list<string> list1;
    for(int i=0;i<N;i++){
        cin>>a;
        list1.push_back(a);
    }
    list<string>::iterator iter;
    list1.sort(SizeComp);
    list1.unique();
    
    for(iter=list1.begin();iter!=--list1.end();iter++){
        cout<<*iter<<endl;
    }
    cout<<*iter;
}
