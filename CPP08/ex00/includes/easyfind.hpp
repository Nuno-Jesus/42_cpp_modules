/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:06:22 by marvin            #+#    #+#             */
/*   Updated: 2023/07/02 12:06:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <iomanip>
# include <climits>
# include <algorithm>
# include <vector>
# include <list>
# include <deque>

template <typename T>
int easyfind(T container, int tofind);

# include "easyfind.tpp"

#endif
