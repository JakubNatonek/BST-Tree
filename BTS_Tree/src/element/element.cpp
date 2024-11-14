#include "element.h"


element::element( const int new_value ) {
    this->value_ = new_value;
    this->left_element_ = this;
    this->right_element_ = this;
    this->previous_element_ = this;
}

element::~element() {
    this->left_element_ = this;
    this->right_element_ = this;
    this->previous_element_ = this;
}

void element::set_value( const int new_value) {
    this->value_ = new_value;
}

int element::get_value() const {
    return this->value_;
}

void element::set_left_element( element* new_left_element ) {
    this->left_element_ = new_left_element;
}

element* element::get_left_element( void ) const {
    return this->left_element_;
}

void element::set_right_element( element* new_right_element ) {
    this->right_element_ = new_right_element;
}

element* element::get_right_element( void ) const {
    return this->right_element_;
}

void element::set_previous_element( element* new_previous_element ) {
    this->previous_element_ = new_previous_element;
}

element* element::get_previous_element( void ) const {
    return this->previous_element_;
}

bool element::is_left_child( const element* element ) const {
    if( this->get_left_element() == element ) {
        return true;
    }
    else if( this->get_right_element() == element ) {
        return false;
    }
    return false;
}
    
bool element::is_right_child(const element* element ) const {
    if( this->get_right_element() == element ) {
        return true;
    }
    else if( this->get_left_element() == element ) {
        return false;
    }
    return false;
}

bool element::have_right_child( void ) const {
    if( this != this->get_right_element() ) {
        return true;
    }
    else {
        return false;
    }
}

bool element::have_left_child( void ) const {
    if( this != this->get_left_element() ) {
        return true;
    }
    else {
        return false;
    }
}