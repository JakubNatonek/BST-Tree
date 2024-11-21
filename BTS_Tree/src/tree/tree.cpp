#include "tree.h"
#include "../element/element.h"
#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief Konstruktor domyślny klasy tree, inicjalizuje puste drzewo.
 */
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

/**
 * @brief Ustawia element startowy drzewa.
 * @param new_start_element Wskaźnik na nowy element startowy.
 */
void tree::set_start_element( element* new_start_element ) {
    if( this->get_start_element() == nullptr ) {
        this->start_element_ = new_start_element;
        return;
    }
    this->start_element_ = new_start_element;
}

/**
 * @brief Ustawia wartość elementu startowego drzewa.
 * @param new_value Nowa wartość elementu startowego.
 */
void tree::set_start_element( int new_value ) {
    if( this->get_start_element() == nullptr ) {
        this->start_element_ = new element( new_value );
        return;
    }
    this->start_element_->set_value( new_value );
}

/**
 * @brief Pobiera wskaźnik na element startowy drzewa.
 * @return Wskaźnik na element startowy drzewa.
 */
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

/**
 * @brief Dodaje nowy element do drzewa binarnego.
 * @param value Wartość nowego elementu do dodania do drzewa.
 */
void tree::add_element( int value ) {
    element* new_element = new element( value );
    add_element( new_element );
}

/**
 * @brief Rekurencyjnie dodaje nowy element do odpowiedniego miejsca w drzewie.
 * @param new_element Nowy element do dodania.
 * @param root Korzeń drzewa, od którego zaczyna się dodawanie.
 */
void tree::_add_element( element* new_element, element* root ) {
    if(new_element->get_value() < root->get_value()) {
        if( root == root->get_left_element() ) {
            new_element->set_previous_element( root );
            root->set_left_element( new_element );
            return;
        }
        this->_add_element( new_element, root->get_left_element() );
    }
    else if( new_element->get_value() > root->get_value() ) {
        if( root == root->get_right_element() ) {
            new_element->set_previous_element( root );
            root->set_right_element( new_element );
            return;
        }
        this->_add_element( new_element, root->get_right_element() );
    }
}

/**
 * @brief Usuwa element z drzewa binarnego na podstawie wartości.
 * @param value Wartość elementu do usunięcia.
 */
void tree::remove_element( int value ) {
    // usuwanie startowego elementu
    if( value == this->get_start_element()->get_value() ) {
        return;
    }
    // wyszukanie elementu do usunięcia
    element* root = this->search_for_element( value );

    this->remove_element( root );
}

