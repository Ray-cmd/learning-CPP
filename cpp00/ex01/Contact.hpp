/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:47:15 by lray              #+#    #+#             */
/*   Updated: 2023/06/24 03:21:01 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Contact {
	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phone;
		std::string _secret;

	public:
		Contact();
		Contact(
			std::string firstname,
			std::string lastname,
			std::string nickname,
			std::string phone,
			std::string secret
		);
		Contact(const Contact& other);
		Contact& operator=(const Contact& other);
		~Contact();
		std::string getFirstname();
		std::string getLastname();
		std::string getNickname();
		std::string getPhone();
		std::string getSecret();
		void setFirstname(std::string);
		void setLastname(std::string);
		void setNickname(std::string);
		void setPhone(std::string);
		void setSecret(std::string);
		void show();
};
#endif
