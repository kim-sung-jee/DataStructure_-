#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<pair<pair<int,int>,pair<int,int>>> day;
int N;
int main(){
    cin>>N;
    int a,b,c,d;
    for(int i=0;i<N;i++){
        cin>>a>>b>>c>>d;
        day.push_back({{a,b},{c,d}});
    }
    int firstD=1;
    int firstM=3;
    int lastM=3;
    int lastD=1;
    int ans=0;
    while(true){
        int f1,f2;
        for(int i=0;i<N;i++){
            int fM=day[i].first.first;
            int fD=day[i].first.second;
            int lD=day[i].second.second;
            int lM=day[i].second.first;
            if(fM<firstM&&lastM<lM){
                lastD=lD;lastM=lM;
            }else if(fM==firstM&&fD<=firstD&&lastM<lM){
                
                lastD=lD;lastM=lM;
            }else if(lastM==lM&&lastD<lD&&fM<firstM){
                
                lastD=lD;lastM=lM;
            }else if(fM==firstM&&fD<=firstD&&lastM==lM&&lastD<lD){
               
                lastD=lD;lastM=lM;
            }
        }
        ans+=1;
        firstD=lastD;firstM=lastM;
        if(ans>=300){
            cout<<"0";
            return 0;
        }
        if(lastM>11){
            break;
        }

    }
    cout<<ans;

}
