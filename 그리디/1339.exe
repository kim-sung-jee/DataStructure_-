#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

vector<char> a[10];
int N;

int maxi=0;
map<char,int> m;
int pow(int x, int p)
{
    int a=x;
    if(p==0){
        
        return 1;
    }
    while(--p){
        x=x*a;
    }
    return x;
}
int main(){
    cin>>N;
    string b;
   
    
    for(int i=0;i<N;i++){
        cin>>b;
        for(int t=0;t<b.length();t++){
            a[i].push_back(b[t]);
            m.insert({b[t],0});
        }
      
    }
    for(int i=0;i<N;i++){
        for(int t=0;t<a[i].size();t++){
            char c=a[i][t];
            m[c]+=pow(10,a[i].size()-t-1);
        }
    }
    vector<int> v;
    map<char,int>::iterator iter;
    for(iter=m.begin();iter!=m.end();iter++){
        
        v.push_back(iter->second);
    }
    sort(v.rbegin(),v.rend());
    int ans=0;
    int q=9;
    for(int i=0;i<v.size();i++){
        ans+=v[i]*q;
        q-=1;
    }
    cout<<ans;
}
