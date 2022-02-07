#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int gate[100001];
int find(int x){
    if(x==gate[x]){
        return gate[x];
    }else{
        return gate[x]=find(gate[x]);
    }
}
void Union(int a,int b){
    int x=find(a);
    int y=find(b);
    if(x>y){
        gate[x]=y;
    }else{
        gate[y]=x;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int G,P;
    cin>>G>>P;
    vector<int> gi;
    
    int a;
    for(int i=0;i<P;i++){
        cin>>a;
        gi.push_back(a);
    }

    
    for(int i=0;i<100001;i++){
        gate[i]=i;
    }
    int ans=0;
    for(int i=0;i<P;i++){
        int p=find(gi[i]);
        if(p==0){
            break;
        }else{
            ans++;
            Union(p,p-1);
        }
    }
    cout<<ans;















    // int gate[100001];
    // fill_n(gate,100001,0);
    // int count=0;
    // for(int i=1;i<=P;i++){
    //     int possible=gi[i-1];
    //     bool torf=false;
    //     for(int t=possible;t>=1;t--){
    //         if(gate[t]==0){
    //             gate[t]=1;
    //             torf=true;
    //             count+=1;
    //             break;
    //         }
    //     }
    //     if(torf==false){
    //         break;
    //     }
    // }
    // cout<<count;
}
