/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:00:16 by yaperalt          #+#    #+#             */
/*   Updated: 2026/11/24 19:42:59 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fixed.hpp"
#include <iostream>

    Fixed::Fixed() : _value(0) {
        std::cout << "Default constructor called" << std::endl;
    }
    
    Fixed::Fixed(const Fixed &copy){
        std::cout << "Copy constructor called" << std::endl;
        this->_value = copy.getRawBits();
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
