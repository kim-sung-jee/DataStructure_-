#include<iostream>
using namespace std;

int main(){
    int L=64;
    int Ll[7]={0,};
    int temp;
    int X;
    int i=0;
    int sum=0;
    cin>>X;
    Ll[0]=L;
    temp=L;
    while(true){
        while(Ll[i]!=0){
            i++;
        }

        // for(int t=0;t<i;t++){
        //     Ll[t]=temp;
        //     temp=temp/2;
        // }

        if(Ll[i-1]==64){
            sum=64;
        }else{
            sum=Ll[i-1];
        }

        if(X==sum){
            cout<<"1";
            return  0;
            
        }else if(X<sum){
            Ll[i]=sum/2;
        }else{
            break;
        }
        temp=L;
        i=0;
        
    }
    
    i=i-1;  // i=1
  
    int wewe=1;
    int Rl[7];
    Rl[0]=Ll[i];
    int asdf=Rl[0];
    for(int wer=1;wer<7-i;wer++){
        Rl[wer]=asdf/2;
        asdf=asdf/2;
    }




    int temp2=Ll[i];

    // 51-32(temp2)=19==asd;
      
    int asd=X-temp2;  //31-16=15;
    int asf=X-temp2;  //48-32=16;
    
    int countcount=1;
    i=1;
    while(asd!=0){
        if(asd>0){
        asd=asd-Rl[i];
        i++;
        countcount+=1;
        }
        if(asd<0){
            asd=asd+Rl[i-1];
            asd=asd-Rl[i];
        
            i++;
        }
    }
    cout<<countcount;
    //
}
