#include <iostream>
#include <vector>

/**
 * Max Heap is like binary tree structure where parent is always maximum than their children 
 * for example if we have array of numbers like:
 * Arr->   -1 100 75 95 60 65 90    // -1 is a dummy value in our vector for calculations of left and right child 
 * Index->  0  1  2  3  4  5  6 
 * 
 * Let's make a binary tree of this:
 *                  100(1)
 *               /        \
 *              75(2)     95(3)
 *            /   \       /  
 *         60(4)  65(5)  90(6) 
 * 
 * Parent Index will always be -> childIdx / 2 
 * e.g. 75(index - 2) & 95(index - 3)  => parent is 100(index - 1) :=> 2/2 = 1 | 3/2 = 1.5 but integer ~1
 * 
 * Left Child will always be -> parentIdx * 2
 * e.g. left child of 100(1)  => 1 * 2 = 4 which is 75(2)
 * 
 * Right Child will always be -> parentIdx * 2 + 1
 * e.g. right child of 100(1) => 1 * 2 + 1 = 3 which is 95(3)
 * */


class MaxHeap {
    int _size{};
    std::vector<int> vect {-1};

    int parent(int i) { return i>>1;} // i / 2
    int leftChild(int i) { return i<<1;} // i*2
    int rightChild(int i) {return (i<<1) + 1;}

public:
    bool isEmpty() const { return _size == 0;}
    int getMax() const { return vect[1]; }
    int getSize() const { return _size; }

    void insert(int val);
    void shiftUp(int i);
    void shiftDown(int i);
    int extractMax();
};

void MaxHeap::shiftDown(int i){
    if(i > _size) return;

    int swapId = i;

    if(leftChild(i) <= _size && vect[i] < vect[leftChild(i)]){
        swapId = leftChild(i);
    }

    if(rightChild(i) <= _size && vect[swapId] < vect[rightChild(i)]){
        swapId = rightChild(i);
    }

    if(i != swapId){
        std::swap(vect[i], vect[swapId]);
        shiftDown(swapId);
    }
    return;
}

/**
 * We can have pop() instead of extractMax() without returning any value
 **/

int MaxHeap::extractMax(){
    //if(_size == 0 ) return 0;
    int max = vect[1];
    std::swap(vect[1], vect[_size--]); // reducing the size after swap
    shiftDown(1);
    return max;
}

void MaxHeap::shiftUp(int i){
    if( i > _size) return;
    if( i == 1) return;

    if(vect[i] > vect[parent(i)]) {
        std::swap(vect[parent(i)], vect[i]);
    }
    shiftUp(parent(i));
}

void MaxHeap::insert(int val){
    if(_size + 1 >= vect.size()){
        vect.push_back(0);  // placeholder
    }

    vect[++_size] = val;
    shiftUp(_size);
    return;
}


int main(){
    MaxHeap* Priority_Queue = new MaxHeap();

    Priority_Queue->insert(100);
    Priority_Queue->insert(75);
    Priority_Queue->insert(95);
    Priority_Queue->insert(60);
    Priority_Queue->insert(65);
    Priority_Queue->insert(90);

    std::cout<<"Size of Priority Queue: " << Priority_Queue->getSize()<<std::endl;;
    std::cout<<"Get Max: " << Priority_Queue->getMax() << std::endl << std::endl;

    std::cout<<"--> Extracting Max/Pop..." << std::endl << std::endl;
    Priority_Queue->extractMax();
    std::cout<<"New Max: " << Priority_Queue->getMax() << std::endl;
    std::cout<<"Size of Priority Queue: " << Priority_Queue->getSize()<<std::endl<<std::endl;

    std::cout<<"--> Extracting Max/Pop..." << std::endl << std::endl;
    Priority_Queue->extractMax();
    std::cout<<"New Max: " << Priority_Queue->getMax() << std::endl;

    std::cout<<"--> Extracting Max/Pop..." << std::endl << std::endl;
    Priority_Queue->extractMax();
    std::cout<<"New Max: " << Priority_Queue->getMax() << std::endl;
    std::cout<<"Size of Priority Queue: " << Priority_Queue->getSize()<<std::endl;

    return 0;
}
