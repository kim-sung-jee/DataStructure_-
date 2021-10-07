#include<iostream>
#include<cassert>
using namespace std;

class Node{
public:
    int data=0;
    Node*next,*pre=nullptr;
    Node(){
        next=pre=nullptr;
        data=0;
    }
};

class Bag{
    public:
        Node*head,*tail;
        Node*cursor=nullptr;
        size_t i=1;
        Bag(){
            head=new Node();
            tail=new Node();
            head->pre=head;
            head->next=tail;
            tail->pre=head;
            tail->next=tail;
        }
        ~Bag(){
            delete head,tail,cursor;
        }
        void list_head_insert(int i){
            Node * node=new Node();
            node->data=i;
            node->pre=head->next->pre;
            node->next=head->next;
            head->next->pre=node;
            head->next=node;
            return;
        }
        void print()const{
            Node * node=head->next;
            if(node==tail){
                cout<<"길이 0이에요"<<endl;;
                return ;
            }
            while(node!=tail){
                cout<<node->data<<" ";
                node=node->next;
            }
            cout<<endl;
            return;
        }
        void search(const int&target){
            Node* c;
            c=this->head->next;
            int i=1;
            if(c==tail){
                cout<<"노드의 길이는 0이에요";
            }
            while(c!=this->tail){
                if(target==c->data){
                    cout<<i<<"번째 노드에"<<target<<"숫자가 있습니다"<<endl;
                }
                i=i+1;
                c=c->next;
            }
            return ;
        }
        int lenght()const{
            int i=0;
            Node* node=this->head->next;
            if(node==this->tail){
                //cout<<"길이는 0이에요";
                return 0;
            }else{
                while(node!=this->tail){
                    node=node->next;
                    i=i+1;
                }
                return i;
            }
        }
        Node* list_locate(int position){
            Node* node=this->head->next;
            if(node==this->tail){
                cout<<"노드가 존재하지 않습니다";
                return nullptr;
            }
            assert(0<position);
            for(int i=1;(node!=tail&&i<position);i++){
                node=node->next;
            }
            return node;
        }

        void remove_head(){
            Node *delete_node;
            delete_node=head->next;
            head->next=head->next->next;
            head->next->next->pre=head;
            delete delete_node;
            return;
        }
        void remove(int position){
            Node*remove_node;
            remove_node=list_locate(position);
            remove_node->pre->next=remove_node->next;
            remove_node->next->pre=remove_node->pre;
            delete remove_node;

        }
        void remove_tail(){
            Node *delete_node;
            delete_node=tail->pre;
            tail->pre=delete_node->pre;
            delete_node->pre->next=delete_node->next;
            delete delete_node;
            return ;
        }
        //position의 다음 노드에 생성한다.
        void insert(int i,int position){
            Node * node1=new Node();
            Node * node2=this->list_locate(position);
            assert(0<=position);
            assert(position<=1+this->lenght());
        
           if(node2->next==tail){
                node1->data=i;
                node1->pre=node2;
                node1->next=node2->next;
                node2->next->pre=node1->next;
                node2->next=node1;
                return;
            }
            node1->data=i;
            node1->next=node2->next;
            node2->next->pre=node1;
            node2->next=node1;
            node1->pre=node2;
            return ;
        }
        int count(int i){
            int count=0;
            Node* node=head->next;

            while(node!=tail){
                if(i==node->data){
                    count=count+1;
                }
                node=node->next;
            }
            return count;
        }
        void clear(){
            int i=0;
            int lenght=this->lenght();
            if(this->head->next==this->tail){
                
                return;
            }
            while(i<lenght){
                this->remove_head();
                i=i+1;
            }
            return ;
        }

        void copy(Bag&b1){
            Node*node=this->head->next;
            int i=1;
            b1.clear();
            b1.list_head_insert(node->data);
            node=node->next;
            while(node!=tail){
                b1.insert(node->data,i);
               
                i=i+1;
                node=node->next;
            }
            return ;
        }
        void sort_list(){
            int N=this->lenght();
            int temp=0;
            for(int i=1;i<N;i++){
                for(int j=i+1;j<N+1;j++){
                    if((this->list_locate(i)->data)>this->list_locate(j)->data){
                        temp=this->list_locate(i)->data;
                        this->list_locate(i)->data=this->list_locate(j)->data;
                        this->list_locate(j)->data=temp;
                    }
                }
            }
        }
        Bag(Bag& source){

            head=new Node();
            tail=new Node();

            head->pre=nullptr;
            head->next=tail;
            tail->pre=head;
            tail->next=nullptr;
            source.copy(*this);
        }

        void operator=(Bag&source){
            this->clear();
            source.copy(*this);   
        }
        void operator+=(const Bag& append){
            Node *node=append.head->next;
            int i=this->lenght();
            for(int t=0;t<append.lenght();t++){
                this->insert(node->data,i);
                node=node->next;
                i++;
            }
        }
        bool operator!=(const Bag&b1){
            int lenght;
            Node*node,*node2;
            node=this->head->next;
            node2=b1.head->next;
            if(this->lenght()>=b1.lenght()){
                lenght=b1.lenght();
            }else{
                lenght=this->lenght();
            }
            for(int i=0;i<lenght;i++){
                if(node->data!=node2->data){
                    return true;
                }
                node=node->next;
                node2=node2->next;
            }
            return false;
        }

         bool operator==(const Bag&b1){
            int lenght;
            Node*node,*node2;
            node=this->head->next;
            node2=b1.head->next;
            if(this->lenght()>=b1.lenght()){
                lenght=b1.lenght();
            }else{
                lenght=this->lenght();
            }
            for(int i=0;i<lenght;i++){
                if(node->data!=node2->data){
                    return false;
                }
                node=node->next;
                node2=node2->next;
            }
            return true;
    }
};



int main(){
    Bag b1;
    Bag b2;
    b1.list_head_insert(5);
    cout<<"인서트 해드 결과:";
    b1.print();
    b1.insert(5,1);
    b1.insert(-5,2);
    b1.insert(77,3);
    b1.insert(92,4);
    b1.insert(1,5);
    b1.insert(2,6);
    b1.insert(12,7);
    cout<<" 일반 인서트 결과:";
    b1.print();
    b1.remove_head();
    cout<<"해드 지우기 결과:";
    b1.print();
    b1.remove_tail();
    cout<<"테일 지우기 결과:";
    b1.print();
    b1.search(5);
    b1.copy(b2);
    cout<<"리스트 카피 결과:";
    b2.print();
    b2.clear();
    cout<<"리스트 비우기 결과:";
    b2.print();
    cout<<"리스트 오름차순 정렬 결과:";
    b1.sort_list();

    b1.print();
    
    Bag b3(b1);
    cout<<"복사 생성자 결과:";
    b3.print();
    Bag b4;
    b4=b1;
    cout<<"대입 연산자 결과:";
    b4.print();
    b4+=b1;
    cout<<"+=연산자 결과:";
    b4.print();
    Bag b5;
    b5.list_head_insert(5);
    b5.list_head_insert(5);
    b5.list_head_insert(5);

    bool bool1=b1==b5;
    cout<<"==연산자 결과:"<<bool1<<endl;
    bool bool2=b1==b2;
    cout<<"==연산자 결과:"<<bool2<<endl;
    bool bool3=b1!=b5;
    cout<<"!=연산자 결과:"<<bool3<<endl;
    bool bool4=b1!=b2;
    cout<<"!=연산자 결과:"<<bool4<<endl;
}