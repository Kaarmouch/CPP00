#include "PhoneBook.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

Contact::Contact(const Contact &contact)
{
	this->first_name = contact.first_name;
	this->last_name = contact.last_name;
	this->nickname = contact.nickname;
	this->phone_number = contact.phone_number;
	this->darkest_secret = contact.darkest_secret;
}

static bool isNumeric(const std::string& str)
{
	int	i = 0;
        while (i < (int)str.length())
        {
                if (!std::isdigit(str[i]))
                {
                        return false; // Si un caractère n'est pas un chiffre, on retourne false
                }
		i++;
        }
        return true; // Tous les caractères sont des chiffres
}

static std::string	userPromptTest(std::string question)
{
	std::string	str;

	std::cout << question << std::setw(16 - question.length()) << ": ";
	while (true)
	{
		if (!std::cin.eof())
			std::cin >> str;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (str.empty())
		{
			std::cout << "Promte vide non accepté. Veuillez réessayer." << std::endl;
		}
		else 
			return str;
	}
}

void	Contact::fillContact()
{
	first_name = last_name = nickname = phone_number = darkest_secret = "";

	first_name = userPromptTest("First Name");

	last_name = userPromptTest("Last Name");

	nickname = userPromptTest("Nickname");

	// Saisie et validation du numéro de téléphone
	while (true)
	{
		std::cout << "Phone Number   : ";
		std::cin >> phone_number;

		if (!isNumeric(phone_number)) 
			std::cout << "Le numéro invalide" << std::endl;
		else
			break;
	}

	std::cout << "Darkest Secret : ";
	std::cin >> darkest_secret;

	std::cout << "\nContact \"" << first_name << "\" ajouté avec succès\n";
}


void Contact::displayDetails()
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

static std::string trunc(std::string str)
{
        if (int(str.length()) > 10)
                return str.substr(0, 9) + ".";
        return str;

}

void	Contact::displaySummary(int idx)
{
	std::cout << std::setw(10) << idx << "|"
		<< std::setw(10) << trunc(first_name) << "|"
		<< std::setw(10) << trunc(last_name) << "|"
		<< std::setw(10) << trunc(nickname) << std::endl;
}
