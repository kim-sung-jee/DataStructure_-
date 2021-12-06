#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

    

    bool IsOperand(char ch)
    {
        if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        return true;
        }
        return false;
    }


    
    


template<typename T>
class Node {
public:
    T data;
    Node<T>* next, * prev;
    Node() {
        next = prev = nullptr;
        data = 0;
    }
    Node(T i, Node<T>* ptr) {
        data = i;
        prev = ptr;
        next = ptr->next;
        next->prev = prev->next = this;
    }

};


template<typename T>
class doublylinkedlist {

public:
    Node<T>* head, * tail;
    Node<T>* cursor = nullptr;
    size_t i = 1;
    doublylinkedlist() {
        head = new Node<T>();
        tail = new Node<T>();
        head->prev = nullptr;
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
        
    }
    ~doublylinkedlist() {
        delete head, tail, cursor;
    }
    
    void list_tail_insert(T i) {
        Node<T>* new_node = new Node<T>();
        new_node->data = i;
        
        new_node->next=tail;
        new_node->prev=tail->prev;

        tail->prev->next = new_node;
        tail->prev=new_node;
            
           
        
        return;
    }

    //head,tail 노드를 제외한 n번째 노드 다음인 n+1에 생성된다.



    //노드의 길이를 잰다
    int list_lenght()const {
        int i = 0;
        Node<T>* p1 = this->head;

        while (p1->next->next != nullptr) {
            p1 = p1->next;
            i++;
        }

        return i;
    }
    //전체 노드 출력
    void printAll()const {
        Node<T>* p1 = head->next;
        if (p1 == tail) {
            cout << "길이는 0입니다";
        }
        while (p1 != tail) {
            cout << p1->data << " ";
            p1 = p1->next;
        }
        
    }
    T top(){
        return tail->prev->data;
    }

    void removetail(){
        Node<T>* p1 = tail->prev;
        tail->prev=p1->prev;
        p1->prev->next=tail;
        
        delete p1;
        
    }


    

    


    void list_copy(const Node<T>* source_ptr, Node<T>*& head_ptr) {
        if (source_ptr->next->next == nullptr) {
            return;
        }
        Node<T>* ptr = head_ptr;
        list_head_insert(source_ptr->next->data);
        source_ptr = source_ptr->next;
        while (source_ptr->next->next != nullptr) {
            insertInBag_next_node(source_ptr->next->data, ptr->next);
            ptr = ptr->next;
            source_ptr = source_ptr->next;
        }
    }
   


};
template<typename T>
class myStack {
private:
    int top;
    doublylinkedlist<T>* list_d;
public:
    myStack() {
        top = -1;
        list_d = new doublylinkedlist<T>();
    }
    
    
    T pop(){
        list_d->removetail();
    }
    bool empty(){
        if(list_d->head->next==list_d->tail){
            return true;
        }else{
            return false;
        }
    }
    T size();
    T Top(){
        return list_d->top();
    }
    void push(T element) {
        list_d->list_tail_insert(element);
    }
    void print() {
        list_d->printAll();
        return;
    }
    void print_size(){
        cout<<list_d->list_lenght();
    }
};







class evaluator {
public:
    myStack<double>*numbers;
    myStack<char>*operations;
    myStack<char>*postFix;
    myStack<double> *evaluate;
public:

