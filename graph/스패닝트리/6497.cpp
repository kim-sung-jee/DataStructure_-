#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,M;

vector<pair<int,pair<int,int>>> v;
int p[200000];
vector<int> ans;
int find(int x){
    if(p[x]==x){
        return x;
    }else{
        return p[x]=find(p[x]);
    }

}

int main(){

    while(true){
        int nSum=0;
        cin>>M>>N;
        if(M==0&&N==0){
            break;
        }
        v.clear();
        int s,e,c;
        for(int i=0;i<N;i++){
            cin>>s>>e>>c;
            v.push_back({c,{s,e}});
            nSum+=c;
        }
        for(int i=0;i<M;i++){
            p[i]=i;
        }
        int count=0;
        int sum=0;
        int ccc=0;
        sort(v.begin(),v.end());
        while(true){
            
            int next=v[ccc].first;
            int x=v[ccc].second.first;
            
            int y=v[ccc].second.second;
           
            
            int a=find(x);
           
            int b=find(y);
            
            if(a==b){
                ccc++;
                continue;
            }
            if(a>b){
                p[a]=y;
            }else{
                p[b]=a;
            }
            count+=1;
            ccc++;
            sum+=next;
           
            if(count==M-1){
                
                ans.push_back(nSum-sum);
                break;
            }
            
        }

        
        
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

}
