#include<iostream>
#include<iomanip>
using namespace std;

template<class item>
class Set {
public:
    Set() {
        count = 0;
        children = 0;
        depth=0;
    }
    void upcount(){count+=1;}
    void dwcount(){count-=1;}
    void operator=(const Set& source);
    void clear();
    bool insert(const item& entry);
    bool remove(const item& target);
    bool contains(const item& target)const;
    bool is_empty()const { return count == 0; }
    void print(Set<item>* a,int depth);
    int get_depth(){return depth;}
private:
    int count;
    int depth;
    const static int MINIMUM = 1;
    const static int MAXIMUM = 2;
    item data[MAXIMUM + 1];
    int children;
    Set* subset[MAXIMUM + 2] = { NULL, };

    bool is_leaf()const { return children == 0; }
    bool loose_insert(const item& entry);
    bool loose_remove(const item& target);
    void remove_largest(item& removed);
    void fix_excess(item x);
    void fix_shortage(int x);
};

template<class item>
bool Set<item>::remove(const item&target){
    if(!(loose_remove(target))){
        return false;
    }
    if(count==0&&children==1){

    }
}
template<class item>
void Set<item>::remove_largest(item& removed){
    if(children==0){
        removed=data[count-1];
        count-=1;
    }else if(children!=0){
        subset[children-1]->remove_largest(removed);
        if(subset[children-1]->count<MINIMUM){
            fix_shortage(children-1);
        }
    }
}
template<class item>
bool Set<item>::loose_remove(const item&target){
    int t;
    for(t=0;(t<count&&data[t]<target);t++);
    
    //리프 도달 타겟 못찾음
    if(is_leaf()&&data[t]!=target){
        
        return false;
    }
    // 리프에 도달 타겟 찾음
    if(data[t]==target&&is_leaf()){
        
        if(t==1){
            count-=1;
        }else if(t==0){
            data[t]=data[t+1];
            count-=1;
        }
        
        return true;
    }
    // 리프까지 가기, 타겟 못찾음
    if(data[t]!=target&&!is_leaf()){
        
        subset[t]->loose_remove(target);
        if(subset[t]->count<MINIMUM){
            fix_shortage(t); //t=1; 이다
        }
        return true;
    }
    // 안쪽 노드에서 찾았을 경우
    if(data[t]==target&&children!=0){
        subset[t]->remove_largest(data[t]);
        
        if(subset[t]->count<MINIMUM){
            fix_shortage(t);//t=0;
        }
        return true;
    }
    
}

template<class item>
void Set<item>::fix_shortage(int x){
    if(subset[x]){
        
    }else if(subset[x+1]->count>=MINIMUM){
        //위에꺼 빌려온다.
        subset[x]->upcount();
        subset[x]->data[subset[x]->count-1]=data[x];
        dwcount();
        //오른쪽 아래 꺼 하나 가져옴
        data[x]=subset[x+1]->data[0];
        subset[x+1]->dwcount();
        upcount();
        // subset[x+1]이 리프노드가 아닐 경우
        if(!(subset[x+1]->is_leaf())){

        }
    }else if(subset[x]->count==MINIMUM){
        
    }
}


template<class item>
void Set<item>::print(Set<item> *a,int depth) {
    if (a!=NULL) {
        if(a->count!=0){
            print(a->subset[0], depth - 1);
            cout << setw(4 * depth) << "" << a->data[0] << endl;
            print(a->subset[1], depth - 1);
            if (a->count == 2) {
                cout << setw(4 * depth) << "" << a->data[1] << endl;
                print(a->subset[2], depth - 1);
            }
        }else{
            cout<<"null0"<<endl;
        }
    }
}


template<class item>
bool Set<item>::loose_insert(const item& entry) {

    int t;
    for (t = 0; (t < count && data[t] < entry); t++);

    if (t < count && data[t] == entry) {
        return false;
    }
    if (is_leaf()) {
        for (int x = count; t < x; x--) {
            data[x] = data[x-1];
        }
        count++;
        data[t] = entry;
        return true;
    }
    else {
        bool torf = subset[t]->loose_insert(entry);
        if (subset[t]->count > MAXIMUM) {
            fix_excess(t);
        }
        return torf;
    }
}

template<class item>
bool Set<item>::insert(const item& entry) {
    if (loose_insert(entry)) {
        if (count > MAXIMUM) {
            
            depth+=1; 
            Set* child = new Set;
            for (int x = 0; x < count; x++) {
                child->data[x] = data[x];
            }
            for (int y = 0; y < children; y++) {
                child->subset[y] = subset[y];
            }
            child->children = children;
            child->count = count;

            count = 0;
            children = 1;

            subset[0] = child;
            fix_excess(0);
        }
        return true;
    }
    return false;
}

template<class item>
void Set<item>::fix_excess(item x) {
    int t;
    
    for(t=count;x<t;t--){
        data[t]=data[t-1];
    }
    data[x] = subset[x]->data[1];
    count++;

    Set* left, * right;
    left = new Set;
    right = new Set;
    left->count = MINIMUM;
    right->count = MINIMUM;

    for(t=0;t<MINIMUM;t++){
        left->data[t] = subset[x]->data[t];
        right->data[t] = subset[x]->data[t+MINIMUM+1];
    }
    
    if (!(subset[x]->is_leaf())) {
        
        for (t = 0; t < 2; t++) {
            left->subset[t] = subset[x]->subset[t];
            right->subset[t] = subset[x]->subset[t + 2];
        }
        left->children=MINIMUM + 1;
        right->children=MINIMUM + 1;
    }
    //subset[children]=new Set;
    for(t=children;x<t;t--){
        subset[t]=subset[t-1];
    }
    
    children++;
    subset[x] = left;
    subset[x + 1] = right;

}


template<class item>
bool Set<item>::contains(const item& target)const {
    int t;
    for (t = 0; (t < count) && (data[t] < target); t++);
    if ((t < count) && data[t] == target) {
        return true;
    }
    if (is_leaf()) {
        return false;
    }
    return subset[t]->contains(target);
}

int main() {
    Set<int> a;
    a.insert(13);
    a.insert(1);
    a.insert(5);
    a.insert(65);
    a.insert(95);
    a.insert(57);
    a.insert(7);
    
    a.remove(65);
    //a.remove(1);
    //a.remove(2);
    //a.remove(1);
    
    a.print(&a,a.get_depth());
    
}
