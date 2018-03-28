#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinHeap{
    private:
    int capacity;
    vector<int> heap;
    
    public:
    MinHeap(int c){
        capacity = c;
    };
    void push(int); //element as input
    //void pop();
    int extractmin();
    void Heapify(int); //index as input
    int parent(int i){
        return i/2;
    }; //return the index of the parent of the element at index i
    int lchild(int i){
        return (2*i)+1;
    };
    int rchild(int i){
        return (2*i)+2;
    };
    void printminheap();
};

void MinHeap::push(int e){
    
    heap.push_back(e);
    int heapsize = heap.size();
    int i = heapsize - 1;
    int p = parent(i);
    
    while(i > 0){
        if (heap[p] > heap[i]){
            swap(heap[p], heap[i]);

        }
        i = p;
        p = parent(i);        
        //i = p;
    }
};

int MinHeap::extractmin(){
    if(heap.size() == 0) return -1; // error case heap is 0
    int min = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.erase(heap.end()-1);
    Heapify(0); //heap from index 0
    return min;
}

void MinHeap::Heapify(int i){
    if(heap.size() == 0) return; //error case

    if(i >= 0 && i < heap.size()){
        int smaller = -1; //index
     
        //smaller = min(v[lchild(i)], v[rchild(i)])
        if(lchild(i) < heap.size()){
            smaller = lchild(i);
            //cout << lchild(i) << endl;
        }
        if(rchild(i) < heap.size() && heap[rchild(i)] < heap[lchild(i)]){
            smaller = rchild(i);  
            //cout << rchild(i) << endl;            
        }
        if( smaller != -1 && heap[i] > heap[smaller]){
            //cout << smaller << endl;                
            swap(heap[i], heap[smaller]);   
            Heapify(smaller);                
        }
    }
};

void MinHeap::printminheap(){
    for(int i =0; i < heap.size(); i++){
        cout << heap[i] << endl;
    }
};

int main(){
    MinHeap min_h(7);

    min_h.push(1);
    min_h.push(3);   
    min_h.push(5);
    min_h.push(6);
    min_h.push(7);
    min_h.push(8);
    min_h.printminheap();
    //min_h.push(1);
    cout << " min is " << min_h.extractmin() << endl;
    min_h.printminheap();    
    
};
