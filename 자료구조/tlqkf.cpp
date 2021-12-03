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
    void loose_remove(const item& target);
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
void Set<item>::print(Set<item> *a,int depth) {
    if (a!=NULL) {
        print(a->subset[0], depth - 1);
        cout << setw(4 * depth) << "" << a->data[0] << endl;
        print(a->subset[1], depth - 1);
        if (a->count == 2) {
            cout << setw(4 * depth) << "" << a->data[1] << endl;
            print(a->subset[2], depth - 1);
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
    a.insert(5);
    a.insert(1);
    a.insert(2);
    a.insert(7);
    a.insert(8);
    a.insert(5);
    a.insert(4);
    a.insert(3);
    a.insert(13);
    a.insert(15);
    a.insert(18);
    a.insert(19);
    a.insert(21);
    a.insert(23);
    a.insert(17);
    a.insert(14);
    a.insert(9);
    a.insert(10);
    a.insert(123);
    a.insert(125);
    a.insert(139);
    a.insert(149);
    a.insert(129);
    a.insert(131);

    a.print(&a,a.get_depth());
    
}
