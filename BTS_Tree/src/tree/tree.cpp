#include "tree.h"
#include "../element/element.h"
#include <iostream>

tree::tree() {
    this->start_element_ = nullptr;
    size = 0;
}

/**
 * @brief Konstruktor klasy tree tworzący nowe drzewo z początkowym elementem o zadanej wartości.
 * @param new_value Wartość pierwszego elementu drzewa.
 */
tree::tree( int const new_value ) {
    this->start_element_ = new element( new_value );
    size = 1;
}


/**
 * @brief Destruktor klasy tree.
 */
tree::~tree( void ) {

}

void tree::set_start_element( element* new_start_element ) {
    this->start_element_ = new_start_element;
}

element* tree::get_start_element( void ) const {
    return this->start_element_;
}

/**
 * @brief Dodaje nowy element do drzewa binarnego.
 * @param new_element element do dodania do drzewa.
 */
void tree::add_element( element* new_element ) {
    if( this->get_start_element() == nullptr ) {
        this->set_start_element( new_element );
        size = 1;
    }
    this->_add_element( new_element, this->get_start_element() );
    size = size + 1;
}

void tree::_add_element( element* new_element, element* root ) {
    //left
    if(new_element->get_value() < root->get_value()) {
        if( root == root->get_left_element() ) {
            new_element->set_previous_element( root );
            root->set_left_element( new_element );
            return;
        }
        this->_add_element( new_element, root->get_left_element() );
    }
    //right
    else if( new_element->get_value() > root->get_value() ) {
        if( root == root->get_right_element() ) {
            new_element->set_previous_element( root );
            root->set_right_element( new_element );
            return;
        }
        this->_add_element( new_element, root->get_right_element() );
    }
}

void tree::_show_tree( element* element ) {
    std::cout << element->get_value() << " ";
    
    if( element == element->get_left_element() && element == element->get_right_element() ) {
        return;
    }

    if( element != element->get_right_element() ) {
        this->_show_tree( element->get_right_element() );
    }

    if( element != element->get_left_element() ) {
        this->_show_tree( element->get_left_element() );
    }
}

void tree::show_tree() {
    if( this->get_start_element() == nullptr ) {
        return;
    }

    std::cout << this->get_start_element()->get_value() << std::endl;

    if( this->get_start_element() != this->get_start_element()->get_right_element() ) {
        this->_show_tree( this->get_start_element()->get_right_element() );\
        std::cout << std::endl;
    }

    if( this->get_start_element() != this->get_start_element()->get_left_element() ) {
        this->_show_tree( this->get_start_element()->get_left_element() );
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
}

void tree::remove_element( int value ) {
    // usuwanie startowego elementu
    if( value == this->get_start_element()->get_value() ) {
        return;
    }

    // wyszukanie elementu do usunięcia
    element* root = this->search_for_element( value );
    
    std::cout << root->get_value() << "E " << value << std::endl;

    // sprawdzenie czy usuwany element jest prawym czy lewym dzieckiem
    if( root->get_previous_element()->is_left_child(root) ) {
        // usunięcie lewego dziecka
        root->get_previous_element()->set_left_element(root->get_previous_element());
    }
    else if( root->get_previous_element()->is_right_child(root) ) {
        // usunięcie prawego dziecka
        root->get_previous_element()->set_right_element(root->get_previous_element());
    }
    
    // ostatni element
    if( !root->have_left_child() && !root->have_right_child() ) {
        root->~element();
        std::cout << "OSTATNI" << std::endl;
        return;
    }
}



element* tree::search_for_element(int value) {
    return this->_search_for_element( this->get_start_element(), value );
}

element* tree::_search_for_element( element* root, int value ) {
    //left
    if(value < root->get_value()) {
        this->_search_for_element( root->get_left_element(), value );
    }
    //right
    else if( value > root->get_value() ) {
        this->_search_for_element( root->get_right_element(), value );
    }
    else {
        return root;
    }
}

