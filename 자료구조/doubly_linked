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
        //헤드노드가 직전으로 즉 맨 앞 노드로 삽입
        void list_head_insert(int i){
            node* new_node=new node();
            new_node->data=i;
            new_node->prev=head->next->prev;
            new_node->next=head->next;
            head->next->prev=new_node;
            head->next=new_node;
            return ;
        }

        //head,tail 노드를 제외한 n번째 노드 다음인 n+1에 생성된다.
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
        //특정 데이터가 있는지 검사
        void list_search(node* head_ptr, const int & target){
            node* cursor;
            cursor=head_ptr;
            int i=0;
            while(cursor->next->next!=nullptr){
                if(target==cursor->data)
                    cout<<i<<"번째 노드에 "<<target<<"data가 있습니다"<<endl;
                cursor=cursor->next;
                i+=1;
            }
            
        }
        //노드의 길이를 잰다
        int list_lenght()const {
            int i=0;
            node* p1=this->head;

            while(p1->next->next!=nullptr){
                p1=p1->next;
                i++;
            }
            
            return i;
        }
        //전체 노드 출력
        void printAll()const {
            node* p1=head;
            if(head->next==tail){
                cout<<"길이는 0입니다";
            }
            while(p1->next->next!=nullptr){
                cout<<p1->next->data<<" ";
                p1=p1->next;
            }
        }

        // n번째 노드의 주솟값을 반환하는 함수이다.
        node*list_locate(node *head_ptr,size_t position){
            node*cursor=head_ptr;
            assert(0<position);
            for(i=0;(cursor!=nullptr&&i<position);i++)
            {
                cursor=cursor->next;
            }   
            return cursor;
        }
        //맨앞 노드를 삭제
        void list_head_remove(node*head_ptr){
            assert(head_ptr->next!=this->tail);
            node*delete_ptr;
            delete_ptr=head_ptr->next;
            head_ptr->next=head_ptr->next->next;
            head_ptr->next->next->prev=head_ptr;
            delete delete_ptr;
        }
        //list_locate으로 반환 받은 값을 이용하여 특정 인덱스의 노드 삭제
        void list_remove(node*ptr){
            node* remove_ptr;
            remove_ptr=ptr;
            remove_ptr->prev->next=remove_ptr->next;
            remove_ptr->next->prev=remove_ptr->prev;
            delete remove_ptr;
        }
        // head,tail을 제외한 노드들 삭제
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
        // 노드들 카피하는 함수
        void list_copy(const node*source_ptr,node*&head_ptr){
            if(source_ptr->next->next==nullptr){
                return;
            }
            node*ptr=head_ptr;
            list_head_insert(source_ptr->next->data);
            source_ptr=source_ptr->next;
            while(source_ptr->next->next!=nullptr){
                insertInBag_next_node(source_ptr->next->data,ptr->next);
                ptr=ptr->next;
                source_ptr=source_ptr->next;
            }
        }
        // 특정 데이터가 몇개의 노드에 들어있는지 세는 함수
        int count(int i){
            int t=0;
            node* p1=this->head;

            while(p1->next->next!=nullptr){
                if(i==p1->next->data){
                    t+=1;
                }
                p1=p1->next;
            }
            return t;
        }
        //오름차순 정렬함수 배열안씀
        void sort_list(node*head_ptr){
            int N=this->list_lenght();
            int temp=0;
            for(int i=1;i<N;i++){
                for(int j=i+1;j<N+1;j++){
                    if((this->list_locate(head_ptr,i)->data)>this->list_locate(head_ptr,j)->data){
                        temp=this->list_locate(head_ptr,i)->data;
                        this->list_locate(head_ptr,i)->data=this->list_locate(head_ptr,j)->data;
                        this->list_locate(head_ptr,j)->data=temp;
                    }
                }
            }
        }
        //복사 생성자
        bag(const bag& source){
            head=new Node();
            tail=new Node();
            head->prev=nullptr;
            head->next=tail;
            tail->prev=head;
            tail->next=nullptr;
            this->list_copy(source.head,this->head);
        }
        // =연산자 오버로딩
        void operator=(const bag&source){
            list_clear(head);
            list_copy(source.head,this->head);   
        }
        // += 연산자 오버로딩
        void operator+=(const bag& addend){
            node*ptr=this->head;
            node*ptr1=this->head->next->next;
            this->list_head_insert(addend.head->next->data);
            for(int i=0;i<addend.list_lenght()-1;i++){
                ptr=ptr->next;
                this->insertInBag_next_node(ptr1->data,ptr);
                ptr1=ptr1->next;
            }
        }
        // =! 연산자 오버로딩
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
        // ==연산자 오버로딩
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
    bag bag3;
    bag1.insertInBag_next_node(1,bag1.head);
    bag1.printAll(); cout<<"첫번째 출력"<<endl;
    bag1.insertInBag_next_node(8,bag1.list_locate(bag1.head,1));
    bag1.printAll(); cout<<"두번째 출력"<<endl;
    bag1.insertInBag_next_node(5,bag1.list_locate(bag1.head,1));
    bag1.printAll(); cout<<"세번째 출력"<<endl;
    bag1.insertInBag_next_node(11,bag1.list_locate(bag1.head,2));
    bag1.printAll(); cout<<"네번째 출력"<<endl;
    bag1.insertInBag_next_node(5,bag1.list_locate(bag1.head,3));
    bag1.printAll(); cout<<"다섯번째 출력"<<endl;
    bag1.insertInBag_next_node(-11,bag1.list_locate(bag1.head,4));
    bag1.printAll(); cout<<"여섯번째 출력"<<endl;
    bag1.insertInBag_next_node(1,bag1.list_locate(bag1.head,5));
    bag1.printAll(); cout<<"일곱번째 출력"<<endl;
    bag1.insertInBag_next_node(-9,bag1.list_locate(bag1.head,7));
    bag1.printAll(); cout<<"여덟번째 출력"<<endl;

    bag1.list_head_insert(9);            //////////////////// head insert 임@@@@@@@@@@@@
    bag1.printAll(); cout<<"아홉번째 출력 head insert!"<<endl;

    bag1.insertInBag_next_node(2,bag1.list_locate(bag1.head,9));
    bag1.printAll(); cout<<"열번째 출력"<<endl;
    bag1.insertInBag_next_node(-99,bag1.list_locate(bag1.head,9));
    bag1.printAll(); cout<<"열한번째 출력"<<endl;

    bag1.list_head_remove(bag1.head);
    bag1.printAll(); cout<<"head_remove 실행결과"<<endl;

    bag1.list_search(bag1.head,5);  //list_search실행

    cout<<"bag1의 길이는"<<bag1.list_lenght()<<endl;

    bag1.insertInBag_next_node(-98,bag1.list_locate(bag1.head,9));
    bag1.printAll(); cout<<"열두번째 출력"<<endl;

    bag1.list_remove(bag1.list_locate(bag1.head,7));
    bag1.printAll(); cout<<"bag1의 7번째 노드를 삭제하였습니다"<<endl;

    bag3.list_copy(bag1.head,bag3.head);
    bag3.printAll(); cout<<"bag3이 bag1의 노드를 카피하였습니다"<<endl;

    bag3.printAll();
    cout<<"bag3의 list_clear 함수 호출 전"<<endl;
    bag3.list_clear(bag3.head);
    bag3.printAll(); cout<<"bag3의 list_clear 함수 호출 후"<<endl;


    cout<<"bag1의 숫자5는 "<<bag1.count(5)<<"개 만큼 들어있습니다"<<endl;

    cout<<"bag1의 정렬전은 ";bag1.printAll(); cout<<endl;
    bag1.sort_list(bag1.head);
    cout<<"bag1의 오름차순정렬 후는 ";bag1.printAll(); cout<<endl;

    cout<<"bag2의 복사 생성자 호출"<<endl;
    bag bag2(bag1);
    bag2.printAll(); cout<<"bag2 모두 출력"<<endl;

    bag bag4;
    cout<<"bag4 대상으로 연산자 '=' 오버로딩 태스트 후 bag4 출력 ";
    bag4=bag1; bag4.printAll(); cout<<endl;
    cout<<"bag4 대상으로 연산자 '+=' 오버로딩 태스트 후 bag4 출력";
    bag4+=bag1; bag4.printAll(); cout<<endl;


    bag bag5; // == =! 테스트 위해 생성


    bag5.insertInBag_next_node(1,bag5.head);
    bag5.insertInBag_next_node(5,bag5.head);
    bag5.insertInBag_next_node(-9,bag5.head);
    bag5.insertInBag_next_node(2,bag5.head);
    bag5.insertInBag_next_node(1,bag5.head);
    bag5.insertInBag_next_node(7,bag5.head);
    bag5.insertInBag_next_node(1,bag5.head);

    bool torf=bag5!=bag4;
    cout<<"bag5!=bag1 의 연산결과 ";
    cout<<torf; cout<<endl;
    torf=bag5==bag1;
    cout<<"bag5==bag1 의 연산결과 ";
    cout<<torf; cout<<endl;

    bag bag6;
    bag6.list_copy(bag1.head,bag6.head);
    torf=bag6==bag1;
    cout<<"bag6==bag1 의 연산결과 ";
    cout<<torf; cout<<endl;
    torf=bag6!=bag1;
    cout<<"bag6!=bag1 의 연산결과 ";
    cout<<torf; cout<<endl;

    return 0;
}
