#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

int max1(int a,int b){
    if(a>=b){      
        return a;
    }else{
        return b;
    }
}
int min1(int a,int b){
    if(a<=b){      
        return a;
    }else{
        return b;
    }
}

int main(){
    int x1,y1,x2,y2,r1,r2;
    int T;
    cin>>T;
    int*array=new int[T];
    for(int i=0;i<T;i++){
        
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        int max=max1(r1,r2);
        int min=min1(r1,r2);
        double d=sqrt(pow(abs(x1-x2),2)+pow(abs(y1-y2),2));
        if(d==0&&max==min){
            array[i]=-1;
            continue;
        }

        if(max-min-d>0){
            array[i]=0;
        }else if(max-min-d==0){
            array[i]=1;
        }else if(max+min-d>0){
            array[i]=2;
        }else if(max+min-d==0){
            array[i]=1;
        }else{
            array[i]=0;
        }
    }
    for(int i=0;i<T-1;i++){
        cout<<array[i]<<endl;
    }
    cout<<array[T-1];
     

}
