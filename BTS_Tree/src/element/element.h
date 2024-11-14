#ifndef ELEMENT_H
#define ELEMENT_H


class element {
    private:
        int value;
        element *left_element;
        element *right_element;
        element *previus_element;
    public:
        element(int value);
        ~element(void);

        int get_value(void);
        void set_value(int value);

        void set_left_element(element *left_element);
        element* get_left_element(void);

        void set_right_element(element *right_element);
        element* get_right_element(void);

        void set_previus_element(element *previus_element);
        element* get_previus_element(void);
};

#endif