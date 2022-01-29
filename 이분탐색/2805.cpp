#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long> v;
long long H;
bool cutting(long long middle){
    long long sum=0;
    for(int i=0;i<v.size();i++){
        if(v[i]-middle<0){
            continue;
        }else{
            sum+=v[i]-middle;
        }
    }
    if(sum<H){
        return false;
    }else{
        return true;
    }
}
int main(){
    int N;
    
    cin>>N>>H;
    long long a;
    long long maxi=0;
    long long mini=2000000000;
    for(int i=0;i<N;i++){
        cin>>a;
        v.push_back(a);
        maxi=max(maxi,a);
        mini=min(mini,a);
    }
    long long mid;
    //
    long long start=0;
    long long end=1e9;
    //
    while(start<=end){
        mid=(start+end)/2;
        if(cutting(mid)==true){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    cout<<end;
}
