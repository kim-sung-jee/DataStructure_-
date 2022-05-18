#include<iostream>
#include<map>
using namespace std;


string house[5]={"blue","green","red","white","yellow"};
string nationality[5]={"Brit","Dane","German","Norwegian","Swede"};
string beverage[5]={"beer","coffee","milk","tea","water"};
string cigar[5]={"Blue Master","Dunhill","Pall Mall","Prince","Blend"};
string pet[5]={"cat","bird","dog","fish","horse"};
map<string,int> m_house;
map<string,int> m_nationaltiy;
map<string,int> m_beverage;
map<string,int> m_cigar;
map<string,int> m_pet;
// 5개가 전부다 사람마다 달라야함
// 사람 번호를 기준으로 나눠주기.
const int Peoples=5;
const int Properties=5;
const int arrSize=5;

const int Color=0;
const int Beverage=1;
const int Pet=2;
const int Cigarets=3;
const int Nationality=4;

// y번 사람의 x번 째 속성
int ans[Peoples][Properties];




void init(){
    
    for(int i=0;i<arrSize;i++){
        m_house.insert({house[i],i});
        m_nationaltiy.insert({nationality[i],i});
        m_beverage.insert({beverage[i],i});
        m_cigar.insert({cigar[i],i});
        m_pet.insert({pet[i],i});
    }
    // ans 초기화
    for(int i=0;i<Properties;i++){
        fill_n(ans[i],arrSize,-1);
    }
}


