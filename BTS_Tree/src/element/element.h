#ifndef ELEMENT_H
#define ELEMENT_H

/**
 * @class element
 * @brief Klasa reprezentująca pojedynczy element o określonej wartości oraz wskaźnikach do sąsiednich elementów.
 */
class element {
private:
    int value; ///< Wartość przechowywana w elemencie.
    element *left_element; ///< Wskaźnik na lewy element.
    element *right_element; ///< Wskaźnik na prawy element.
    element *previus_element; ///< Wskaźnik na poprzedni element.

public:
    /**
     * @brief Konstruktor inicjalizujący wartość oraz ustawiający wskaźniki na bieżący obiekt.
     * @param value Wartość przypisywana do elementu.
     */
    element(int value);

    /**
     * @brief Destruktor klasy element.
     */
    ~element(void);

    /**
     * @brief Pobiera wartość przechowywaną w elemencie.
     * @return Zwraca wartość typu int.
     */
    int get_value(void);

    /**
     * @brief Ustawia nową wartość elementu.
     * @param value Nowa wartość do ustawienia.
     */
    void set_value(int value);

    /**
     * @brief Ustawia wskaźnik na lewy element.
     * @param left_element Wskaźnik na nowy lewy element.
     */
    void set_left_element(element *left_element);

    /**
     * @brief Pobiera wskaźnik na lewy element.
     * @return Wskaźnik na lewy element.
     */
    element* get_left_element(void);

    /**
     * @brief Ustawia wskaźnik na prawy element.
     * @param right_element Wskaźnik na nowy prawy element.
     */
    void set_right_element(element *right_element);

    /**
     * @brief Pobiera wskaźnik na prawy element.
     * @return Wskaźnik na prawy element.
     */
    element* get_right_element(void);

    /**
     * @brief Ustawia wskaźnik na poprzedni element.
     * @param previus_element Wskaźnik na nowy poprzedni element.
     */
    void set_previus_element(element *previus_element);

    /**
     * @brief Pobiera wskaźnik na poprzedni element.
     * @return Wskaźnik na poprzedni element.
     */
    element* get_previus_element(void);
};

#endif // ELEMENT_H
