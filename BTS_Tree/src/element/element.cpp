#include "element.h"

/* *
 * @brief Konstruktor ustawiający początkową wartość oraz inicjalizujący wskaźniki na bieżący obiekt.
 * @param new_value Wartość przypisywana do elementu.
 */
element::element( const int new_value ) {
    this->value_ = new_value;
    this->left_element_ = this;
    this->right_element_ = this;
    this->previous_element_ = this;
}

/**
 * @brief Destruktor klasy element.
 */
element::~element() {
    this->left_element_ = this;
    this->right_element_ = this;
    this->previous_element_ = this;
}

/**
 * @brief Ustawia nową wartość elementu.
 * @param new_value Nowa wartość przypisywana do elementu.
 */
void element::set_value( const int new_value) {
    this->value_ = new_value;
}

/**
 * @brief Pobiera wartość elementu.
 * @return Wartość typu int przechowywana w obiekcie.
 */
int element::get_value() const {
    return this->value_;
}

/**
 * @brief Ustawia wskaźnik na lewy element.
 * @param new_left_elemen Wskaźnik na lewy element.
 */
void element::set_left_element( element* new_left_element ) {
    this->left_element_ = new_left_element;
}

/**
 * @brief Pobiera wskaźnik na lewy element.
 * @return Wskaźnik na lewy element.
 */
element* element::get_left_element( void ) const {
    return this->left_element_;
}

/**
 * @brief Ustawia wskaźnik na prawy element.
 * @param new_right_element Wskaźnik na lewy element.
 */
void element::set_right_element( element* new_right_element ) {
    this->right_element_ = new_right_element;
}

/**
 * @brief Pobiera wskaźnik na prawy element.
 * @return Wskaźnik na prawy element.
 */
element* element::get_right_element( void ) const {
    return this->right_element_;
}

/**
 * @brief Ustawia wskaźnik na poprzedni element.
 * @param new_previous_element Wskaźnik na poprzedni element.
 */
void element::set_previous_element( element* new_previous_element ) {
    this->previous_element_ = new_previous_element;
}

/**
 * @brief Pobiera wskaźnik na poprzedni element.
 * @return Wskaźnik na poprzedni element.
 */
element* element::get_previous_element( void ) const {
    return this->previous_element_;
}

/** 
 * @brief Sprawdza, czy dany element jest lewym dzieckiem tego elementu.
 *
 * @param element Wskaźnik do elementu do sprawdzenia.
 * @return true jeśli dany element jest lewym elementem potomnym, false w przeciwnym razie.
 */
bool element::is_left_child( const element* element ) const {
    if( this->get_left_element() == element ) {
        return true;
    }
    else if( this->get_right_element() == element ) {
        return false;
    }
    return false;
}
 
/** 
 * @brief Sprawdza, czy dany element jest właściwym dzieckiem tego elementu. 
 * @param element Wskaźnik do elementu do sprawdzenia. 
 * @return prawdziwe, jeśli dany element jest właściwym elementem potomnym, false w przeciwnym razie. 
 */   
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