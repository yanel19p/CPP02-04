/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:00:16 by yaperalt          #+#    #+#             */
/*   Updated: 2026/11/26 16:10:49 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}
    
Fixed::Fixed(const Fixed &copy){
    std::cout << "Copy constructor called" << std::endl;
    this->_value = copy.getRawBits();
}

Fixed::Fixed(int const num)//ex01
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = num << _bits;// desplazar 8 bits equivale a multiplicar por 256
}

Fixed::Fixed(float const num)//ex01
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(num * (1 << _bits));
}

Fixed &Fixed::operator=(const Fixed &copy){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy) {
    //this is a pointer of the current object(on the left side of =)
    //&copy gets the memory address of the object being passed in (the one on the right side of =)
    //assignments like a = b = c, work right to left first b = c then a = b
        this->_value = copy.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits(int const raw){
    this->_value = raw;
}

int		Fixed::toInt(void) const//ex01, elimina los bits de la parte fraccionaria
{
	return (this->_value >> _bits);
}

float	Fixed::toFloat(void) const//ex01, divide entre 256 y recupera el numero decimal
{
	return ((float)this->_value / (1 << _bits));
}

std::ostream	&operator<<(std::ostream &os, const Fixed &obj)//ex01, permite imprimir directamente un objeto
{
	os << obj.toFloat();
	return (os);
}