bool promising(){
    // 서로의 속성이 다 다른지 체크해주기
    //  i 사람번호
    for(int i=0;i<Peoples;i++){
        // t 속성번호!
        for(int t=0;t<Properties;t++){
            // k 사람번호
            for(int k=i+1;k<Peoples;k++){
                if(ans[i][t]!=-1&&ans[k][t]!=-1&&ans[i][t]==ans[k][t]){
                    //cout<<ans[i][t]<<" "<<ans[k][t]<<"i t k is "<<i<<t<<k<<endl;
                    return false;
                }
            }
        }
    }
    
    //1번 조건
    //brit 는 red house에 산다.
    // 확인 완료...
    for(int i=0;i<Properties;i++){
        if(ans[i][Nationality]==m_nationaltiy["Brit"]&&ans[i][Color]!=m_house["red"]&&ans[i][Color]!=-1){
            return false;
        }
    }
    // 2번 조건
    // swede는 pet을 dog로 가진다.
    // 확인 완료...
    for(int i=0;i<Properties;i++){
        // i번째 사람이 스웨덴이고 + i번째 사람의 펫이 dog 가 아니고 + i 번째 사람의 pet이 할당이 된 상태라면
        // 즉 초기화만 일어난 상태가 아니라면
        if(ans[i][Nationality]==m_nationaltiy["Swede"]&&ans[i][Pet]!=m_pet["dog"]&&ans[i][Pet]!=-1){
            return false;
        }
    }
    // 3번 조건  Dane 는 tea를 마신다.
    // 확인완료
    for(int i=0;i<Properties;i++){
        if(ans[i][Nationality]==m_nationaltiy["Dane"]&&ans[i][Beverage]!=m_beverage["tea"]&&ans[i][Beverage]!=-1){
            return false;
        }
    }
    // 4번 조건 초록색집은 하얀색 집 왼쪽에 있다.
    // 즉 초록색 집 오른쪽에는 하얀색집이 올수잇어야함.
    // 확인 완료
    for(int i=0;i<Properties;i++){
      
        if(i==4){
            if(ans[i][Color]==m_house["green"]){
                return false;
            }
        }else{
            if(ans[i][Color]==m_house["green"]&&ans[i+1][Color]!=m_house["white"]&&ans[i+1][Color]!=-1){
                return false;
            }
        }

        return false;
    }
    // 5번 조건 초록색집의 주인은 커피를 마신다.
    // 확인 완료
    for(int i=0;i<Properties;i++){
        if(ans[i][Color]==m_house["green"]&&ans[i][Beverage]!=m_beverage["coffee"]&&ans[i][Beverage]!=-1){
            return false;
        }
    }
    // 6번 조건 pall mall 피는 애는 새를 기른다.
    // 확인 완료
    for(int i=0;i<Properties;i++){
        if(ans[i][Cigarets]==m_cigar["Pall Mall"]&&ans[i][Pet]!=m_pet["bird"]&&ans[i][Pet]!=-1){
            return false;
        }
    }

    // 7번 조건 노란색 집 사는 애는 던힐 핀다.
    for(int i=0;i<Properties;i++){
        if(ans[i][Color]==m_house["yellow"]&&ans[i][Cigarets]!=m_cigar["Dunhill"]&&ans[i][Cigarets]!=-1){
            return false;
        }
    }
    // 8번 조건 중앙집 바로 오른쪽에서 사는 애는 우유를 마신다.
    // 확인 완료
    if(ans[3][Beverage]!=m_beverage["milk"]&&ans[3][Beverage]!=-1){
        return false;
    }
    
    // 9번 조건 노르웨이 사람은 맨 왼쪽에 산다.
    // 확인 완료
    if(ans[0][Nationality]!=m_nationaltiy["Norwegian"]&&ans[0][Nationality]!=-1){
        return false;
    }
    // 10번 조건 
    // blend 피는 사람은 옆에 고양이 기르는 사람이 있따.
    // 확인 완료
    for(int i=0;i<Properties;i++){
        
        if(i==0){
            if(ans[i][Cigarets]==m_cigar["Blend"]&&ans[i+1][Pet]!=m_pet["cat"]&&ans[i+1][Pet]!=-1){
                return false;
            }
        }else if(i==4){
            if(ans[i][Cigarets]==m_cigar["Blend"]&&ans[i-1][Pet]!=m_pet["cat"]&&ans[i-1][Pet]!=-1){
                return false;
            }
        }else{
            // 2개다 true면 false 반환
            // 두개중 하나라도 true 면 false 임...
            // i번째 사람이 blend 피고 + 왼쪽사람이 cat을 안기른다.
            if((ans[i][Cigarets]==m_cigar["Blend"]&&ans[i-1][Pet]!=m_pet["cat"]&&ans[i-1][Pet]!=-1)||
            // i 번째 사람이 blend 피고 + 오른쪽 사람이 cat을 안기른다.
            (ans[i][Cigarets]==m_cigar["Blend"]&&ans[i+1][Pet]!=m_pet["cat"]&&ans[i+1][Pet]!=-1)){
                return false;
            }
        }
    }
    // 11번 조건
    // 말 기르는 사람은 dunhill 피는 사람 옆에 산다.
    // 확인 완료
    for(int i=0;i<Properties;i++){
       
        if(i==0){
            if(ans[i][Pet]==m_pet["horse"]&&ans[i+1][Cigarets]!=m_cigar["Dunhill"]&&ans[i+1][Cigarets]!=-1){
                return false;
            }
        }else if(i==4){
            if(ans[i][Pet]==m_pet["horse"]&&ans[i-1][Cigarets]!=m_cigar["Dunhill"]&&ans[i-1][Cigarets]!=-1){
                return false;
            }
        }else{
            if((ans[i][Pet]==m_pet["horse"]&&ans[i-1][Pet]!=m_cigar["Dunhill"]&&ans[i-1][Cigarets]!=-1)||
            
            (ans[i][Cigarets]==m_pet["horse"]&&ans[i+1][Pet]!=m_cigar["Dunhill"]&&ans[i+1][Cigarets]!=-1)){
                return false;
            }
        }

    }
    // 12번 조건
    // blue master 피는 사람은 beer 마심
    //확인 완료
    for(int i=0;i<Properties;i++){
        if(ans[i][Cigarets]==m_cigar["Blue Master"]&&ans[i][Beverage]!=m_beverage["beer"]&&ans[i][Beverage]!=-1){
            return false;
        }
    }
    // 13번 조건
    // german 사람은 prince 를 핀다.
    // 확인 완료
    for(int i=0;i<Properties;i++){
        if(ans[i][Nationality]==m_nationaltiy["German"]&&ans[i][Cigarets]!=m_cigar["Prince"]&&ans[i][Cigarets]!=-1){
            return false;
        }
    }
    // 14번 조건
    // norwegian 은 blue옆에 산다.
    for(int i=0;i<Properties;i++){
        

        if(i==0){
            if(ans[i][Nationality]==m_nationaltiy["Norwegian"]&&ans[i+1][Color]!=m_house["blue"]&&ans[i+1][Color]!=-1){
                return false;
            }
        }else if(i==4){
            if(ans[i][Nationality]==m_nationaltiy["Norwegian"]&&ans[i-1][Color]!=m_house["blue"]&&ans[i-1][Color]!=-1){
                return false;
            }
        }else{
            if((ans[i][Nationality]==m_nationaltiy["Norwegian"]&&ans[i-1][Color]!=m_house["blue"]&&ans[i-1][Color]!=-1)||
            
            (ans[i][Nationality]==m_nationaltiy["Norwegian"]&&ans[i+1][Color]!=m_house["blue"]&&ans[i+1][Color]!=-1)){
                return false;
            }
        }
    }
    // 15번 조건
    // Blend 피는 사람은 물마시는 사람 옆에 있다.
    for(int i=0;i<Properties;i++){
       

        if(i==0){
            if(ans[i][Cigarets]==m_cigar["Blend"]&&ans[i+1][Beverage]!=m_beverage["water"]&&ans[i+1][Beverage]!=-1){
                return false;
            }
        }else if(i==4){
            if(ans[i][Cigarets]==m_cigar["Blend"]&&ans[i-1][Beverage]!=m_beverage["water"]&&ans[i-1][Beverage]!=-1){
                return false;
            }
        }else{
            if((ans[i][Cigarets]==m_cigar["Blend"]&&ans[i-1][Beverage]!=m_beverage["water"]&&ans[i-1][Beverage]!=-1)||
            
            (ans[i][Cigarets]==m_cigar["Blend"]&&ans[i+1][Beverage]!=m_beverage["water"]&&ans[i+1][Beverage]!=-1)){
                return false;
            }
        }
    }
    return true;
}  


bool solution(int people,int property){
    int oldValue=ans[people][property];
   
    for(int i=0;i<arrSize;i++){
        ans[people][property]=i;
        
        if(promising()==true){
            int newPeople=(people+1)%Peoples;
            int temp=0;
            if(newPeople==0){
                temp=1;
            }
            int newProperty=property+temp;
            if(newProperty>=Properties||solution(newPeople,newProperty)){
                
                return true;
            }
        }
    }
    ans[people][property]=oldValue;
    return false;
}


int main(){

    init();
    //cout<<m_cigar["Blend"]<<endl;
    //cout<<m_cigar["Blue Master"]<<endl;
    // if(solution(0,0)){
    //     for(int i=0;i<arrSize;i++){
    //         cout<<ans[i][0]<<" ";
    //     }
    //     cout<<"ahah"<<endl;
    // }
    cout<<solution(0,0)<<endl;
}
