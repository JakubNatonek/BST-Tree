#ifndef TREE_H
#define TREE_H

#include "../element/element.h"

/**
 * @class tree
 * @brief Klasa reprezentująca drzewo binarne, umożliwiająca dodawanie, usuwanie i zarządzanie elementami drzewa.
 */
class tree {
private:
    element *start_element; ///< Wskaźnik na korzeń drzewa binarnego.

public:
    /**
     * @brief Konstruktor tworzący nowe drzewo z początkowym elementem o zadanej wartości.
     * @param value Wartość korzenia drzewa.
     */
    tree(int value);

    /**
     * @brief Destruktor zwalniający zasoby drzewa.
     */
    ~tree();

    /**
     * @brief Dodaje nowy element do drzewa binarnego.
     * @param root Wskaźnik na korzeń lub bieżący element, od którego rozpoczyna się dodawanie.
     * @param value Wartość nowego elementu do dodania.
     */
    void add_element(element *root, int value);

    /**
     * @brief Usuwa element o zadanej wartości z drzewa binarnego.
     * @param root Wskaźnik na korzeń lub bieżący element, od którego rozpoczyna się usuwanie.
     * @param value Wartość elementu do usunięcia.
     */
    void remove_element(element *root, int value);

    /**
     * @brief Usuwa całe drzewo, zwalniając wszystkie zasoby.
     */
    void remove_tree();

    /**
     * @brief Wyszukuje element w drzewie.
     * @todo Implementacja wyszukiwania elementu.
     */
    void search_for_element();

    /**
     * @brief Zapisuje drzewo do pliku.
     * @todo Implementacja funkcji zapisu drzewa do pliku.
     */
    void save_to_fille();

    /**
     * @brief Wczytuje drzewo z pliku.
     * @todo Implementacja funkcji wczytywania drzewa z pliku.
     */
    void read_from_fille();
};

#endif // TREE_H
