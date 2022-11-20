/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:09:28 by snair             #+#    #+#             */
/*   Updated: 2022/11/20 10:09:29 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void) 
{
  PhoneBook phone_book;
  std::string command;

  std::cout << "Welcome to My Phone Book!" << std::endl;
  std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl;
  while (getline(std::cin, command)) 
  {
    if (command == "ADD") 
    {	
      if (phone_book.add_contacts()) 
      {
				std::cout << "adding contact error" << std::endl;
				return 1;
			}
		}
    else if (command == "SEARCH") 
    {
			if (phone_book.search_contacts()) 
      {
				std::cout << "search error" << std::endl;
				return 1;	
			}
		}
    else if (command == "EXIT")
      break;
		else
			std::cout << "Command is invalid, please try again" << std::endl;
    std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl;
  }
  std::cout << "Thank you for using my awesome phonebook!" << std::endl;
}