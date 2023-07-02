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
	typename T::iterator i;
	int k;

	pos = std::find(container.begin(), container.end(), tofind);
	if (pos == container.end())
		return (-1);
	k = 0;
	for (i = container.begin(); i != pos; i++)
		k++;
	return (k);
}
