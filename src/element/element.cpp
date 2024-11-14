#include "element.h"


element::element(int value) {
    this->value = value;
    this->left_element = this;
    this->right_element = this;
    this->previus_element = this;
}

element::~element() {
}

void element::set_left_element(element left_element) {
    this->left_element = left_element;
}

element element::get_left_element(void) {
    return this->left_element;
}

void element::set_right_element(element right_element) {
    this->right_element = right_element;
}

element element::get_right_element(void) {
    return this->right_element;
}

void element::set_previus_element(element previus_element) {
    this->previus_element = previus_element;
}

element element::get_previus_element(void) {
    return this->previus_element;
}