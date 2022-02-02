#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int N;
    cin>>N;
    vector<int> v;
    int a;
    long long ans=0;
    bool torf=false;
    int mCount=0;
    int pCount=0;
    for(int i=0;i<N;i++){
        cin>>a;
        if(a==0){
            torf=true;
        }else if(a==1){
            ans+=1;
        }
        else if(a>0){
            v.push_back(a);
            pCount+=1;
        }else{
            v.push_back(a);
            mCount+=1;
        }
    }
    sort(v.begin(),v.end());
    // 0이 있을 때
    
    if(torf==true){
        if(mCount%2==0&&pCount%2==0){
            for(int i=0;i<v.size();i+=2){
                ans+=v[i]*v[i+1];
            }
        }else if(mCount%2==0&&pCount%2==1){
            for(int i=0;i<mCount;i+=2){
                ans+=v[i]*v[i+1];
            }
            ans+=v[mCount];
            for(int i=mCount+1;i<v.size();i+=2){
                ans+=v[i]*v[i+1];
            }
        }else if(mCount%2==1&&pCount%2==0){
            for(int i=0;i<mCount-1;i+=2){
                ans+=v[i]*v[i+1];
            }
            for(int i=mCount;i<v.size();i+=2){
                ans+=v[i]*v[i+1];
            }
        }else{
             for(int i=0;i<mCount-1;i+=2){
                ans+=v[i]*v[i+1];
            }
            ans+=v[mCount];
            for(int i=mCount+1;i<v.size();i+=2){
                ans+=v[i]*v[i+1];
            }
        }





    // 0이 없을 때
    }else{
        if(mCount%2==0&&pCount%2==0){
            for(int i=0;i<v.size();i+=2){
                ans+=v[i]*v[i+1];
            }
        }else if(mCount%2==1&&pCount%2==1){
            for(int i=0;i<mCount-1;i+=2){
                ans+=v[i]*v[i+1];
            }
            ans+=v[mCount-1]+v[mCount];
            for(int i=mCount+1;i<v.size();i+=2){
                ans+=v[i]*v[i+1];
            }
        }else if(mCount%2==0&&pCount%2==1){
            for(int i=0;i<mCount;i+=2){
                ans+=v[i]*v[i+1];
            }
            ans+=v[mCount];
            for(int i=mCount+1;i<v.size();i+=2){
                ans+=v[i]*v[i+1];
            }
        }else{
            for(int i=0;i<mCount-1;i+=2){
                ans+=v[i]*v[i+1];
            }
            ans+=v[mCount-1];
            for(int i=mCount;i<v.size();i+=2){
                ans+=v[i]*v[i+1];
            }
        }


    }


    cout<<ans;
}
