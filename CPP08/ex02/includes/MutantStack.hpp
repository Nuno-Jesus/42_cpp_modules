/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:58:50 by marvin            #+#    #+#             */
/*   Updated: 2023/07/02 16:58:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <iostream>
# include <iomanip>
# include <stack>

template <typename T>
class MutantStack : public std::stack
{
	private:

	public:
		//! Constructors and destructor
		MutantStack();
		MutantStack(const MutantStack& copy);
		~MutantStack();

		//! Operator overloading
		MutantStack& operator=(const MutantStack& right);

	class iterator : public std::stack<T>::iterator
	{

	};

	class const_iterator : public std::stack<T>::const_iterator
	{

	};

	class reverse_iterator : public std::stack<T>::reverse_iterator
	{

	};

	class const_reverse_iterator : public std::stack<T>::const_reverse_iterator
	{

	};

	class 
};

#endif
