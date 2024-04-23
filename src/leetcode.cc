#include <iostream>
#include <list>
using namespace std;
class ProductOfNumbers {
public:
    ProductOfNumbers() {

    }
    
    void add(int num) {
        list<int> l;
        l.push_back(num);
    }

    int getProduct(int k) {
      
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */