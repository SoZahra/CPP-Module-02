/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:33:45 by fzayani           #+#    #+#             */
/*   Updated: 2025/02/10 14:29:18 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->fraction_part;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value *(1 << this->fraction_part));
}

float Fixed::toFloat( void ) const
{
	return ((float)this->value / (1 << this->fraction_part));
}

int Fixed::toInt( void ) const
{
	return (this->value >> this->fraction_part);
}

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		this->value = other.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return this->value;
}

void Fixed::setRawBits( int const raw)
{
	this->value = raw;
}
