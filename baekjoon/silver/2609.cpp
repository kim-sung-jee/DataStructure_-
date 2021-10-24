#include<iostream>
using namespace std;
int main(){

    int A,B;
    cin>>A>>B;

    int temp;
    int temp2;
    if(A>=B){
        temp=A;
        A=B;
        B=temp;
    }
    temp2=A*B;
    while(A!=0){
        temp=B%A;
        B=A;
        A=temp;
    }
    cout<<B<<endl;
    cout<<temp2/B;

    return 0;
}
