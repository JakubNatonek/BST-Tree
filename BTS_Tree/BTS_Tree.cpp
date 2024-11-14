#include <iostream>
#include "src/element/element.h"
#include "src/tree/tree.h"

int main(int argc, char* argv[]) {

    element* right = new element(12);
    element* left = new element(13);

    tree* tst = new tree(10);
    tst->add_element(left);
    tst->add_element(right);

    for( int i = 1; i <= 10; i += 2 ) {
        tst->add_element( new element( i ) );
    }

    for( int i = 1; i <= 10; i++ ) {
        tst->add_element( new element( i ) );
    }

    tst->show_tree();

    std::cout << tst->search_for_element( 12 )->get_value() << std::endl;

    tst->remove_element( 12 );
    
    return 0;
}
