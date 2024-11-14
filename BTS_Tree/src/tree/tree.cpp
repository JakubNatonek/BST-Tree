#include "tree.h"
#include "../element/element.h"

/**
 * @brief Konstruktor klasy tree tworzący nowe drzewo z początkowym elementem o zadanej wartości.
 * @param value Wartość pierwszego elementu drzewa.
 */
tree::tree(int value) {
    this->start_element = new element(value);
}

/**
 * @brief Destruktor klasy tree.
 */
tree::~tree() {
}

/**
 * @brief Dodaje nowy element do drzewa binarnego.
 * @param root Korzeń lub bieżący element drzewa, od którego rozpoczyna się dodawanie.
 * @param value Wartość nowego elementu do dodania.
 */
void tree::add_element(element *root, int value) {
    if(value < root->get_value()) { // dodajemy do lewego poddrzewa
        if(root == root->get_left_element()) {
            element *temporary = new element(value); // tworzy nowy element
            temporary->set_previus_element(root);
            root->set_left_element(temporary);
            return;
        }
        add_element(root->get_left_element(), value);
    }
    else { // dodajemy do prawego poddrzewa
        if(root == root->get_right_element()) {
            element *temporary = new element(value);
            temporary->set_previus_element(root);
            root->set_right_element(temporary);
            return;
        }
        add_element(root->get_right_element(), value);
    }
}

/**
 * @brief Usuwa element o zadanej wartości z drzewa binarnego.
 * @param root Korzeń lub bieżący element drzewa, od którego rozpoczyna się usuwanie.
 * @param value Wartość elementu do usunięcia.
 */
void tree::remove_element(element *root, int value) {
    if(value < root->get_value()) { // przeszukiwanie w lewym poddrzewie
        remove_element(root->get_left_element(), value);
    }
    else if(value > root->get_value()) { // przeszukiwanie w prawym poddrzewie
        remove_element(root->get_right_element(), value);
    }
    else if (value == root->get_value()) { // element znaleziony
        if(root->get_previus_element()->get_left_element() == root) {
            root->get_previus_element()->set_left_element(root->get_previus_element());
        }
        // Można dodać kod usuwający element i przestawiający wskaźniki
    }
}
