#include<iostream>
#include<cassert>
#include<algorithm>
using namespace std;


class Node{
public:
    int data;
    Node*next,*prev;
    Node(){
        next=prev=nullptr;
        data=0;
    }
    Node(int i,Node* ptr){
        data=i;
        prev=ptr;
        next=ptr->next;
        next->prev=prev->next=this;
    }
   
}typedef node;


class bag{

    public:
        node*head,*tail;
        node*cursor=nullptr;
        size_t i=1;
        bag(){
            head=new Node();
            tail=new Node();
            head->prev=nullptr;
            head->next=tail;
            tail->prev=head;
            tail->next=nullptr;
        }
        ~bag(){
             delete head,tail,cursor;
        }
        void list_head_insert(int i,node*previous_ptr){
            node* new_node=new node();
            new_node->data=i;
            new_node->prev=head->next->prev;
            new_node->next=head->next;
            head->next->prev=new_node;
            head->next=new_node;
            return ;
        }
        void insertInBag_next_node(int i,node*preivous_ptr){
            node* new_node=new node();
            if(preivous_ptr->next==tail){
                new_node->data=i;
                new_node->prev=preivous_ptr;
                new_node->next=preivous_ptr->next;
                preivous_ptr->next->prev=new_node->next;
                preivous_ptr->next=new_node;
                return;
            }
            new_node->data=i;
            new_node->next=preivous_ptr->next;
            preivous_ptr->next->prev=new_node;
            preivous_ptr->next=new_node;
            new_node->prev=preivous_ptr;
            return ;
        }
        node* list_search(node* head_ptr, const int & target){
            node* cursor;
            cursor=head_ptr;
            while(cursor->next->next!=nullptr){
                if(target==cursor->data)
                    
                    return cursor;
                cursor=cursor->next;
            }
            return nullptr;
        }
        
        int list_lenght()const {
            int i=0;
            node* p1=this->head;

            while(p1->next->next!=nullptr){
                p1=p1->next;
                i++;
            }
            
            return i;
        }
        void printAll()const {
            node* p1=head;
            while(p1->next->next!=nullptr){
                cout<<p1->next->data<<" ";
                p1=p1->next;
            }
        }
        node*list_locate(node *head_ptr,size_t position){
            node*cursor=head_ptr;
            assert(0<position);
            for(i=0;(cursor!=nullptr&&i<position);i++)
            {
                cursor=cursor->next;
            }   
            return cursor;
        }
        void list_head_remove(node*head_ptr){
            node*delete_ptr;
            delete_ptr=head_ptr->next;
            head_ptr->next=head_ptr->next->next;
            head_ptr->next->next->prev=head_ptr;
            delete delete_ptr;
        }
        void list_remove(node*ptr){
            node* remove_ptr;
            remove_ptr=ptr;
            remove_ptr->prev->next=remove_ptr->next;
            remove_ptr->next->prev=remove_ptr->prev;
            delete remove_ptr;
        }
        void list_clear(node *head_ptr){
            int i=0;
            int t=this->list_lenght();
            if(head->next==tail){
                return;
            }
            while(i+1<t){
                this->list_head_remove(head_ptr);
                i++;
            }
            this->list_remove(head->next);
            
        }
        void list_copy(const node*source_ptr,node*&head_ptr){
            if(source_ptr->next->next==nullptr){
                return;
            }
            node*ptr=head_ptr;
            list_head_insert(source_ptr->next->data,ptr);
            source_ptr=source_ptr->next;
            while(source_ptr->next->next!=nullptr){
                insertInBag_next_node(source_ptr->next->data,ptr->next);
                ptr=ptr->next;
                source_ptr=source_ptr->next;
            }
        }
        void sort_list(node* head_ptr){
            int a=this->list_lenght();
            int *b=new int[a];
            for(int i=0;i<a;i++){
                b[i]=head_ptr->next->data;
                head_ptr=head_ptr->next;
            }
            sort(b,b+a);
            bag*bag_c=new bag();
            node*ptr=bag_c->head;
            int i=0;
            bag_c->list_head_insert(b[0],ptr);
            for(int i=1;i<a;i++){
                ptr=ptr->next;
                bag_c->insertInBag_next_node(b[i],ptr);
            }
            this->list_clear(this->head);
            this->list_copy(bag_c->head,this->head);
            
        }

