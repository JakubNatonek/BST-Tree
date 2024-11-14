#include <iostream>
#include "src/element/element.h"
#include "src/tree/tree.h"

int main() {
    std::cout<<"Hello World";

    element test = new element(8);

    if(test == test.get_left_element()) {
        std::cout << "Tak" << std::endl;
    }
    else {
        std::cout << "Nie" << std::endl;
    }

    return 0;
}