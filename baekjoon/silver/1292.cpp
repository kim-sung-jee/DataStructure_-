#include<iostream>
#include<list>
using namespace std;

int main(){

    int A,B;
    cin>>A>>B;
    
    list<int> list1;
    
    ;
    for(int i=1;i<46;i++){
        for(int t=0;t<i;t++){
            list1.push_back(i);
        }
    }
    list<int>::iterator iter;
    list<int>::iterator iter2;
    iter=list1.begin();
    iter2=list1.begin();
    for(int i=0;i<A-1;i++){
        iter++;
    }
    for(int i=0;i<B-1;i++){
        iter2++;
    }
    int sum=0;
    iter2++;
    for(;iter!=iter2;iter++){
        sum+=*iter;
    }
    cout<<sum;
}
