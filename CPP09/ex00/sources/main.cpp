/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:14:30 by crypto            #+#    #+#             */
/*   Updated: 2023/09/10 17:03:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	BTC currency;

	if (argc < 2)
		return (-1);
	currency.readExchangeRates();
	// currency.dump();
	currency.convert(argv[1]);
	return (0);
}