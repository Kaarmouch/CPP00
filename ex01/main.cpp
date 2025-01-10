#include "PhoneBook.hpp"

int main() 
{
	PhoneBook phoneBook;
	std::string command;
	std::string input;
	int index;
	bool validInput;

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
			std::cin >> input;
			validInput = true;
			for (size_t i = 0; i < input.length(); i++)
			{
				if (!std::isdigit(static_cast<unsigned char>(input[i])))
				{
					validInput = false;
					break;
				}
			}
			if (validInput)
			{
				index = 0;
				for (size_t i = 0; i < input.length(); i++)
					index = index * 10 + (input[i] - '0');
				phoneBook.displayContactDetail(index);
			}
			else 
				std::cout << "Erreur : l'index doit être un entier valide." << std::endl;
		} 
		else if (command == "EXIT") 
			break;
	       	else 
			std::cout << "Commande non reconnue." << std::endl;
	}
	return 0;
}
