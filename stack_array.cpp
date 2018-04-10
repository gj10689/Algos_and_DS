#include <iostream>

using namespace std;

class stack{
    int size;
    int t;
    int b;
    int* a;
    
public:
    stack(int s){
        size = s;
        t = -1;
        //b = -1;
        a = new (nothrow) int[size];
        if (!a) cout << "allocation of the array failed \n";
    }
    
    void push(int);
    void pop();
    int top();
};

void stack::push(int x){
    if(t < size){
        t++;
        cout << t << "\n";
        cout << x << "\n";        
        a[t] = x;
        //t++;
    }else{
        cout << "The stak is full \n";
    }
}

void stack::pop(){
    //delete(a[t]);
    if(t > 0){
        t--;        
    }else{
        cout << "the stack is empty \n";
    }
}

int stack::top(){
    if(t < size){
        int x = a[t];        
    }
}

int main()
{
    stack* s = new stack(100);
    s->pop();
    for(int i = 0; i < 100; i++){
        s->push(i);
    }
    //s->push(1);
    //s->push(2);
    //s->push(3);
    int r = s->top();
    cout << "the top is "<< r << "\n";
    s->pop();
    r = s->top();
    cout << "the top is "<< r << "\n";    
   cout << "Hello World" << endl; 
   delete(s);
   
   return 0;
}
