/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:58:45 by lray              #+#    #+#             */
/*   Updated: 2023/06/24 03:48:00 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	_nbrContacts = 0;
}
PhoneBook::~PhoneBook() {

}

int PhoneBook::getNbrContacts() {
	return (this->_nbrContacts);
}

void PhoneBook::addContact(
	std::string firstname,
	std::string lastname,
	std::string nickname,
	std::string phone,
	std::string secret
) {
	if (_nbrContacts < NBR_CONTACT)
	{
		contacts[_nbrContacts] = Contact(firstname, lastname, nickname, phone, secret);
		_nbrContacts++;
	} else {
		for (int i = 0; i < (NBR_CONTACT - 1); i++) {
			contacts[i] = contacts[i + 1];
		}
		contacts[7] = Contact(firstname, lastname, nickname, phone, secret);
	}
}

void PhoneBook::showContacts() {
	for (int i = 0; i < _nbrContacts; i++)
	{
		std::cout << "#" << (i + 1) << " : " << contacts[i].getFirstname();
		std::cout << " " << contacts[i].getLastname() << " (" << contacts[i].getNickname();
		std::cout << ") " << std::endl;
	}
}
void PhoneBook::showContact(int id)
{
	std::cout << "First name : " << contacts[id].getFirstname() << std::endl;
	std::cout << "Last name : " << contacts[id].getLastname() << std::endl;
	std::cout << "Nickname : " << contacts[id].getNickname() << std::endl;
	std::cout << "Phone number : " << contacts[id].getPhone() << std::endl;
	std::cout << "Secret : " << contacts[id].getSecret() << std::endl;
}
