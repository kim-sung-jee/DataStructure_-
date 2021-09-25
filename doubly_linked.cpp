#include<iostream>
#include<cassert>
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
        // ~bag(){
        //     cout<<"소멸자 호출"<<endl;
        // }
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
            while(i+1<t){
                this->list_head_remove(head_ptr);
                i++;
            }
            this->list_remove(head->next);
            
        }
        //     node*delete_ptr;
        //     node*temp;
        //     delete_ptr=head_ptr;
        //     for(node* delete_ptr;delete_ptr!=nullptr;delete_ptr=delete_ptr->next){
        //         temp=head->next;
        //         delete delete_ptr;
        //         delete_ptr=temp;
        //     }
        //     delete temp;
        // }
};


int main(){
    bag bag1;
    node *a;
    bag1.insertInBag_next_node(1,bag1.head);
    bag1.insertInBag_next_node(2,bag1.list_locate(bag1.head,1));
    bag1.insertInBag_next_node(3,bag1.list_locate(bag1.head,2));
    bag1.insertInBag_next_node(4,bag1.list_locate(bag1.head,3));
    bag1.insertInBag_next_node(5,bag1.list_locate(bag1.head,4));
    bag1.insertInBag_next_node(6,bag1.list_locate(bag1.head,5));
    bag1.insertInBag_next_node(7,bag1.list_locate(bag1.head,6));
    bag1.insertInBag_next_node(8,bag1.list_locate(bag1.head,7));
    bag1.printAll();
    // bag1.list_head_remove(bag1.head);
    // bag1.printAll();
    // cout<<bag1.list_lenght();
    bag1.list_clear(bag1.head);
    cout<<bag1.list_lenght();
    bag1.insertInBag_next_node(1,bag1.head);
    cout<<endl;
    bag1.printAll();
    cout<<bag1.list_lenght();
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