#include "tree.h"
#include "../element/element.h"
#include <iostream>
#include <fstream>
#include <string>

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
        std::cout<<"COS 139" <<std::endl;
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
    else if( root->have_right_child() && !root->have_left_child() ) {
        std::cout << "153 prawo" << std::endl;
        // jeśli usuwany element jest lewym dzieckiem
        if( root->get_previous_element()->is_left_child( root ) ) {
            std::cout << "156 prawo" << std::endl;
            // ustawienie prawego dziecka w miejsce usuwanego elementu lewe dziecko
            root->get_previous_element()->set_left_element( root->get_right_element() );
        }
        // jeśli usuwany element jest prawym dzieckiem
        else if( root->get_previous_element()->is_right_child( root ) ) {
            std::cout << "162 prawo" << std::endl;
            // ustawienie prawego dziecka w miejsce usuwanego elementu prawe dziecko
            root->get_previous_element()->set_right_element( root->get_right_element() );
                // 10 -> 12 -> 13
        }
        // ustawienie poprzedniego elementu na element poprzedni usuniętego elementu
        root->get_right_element()->set_previous_element( root->get_previous_element() );
        // 13 -> 12 -> 10 
        delete root;
        return;
    }
    // jeśli posiada lewe dziecko
    else if( root->have_left_child() && !root->have_right_child() ) {
        std::cout << "Lewe  Powino 170" << std::endl;
        // jeśli usuwany element jest lewym dzieckiem
        if( root->get_previous_element()->is_left_child(root) ) {
            std::cout << "Lewe nie Powino 173" << std::endl;
            // ustawienie lewego dziecka w miejsce usuwanego elementu lewe dziecko
            root->get_previous_element()->set_left_element( root->get_left_element() );
        }
        // jeśli usuwany element jest prawym dzieckiem
        else if( root->get_previous_element()->is_right_child(root) ) {
            std::cout << "Lewe Powino 179" << std::endl;
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
        std::cout << "CZEMU TU" << std::endl;
        element* element_for_swap = root->get_right_element();

        // lewy element
        if( element_for_swap->have_left_child() ) {
            element_for_swap = element_for_swap->get_left_element();
            // przejscia w lewo
            while ( element_for_swap->have_left_child() ) {
                element_for_swap = element_for_swap->get_left_element();
            }
            // zamiana elementów
            // jeśli jest lewym elementem bez dzieci
            if( !element_for_swap->have_right_child() && !element_for_swap->have_left_child() ) {
                // usunięcie elementu z swojego miejsca w celu wpisania go w miejsce usuniętego elementu
                element_for_swap->get_previous_element()->set_left_element( element_for_swap->get_previous_element() );
                // 4 -> 5 set l 5

                // dołączenie elementu w miejsce usuniętego elementu
                element_for_swap->set_previous_element( root->get_previous_element() );
                // 4 set p 7

                if( root->get_previous_element()->is_left_child( root ) ) {
                    std::cout << "Lewe  Powino 227" << std::endl;
                    // ustawienie lewego dziecka w miejsce usuwanego elementu lewe dziecko
                    root->get_previous_element()->set_left_element( element_for_swap );
                    // 3 -> 7 set l 4
                }
                // jeśli usuwany element jest prawym dzieckiem
                else if( root->get_previous_element()->is_right_child( root ) ) {
                    std::cout << "Lewe Powino 233" << std::endl;
                    // ustawienie lewego dziecka w miejsce usuwanego elementu prawe dziecko
                    root->get_previous_element()->set_right_element( element_for_swap );
                    // 3 -> 7 set r 4
                }

                // dodłączenie lewego dziecka usuniętego elementu
                element_for_swap->set_left_element( root->get_left_element() );
                // 4 set l 1
                element_for_swap->get_left_element()->set_previous_element( element_for_swap );
                // 4 -> 1 set p 4
                // odłączenie prawego dziecka usuniętego elementu
                element_for_swap->set_right_element( root->get_right_element() );
                // 4 set r 5
                element_for_swap->get_right_element()->set_previous_element( element_for_swap );
                // 4 -> 5 set p 4
                delete root;
                return;
            }
            else if ( element_for_swap->have_right_child() && !element_for_swap->have_left_child() ) {
                // przepięcie prawego dziecka w miejsce nominowanego elementu
                element_for_swap->get_previous_element()->set_left_element( element_for_swap->get_right_element() );
                element_for_swap->get_right_element()->set_previous_element( element_for_swap->get_previous_element() );
                // 4 -> 5 set l

                // dołączenie elementu w miejsce usuniętego elementu
                element_for_swap->set_previous_element( root->get_previous_element() );
                // 4 set p 7

                if( root->get_previous_element()->is_left_child( root ) ) {
                    std::cout << "Lewe  Powino 227" << std::endl;
                    // ustawienie lewego dziecka w miejsce usuwanego elementu lewe dziecko
                    root->get_previous_element()->set_left_element( element_for_swap );
                    // 3 -> 7 set l 4
                }
                // jeśli usuwany element jest prawym dzieckiem
                else if( root->get_previous_element()->is_right_child( root ) ) {
                    std::cout << "Lewe Powino 233" << std::endl;
                    // ustawienie lewego dziecka w miejsce usuwanego elementu prawe dziecko
                    root->get_previous_element()->set_right_element( element_for_swap );
                    // 3 -> 7 set r 4
                }

                // dodłączenie lewego dziecka usuniętego elementu
                element_for_swap->set_left_element( root->get_left_element() );
                // 4 set l 1
                element_for_swap->get_left_element()->set_previous_element( element_for_swap );
                // 4 -> 1 set p 4
                // odłączenie prawego dziecka usuniętego elementu
                element_for_swap->set_right_element( root->get_right_element() );
                // 4 set r 5
                element_for_swap->get_right_element()->set_previous_element( element_for_swap );
                // 4 -> 5 set p 4
                delete root;
                return;
            }
            return;
        }
        // ma prawe dziecko i nie ma lewego
        else if( element_for_swap->have_right_child() && !element_for_swap->have_left_child() ) {
            element_for_swap->set_previous_element( root->get_previous_element() );

            if( root->get_previous_element()->is_left_child( root ) ) {
                std::cout << "Lewe  Powino 227" << std::endl;
                // ustawienie lewego dziecka w miejsce usuwanego elementu lewe dziecko
                root->get_previous_element()->set_left_element( element_for_swap );
                // 3 -> 7 set l 4
            }
            // jeśli usuwany element jest prawym dzieckiem
            else if( root->get_previous_element()->is_right_child( root ) ) {
                std::cout << "Lewe Powino 233" << std::endl;
                // ustawienie lewego dziecka w miejsce usuwanego elementu prawe dziecko
                root->get_previous_element()->set_right_element( element_for_swap );
                // 3 -> 7 set r 4
            }

            element_for_swap->set_left_element( root->get_left_element() );
            element_for_swap->get_left_element()->set_previous_element( element_for_swap );
            delete root;
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

void tree::save_to_file_txt( std::string path ) {
    if (this->get_start_element() == nullptr) {
        return;
    }
    std::ofstream file;
    
    file.open(path);
    
    if (!file.is_open()) {
        std::cerr << "Nie udalo sie otworzyc pliku do zapisu!" << std::endl;
        return;
    }

    this->_pre_order_save_to_txt( this->get_start_element(), file );

    file.close(); // not necessary, but a good practice
}

void tree::_pre_order_save_to_txt( element* element, std::ofstream& file ) {

    // Root, Left, Right
    file << element->get_value() <<  std::endl;

    if (element->have_left_child()) {
        this->_pre_order_save_to_txt( element->get_left_element(), file );
    }

    if (element->have_right_child()) {
        this->_pre_order_save_to_txt( element->get_right_element(), file);
    }
}

void tree::load_from_file_txt(std::string path) {
    std::string line;
    std::ifstream file;
    file.open( path );
    if (!file.is_open()) {
        std::cerr << "Nie udalo sie otworzyc pliku do zapisu!" << std::endl;
        return;
    }
    
    this->remove_tree();
    
    while (std::getline (file, line)) {
        // Output the text from the file
        this->add_element(  std::stoi( line ) );
    }

    file.close();
}

void tree::save_to_file_bin( std::string path ) {
    if (this->get_start_element() == nullptr) {
        return;
    }
    std::ofstream file(path, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Nie udalo sie otworzyc pliku do zapisu!" << std::endl;
        return;
    }

    this->_pre_order_save_to_bin(this->get_start_element(), file);

    file.close(); // niekonieczne, ale dobra praktyka
}

void tree::_pre_order_save_to_bin(element* element, std::ofstream& file) {
    if (!element) return;

    // Zapisujemy wartość elementu w formacie binarnym
    int value = element->get_value();
    file.write(reinterpret_cast<const char*>(&value), sizeof(value));

    if (element->have_left_child()) {
        this->_pre_order_save_to_bin(element->get_left_element(), file);
    }

    if (element->have_right_child()) {
        this->_pre_order_save_to_bin(element->get_right_element(), file);
    }
}

void tree::load_from_file_bin(std::string path) {
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Nie udalo sie otworzyc pliku do zapisu!" << std::endl;
        return;
    }

    this->remove_tree();

    // Czytanie wartości liczbowych z pliku
    int value;
    while (file.read(reinterpret_cast<char*>(&value), sizeof(value))) {
        this->add_element(value);
    }

    file.close();
}