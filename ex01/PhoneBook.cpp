/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:09:14 by snair             #+#    #+#             */
/*   Updated: 2022/11/20 10:09:17 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{ 
  this->index = 0;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Destructor Called" << std::endl;

}

//to make sure that phone number field only contains numbers
static int is_number(std::string str) 
{
  for (int i = 0; str[i]; i++)
    if (!isdigit(str[i])) 
      return 1;
  return 0;
}

//gets input from user and ensure its not empty
static int get_input(std::string &input)
{
  while (1) 
  {
    getline(std::cin, input);
    if (input.empty())
      std::cout << "Input cannot be empty, please fill in field." << std::endl;
    else
      return 0;
  }
}

//adds contacts to phonebook
int PhoneBook::add_contacts() 
{
  Contact temp;
  std::string input;

  std::cout << "Enter first name:" << std::endl;
  get_input(input);
  temp.set_first_name(input);

  std::cout << "Enter last name:" << std::endl;
  get_input(input);
  temp.set_last_name(input);

  std::cout << "Enter nickname:" << std::endl;
  get_input(input);
  temp.set_nickname(input);

  std::cout << "Enter phone number:" << std::endl;
  while (1) 
  {
    get_input(input);
    if (is_number(input) == 0) 
      break;
    std::cout << input << " is not a number. please enter numbers only." << std::endl;
  }
  temp.set_phone_number(input);
  std::cout << "Enter darkest secret:" << std::endl;
  get_input(input);
  temp.set_darkest_secret(input);
  this->contacts[this->index] = temp;
  this->index = (this->index % 8) + 1;
  return 0;
}

//to ensure contact info is not more than 10 chars long
std::string shortend(std::string str) 
{
  if (str.length() > 10) 
    return str.substr(0, 9) + ".";
  return str;
}

//prints contact information for search command
static void print_search_index(Contact contact, int i)
{
  std::cout << std::right << std::setw(10) << i << "|";
  std::cout << std::right << std::setw(10) << shortend(contact.get_first_name()) << "|";
  std::cout << std::right << std::setw(10) << shortend(contact.get_last_name()) << "|";
  std::cout << std::right << std::setw(10) << shortend(contact.get_nickname()) << "|" 
            << std::endl;
}

//searchs phonebook for contacts and then prints out full details for specified index
int PhoneBook::search_contacts() const 
{
  std::string input;
	int ind;

  if (this->contacts[0].get_first_name().empty()) {
    std::cout << "Phone book is currently empty, please add some contacts!" << std::endl;
    return 0;
  }

  //prints index number and first 3 fields
  std::cout << std::right << std::setw(10) << "Index";
  std::cout << "|";
  std::cout << std::right << std::setw(10) << "First name";
  std::cout << "|";
  std::cout << std::right << std::setw(10) << "Last name";
  std::cout << "|";
  std::cout << std::right << std::setw(10) << "Nickname" << "|" << std::endl;
  for (int i = 0; i < 8; i++) {
    if (this->contacts[i].get_first_name().empty() == false) {
      print_search_index(this->contacts[i], i);
    }
  }

  // Get input to show a specific index of the phone book
  std::cout << "Enter an index to show all info of a contact:" << std::endl;
  while (1) 
  {
    getline(std::cin, input);
    if (input.empty())
      std::cout << "Input cannot be empty. Try again." << std::endl;
    else 
    {
      ind = input[0] - 48;
      if (input[1] || ind < 0 || ind > 7 ||
          this->contacts[ind].get_first_name().empty())
        std::cout << "Invalid index. Try again." << std::endl;
      else
        break;
    }
  }

  // print  full contact info
  std::cout << std::endl; 
  std::cout << std::left << std::setw(17) << "First Name: "
  					<< this->contacts[ind].get_first_name()
						<< std::endl;
  std::cout << std::left << std::setw(17) << "Last Name: "
  					<< this->contacts[ind].get_last_name()
						<< std::endl;
  std::cout << std::left << std::setw(17) << "Nickname: "
  					<< this->contacts[ind].get_nickname()
						<< std::endl;
  std::cout << std::left << std::setw(17) << "Phone Number: "
  					<< this->contacts[ind].get_phone_number()
            << std::endl;
  std::cout << std::left << std::setw(17) << "Darkest Secret: "
  					<< this->contacts[ind].get_darkest_secret()
            << std::endl << std::endl;
  return 0;
}