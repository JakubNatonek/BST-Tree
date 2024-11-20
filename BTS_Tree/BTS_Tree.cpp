#include <iostream>
#include "src/element/element.h"
#include "src/tree/tree.h"

int main(int argc, char* argv[]) {

    element* right = new element(12);
    element* left = new element(13);

    tree* tst = new tree(10);
    tst->add_element(left);
    tst->add_element(right);

    for( int i = 1; i <= 10; i += 2 ) {
        tst->add_element( new element( i ) );
    }



    int choice;
    bool running = true;
    int temp =0;
    while (running) {
        // Wyœwietlanie menu
        std::cout << "Menu:\n";
        std::cout << "1. Wczytaj drzewo z pliku\n";
        std::cout << "2. Zapisz drzewo do pliku\n";
        std::cout << "3. Dodaj wartosc do drzewa\n";
        std::cout << "4. Usun wartosc z drzewa\n";
        std::cout << "5. Przejdz drzewa metoda post-order\n";
        std::cout << "6. Przejdz drzewa metoda in-order\n";
        std::cout << "7. Przejdz drzewa metoda pre-order\n";
        std::cout << "8. Wypisz drzewo\n";
        std::cout << "9. Wyjdz\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;
        std::cout<<""<<std::endl;
        
        switch (choice) {
        case 1:
            std::cout<<"Jaki typ pliku? 1. zapisany binarnie, 2. zapisany cyfrowo.";
            std::cin>>temp;
            if (temp == 1)
            {
                //funkcja binarna
            }
            else
            {
                //funkcja cyfrowa
            }
            std::cout << "" << std::endl;
            break;
        case 2:
            std::cout << "Jaki typ pliku? 1. zapisany binarnie, 2. zapisany cyfrowo.";
            std::cin >> temp;
            if (temp == 1)
            {
                //funkcja binarna
            }
            else
            {
                //funkcja cyfrowa
            }
            std::cout << "" << std::endl;
            break;
        case 3:
            //std::cin>>temp;
            //tst->add_element(temp);
            std::cout << "" << std::endl;
            break;
        case 4:
            std::cin >> temp;
            tst->remove_element(temp);
            std::cout << "" << std::endl;
            break;
        case 5:
            tst->post_order();
            std::cout << "" << std::endl;
            break;
        case 6:
            tst->in_order();
            std::cout << "" << std::endl;
            break;
        case 7:
            tst->pre_order();
            std::cout << "" << std::endl;
            break;
        case 8:
            tst->show_tree();
            std::cout << "" << std::endl;
            break;
        case 9:
            running = false;
            break;
        default:
            std::cout << "Niepoprawna opcja! Spróbuj ponownie.\n";
        }
    }

    return 0;

    
    return 0;
}
