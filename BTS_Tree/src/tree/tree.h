#ifndef TREE_H
#define TREE_H

#include "../element/element.h"
#include <fstream>

/**
 * @class tree
 * @brief Klasa reprezentująca drzewo binarne, umożliwiająca dodawanie, usuwanie i zarządzanie elementami drzewa.
 */
class tree {
    private:
        element* start_element_; ///< Wskaźnik na korzeń drzewa binarnego.
        void _add_element( element* new_element, element* root );
        void _show_tree( element* element );
        void _pre_order(element* element);
        void _in_order(element* element);
        void _post_order(element* element);

        element* _search_for_element( element* root, int value );
        void _remove_tree( element* element );

        void _pre_order_save_to_txt( element* element, std::ofstream& file );
    public:
        tree( void );
        
        /**
         * @brief Konstruktor tworzący nowe drzewo z początkowym elementem o zadanej wartości.
         * @param new_value Wartość korzenia drzewa.
         */
        tree( int const new_value );
        
        /**
         * @brief Destruktor zwalniający zasoby drzewa.
         */
        ~tree( void );

        void set_start_element( element* new_start_element );
        void set_start_element( int new_value );
        element *get_start_element( void ) const;
        void add_element( element* new_element );
        void add_element( int value );
        void show_tree( void );
        void remove_element( element* root );
        void remove_element( int value );
        void remove_tree();
        element* search_for_element( int value );
        void search_for_path_to_element( element* root );
        void save_to_file_txt();
        void load_from_file_txt( std::string path );

        void pre_order();
        void in_order();
        void post_order();
};

#endif // TREE_H