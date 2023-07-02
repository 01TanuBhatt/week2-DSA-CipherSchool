#include <bits/stdc++.h>
using namespace std;

class Minheap {
    int capacity;
    int size;
    int *heap;

    int parent(int index){
        return (index-1)/2;
    }
    public:
    Minheap(int capacity) {
        this->capacity =capacity;
        this->size = 0;
        this->heap = new int[this->capacity];
    }

    void Push(int key) {
        if(this->size == this->capacity) {
            return;
        }
        this->size++;
        int index = this->size-1;
        this->heap[index] = key;

        while(index != 0 && this->heap[index] < this->heap[parent(index)]) {
            swap(this->heap[index],this->heap[parent(index)]);
            index = parent(index);
        }
    }
    int top() {
        return this->size == 0? 0: this->heap[0];
        
    }
    
};
int main(){

}