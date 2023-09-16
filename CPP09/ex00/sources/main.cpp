/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:14:30 by crypto            #+#    #+#             */
/*   Updated: 2023/09/16 14:56:47 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BTC	currency;

	if (argc < 2)
		return (ERROR_USAGE, 1);
	if (!currency.convert(argv[1]))
		return (ERROR_BAD_FILE(argv[1]), 1);
	return (0);
}
