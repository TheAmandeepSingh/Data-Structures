#include <iostream>
#include <vector>

class MaxHeap {
    int _size{};
    std::vector<int> vect {-1};

public:
    bool isEmpty(){ return _size == 0;}
    int getMax() { if(_size != 0) {return vect[1];}}
    

};

int main(){
    std::cout<<"Yes";
    return 0;
}
