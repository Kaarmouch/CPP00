#pragma once

#include <string>

class Contact
{
	private:
		std::string first_name, last_name, nickname, phone_number, darkest_secret;
	public:
		Contact();
		Contact(const Contact &contact);
		~Contact();
		void	fillContact();
		void	displaySummary(int idx);
		void	displayDetails();
};	
