/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:59:46 by lray              #+#    #+#             */
/*   Updated: 2023/06/24 03:37:50 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	private:
		static const int NBR_CONTACT = 8;
		Contact contacts[NBR_CONTACT];
		int _nbrContacts;

	public:
		PhoneBook();
		~PhoneBook();

		int getNbrContacts();

		void addContact(
			std::string firstname,
			std::string lastname,
			std::string nickname,
			std::string phone,
			std::string secret
		);
		void showContacts();
		void showContact(int id);
};

#endif
