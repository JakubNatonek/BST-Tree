#include <iostream>
#include "src/element/element.h"
#include "src/tree/tree.h"

int main(int argc, char* argv[]) {

    int test_array[] = {7,3,1,2,5,4,6,10,9,8,12,13};
    
    tree* tst = new tree();
    
    for (int i = 0; i < std::size(test_array); i++) {
        tst->add_element( test_array[i] );
    }
    
    tst->show_tree();

    std::cout << "ddd" << tst->search_for_element( 12 )->get_value() << std::endl;
    
    tst->remove_element( 12 );
    
    std::cout << "ddd" << tst->search_for_element( 12 )->get_value() << std::endl;
    
    tst->remove_tree();

    std::cout << "===============" << std::endl;
    
    tst->show_tree();
    
    return 0;
}