    evaluator(){
        numbers=new myStack<double>();
        operations=new myStack<char>();
        postFix=new myStack<char>();
        evaluate=new myStack<double>();
    }
    int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
    }
    

    string conver_to_postfix(string s){
        
        string result;
        
        for(int i = 0; i < s.length(); i++) {
        char c = s[i];
    
        // If the scanned character is
        // an operand, add it to output string.
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            result += c;
            
        }
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if(c == '(')
            postFix->push('(');
            
        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(c == ')') {
            while(postFix->Top() != '(')
            {   
                
                result += postFix->Top();
                postFix->pop();
            }
            postFix->pop();
        }else if(c=='.'){
            result+=c;
        }else if(c=='-'){
            if(i==0){
                result+=c;
            }else if(strchr("+-*/(",s[i-1])){
                result+=' ';
                result+=c;
                
                
            }
        }
        //If an operator is scanned
        else {
            while(!postFix->empty() && prec(s[i]) <= prec(postFix->Top())) {
                result += postFix->Top();
                postFix->pop(); 
            }
            postFix->push(c);
        }
    }
 
    // Pop all the remaining elements from the stack
    while(!postFix->empty()) {
        result += postFix->Top();
        postFix->pop();
    }
        
        return result;
    }



    string read_expression(istream&ins){
        
        const char RIGHT_PARENTHESIS=')';

        
        string a;
        double number;
        char symbol;
        while(ins&&ins.peek()!='\n'){
            if(isdigit(ins.peek())){
                ins>>number;
                numbers->push(number);
                a.append(to_string(number));
            }
            else if(strchr("+-*/",ins.peek())!=NULL){
                ins>>symbol;
                operations->push(symbol);
                
                a+=symbol;
                
            }
            else if(ins.peek()==RIGHT_PARENTHESIS){
                symbol=ins.peek();
                a+=symbol;
                ins.ignore();
            }else if(ins.peek()=='.'){
                ins>>symbol;
                a+=symbol;
            }
            else{
                symbol=ins.peek();
                a+=symbol;
                ins.ignore();
              
            }
        }
        
        return a;
    }





   

    double evaluate_postfix(string s){
        string sto_d;
        double op1,op2;
        double d;
        int i=0;
        
        while(i!=s.size()){
            
            char c=s[i];
            if(c=='+'){
                op2=evaluate->Top();
                evaluate->pop();
                op1=evaluate->Top();
                evaluate->pop();
                evaluate->push(double(op1+op2));

                i+=1;
            }else if(c=='*'){
                op2=evaluate->Top();
                evaluate->pop();
                op1=evaluate->Top();
                evaluate->pop();
                evaluate->push(double(op1*op2));
                i+=1;
            }
            else if(c=='-'){
                
                if(s[i-1]==' '){
                    sto_d+=c;
                    i++;
                    
                }else{
                    op2=evaluate->Top();
                    evaluate->pop();
                    op1=evaluate->Top();
                    evaluate->pop();
                    evaluate->push(double(op1-op2));
                    i+=1;
                }
            }else if(c=='/'){
                op2=evaluate->Top();
                evaluate->pop();
                op1=evaluate->Top();
                evaluate->pop();
                evaluate->push(double(op1/op2));
                i+=1;
            }else if(isdigit(c)){
                
                
                while(isdigit(s[i])){
                    sto_d+=s[i];
                    i++;
                    
                }
                sto_d+=s[i];
                i++;
                for(int t=0;t<6;t++){
                    sto_d+=s[i];
                    i+=1;
                }
                d=stod(sto_d);
                evaluate->push(d);
                
                sto_d="";
            }else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                double t;
                string aa;
                int tt=0;
                cout<<"please input about :"<<c<<":";
                cin>>t;
                if(sto_d=="-"){
                    t=-t;
                    cout<<t<<endl;
                }
                evaluate->push(t);
                i++;
                sto_d="";
            }else if(c==' '){
                i++;
            }
            
            
        }
        
        return evaluate->Top();

    }


};


int main() {

    evaluator e1;
    string b=e1.conver_to_postfix(e1.read_expression(cin));;
    cout<<b<<endl;
    double d=e1.evaluate_postfix(b);
    cout<<d;
    bool running=true;
    int input;
    // while(running){
    //     cout<<"num1 is start"<<" "<<"num2 is quit :";
    //     cin>>input;
    //     if(input==1){
    //         // string read_expression(istream&ins) <<함수 원형
    //         cout<<"infix :";
    //         cin.ignore();
    //         string c=e1.read_expression(cin);

    //         string a=e1.conver_to_postfix(c);
            
    //         double b=e1.evaluate_postfix(a);
    //         cout<<b<<endl;
    //     }else if(input==2){
    //         running=false;
    //     }else{
    //         cout<<"it is no t valid num";
    //     }
    // }
    


}
