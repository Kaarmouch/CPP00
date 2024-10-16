#include "PhoneBook.hpp"

int main() 
{
	PhoneBook phoneBook;
	std::string command;
	int index;

	while (true) 
	{
		std::cout << "Entrez une commande (ADD, SEARCH, EXIT) : ";
		std::cin >> command;
		if (command == "ADD") 
			phoneBook.addContact();
		else if (command == "SEARCH")
		{
			phoneBook.displayContact();
			std::cout << "Entrez l'index du contact à afficher : ";
			std::cin >> index;
			std::cin.ignore(); // Ignorer le caractère de nouvelle ligne restant
			phoneBook.displayContactDetail(index);

		} 
		else if (command == "EXIT") 
		{
			break;

		}
	       	else 
			std::cout << "Commande non reconnue." << std::endl;
	}
    return 0;
}
