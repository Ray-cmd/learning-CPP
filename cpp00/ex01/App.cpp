/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 00:34:29 by lray              #+#    #+#             */
/*   Updated: 2023/06/24 03:56:34 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "App.hpp"

static int atoi(const std::string &str);

void App::run()
{
	std::string cmd;

	while (true)
	{
		std::cout << "Commande (add, show, exit) : ";
		std::getline(std::cin, cmd);

		if (cmd == "add")
		{
			_addContact();
		}
		else if (cmd == "show")
		{
			_showContacts();
		}
		else if (cmd == "exit")
		{
			break;
		}
		else
		{
			std::cout << "Invalid commande !" << std::endl;
		}
	}
}

void App::_addContact()
{
	std::string firstname, lastname, nickname, phone, secret;

	std::cout << "First name : ";
	std::getline(std::cin, firstname);
	std::cout << "Last name : ";
	std::getline(std::cin, lastname);
	std::cout << "Nickname : ";
	std::getline(std::cin, nickname);
	std::cout << "Phone number : ";
	std::getline(std::cin, phone);
	std::cout << "Secret : ";
	std::getline(std::cin, secret);
	try
	{
		_phoneBook.addContact(firstname, lastname, nickname, phone, secret);
	}
	catch (std::invalid_argument &err)
	{
		std::cout << "[Error] addContact - " << err.what() << std::endl;
	}
}

void App::_showContacts()
{
	std::string id;
	int id_int;

	_phoneBook.showContacts();
	std::cout << "ID (1-7) : ";
	std::getline(std::cin, id);
	id_int = atoi(id);
	_phoneBook.showContact(id_int - 1);
}

static int atoi(const std::string &str)
{
	std::istringstream iss(str);
	int num;
	if (!(iss >> num))
		num = 0;
	return num;
}
