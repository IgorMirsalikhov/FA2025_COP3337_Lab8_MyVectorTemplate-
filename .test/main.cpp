#include "MyVector.hpp"
#include "MyVector.cpp"
#include <iostream>
#include <random>

int main(void) {
    std::mt19937 eng(1);
    std::uniform_int_distribution<int> dist(0, 20);
    
    MyVector<int> *p = new MyVector<int>(100);
    for (int i = 0; i < 20; i++) {
        p->push_front(dist(eng));
    }
    
    // Test erase
    while (p->getSize() > 5) {
        std::uniform_int_distribution<int> dist2(p->getSize() * -1, p->getSize() - 1);
        int index = dist2(eng);
        std::cout << index << std::endl;
        p->erase(index);
        p->print();
    }

     std::cout << "Capacity: " << p->getCapacity() << std::endl;

    // Test remove_dups
    for (int i = 0; i < 20; i++) {
        p->push_front(dist(eng));
    }

    std::cout << "Before remove_dups()\n";
    p->print();
    p->remove_dups();
    std::cout << "After remove_dups()\n";
    p->print();

    delete p;
  
    return 0;
}
