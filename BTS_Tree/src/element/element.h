#ifndef ELEMENT_H
#define ELEMENT_H

/**
 * @class element
 * @brief Klasa reprezentująca pojedynczy element o określonej wartości oraz wskaźnikach do sąsiednich elementów.
 */
class element {
    private:
        int value_; ///< Wartość przechowywana w elemencie.
        element* left_element_; ///< Wskaźnik na lewy element.
        element* right_element_; ///< Wskaźnik na prawy element.
        element* previous_element_; ///< Wskaźnik na poprzedni element.
    public:
        /**
         * @brief Konstruktor inicjalizujący wartość oraz ustawiający wskaźniki na bieżący obiekt.
         * @param new_value Wartość przypisywana do elementu.
         */
        element(const int new_value);
        
        /**
         * @brief Destruktor klasy element.
         */
        ~element(void);
    
        /**
         * @brief Ustawia nową wartość elementu.
         * @param new_value Nowa wartość do ustawienia.
         */
        void set_value( const int new_value );
        
        /**
         * @brief Pobiera wartość przechowywaną w elemencie.
         * @return Zwraca wartość typu int.
         */
        int get_value(void) const;

        /**
         * @brief Ustawia wskaźnik na lewy element.
         * @param new_left_element Wskaźnik na nowy lewy element.
         */
        void set_left_element( element* new_left_element );
        
        /**
         * @brief Pobiera wskaźnik na lewy element.
         * @return Wskaźnik na lewy element.
         */
        element* get_left_element( void ) const;

        /**
         * @brief Ustawia wskaźnik na prawy element.
         * @param new_right_element Wskaźnik na nowy prawy element.
         */
        void set_right_element( element* new_right_element );
        
        /**
         * @brief Pobiera wskaźnik na prawy element.
         * @return Wskaźnik na prawy element.
         */
        element* get_right_element(void) const;

        /**
         * @brief Ustawia wskaźnik na poprzedni element.
         * @param new_previous_element Wskaźnik na nowy poprzedni element.
         */
        void set_previous_element( element* new_previous_element );
        
        /**
         * @brief Pobiera wskaźnik na poprzedni element.
         * @return Wskaźnik na poprzedni element.
         */
        element* get_previous_element( void ) const;

        /**
        * @brief Sprawdza, czy dany element jest lewym dzieckiem tego elementu.
        * @param element Wskaźnik do elementu do sprawdzenia.
        * @return true jeśli dany element jest lewym elementem potomnym, false w przeciwnym razie.
        */
        bool is_left_child( const element*  element ) const;

         /**
         * @brief Sprawdza, czy dany element jest prawym dzieckiem tego elementu.
         * @param element Wskaźnik do elementu do sprawdzenia.
         * @return true jeśli dany element jest prawym elementem potomnym, false w przeciwnym razie.
         */
        bool is_right_child( const element*  element ) const;

         /**
         * @brief Sprawdza, czy element ma lewego potomka.
         * @return true jeśli element ma lewego potomka, false w przeciwnym razie.
         */
        bool have_left_child( void ) const;

        /**
        * @brief Sprawdza, czy element ma prawego potomka.
        * @return true jeśli element ma prawego potomka, false w przeciwnym razie.
        */
        bool have_right_child( void ) const;
};

#endif // ELEMENT_H