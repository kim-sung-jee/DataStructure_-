#include<iostream>
#include<list>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
 
int gcd(int a, int b) {
    int temp;
    if (a < b)
        swap(a, b);
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main(){
    
    int T;
    cin>>T;
    int*A=new int[T];
    int*B=new int[T];
    for(int i=0;i<T;i++){
        cin>>A[i]>>B[i];
    }
    for(int i=0;i<T;i++){
        if(i==T-1){
            cout<<lcm(A[i],B[i]); 
            break;
        }
        cout<<lcm(A[i],B[i])<<endl;
    }
    // int T;
    // cin>>T;
    // int*A=new int[T];
    // int*B=new int[T];

   

    // list<int> list1;
    // list<int> list2;
    
    // for(int i=0;i<T;i++){
    //     cin>>A[i]>>B[i];
    // }

    // for(int i=0;i<T;i++){

    //     for(int t=2;t<A[i];t++){
    //         if(A[i]%t==0){
    //             list1.push_back(t);
    //         }
    //     }

    //     for(int t=2;t<B[i];t++){
    //         if(B[i]%t==0){
    //             list2.push_back(t);
    //         }
    //     }

    //     if(list1.empty()||list2.empty()){
    //         if(i<T-1){
    //             cout<<A[i]*B[i]<<endl;
    //             continue;
    //         }else if(i==T-1){
    //             cout<<A[i]*B[i];
    //             continue;
    //         }
    //     }

    //     // list1.merge(list2);
    //     // list1.sort();
    //     list<int>::iterator iter1;
    //     list<int>::iterator iter2;
    //     iter1=list1.begin();
    //     iter2=list2.begin();
    //     while(true){
    //         if(*iter1>*iter2){
    //             iter2++;
    //         }else if(*iter1<*iter2){
    //             iter1++;
    //         }else{
    //             if(i<T-1){
    //                 cout<<A[i]*B[i]/(*iter1)<<endl;
    //                 break;
    //             }else if(i==T-1){
    //                 cout<<A[i]*B[i]/(*iter1);
    //                 break;
    //             }
    //         }
    //     }
    //     list1.clear();
    //     list2.clear();
    // }

}
