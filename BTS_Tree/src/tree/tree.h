#ifndef TREE_H
#define TREE_H

#include "../element/element.h"

class tree {
    private:
        int size;
        element* start_element_;
        void _add_element( element* new_element, element* root );
        void _show_tree( element* element );

        element* _search_for_element( element* root, int value );

    public:
        tree( void );
        tree( int const new_value );
        ~tree( void );

        void set_start_element( element* new_start_element );
        element *get_start_element( void ) const;
        
        void add_element( element* new_element);
        void show_tree( void );
        
        void remove_element( int value );
        void remove_tree();
        element* search_for_element( int value );
        void save_to_file();
        void read_from_file();
};

#endif