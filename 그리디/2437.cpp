#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> weight;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    int w;
    for(int i=0;i<N;i++){
        cin>>w;
        weight.push_back(w);
    }
    sort(weight.begin(),weight.end());
    int sum=0;
    int ans=-1;
    for(int i=0;i<N;i++){
        if(sum+1<weight[i]){
            break;
        }
        sum+=weight[i];
    }
    cout<<sum+1;
}
