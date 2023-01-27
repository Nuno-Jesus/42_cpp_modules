/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:55:47 by marvin            #+#    #+#             */
/*   Updated: 2023/01/26 23:55:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# define MAX_CONTACTS 8

# include "Contact.class.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void addContact();
		void displayContacts(void);

	private:
		int _i;
		Contact _contacts[MAX_CONTACTS];
};

#endif