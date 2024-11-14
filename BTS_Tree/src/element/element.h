#ifndef ELEMENT_H
#define ELEMENT_H


class element {
    private:
        int value_;
        element* left_element_;
        element* right_element_;
        element* previous_element_;
    public:
        element(const int new_value);
        ~element(void);
    
        void set_value( const int new_value );
        int get_value(void) const;

        void set_left_element( element* new_left_element );
        element* get_left_element( void ) const;

        void set_right_element( element* new_right_element );
        element* get_right_element(void) const;

        void set_previous_element( element* new_previous_element );
        element* get_previous_element( void ) const;

        bool is_left_child( const element*  element ) const;
        bool is_right_child( const element*  element ) const;

        bool have_left_child( void ) const;
        bool have_right_child( void ) const;
};

#endif