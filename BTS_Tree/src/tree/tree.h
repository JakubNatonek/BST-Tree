#ifndef TREE_H
#define TREE_H

#include "../element/element.h"
#include <fstream>

/**
 * @class tree
 * @brief Klasa reprezentująca drzewo binarne, umożliwiająca dodawanie, usuwanie i zarządzanie elementami drzewa.
 */
class tree {
    private:
        element* start_element_; ///< Wskaźnik na korzeń drzewa binarnego.

        /**
         * @brief Prywatna metoda pomocnicza dodająca nowy element do drzewa.
         * @param new_element Wskaźnik na nowy element.
         * @param root Wskaźnik na korzeń drzewa lub poddrzewa.
         */
        void _add_element( element* new_element, element* root );

        /**
        * @brief Prywatna metoda pomocnicza do przechodzenia drzewa w porządku pre-order.
        * @param element Wskaźnik na aktualny element.
        */
        void _pre_order(element* element);

         /**
         * @brief Prywatna metoda pomocnicza do przechodzenia drzewa w porządku in-order.
         * @param element Wskaźnik na aktualny element.
         */
        void _in_order(element* element);

         /**
         * @brief Prywatna metoda pomocnicza do przechodzenia drzewa w porządku post-order.
         * @param element Wskaźnik na aktualny element.
         */
        void _post_order(element* element);
 
        /**
         * @brief Prywatna metoda pomocnicza do szukania elementu o zadanej wartości.
         * @param root Wskaźnik na korzeń drzewa lub poddrzewa.
         * @param value Wartość elementu do znalezienia.
         * @return element* Wskaźnik na znaleziony element, jeśli istnieje, w przeciwnym razie nullptr.
         */
        element* _search_for_element( element* root, int value );

         /**
         * @brief Prywatna metoda pomocnicza do usuwania drzewa zaczynając od podanego elementu.
         * @param element Wskaźnik na aktualny element.
         */
        void _remove_tree( element* element );

         /**
         * @brief Prywatna metoda pomocnicza do zapisywania drzewa w formacie pre-order do pliku tekstowego.
         * @param element Wskaźnik na aktualny element.
         * @param file Referencja do obiektu pliku.
         */
        void _pre_order_save_to_txt( element* element, std::ofstream& file );

         /**
         * @brief Prywatna metoda pomocnicza do zapisywania drzewa w formacie pre-order do pliku binarnego.
         * @param element Wskaźnik na aktualny element.
         * @param file Referencja do obiektu pliku.
         */
         void _pre_order_save_to_bin(element* element, std::ofstream& file);
    public:
        /**
         * @brief Konstruktor domyślny tworzący nowe drzewo.
         */
        tree(void);

        /**
         * @brief Konstruktor tworzący nowe drzewo z początkowym elementem o zadanej wartości.
         * @param new_value Wartość korzenia drzewa.
         */
        tree(int const new_value);

        /**
         * @brief Destruktor zwalniający zasoby drzewa.
         */
        ~tree(void);

        /**
         * @brief Ustawia nowy element początkowy drzewa.
         * @param new_start_element Wskaźnik na nowy element początkowy.
         */
        void set_start_element(element* new_start_element);

        /**
         * @brief Ustawia nowy element początkowy drzewa z wartością.
         * @param new_value Wartość nowego elementu początkowego.
         */
        void set_start_element(int new_value);

        /**
         * @brief Zwraca wskaźnik na element początkowy drzewa.
         * @return element* Wskaźnik na element początkowy drzewa.
         */
        element* get_start_element(void) const;

        /**
         * @brief Dodaje nowy element do drzewa.
         * @param new_element Wskaźnik na nowy element.
         */
        void add_element(element* new_element);

        /**
         * @brief Dodaje nowy element do drzewa o zadanej wartości.
         * @param value Wartość nowego elementu.
         */
        void add_element(int value);

        /**
         * @brief Usuwa element z drzewa zaczynając od podanego elementu.
         * @param root Wskaźnik na element od którego zaczyna się usuwanie.
         */
        void remove_element(element* root);

        /**
         * @brief Usuwa element z drzewa o zadanej wartości.
         * @param value Wartość elementu do usunięcia.
         */
        void remove_element(int value);

        /**
         * @brief Usuwa całe drzewo.
         */
        void remove_tree();

        /**
         * @brief Szuka elementu o zadanej wartości.
         * @param value Wartość elementu do znalezienia.
         * @return element* Wskaźnik na znaleziony element, jeśli istnieje.
         */
        element* search_for_element(int value);

        /**
         * @brief Szuka ścieżki do podanego elementu i wyświetla ją.
         * @param root Wskaźnik na aktualny element.
         */
        void search_for_path_to_element(element* root);

        /**
         * @brief Zapisuje drzewo do pliku tekstowego.
         * @param path Ścieżka do pliku.
         */
        void save_to_file_txt(std::string path);

        /**
         * @brief Ładuje drzewo z pliku tekstowego.
         * @param path Ścieżka do pliku.
         */
        void load_from_file_txt(std::string path);

        /**
         * @brief Zapisuje drzewo do pliku binarnego.
         * @param path Ścieżka do pliku.
         */
        void save_to_file_bin(std::string path);
 
        /**
         * @brief Ładuje drzewo z pliku binarnego.
         * @param path Ścieżka do pliku.
         */
        void load_from_file_bin(std::string path);

        /**
         * @brief Wykonuje przejście pre-order drzewa.
         */
        void pre_order();

        /**
         * @brief Wykonuje przejście in-order drzewa.
         */
        void in_order();

        /**
         * @brief Wykonuje przejście post-order drzewa.
         */
        void post_order();
};

#endif // TREE_H