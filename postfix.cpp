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
    Node* Head;
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
        return count+1;
    }
    void set(int index,int data){

    }
    //인덱스 0부터 시작
    void remove(int index){
        Node*node;
        Node*tmp;
        node=this->Head;
        for(int i=0;i<index-1;i++){
            node=node->nextNode;
        }
        tmp=node->nextNode;
        node->nextNode=node->nextNode->nextNode;
        delete tmp;
        count-=1;
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
    List l1;
    l1.add_head(1);
    l1.add_head(2);
    l1.add_head(3);
    l1.add_head(4);
    l1.add_head(5);
    l1.add_head(6);
    l1.add_head(7);
    l1.add_head(8);
    //l1.get(5);
    l1.remove(5);
    l1.printAll();


}