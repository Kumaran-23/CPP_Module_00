/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:08:49 by snair             #+#    #+#             */
/*   Updated: 2022/11/20 10:08:54 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iomanip>
# include <iostream>
# include <cctype>
# include "Contact.hpp"

class PhoneBook 
{
    private:
        Contact contacts[8];
        int index;
    public:
        PhoneBook();
        ~PhoneBook();
        int add_contacts();
        int search_contacts() const;
};

#endif