#pragma once

#include "Contact.hpp"
#include <iostream>
#include <iomanip> // std::setw
#include <string>
#include <cctype> // pour std::isspace
#include <limits>

class	PhoneBook
{
	private:
		int	already_in;
		int	last_idx;
		Contact contacts[8];
	public:
		PhoneBook();
		PhoneBook(const PhoneBook &phone_book);
		~PhoneBook();
		void	addContact();
		void	displayContact();
		void	displayContactDetail(int i);
};
