#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
#include<vector>
using namespace std;


int main(){


    int t;
    cin>>t;

    while(t!=1){
        vector<pair<int,int>> p;
        vector<int>s;
        for(int i=0;i<4;i++){
            int x,y;
            cin>>x>>y;
            p.push_back(make_pair(x,y));
        }
        for(int i=0;i<4;i++){
            for(int z=i+1;z<4;z++){
                s.push_back(pow(p[i].first-p[z].first,2)+pow(p[i].second-p[z].second,2));
            }
        }
        sort(s.begin(),s.end());
        if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3]&&s[4]==s[5]){
            cout<<"1"<<endl;
        }else{
            cout<<"0"<<endl;
        }
        t--;
    }
        vector<pair<int,int>> p;
        vector<int>s;
        for(int i=0;i<4;i++){
            int x,y;
            cin>>x>>y;
            p.push_back(make_pair(x,y));
        }
        for(int i=0;i<4;i++){
            for(int z=i+1;z<4;z++){
                s.push_back(pow(p[i].first-p[z].first,2)+pow(p[i].second-p[z].second,2));
            }
        }
        sort(s.begin(),s.end());
        if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3]&&s[4]==s[5]){
            cout<<"1";
        }else{
            cout<<"0";
        }

    // int T;
    // double x1,x2,x3,x4,y1,y2,y3,y4;
    // cin>>T;
    // double d[3];
    // double maxi;
    
    // double v1,v2,v3,v4;
    



    // int *Test=new int[T];
    // for(int i=0;i<T;i++){
    //     cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    //     d[0]=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    //     d[1]=sqrt(pow((x1-x3),2)+pow((y1-y3),2));
    //     d[2]=sqrt(pow((x1-x4),2)+pow((y1-y4),2));

        
    //     maxi=max(d[0],d[1]);
    //     maxi=max(maxi,d[2]);

    //     if(maxi==d[0]){
    //         v1=(x1-x2);v2=(y1-y2);
    //         v3=(x1-x3);v4=(y1-y3);
    //     }else if(maxi==d[1]){
    //         v1=(x1-x3);v2=(y1-y3);
    //         v3=(x1-x2);v4=(y1-y2);
    //     }else{
    //         v1=(x1-x4);v2=(y1-y4);
    //         v3=(x1-x2);v4=(y1-y2);
    //     }
     
    //     sort(d,d+3);
    //     if(d[0]==d[1]){
    //         if(CompareDoubleAbsoulte(d[2]/sqrt(2),d[0])){
                
    //             if(CompareDoubleAbsoulte(abs((v1*v3+v2*v4))/(sqrt(pow(v1,2)+pow(v2,2))*sqrt(pow(v3,2)+pow(v4,2))),sqrt(2)/2)){
    //                 Test[i]=1;
    //             }else{
                    
    //                 Test[i]=0;
    //             }

    //         }else{
    //             Test[i]=0;
    //         }
    //     }else{
    //         Test[i]=0;
    //     }
    // }
    
    // for(int i=0;i<T-1;i++){
    //     cout<<Test[i]<<endl;
    // }
    // cout<<Test[T-1];
}
