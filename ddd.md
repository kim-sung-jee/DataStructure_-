개관
===========

* 알고리즘을 설계하는 작업은 한순간의 영감보다는 여러 전략적인 선택에 따라 좌우된다.


무식하게 풀기
==========

무식하게 푼다(__brute-force__) --> 컴퓨터의 빠른 계산 능력을 활용하여
가능한 경우의 수를 일일이 나열하면서 답을 찾는 방법을 의미한다.

이렇게 가능한 방법을 전부 만들어 보는 알고리즘들을 가리켜 흔히 __완전탐색__ 이라고 부른다.


재귀 호출과 완전탐색
---------

* 1부터 n까지의 합을 반환하는 함수
```cpp
int recursiveSum(int n){
  if(n==0){return 1;}
  return n+recursiveSum(n-1);
  }
 ```
 ***
n개의 숫자의 합을 구하는 작업을 n개의 조각으로 쪼개, 더할 각 숫자가 하나의 조각이 되도록합니다.
재귀 호출을 이용하기 위해서는 이 조각 중 __하나를 떼내어 자신이 해결하고__, __나머지 조각들은 자기 자신을 호출해 해결해야 합니다__

한가지 유의할 점  n개의 조각 중 n이 아니라 1을 빼냈을 경우 이런 방법으로 문제를 해결할 수 없다.

(기저사례란?
'더이상 쪼개지지 않는' 최소한의 작업에 도달했을 때 답을 곧장 반환하는 조건문을 포함해야 한다.)
***

* 예제:조합구현하기
```cpp
#include<iostream>
#include<vector>

using namespace std;
vector<int> v;
void pick(int n,int toPick){
    if(toPick==0){
        for(int i=0;i<v.size();i++){
            cout<<v[i];
        }
        cout<<endl;
        return;}
    int smallest;

    if(v.empty()){
        smallest=0;
    }else{
        smallest=v.back()+1;
    }


    for(int next=smallest;next<n;next++){
        v.push_back(next);
        pick(n,toPick-1);
        v.pop_back();
    }
}
int main(){
    
    pick(5,3);
}
```

