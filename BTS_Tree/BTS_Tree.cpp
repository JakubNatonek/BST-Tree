#include <iostream>
#include "src/element/element.h"
#include "src/tree/tree.h"

int main(int argc, char* argv[]) {

	int test_array[] = {7,3,1,2,5,4,6,10,9,8,12,13,21,14,15,35,32,34};
	
	tree* tst = new tree();
    
	for (int i = 0; i < std::size(test_array); i++) {
		tst->add_element( test_array[i] );
	}
	
	int choice;
	bool running = true;
	int temp;
	std::string path = "";
	while (running) {
		// Wyswietlanie menu
		std::cout << "Menu:\n";
		std::cout << "1. Wczytaj drzewo z pliku\n";
		std::cout << "2. Zapisz drzewo do pliku\n";
		std::cout << "3. Dodaj wartosc do drzewa\n";
		std::cout << "4. Usun wartosc z drzewa\n";

		std::cout << "5. Wypisz drzewo\n";
		std::cout << "6. Szukaj drogi do podanego elementu,\n";
		std::cout << "7. Usun cale drzewo,\n";
		std::cout << "8. Wyjdz\n";
		std::cout << "Wybierz opcje: ";
		std::cin >> choice;
		std::cout << "" << std::endl;

		switch (choice) {
			case 1:
				std::cout << "Podaj sciezke do pliku: " << std::endl;
				std::cin >> path;
				std::cout << "Jaki typ pliku? 1. zapisany binarnie, 2. zapisany cyfrowo:" << std::endl;
				std::cin >> temp;
				if (temp == 1) {
					//funkcja binarna
					tst->load_from_file_bin(path);
				}
				else {
					//funkcja cyfrowa
					tst->load_from_file_txt(path);
				}
				std::cout << "" << std::endl;
				break;
			case 2:
				std::cout << "Podaj sciezke do pliku: " << std::endl;
				std::cin >> path;
				std::cout << "Jaki typ pliku? 1. zapisany binarnie, 2. zapisany cyfrowo:" << std::endl;
				std::cin >> temp;
				if (temp == 1) {
					//funkcja binarna
					tst->save_to_file_bin( path );
				}
				else {
					//funkcja cyfrowa
					tst->save_to_file_txt( path );
				}
				std::cout << "" << std::endl;
				break;
			case 3:
				std::cout << "Podaj cyfre do dodania:" << std::endl;
				std::cin>>temp;
				tst->add_element(temp);
				std::cout << "" << std::endl;
				break;
			case 4:
				std::cout << "Podaj cyfre do usuniecia:" << std::endl;
				std::cin >> temp;
				tst->remove_element(temp);
				std::cout << "" << std::endl;
				break;
			case 5:
				std::cout << "1. Przejdz drzewa metoda post-order\n";
				std::cout << "2. Przejdz drzewa metoda in-order\n";
				std::cout << "3. Przejdz drzewa metoda pre-order\n";
				std::cout << "Wybierz opcje: ";
				std::cin >> temp;
				
				switch (temp) {
					case 1:
						std::cout << "Przejdz drzewa metoda post-order\n";
						tst->post_order();
						break;
					case 2:
						std::cout << "Przejdz drzewa metoda in-order\n";
						tst->in_order();
						break;
					case 3:
						std::cout << "Przejdz drzewa metoda pre-order\n";
						tst->pre_order();
						break;
					default:
						break;
				}
				std::cout << "" << std::endl;
				break;
			case 6:
				std::cout << "Podaj cyfre do znalezienia ścieżki:" << std::endl;
				std::cin >> temp;
				tst->search_for_path_to_element( tst->search_for_element(temp) );
				std::cout << "" << std::endl;
				break;
			case 7:
				tst->remove_tree();
				break;
			case 8:
				running = false;
				break;
			default:
				std::cout << "Niepoprawna opcja! Sprobuj ponownie." << std::endl;
		}
	}
	
    return 0;
}
