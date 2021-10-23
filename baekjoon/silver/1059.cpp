#include<iostream>
using namespace std;

int main(){
    int L;
    cin>>L;

    int *list=new int[L];
    int list2[50];
    for(int i=0;i<L;i++){
        cin>>list[i];
    }

    int n;
    cin>>n;

    int temp;
    for(int i=0;i<L;i++){
        for(int t=i+1;t<L;t++){
            if(list[i]>list[t]){
                temp=list[i];
                list[i]=list[t];
                list[t]=temp;
            }
        }
    }
   
    int i=0;

    while(true){
        if(temp=list[i]-n==0){
            cout<<"0";
            return 0;
        }
        if(temp=list[i]-n<0){
            i++;
        }else{
            break;
        }
    }
    
    // i~i+1;
    //list[i]~list[i+1];
    int x=list[i-1]+1;
    int y=list[i]-1;
    //2~9;
    x=n-x;
    y=y-n;
    cout<<x*(y+1)+y;
}  
