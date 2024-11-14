#include "tree.h"
#include "../element/element.h"

tree::tree(int value) {
    this->start_element = new element(value);
}

tree::~tree() {

}

void tree::add_element(element *root, int value) {
    if(value < root->get_value()) { //left
        if(root == root->get_left_element()) {
            element *temporary = new element(value);//przerub na element zamiast value
            temporary->set_previus_element(root);
            root->set_left_element(temporary);
            return;
        }
        add_element(root->get_left_element(), value);
    }
    else { //right
        if(root == root->get_right_element()) {
            element *temporary = new element(value);
            temporary->set_previus_element(root);
            root->set_right_element(temporary);
            return;
        }
        add_element(root->get_right_element(), value);
    }
}


void tree::remove_element(element *root, int value) {
    if(value < root->get_value()) { //left
        add_element(root->get_left_element(), value);
    }
    else if(value > root->get_value()){ //right
        add_element(root->get_right_element(), value);
    }
    else if (value == root->get_value()) {
        if( root->get_previus_element()->get_left_element() == root ) {
            root->get_previus_element()->set_left_element(root->get_previus_element());
         
        }
    }
}