/**
 * @brief Usuwa element z drzewa binarnego.
 * @param root Wskaźnik na element do usunięcia.
 */
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
    else if( root->have_right_child() && !root->have_left_child() ) {
        // jeśli usuwany element jest lewym dzieckiem
        if( root->get_previous_element()->is_left_child( root ) ) {
            // ustawienie prawego dziecka w miejsce usuwanego elementu lewe dziecko
            root->get_previous_element()->set_left_element( root->get_right_element() );
        }
        // jeśli usuwany element jest prawym dzieckiem
        else if( root->get_previous_element()->is_right_child( root ) ) {
            // ustawienie prawego dziecka w miejsce usuwanego elementu prawe dziecko
            root->get_previous_element()->set_right_element( root->get_right_element() );
        }
        // ustawienie poprzedniego elementu na element poprzedni usuniętego elementu
        root->get_right_element()->set_previous_element( root->get_previous_element() );
        delete root;
        return;
    }
    // jeśli posiada lewe dziecko
    else if( root->have_left_child() && !root->have_right_child() ) {
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

        // lewy element
        if( element_for_swap->have_left_child() ) {
            element_for_swap = element_for_swap->get_left_element();
            // przejscia w lewo
            while ( element_for_swap->have_left_child() ) {
                element_for_swap = element_for_swap->get_left_element();
            }
            // jeśli jest lewym elementem bez dzieci
            if( !element_for_swap->have_right_child() && !element_for_swap->have_left_child() ) {
                // usunięcie elementu z swojego miejsca w celu wpisania go w miejsce usuniętego elementu
                element_for_swap->get_previous_element()->set_left_element( element_for_swap->get_previous_element() );
                // dołączenie elementu w miejsce usuniętego elementu
                element_for_swap->set_previous_element( root->get_previous_element() );

                if( root->get_previous_element()->is_left_child( root ) ) {
                    // ustawienie lewego dziecka w miejsce usuwanego elementu lewe dziecko
                    root->get_previous_element()->set_left_element( element_for_swap );
                }
                // jeśli usuwany element jest prawym dzieckiem
                else if( root->get_previous_element()->is_right_child( root ) ) {
                    // ustawienie lewego dziecka w miejsce usuwanego elementu prawe dziecko
                    root->get_previous_element()->set_right_element( element_for_swap );
                }
                // dodłączenie lewego dziecka usuniętego elementu
                element_for_swap->set_left_element( root->get_left_element() );
                element_for_swap->get_left_element()->set_previous_element( element_for_swap );
                // odłączenie prawego dziecka usuniętego elementu
                element_for_swap->set_right_element( root->get_right_element() );
                element_for_swap->get_right_element()->set_previous_element( element_for_swap );
                delete root;
                return;
            }
            else if ( element_for_swap->have_right_child() && !element_for_swap->have_left_child() ) {
                // przepięcie prawego dziecka w miejsce nominowanego elementu
                element_for_swap->get_previous_element()->set_left_element( element_for_swap->get_right_element() );
                element_for_swap->get_right_element()->set_previous_element( element_for_swap->get_previous_element() );

                // dołączenie elementu w miejsce usuniętego elementu
                element_for_swap->set_previous_element( root->get_previous_element() );

                if( root->get_previous_element()->is_left_child( root ) ) {
                    // ustawienie lewego dziecka w miejsce usuwanego elementu lewe dziecko
                    root->get_previous_element()->set_left_element( element_for_swap );
                }
                // jeśli usuwany element jest prawym dzieckiem
                else if( root->get_previous_element()->is_right_child( root ) ) {
                    // ustawienie lewego dziecka w miejsce usuwanego elementu prawe dziecko
                    root->get_previous_element()->set_right_element( element_for_swap );
                }
                // dodłączenie lewego dziecka usuniętego elementu
                element_for_swap->set_left_element( root->get_left_element() );
                element_for_swap->get_left_element()->set_previous_element( element_for_swap );
                // odłączenie prawego dziecka usuniętego elementu
                element_for_swap->set_right_element( root->get_right_element() );
                element_for_swap->get_right_element()->set_previous_element( element_for_swap );
                delete root;
                return;
            }
            return;
        }
        // ma prawe dziecko i nie ma lewego
        else if( element_for_swap->have_right_child() && !element_for_swap->have_left_child() ) {
            element_for_swap->set_previous_element( root->get_previous_element() );

            if( root->get_previous_element()->is_left_child( root ) ) {
                // ustawienie lewego dziecka w miejsce usuwanego elementu lewe dziecko
                root->get_previous_element()->set_left_element( element_for_swap );
            }
            // jeśli usuwany element jest prawym dzieckiem
            else if( root->get_previous_element()->is_right_child( root ) ) {
                // ustawienie lewego dziecka w miejsce usuwanego elementu prawe dziecko
                root->get_previous_element()->set_right_element( element_for_swap );
            }
            element_for_swap->set_left_element( root->get_left_element() );
            element_for_swap->get_left_element()->set_previous_element( element_for_swap );
            delete root;
            return;
        }
    }
}

/**
 * @brief Szuka elementu o zadanej wartości.
 * 
 * @param value Wartość elementu do znalezienia.
 * @return element* Wskaźnik do znalezionego elementu.
 */
element* tree::search_for_element(int value) {
    return this->_search_for_element( this->get_start_element(), value );
}

/**
 * @brief Prywatna metoda pomocnicza do szukania elementu o zadanej wartości.
 * 
 * @param root Wskaźnik do korzenia drzewa lub poddrzewa.
 * @param value Wartość elementu do znalezienia.
 * @return element* Wskaźnik do znalezionego elementu, jeśli istnieje; w przeciwnym razie nullptr.
 */
element* tree::_search_for_element( element* root, int value ) {
    if(value < root->get_value()) {
        this->_search_for_element( root->get_left_element(), value );
    }
    else if( value > root->get_value() ) {
        this->_search_for_element( root->get_right_element(), value );
    }
    else {
        return root;
    }
}

/**
 * @brief Wykonuje przejście pre-order drzewa zaczynając od podanego elementu.
 * 
 * @param element Wskaźnik do aktualnego elementu.
 */
void tree::_pre_order(element* element) {
    if (element == nullptr) {
        return;
    }
    std::cout << element->get_value() << " ";
    if (element->have_left_child()) {
        this->_pre_order(element->get_left_element());
    }
    if (element->have_right_child()) {
        this->_pre_order(element->get_right_element());
    }
}

