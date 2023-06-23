/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:54:35 by lray              #+#    #+#             */
/*   Updated: 2023/06/23 18:32:19 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Megaphone {
public:
	void say(std::string& msg) {
		std::cout << toUpperCase(msg);
	}

private:
	std::string toUpperCase(const std::string& str) {
		std::string res = str;

		for (std::size_t i = 0; i < res.size(); i++) {
			res[i] = std::toupper(res[i]);
		}
		return (res);
	}
};

int	main(int argc, char **argv) {
	Megaphone megaphone;
	std::string msg = "* loud and unbearable feedback noise *";

	if (argc == 1) {
		megaphone.say(msg);
	}
	else {
		for (std::size_t i = 1; argv[i]; i++) {
			msg = std::string(argv[i]);
			megaphone.say(msg);
		}
	}
	std::cout << std::endl;
}
