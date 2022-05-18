#include<iostream>
#include<map>
using namespace std;


string house[5]={"blue","green","red","white","yellow"};
string nationality[5]={"Brit","Dane","German","Norwegian","Swede"};
string beverage[5]={"beer","coffee","milk","tea","water"};
string cigar[5]={"Blue_Master","Dunhill","Pall_Mall","Prince","Blend"};
string pet[5]={"cat","bird","dog","fish","horse"};
// enum {blue,green,red,white,yellow}
// enum {Brit,Dane,German,Norwegian,Swede}
map<string,int> m_house;
map<string,int> m_nationality;
map<string,int> m_beverage;
map<string,int> m_cigar;
map<string,int> m_pet;
// 5개가 전부다 사람마다 달라야함
// 사람 번호를 기준으로 나눠주기.
const int Peoples=5;
const int Properties=5;
const int arrSize=5;
enum {Color,Beverage,Pet,Cigarets,Nationality};

// y번 사람의 x번 째 속성
int ans[Peoples][Properties];




void init(){
    
    for(int i=0;i<arrSize;i++){
        m_house.insert({house[i],i});
        m_nationality.insert({nationality[i],i});
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
                    
                    return false;
                }
            }
        }
    }
    
    //1번 조건
    //brit 는 red house에 산다.
    // 확인 완료...
    for(int i=0;i<Properties;i++){
        if(ans[i][Nationality]==m_nationality["Brit"]&&ans[i][Color]!=m_house["red"]&&ans[i][Color]!=-1){
            return false;
        }
    }
    // 2번 조건
    // swede는 pet을 dog로 가진다.
    // 확인 완료...
    for(int i=0;i<Properties;i++){
        // i번째 사람이 스웨덴이고 + i번째 사람의 펫이 dog 가 아니고 + i 번째 사람의 pet이 할당이 된 상태라면
        // 즉 초기화만 일어난 상태가 아니라면
        if(ans[i][Nationality]==m_nationality["Swede"]&&ans[i][Pet]!=m_pet["dog"]&&ans[i][Pet]!=-1){
            return false;
        }
    }
    // 3번 조건  Dane 는 tea를 마신다.
    // 확인완료
    for(int i=0;i<Properties;i++){
        if(ans[i][Nationality]==m_nationality["Dane"]&&ans[i][Beverage]!=m_beverage["tea"]&&ans[i][Beverage]!=-1){
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
        if(ans[i][Cigarets]==m_cigar["Pall_Mall"]&&ans[i][Pet]!=m_pet["bird"]&&ans[i][Pet]!=-1){
            return false;
        }
    }

    // 7번 조건 노란색 집 사는 애는 던힐 핀다.
    for(int i=0;i<Properties;i++){
        if(ans[i][Color]==m_house["yellow"]&&ans[i][Cigarets]!=m_cigar["Dunhill"]&&ans[i][Cigarets]!=-1){
            return false;
        }
    }
    // 8번 조건 중앙집  사는 애는 우유를 마신다.
    // 확인 완료
    if(ans[2][Beverage]!=m_beverage["milk"]&&ans[2][Beverage]!=-1){
        return false;
    }
    
    // 9번 조건 노르웨이 사람은 맨 왼쪽에 산다.
    // 확인 완료
    if(ans[0][Nationality]!=m_nationality["Norwegian"]&&ans[0][Nationality]!=-1){
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
            if((ans[i][Cigarets]==m_cigar["Blend"]&&ans[i-1][Pet]!=m_pet["cat"]&&ans[i-1][Pet]!=-1)&&
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
            if((ans[i][Pet]==m_pet["horse"]&&ans[i-1][Pet]!=m_cigar["Dunhill"]&&ans[i-1][Cigarets]!=-1)&&
            
            (ans[i][Cigarets]==m_pet["horse"]&&ans[i+1][Pet]!=m_cigar["Dunhill"]&&ans[i+1][Cigarets]!=-1)){
                return false;
            }
        }
    }

    
    // 12번 조건
    // blue master 피는 사람은 beer 마심
    //확인 완료
    for(int i=0;i<Properties;i++){
        if(ans[i][Cigarets]==m_cigar["Blue_Master"]&&ans[i][Beverage]!=m_beverage["beer"]&&ans[i][Beverage]!=-1){
            return false;
        }
    }
    // 13번 조건
    // german 사람은 prince 를 핀다.
    // 확인 완료
    for(int i=0;i<Properties;i++){
        if(ans[i][Nationality]==m_nationality["German"]&&ans[i][Cigarets]!=m_cigar["Prince"]&&ans[i][Cigarets]!=-1){
            return false;
        }
    }
    // 14번 조건
    // norwegian 은 blue옆에 산다.
    for(int i=0;i<Properties;i++){
    
        if(i==0){
            if(ans[i][Nationality]==m_nationality["Norwegian"]&&ans[i+1][Color]!=m_house["blue"]&&ans[i+1][Color]!=-1){
                return false;
            }
        }else if(i==4){
            if(ans[i][Nationality]==m_nationality["Norwegian"]&&ans[i-1][Color]!=m_house["blue"]&&ans[i-1][Color]!=-1){
                return false;
            }
        }else{
            if((ans[i][Nationality]==m_nationality["Norwegian"]&&ans[i-1][Color]!=m_house["blue"]&&ans[i-1][Color]!=-1)&&
            
            (ans[i][Nationality]==m_nationality["Norwegian"]&&ans[i+1][Color]!=m_house["blue"]&&ans[i+1][Color]!=-1)){
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
            if((ans[i][Cigarets]==m_cigar["Blend"]&&ans[i-1][Beverage]!=m_beverage["water"]&&ans[i-1][Beverage]!=-1)&&
            
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
    
    cout<<solution(0,0)<<endl;

    for(int i=0;i<5;i++){
        for(int t=0;t<5;t++){
            cout<<ans[i][t]<<" ";
        }
        cout<<endl;
    }

}

//`
#include <iostream>

enum { _ = -1 };
enum { blue, green, red, white, yellow };
enum { beer, coffee, milk, tea, water };
enum { cat, bird, dog, fish, horse };
enum { Blue_Master, Dunhill, Pall_Mall, Prince, Blend };
enum { Brit, Dane, German, Norwegian, Swede };



enum { Color, Beverage, Pet, Cigarets, Nationality };
const auto PropertiesCount = 5;

// There are five houses.
const auto HousesCount = 5;


int s[HousesCount][PropertiesCount];

bool nextTo(int house, int property, int value)
{
  return (house > 0 && (s[house - 1][property] == _ || s[house - 1][property] == value)) ||
    (house < HousesCount - 1 && (s[house + 1][property] == _ || s[house + 1][property] == value));
}

bool check()
{
  // In the interest of clarity, it must be added that each of
  // the five houses is painted a different color,
  // and their inhabitants are of different national extractions, own
  // different pets, drink different beverages and smoke different brands of American
  // cigarets [sic]. One other thing: in statement 6, right means your right.
  for (auto i = 0; i < HousesCount; ++i)
  {
    for (auto j = 0; j < PropertiesCount; ++j)
    {
      for (auto k = i + 1; k < HousesCount; ++k)
        if (s[i][j] != _ && s[k][j] != _ && s[i][j] == s[k][j])
          return false;
    }
  }

  // The Englishman lives in the red house. 1번
  for (auto i = 0; i < HousesCount; ++i)
    if (s[i][Nationality] == Brit && s[i][Color] != red && s[i][Color] != _)
      return false;
  // The Spaniard owns the dog. 2번
  for (auto i = 0; i < HousesCount; ++i)
    if (s[i][Nationality] == Swede && s[i][Pet] != dog && s[i][Pet] != _)
      return false;
  //3번
  for (auto i = 0; i < HousesCount; ++i)
    if (s[i][Nationality] == Dane && s[i][Beverage] != tea && s[i][Beverage] != _)
      return false;
  // 하얀색 집 왼쪽에 초록색 집이 있다.
  // 초록색 집 오른쪽에 하얀색 집이  잇음 4번
  for (auto i = 0; i < HousesCount; ++i)
    if ((i == 4 && s[i][Color] == green) || (s[i][Color] == green && s[i + 1][Color] != white && s[i + 1][Color] != _))
      return false;


  // Coffee is drunk in the green house. 5번
  for (auto i = 0; i < HousesCount; ++i)
    if (s[i][Color] == green && s[i][Beverage] != coffee && s[i][Beverage] != _)
      return false;
  
  
  
  // The Old Gold smoker owns snails.6번
  for (auto i = 0; i < HousesCount; ++i)
    if (s[i][Cigarets] == Pall_Mall && s[i][Pet] != bird && s[i][Pet] != _)
      return false;
  // Kools are smoked in the yellow house. 7번
  for (auto i = 0; i < HousesCount; ++i)
    if (s[i][Cigarets] == Dunhill && s[i][Color] != yellow && s[i][Color] != _)
      return false;
  // Milk is drunk in the middle house. 8번
  if (s[2][Beverage] != milk && s[2][Beverage] != _)
    return false;
  // The Norwegian lives in the first house. 9번
  if (s[0][Nationality] != Norwegian && s[0][Nationality] != _)
    return false;
  // The man who smokes Chesterfields lives in the house next to the man with the fox.
  // 10번
  for (auto i = 0; i < HousesCount; ++i)
    if (s[i][Cigarets] == Blend && !nextTo(i, Pet, cat))
      return false;
  
  // Kools are smoked in the house next to the house where the horse is kept.
  // 11번
  for (auto i = 0; i < HousesCount; ++i)
    if (s[i][Cigarets] == Dunhill && !nextTo(i, Pet, horse))
      return false;
  // The Lucky Strike smoker drinks orange juice.
  //12 번
  for (auto i = 0; i < HousesCount; ++i)
    if (s[i][Cigarets] == Blue_Master && s[i][Beverage] != beer && s[i][Beverage] != _)
      return false;
  // The Japanese smokes Parliaments.
  //13번
  for (auto i = 0; i < HousesCount; ++i)
    if (s[i][Nationality] == German && s[i][Cigarets] != Prince && s[i][Cigarets] != _)
      return false;
  // The Norwegian lives next to the blue house.
  //14번
  for (auto i = 0; i < HousesCount; ++i)
    if (s[i][Nationality] == Norwegian && !nextTo(i, Color, blue))
      return false;

  //15번
  for(auto i=0;i<HousesCount;i++)
    if(s[i][Cigarets]==Blend&&!nextTo(i,Beverage,water))
      return false;
  


  return true;
}

bool findSolution(int house, int property)
{
  auto oldValue = s[house][property];
  std::cout<<house<<" "<<property<<" "<<oldValue<<std::endl;
  for (auto i = 0; i < 5; i++)
  {
    s[house][property] = i;
    if (check())
    { 
      
      auto newHouse = (house + 1) % HousesCount;
      //무조건 0을 반환한다..
      // newHouse 가 0 이라면 + 1 해줌
      // newHouse 가 0이 아니라면 +0 해줌
      auto newProperty = property + (newHouse == 0 ? 1 : 0);
      // int temp=0;
      // if(newHouse==0){
      //   temp=1;
      // }
      // int newProperty=property+temp;
      if (newProperty >= PropertiesCount || findSolution(newHouse, newProperty))
        return true;
    }
  }
  s[house][property] = oldValue;
  return false;
}

#define STR(x) case x: return #x

std::string toColor(int value)
{
  switch (value)
  {
    STR(red);
    STR(green);
    STR(white);
    STR(yellow);
    STR(blue);
  }
  return "?";
}

std::string toBeverage(int value)
{
  switch (value)
  {
    STR(coffee);
    STR(tea);
    STR(milk); 
    STR(water);
    STR(beer);
  }
  return "?";
}

std::string toPet(int value)
{
  switch (value)
  {
    STR(dog);
    STR(cat);
    STR(bird);
    STR(fish);
    STR(horse);
  }
  return "?";
}

std::string toCigarets(int value)
{
  switch (value)
  {
    STR(Blue_Master);
    STR(Dunhill);
    STR(Pall_Mall);
    STR(Prince);
    STR(Blend);
  }
  return "?";
}

std::string toNationality(int value)
{
  switch (value)
  {
    STR(Brit);
    STR(Dane);
    STR(German);
    STR(Norwegian);
    STR(Swede);
  }
  return "?";
}

// Now, who drinks water? Who owns the zebra?
int main()
{
  for (auto p = 0; p < PropertiesCount; ++p)
    for (auto h = 0; h < HousesCount; ++h)
      s[h][p] = _;
  if (findSolution(0, 0))
  {
    for (auto h = 0; h < HousesCount; ++h)
      std::cout << h + 1 << " " <<
        toColor(s[h][Color]) << " " <<
        toBeverage(s[h][Beverage]) << " " <<
        toPet(s[h][Pet]) << " " <<
        toCigarets(s[h][Cigarets]) << " " <<
        toNationality(s[h][Nationality]) << "\n";
  }
  else
    std::cout << "No solution\n";
}