/**
 * @brief Wykonuje przejście pre-order drzewa.
 */
void tree::pre_order() {
    if (this->get_start_element() == nullptr) {
        return;
    }
    this->_pre_order(this->get_start_element());
    std::cout << std::endl;
}

/**
 * @brief Wykonuje przejście in-order drzewa zaczynając od podanego elementu.
 * 
 * @param element Wskaźnik do aktualnego elementu.
 */
void tree::_in_order(element* element) {
    if (element == nullptr) {
        return;
    }
    if (element->have_left_child()) {
        this->_in_order(element->get_left_element());
    }
    std::cout << element->get_value() << " ";
    if (element->have_right_child()) {
        this->_in_order(element->get_right_element());
    }
}

/**
 * @brief Wykonuje przejście in-order drzewa.
 */
void tree::in_order() {
    if (this->get_start_element() == nullptr) {
        return;
    }
    this->_in_order(this->get_start_element());
    std::cout << std::endl;
}

/**
 * @brief Wykonuje przejście post-order drzewa zaczynając od podanego elementu.
 * 
 * @param element Wskaźnik do aktualnego elementu.
 */
void tree::_post_order(element* element) {
    if (element == nullptr) {
        return;
    }
    if (element->have_left_child()) {
        this->_post_order(element->get_left_element());
    }
    if (element->have_right_child()) {
        this->_post_order(element->get_right_element());
    }
    std::cout << element->get_value() << " ";
}

/**
 * @brief Wykonuje przejście post-order drzewa.
 */
void tree::post_order() {
    if (this->get_start_element() == nullptr) {
        return;
    }
    this->_post_order(this->get_start_element());
    std::cout << std::endl;
}

/**
 * @brief Szuka ścieżki do podanego elementu i wyświetla ją.
 * 
 * @param root Wskaźnik do aktualnego elementu.
 */
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

/**
 * @brief Usuwa całe drzewo.
 */
void tree::remove_tree() {
    this->_remove_tree( this->get_start_element() );
    this->start_element_ = nullptr;
}

/**
 * @brief Prywatna metoda pomocnicza do usuwania drzewa zaczynając od podanego elementu.
 * 
 * @param element Wskaźnik do aktualnego elementu.
 */
void tree::_remove_tree( element* element ) {
    if( element->have_left_child() ) {
        this->_remove_tree( element->get_left_element() );
    }
    if( element->have_right_child() ) {
        this->_remove_tree( element->get_right_element() );
    }
    delete element;
}

/**
 * @brief Zapisuje drzewo do pliku tekstowego.
 * 
 * @param path Ścieżka do pliku.
 */
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
    file.close();
}

/**
 * @brief Prywatna metoda pomocnicza do zapisywania drzewa w formacie pre-order do pliku tekstowego.
 * 
 * @param element Wskaźnik do aktualnego elementu.
 * @param file Obiekt pliku.
 */
void tree::_pre_order_save_to_txt( element* element, std::ofstream& file ) {
    file << element->get_value() <<  std::endl;
    if (element->have_left_child()) {
        this->_pre_order_save_to_txt( element->get_left_element(), file );
    }
    if (element->have_right_child()) {
        this->_pre_order_save_to_txt( element->get_right_element(), file);
    }
}

/**
 * @brief Ładuje drzewo z pliku tekstowego.
 * 
 * @param path Ścieżka do pliku.
 */
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
        this->add_element(  std::stoi( line ) );
    }
    file.close();
}

/**
 * @brief Zapisuje drzewo do pliku binarnego.
 * 
 * @param path Ścieżka do pliku.
 */
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
    file.close();
}

/**
 * @brief Prywatna metoda pomocnicza do zapisywania drzewa w formacie pre-order do pliku binarnego.
 * 
 * @param element Wskaźnik do aktualnego elementu.
 * @param file Obiekt pliku.
 */
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

/**
 * @brief Ładuje drzewo z pliku binarnego.
 * 
 * @param path Ścieżka do pliku.
 */
void tree::load_from_file_bin(std::string path) {
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Nie udalo sie otworzyc pliku do zapisu!" << std::endl;
        return;
    }
    this->remove_tree();
    int value;
    while (file.read(reinterpret_cast<char*>(&value), sizeof(value))) {
        this->add_element(value);
    }
    file.close();
}