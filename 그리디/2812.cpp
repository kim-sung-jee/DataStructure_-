// #include<iostream>
// #include<vector>
// #include<queue>


// using namespace std;
// int main(){
//     int N,K;
//     cin>>N>>K;
    
//     deque<int> q;
//     string a;
//     cin>>a;
    
//     for(int i=0;i<N;i++){
//         char b=a[i];
//         int c=b-'0';
//         q.push_back(c);
//     }
    
    
//     int count=K;
//     int idx=0;
//     //count=4;
//     vector<int> ans;
//     while(true){
//         bool torf=true;
//         int dorl=q[idx];
//         for(int i=0;i<count;i++){
//             if(dorl<q[i+idx+1]){
//                 count-=1;
//                 q[idx]=-1;
//                 torf=false;
//                 break;
//             }
//         }
        
//         if(torf==true){
//             ans.push_back(dorl);
//         }



//         idx+=1;
        

//         if(count==0){
//             break;
//         }

//     }
    
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i];
//     }
//     for(int i=idx;i<q.size();i++){
//         cout<<q[i];
//     }
// }

// idx 보다 현재 빠진 수 만큼까지 비교해서 큰게 있으먄
// 제거해준당
#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n,k,i;
    string s;
    deque<char> dq;
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<s.length();i++){
        while(0<k&&!dq.empty()&&dq.back()<s[i]){
                cout<<dq.back()<<endl;
                dq.pop_back();
                k--;
            
        }
        dq.push_back(s[i]);
    }
    
    for(int i=0;i<dq.size()-k;i++){
        cout<<dq[i];
    }
    
}
