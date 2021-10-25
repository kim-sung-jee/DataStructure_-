#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int main(){
    int N;
    int T;
    list<int> list1;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>T;
        list1.push_back(T);
    }

    list1.sort();

    int k=N;
    int*array=new int[N];
    int i=0;
    list<int>::iterator iter;
    list<int>::iterator iter2;
    for(iter=list1.begin();iter!=list1.end();iter++){
        array[i]=(*iter)*k;
        i++;k--;
    }
    sort(array,array+N);
    cout<<array[N-1];
}
