#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    int val;
    Node* next = NULL;    
};

class stack{
    //int size;
    //int t;
    //int b;
    //Node* s;
    Node* s = NULL;
    Node* t = NULL;
    Node* p = NULL;
    
public:
    void push(int);
    void pop();
    int top();
};

void stack::push(int x){
    Node *c = new Node;
    c->val = x;
    if(!s && (s==t)){
        s = t = c;
    }
    else{
        if(t!=NULL) {
            t->next = c;
            p = t;
            t = t->next;
        }
    }
}

void stack::pop(){
    //delete(a[t]);
    
    if(t){
        delete(t);
        t = p;
    }else if((s!=NULL) && (s == t)){
        delete(t);
        t = NULL;
        s = NULL;
    }else if(!t){
        cout << "stack is empty" << "\n";
    }
}

int stack::top(){
    int r;
    if(t!=NULL){
        r = t->val;        
    }else{
        cout << "stack is empty" << "\n";
        r = -1; // error case
    }
    return r;
}

int main()
{
    stack* g = new stack;
    
    g->pop();

    for(int i = 0; i < 100; i++){
        g->push(i);
    }
    //g->push(1);
    //s->push(2);
    //s->push(3);
    int r = g->top();
    cout << "the top is "<< r << "\n";
    g->pop();
    r = g->top();
    cout << "the top is "<< r << "\n";    
   //cout << "Hello World" << endl; 
   //delete(s);
   
   return 0;
}
