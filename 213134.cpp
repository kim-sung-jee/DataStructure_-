#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* nextNode;
}typedef node;

class List{
public:
    int count;
    Node* Head=nullptr;
    List(){
        count=0;
        
    }
    ~List(){
        delete Head;
    }
    //인덱스는 0부터 시작하는 거로 설정
    int get(int index){
        Node*Node;
        Node=this->Head;
        for(int i=0;i<index;i++){
            Node=Node->nextNode;
        }
        cout<<Node->data;
    }
    void add_head(int data){
        node*new_node=new node;
        if(Head==nullptr){
            Head=new_node;
            new_node->data=data;
            new_node->nextNode=nullptr;
        }
        new_node->nextNode=Head;
        Head=new_node;
        new_node->data=data;
        count+=1;
    }
    //인덱스는 0부터 시작하는 걸로 설정
    void add(int index,int data){
        node*new_node=new node;
        node*Node;
        Node=Head;
        if(Head==nullptr){
            Head=new_node;
            new_node->data=data;
            count+=1;
            return;
        }
        if(index==0){
            this->add_head(data);
            count+=1;
        }
        if(count<index+1){
            for(int i=0;i<index-1;i++){
                Node=Node->nextNode;
            }
            Node->nextNode=new_node;
            new_node->data=data;
            count+=1;
            return;
        }
        for(int i=0;i<index-2;i++){
            Node=Node->nextNode;
        }
        
        new_node->nextNode=Node->nextNode;
        Node->nextNode=new_node;
        new_node->data=data;
       
        count+=1;
    }
    int size(){
        return count;
    }
    void remove(int index){
        if(Head==nullptr){
            cout<<"값이 없습니다"<<endl;
            return;
        }
        if(count<index+1){
            cout<<index<<"에는 값이 들어있지 않습니다"<<endl;
            return;
        }
        if(index==0){
            Node*delete_node=Head;
            Head=Head->nextNode;
            delete delete_node;
            return;
        }
        node* node;
        Node* tmp;
        node=Head;

        for(int i=0;i<index-1;i++){
            node=node->nextNode;
        }
        tmp=node->nextNode;
        node->nextNode=node->nextNode->nextNode;



        count-=1;
        delete tmp;
        return;
    }
    node* locate(int index){

    }
    void set(int index,int data){
        if(Head==nullptr){
            cout<<"값이 없습니다"<<endl;
            return;
        }
        if(count<index+1){
            cout<<index<<"에는 값이 들어있지 않습니다"<<endl;
            return;
        }
        node* node;
        node=Head;
        for(int i=0;i<index;i++){
            node=node->nextNode;
        }
        node->data=data;
        return;
    }
    //인덱스 0부터 시작
    void Clear(){
        Node*node;
        node=Head;
        int t=this->count;
        if(isEmpty()){
            //cout<<"빈 리스트 입니다";
            return;
        }
        for(int i=0;i<t;i++){
            this->printAll();
            cout<<endl;
            this->remove(0);
        }
        Head=nullptr;
        count=0;
        return;
    }
    void Copy(const List&l){
        Node*node=l.Head;
        this->Clear();
        for(int i=0;i<l.count;i++){
            this->add(i,node->data);
            node=node->nextNode;
            
        }
        
    }
    bool isEmpty(){
        if(Head==nullptr){
            return true;
        }else{
            return false;
        }
    }
    void printAll(){
        Node*node;
        node=Head;
        if(node==nullptr){
            cout<<"출력할 것이 없습니다";
        }
        for(int i=0;i<count;i++){
            cout<<node->data<<" ";
            node=node->nextNode;
        }
    }

}typedef list;


int main(){
    List l1,l2;
    l1.add_head(1);
    l1.add_head(2);
    l1.add_head(3);
    l1.add_head(4);
    l1.add_head(5);
    l1.add_head(6);
    l1.add_head(7);
    l1.add_head(8);
    //l1.get(5);
   
    l2.Copy(l1);
    l2.printAll();


}