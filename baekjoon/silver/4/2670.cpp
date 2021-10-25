#include<iostream>
#include<algorithm>
using namespace std;
double aaa(double *array,int n,int t){
    double a=1;
    double a2[t];
    for(int i=0;i<t;i++){
        for(int z=0;z<n;z++){
            a*=*(array+z+i);
        }
        a2[i]=a;
        a=1;
    }
    sort(a2,a2+t);
    return a2[t-1];
}
int main(){
    int N;
    cin>>N;
    double *array=new double[N];
    double a;
    for(int i=0;i<N;i++){
        cin>>a;
        array[i]=a;
    }
    double *array2=new double[N-1];
    for(int i=2;i<N+1;i++){
        array2[i-2]=aaa(array,i,N+1-i);
    }
    sort(array2,array2+N-1);
    cout<<array2[N-2];

}   
