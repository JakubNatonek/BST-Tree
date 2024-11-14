/**
 * @class element
 * @brief Klasa reprezentująca pojedynczy element z wartością oraz wskaźnikami do innych elementów.
 */
class element {
public:
    /**
     * @brief Konstruktor ustawiający początkową wartość oraz inicjalizujący wskaźniki na bieżący obiekt.
     * @param value Wartość przypisywana do elementu.
     */
    element(int value);

    /**
     * @brief Destruktor klasy element.
     */
    ~element();

    /**
     * @brief Pobiera wartość elementu.
     * @return Wartość typu int przechowywana w obiekcie.
     */
    int get_value();

    /**
     * @brief Ustawia nową wartość elementu.
     * @param value Nowa wartość przypisywana do elementu.
     */
    void set_value(int value);

    /**
     * @brief Ustawia wskaźnik na lewy element.
     * @param left_element Wskaźnik na lewy element.
     */
    void set_left_element(element *left_element);

    /**
     * @brief Pobiera wskaźnik na lewy element.
     * @return Wskaźnik na lewy element.
     */
    element* get_left_element();

    /**
     * @brief Ustawia wskaźnik na prawy element.
     * @param right_element Wskaźnik na prawy element.
     */
    void set_right_element(element *right_element);

    /**
     * @brief Pobiera wskaźnik na prawy element.
     * @return Wskaźnik na prawy element.
     */
    element* get_right_element();

    /**
     * @brief Ustawia wskaźnik na poprzedni element.
     * @param previus_element Wskaźnik na poprzedni element.
     */
    void set_previus_element(element *previus_element);

    /**
     * @brief Pobiera wskaźnik na poprzedni element.
     * @return Wskaźnik na poprzedni element.
     */
    element* get_previus_element();

private:
    int value;
    element* left_element; 
    element* right_element; 
    element* previus_element; 
};
