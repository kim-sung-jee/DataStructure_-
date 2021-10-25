#include<iostream>
#include<list>
using namespace std;

void move(list<string>&s){
    string temp;
    temp=s.front();
    s.push_back(temp);
    s.pop_front();
}


int main(){
    
    int N,M;
    cin>>N>>M;
    int max;
    if(N>=M){
        max=N;
    }else{
        max=M;
    }
    string *array=new string[max];
    list<string> list1;
    list<string> list2;
    string a;
    for(int i=0;i<N;i++){
        cin>>a;
        list1.push_back(a);
    }
    for(int i=0;i<M;i++){
        cin>>a;
        list2.push_back(a);
    }
    // list1.sort();
    // list2.sort();
    int z=0;
    for(int i=0;i<max;i++){

        if(list1.front()==list2.front()){
            array[z]=list1.front();
            z++;
            list1.pop_front();list2.pop_front();
        }else if((list1.front()!=list2.front())){

        if(list1.size()>=list2.size()){
            for(int t=0;t<list1.size();t++){
                move(list1);
                if(list1.front()==list2.front()){
                    array[z]=list1.front();
                    z++;
                    list2.pop_front();
                    break;
                }
            }
            list1.pop_front();
        }else{
            for(int t=0;t<list2.size();t++){
                move(list2);
                if(list1.front()==list2.front()){
                    array[z]=list1.front();
                    z++;
                    list1.pop_front();
                    
                    break;
                }
            }
            list2.pop_front();
            //cout<<list2.front();
        }

        }
    }
    if(z==0){
        cout<<"0";
    }else{
        cout<<z<<endl;
    }
    for(int i=0;i<z-1;i++){
        cout<<array[i]<<endl;
    }
    cout<<array[z-1];



    // int z=0;
    // int size=list1.size();
    // list<string>::iterator iter=list2.begin();
    // for(int i=0;i<size;i++){
    //     for(int t=0;t<list2.size();t++){
    //         if(list1.front()==*iter  ){
    //             array[z]=list1.front();
    //             z++;
    //             break;
    //         }
    //         iter++;
    //     }
    //     list1.pop_front();
    //     iter=list2.begin();
    // }
    // if(z==0){
    //     cout<<"0";
    // }else{
    //     cout<<z<<endl;
    // }
    // for(int i=0;i<z-1;i++){
    //     cout<<array[i]<<endl;
    // }
    // cout<<array[z-1];
}