        bag(const bag& source){
            head=new Node();
            tail=new Node();
            head->prev=nullptr;
            head->next=tail;
            tail->prev=head;
            tail->next=nullptr;
            this->list_copy(source.head,this->head);
        }
        void operator=(const bag&source){
            list_clear(head);
            list_copy(source.head,this->head);   
        }
        void operator+=(const bag& addend){
            node*ptr=this->head;
            node*ptr1=this->head->next->next;
            this->list_head_insert(addend.head->next->data,ptr);
            for(int i=0;i<addend.list_lenght()-1;i++){
                ptr=ptr->next;
                this->insertInBag_next_node(ptr1->data,ptr);
                ptr1=ptr1->next;
            }
        }
        bool operator!=(const bag&this2){
            int lenght;
            node*ptr,*ptr2;
            ptr=this->head->next;
            ptr2=this2.head->next;
            if(this->list_lenght()>=this2.list_lenght()){
                lenght=this2.list_lenght();
            }else{
                lenght=this->list_lenght();
            }
            for(int i=0;i<lenght;i++){
                if(ptr->data!=ptr2->data){
                    return true;
                }
                ptr=ptr->next;
                ptr2=ptr2->next;
            }
            return false;
        }
         bool operator==(const bag&this2){
            int lenght;
            node*ptr,*ptr2;
            ptr=this->head->next;
            ptr2=this2.head->next;
            if(this->list_lenght()>=this2.list_lenght()){
                lenght=this2.list_lenght();
            }else{
                lenght=this->list_lenght();
            }
            for(int i=0;i<lenght;i++){
                if(ptr->data!=ptr2->data){
                    return false;
                }
                ptr=ptr->next;
                ptr2=ptr2->next;
            }
            return true;
        }
};


int main(){
    bag bag1;
    bag bag2;
    bag bag3;
    bag1.insertInBag_next_node(1,bag1.head);
    bag1.insertInBag_next_node(5,bag1.list_locate(bag1.head,1));
    bag1.insertInBag_next_node(2,bag1.list_locate(bag1.head,2));
    bag1.insertInBag_next_node(4,bag1.list_locate(bag1.head,3));
    bag1.insertInBag_next_node(7,bag1.list_locate(bag1.head,4));
    bag1.insertInBag_next_node(1,bag1.list_locate(bag1.head,5));
    bag1.insertInBag_next_node(9,bag1.list_locate(bag1.head,6));
    bag1.insertInBag_next_node(8,bag1.list_locate(bag1.head,7));
    //bag1.printAll();
    bag bag4(bag1);
    //cout<<(bag1!=bag4);
    bool torf=bag1==bag4;
    cout<< torf;
    // bag4+=bag1;
    // bag4.printAll();
    // bag bag4(bag1);
    // bag4.printAll();
    // bag2=bag1;
    // bag2.printAll();
    //bag2.list_copy(bag1.head,bag2.head);
    // bag2.list_copy(bag1.head,bag2.head);
    // bag2.printAll();
    // bag1.sort_list(bag1.head);
    // bag1.printAll();
    //bag bag4=bag1;

    // bag1.list_head_remove(bag1.head);
    // bag1.printAll();
    // cout<<bag1.list_lenght();
    // bag1.list_clear(bag1.head);
    // cout<<bag1.list_lenght();
    // bag1.insertInBag_next_node(1,bag1.head);
    // cout<<endl;
    // bag1.printAll();
    // cout<<bag1.list_lenght();
    //bag1.printAll();
    // a=bag1.list_search(bag1.head,2);
    // bag1.list_remove(a);
    // a=bag1.list_locate(bag1.head,5);
    // cout<<a->data<<endl;
    // bag1.list_remove(bag1.list_locate(bag1.head,4));
    // bag1.printAll();
    // bag1.printAll();
    // bag1.list_head_insert(10,bag1.head);
    // cout<<endl;
    // bag1.printAll();
    return 0;
}
