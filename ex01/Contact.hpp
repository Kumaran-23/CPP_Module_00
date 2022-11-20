/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:08:29 by snair             #+#    #+#             */
/*   Updated: 2022/11/20 10:08:32 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact
{
	private:
	 	std::string _first_name;
	 	std::string _last_name;
	 	std::string _nickname;
	 	std::string _phone_number;
		std::string _darkest_secret;
	
	public:
		Contact();
		~Contact();
		std::string get_first_name(void) const;
  		std::string get_last_name(void) const;
  		std::string get_nickname(void) const;
		std::string get_phone_number(void) const;
		std::string get_darkest_secret(void) const;
		void set_first_name(std::string first_name);
  		void set_last_name(std::string last_name);
  		void set_nickname(std::string nickname);
		void set_phone_number(std::string phone_number);
		void set_darkest_secret(std::string darkest_secret);

};


#endif