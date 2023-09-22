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
# include <vector>
# include <list>
# include <deque>
# include <algorithm>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	public:
		//! Constructors and destructor
		MutantStack() {}
		MutantStack(const MutantStack& copy) { *this = copy; }
		~MutantStack() {}

		//! Operator overloading
		MutantStack& operator=(const MutantStack& right) 
		{
			std::stack<T, Container>::operator=(this, right);
			return (*this);
		}

		//! Member functions
		typedef typename Container::iterator iterator;

		iterator begin(void) { return (this->c.begin()); }
		iterator end(void) { return (this->c.end()); }
};

#endif
