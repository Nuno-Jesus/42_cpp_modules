/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:06:25 by marvin            #+#    #+#             */
/*   Updated: 2023/07/02 12:06:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
int easyfind(T container, int tofind)
{
	typename T::iterator pos;

	pos = std::find(container.begin(), container.end(), tofind);
	if (pos == container.end())
		return (-1);
	return (std::distance(container.begin(), pos));
}
