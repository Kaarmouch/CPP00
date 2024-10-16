#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	already_in = 0;
	last_idx = -1;
}

PhoneBook::PhoneBook(const PhoneBook &phone_book)
{
	this->already_in = phone_book.already_in;
	this->last_idx = phone_book.last_idx;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::addContact()
{
	last_idx = (last_idx + 1) % 8;
	contacts[last_idx].fillContact();
	if (already_in < 8)
		already_in++;
}

void	PhoneBook::displayContact()
{
	std::cout << "╔══════════╦══════════╦══════════╦══════════╗" << std::endl;
	std::cout << "║    ID    ║First name║ Lastname ║ Nickname ║" << std::endl;
	for (int i = 0; i < already_in; i++)
	{
		contacts[i].displaySummary(i);
		std::cout << std::endl;
	}
	std::cout << "╚══════════╩══════════╩══════════╩══════════╝" << std::endl;
}

void	PhoneBook::displayContactDetail(int idx)
{
	std::cout << already_in << std::endl;
	if (idx >= already_in || idx < 0)
		std::cout << "Index :" << idx << " introuvable" << std::endl;
	else
		contacts[idx].displayDetails();
}

