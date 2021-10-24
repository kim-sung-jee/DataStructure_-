#include<iostream>
#include<list>
using namespace std;

int main(){

    int N;
    cin>>N;

    char**W=new char*[N];
    for(int i=0;i<N;i++){
        W[i]=new char[100];
    }

    for(int i=0;i<N;i++){
        cin>>W[i];
    }
    int count=0;
    list<char> list1;
    list<char> list2;
    list<char>::iterator iter;
    for(int i=0;i<N;i++){
        
        for(int t=0;t<100;t++){
            if(W[i][t]!=NULL){
                list1.push_back(W[i][t]);
            }else{
                break;
            }
        }
        list1.unique();
        list1.sort();
        list2=list1;
        list2.unique();
        if(list1==list2){
            count+=1;
        }

        

        list1.clear();


    }
    cout<<count;


}
