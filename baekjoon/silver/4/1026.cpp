#include<iostream>
#include<list>
using namespace std;
bool m(int a,int b){
    if(a>=b){
        return true;
    }else{
        return false;
    }
}
int main(){

    int N;
    
    cin>>N;
    list<int> A;
    list<int> B;
    int a;
    for(int i=0;i<N;i++){
        cin>>a;
        A.push_back(a);
    }

    for(int i=0;i<N;i++){
        cin>>a;
        B.push_back(a);
    }
    A.sort();
    B.sort(m);
    list<int>::iterator iter;
    int sum=0;
    for(int i=0;i<N;i++){
        sum+=A.front()*B.front();
        A.pop_front();
        B.pop_front();
    }
    cout<<sum;

}
