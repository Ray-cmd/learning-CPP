/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:42:38 by lray              #+#    #+#             */
/*   Updated: 2023/06/24 03:20:26 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){

}
Contact::Contact(
	std::string firstname,
	std::string lastname,
	std::string nickname,
	std::string phone,
	std::string secret
	) {
		this->setFirstname(firstname);
		this->setLastname(lastname);
		this->setNickname(nickname);
		this->setPhone(phone);
		this->setSecret(secret);
	}
Contact::Contact(const Contact& other) {
	this->setFirstname(other._firstname);
	this->setLastname(other._lastname);
	this->setNickname(other._nickname);
	this->setPhone(other._phone);
	this->setSecret(other._secret);
}
Contact& Contact::operator=(const Contact& other) {
	this->setFirstname(other._firstname);
	this->setLastname(other._lastname);
	this->setNickname(other._nickname);
	this->setPhone(other._phone);
	this->setSecret(other._secret);
	return *this;
}
Contact::~Contact() {

}

std::string Contact::getFirstname(void) {
	return (this->_firstname);
}
std::string Contact::getLastname(void) {
	return (this->_lastname);
}
std::string Contact::getNickname(void) {
	return (this->_nickname);
}
std::string Contact::getPhone(void) {
	return (this->_phone);
}
std::string Contact::getSecret(void) {
	return (this->_secret);
}

void Contact::setFirstname(std::string firstname) {
	if (firstname.empty())
		throw std::invalid_argument("Parameters cannot be empty.");
	this->_firstname = firstname;
}
void Contact::setLastname(std::string lastname) {
	if (lastname.empty())
		throw std::invalid_argument("Parameters cannot be empty.");
	this->_lastname = lastname;
}
void Contact::setNickname(std::string nickname) {
	if (nickname.empty())
		throw std::invalid_argument("Parameters cannot be empty.");
	this->_nickname = nickname;
}
void Contact::setPhone(std::string phone) {
	bool isValid = true;

	if (phone.empty())
		throw std::invalid_argument("Parameters cannot be empty.");
	for (std::size_t i = 0; i < phone.size(); i++)
	{
		if (!isdigit(phone[i]) && phone[i] != '/' && phone[i] != '-') {
			throw std::invalid_argument("The phone number can only contain digits, / and -.");
		}
	}
	this->_phone = phone;
}
void Contact::setSecret(std::string secret) {
	if (secret.empty())
		throw std::invalid_argument("Parameters cannot be empty.");
	this->_secret = secret;
}

void Contact::show() {
	std::cout << "Contact : " << this << std::endl;
	std::cout << "First name : " << this->getFirstname() << std::endl;
	std::cout << "Last name : " << this->getLastname() << std::endl;
	std::cout << "Nickname : " << this->getNickname() << std::endl;
	std::cout << "Phone : " << this->getPhone() << std::endl;
	std::cout << "Secret : " << this->getSecret() << std::endl;
}

