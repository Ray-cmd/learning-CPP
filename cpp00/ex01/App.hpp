/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 00:34:40 by lray              #+#    #+#             */
/*   Updated: 2023/06/24 03:56:40 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_HPP
#define APP_HPP

#include "PhoneBook.hpp"
# include <stdexcept>
#include <sstream>

class App {
	private:
		PhoneBook _phoneBook;

		void _addContact();
		void _showContacts();
	public:
		void run();

};

#endif
