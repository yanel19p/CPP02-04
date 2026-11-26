/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:37:34 by yaperalt          #+#    #+#             */
/*   Updated: 2026/11/26 16:12:01 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fixed.hpp"

// el proposito del ex02, es que los objetos se comporten como numeros normales

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
}