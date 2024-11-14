#ifndef TREE_H
#define TREE_H

class tree {
    private:
        element *start_element;
    public:
        tree(int value);
        ~tree();
        void add_element(element *root = this->start_element, int value);
        void remove_element();
        void remove_tree();
        void search_for_element();
        void save_to_fille();
        void read_from_fille();
}

#endif