#include "tree.h"
#include "../element/element.h"
#include <iostream>

tree::tree() {
    this->start_element_ = nullptr;
}

/**
 * @brief Konstruktor klasy tree tworzący nowe drzewo z początkowym elementem o zadanej wartości.
 * @param new_value Wartość pierwszego elementu drzewa.
 */
tree::tree( int const new_value ) {
    this->start_element_ = new element( new_value );
}


/**
 * @brief Destruktor klasy tree.
 */
tree::~tree( void ) {
    this->remove_tree();
}

void tree::set_start_element( element* new_start_element ) {
    if( this->get_start_element() == nullptr ) {
        this->start_element_ = new_start_element;
        return;
    }
    this->start_element_ = new_start_element;
}
void tree::set_start_element( int new_value ) {
    if( this->get_start_element() == nullptr ) {
        this->start_element_ = new element( new_value );
        return;
    }
    this->start_element_->set_value( new_value );
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
        return;
    }
    this->_add_element( new_element, this->get_start_element() );
}

void tree::add_element( int value ) {
    
    element* new_element = new element( value );
    
    add_element( new_element );
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
        this->_show_tree( this->get_start_element()->get_right_element() );
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

    this->remove_element( root );
}

void tree::remove_element( element* root ) {
    // usuwanie startowego elementu
    if( root == this->get_start_element() ) {
        return;
    }

    // ostatni element
    if( !root->have_left_child() && !root->have_right_child() ) {
        // sprawdzenie czy usuwany element jest prawym czy lewym dzieckiem
        if( root->get_previous_element()->is_left_child(root) ) {
            // usunięcie lewego dziecka
            root->get_previous_element()->set_left_element(root->get_previous_element());
        }
        else if( root->get_previous_element()->is_right_child(root) ) {
            // usunięcie prawego dziecka
            root->get_previous_element()->set_right_element(root->get_previous_element());
        }
        delete root;
        return;
    }
    // jeśli posiada prawe dziecko
    else if( root->have_right_child() ) {
        // jeśli usuwany element jest lewym dzieckiem
        if( root->get_previous_element()->is_left_child( root ) ) {
            // ustawienie prawego dziecka w miejsce usuwanego elementu lewe dziecko
            root->get_previous_element()->set_left_element( root->get_right_element() );
        }
        // jeśli usuwany element jest prawym dzieckiem
        else if( root->get_previous_element()->is_right_child(root) ) {
            // ustawienie prawego dziecka w miejsce usuwanego elementu prawe dziecko
            root->get_previous_element()->set_right_element( root->get_right_element() );
        }
        // ustawienie poprzedniego elementu na element poprzedni usuniętego elementu
        root->get_right_element()->set_previous_element( root->get_previous_element() );
        delete root;
        return;
    }
    // jeśli posiada lewege dziecko
    else if( root->have_left_child() ) {
        // jeśli usuwany element jest lewym dzieckiem
        if( root->get_previous_element()->is_left_child(root) ) {
            // ustawienie lewego dziecka w miejsce usuwanego elementu lewe dziecko
            root->get_previous_element()->set_left_element( root->get_left_element() );
        }
        // jeśli usuwany element jest prawym dzieckiem
        else if( root->get_previous_element()->is_right_child(root) ) {
            // ustawienie lewego dziecka w miejsce usuwanego elementu prawe dziecko
            root->get_previous_element()->set_right_element( root->get_left_element() );
        }
        // ustawienie poprzedniego elementu na element poprzedni usuniętego elementu
        root->get_left_element()->set_previous_element( root->get_previous_element() );
        delete root;
        return;
    }
    // jeśli posiada oba dziecka
    else if( root->have_left_child() && root->have_right_child() ) {
        element* element_for_swap = root->get_right_element();

        // znalezienie elementu bez dzieci
        while ( element_for_swap->have_left_child() || element_for_swap->have_right_child() ) {
            if( element_for_swap->have_left_child() ) {
                // przejście na lewe dziecko
                element_for_swap = element_for_swap->get_left_element();
            }
            else if( element_for_swap->have_right_child() ) {
                // przejście na prawe dziecko
                element_for_swap = element_for_swap->get_right_element();
            }
        }

        // jeśli jest lewym elementem bez dzieci
        if( element_for_swap->get_previous_element()->is_left_child( element_for_swap ) ) {

            // usunięcie elementu z swojego miejsca w celu wpisania go w miejsce usuniętego elementu
            element_for_swap->get_previous_element()->set_left_element( element_for_swap->get_previous_element() );

            // dołączenie elementu w miejsce usuniętego elementu
            element_for_swap->set_previous_element( root->get_previous_element() );

            // dodłączenie lewego dziecka usuniętego elementu
            element_for_swap->set_left_element( root->get_left_element() );
            element_for_swap->get_left_element()->set_previous_element( element_for_swap );
            // odłączenie prawego dziecka usuniętego elementu
            element_for_swap->set_right_element( root->get_right_element() );
            element_for_swap->get_right_element()->set_previous_element( element_for_swap );
            delete root;
            return;
        }
        // jeśli jest prawym elementem bez dzieci
        else if( element_for_swap->get_previous_element()->is_right_child( element_for_swap ) ) {
            // zapisanie vartości prawego dziecka elementu do usunięcia
            int new_value = root->get_right_element()->get_value();
            // usunięcie prawego dziecka elementu do usunięcia
            this->remove_element( root->get_right_element() );
            // przepisanie wartości z rekurencyjnego usuwania
            root->set_value( new_value );
            return;
        }
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

void tree::_pre_order(element* element) {
    if (element == nullptr) {
        return;
    }

    // Root, Left, Right
    std::cout << element->get_value() << " ";

    if (element->have_left_child()) {
        this->_pre_order(element->get_left_element());
    }

    if (element->have_right_child()) {
        this->_pre_order(element->get_right_element());
    }
}

void tree::pre_order() {
    if (this->get_start_element() == nullptr) {
        return;
    }

    this->_pre_order(this->get_start_element());
    std::cout << std::endl;
}

void tree::_in_order(element* element) {
    if (element == nullptr) {
        return;
    }

    // Left, Root, Right
    if (element->have_left_child()) {
        this->_in_order(element->get_left_element());
    }

    std::cout << element->get_value() << " ";

    if (element->have_right_child()) {
        this->_in_order(element->get_right_element());
    }
}

void tree::in_order() {
    if (this->get_start_element() == nullptr) {
        return;
    }

    this->_in_order(this->get_start_element());
    std::cout << std::endl;
}

void tree::_post_order(element* element) {
    if (element == nullptr) {
        return;
    }

    // Left, Right, Root
    if (element->have_left_child()) {
        this->_post_order(element->get_left_element());
    }

    if (element->have_right_child()) {
        this->_post_order(element->get_right_element());
    }

    std::cout << element->get_value() << " ";
}

void tree::post_order() {
    if (this->get_start_element() == nullptr) {
        return;
    }

    this->_post_order(this->get_start_element());
    std::cout << std::endl;
}

void tree::search_for_path_to_element( element* root ) {
    std::cout << root->get_value() << std::endl;
    if( root == this->get_start_element() )
    {
        return;
    }
    else {
        search_for_path_to_element( root->get_previous_element() );
    }
    return;
}

void tree::remove_tree() {
    this->_remove_tree( this->get_start_element() );
    this->start_element_ = nullptr;
}

void tree::_remove_tree( element* element ) {
    if( element->have_left_child() )
    {
        this->_remove_tree( element->get_left_element() );
    }

    if( element->have_right_child() )
    {
        this->_remove_tree( element->get_right_element() );
    }

    delete element;
}