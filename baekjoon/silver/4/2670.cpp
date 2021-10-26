#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    int N;
    cin>>N;
    double *array=new double[N];
    double a;
    for(int i=0;i<N;i++){
        cin>>a;
        array[i]=a;
    }
   
    double maxi=-1;
    double *array2=new double[N];
    for(int i=0;i<N;i++){
        if(i==0){
            array2[i]=array[i];
        }else{
         
            array2[i]=max(array[i],array2[i-1]*array[i]);
        }
        maxi=max(maxi,array2[i]);
    }

    cout<<fixed;
    cout.precision(3);
    cout<<maxi;
    

}
