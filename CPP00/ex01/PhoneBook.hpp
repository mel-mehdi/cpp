#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iostream>
#include <iomanip>

class PhoneBook {
	private:
		Contact contacts[8];
		int current_index;
		int total_contacts;
		std::string getValidInput(std::string& fieldName);
	
	public:
		void addContact();
		void searchContact();
		void displayContactList();
		void displayContact(int index);
		void initialize();
	};

#endif