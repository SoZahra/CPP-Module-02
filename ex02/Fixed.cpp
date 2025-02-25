/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:33:45 by fzayani           #+#    #+#             */
/*   Updated: 2025/02/25 15:42:11 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(const int value)
{
	this->value = value << this->fraction_part;
}

Fixed::Fixed(const float value)
{
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
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed::~Fixed(void)
{
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if(this != &other)
		this->value = other.getRawBits();
	return *this;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed res;

	res.setRawBits((this->value * other.value) >> this->fraction_part);
	return res;
}

bool Fixed::operator>(const Fixed& other) const
{
	return(this->value > other.value);
}

bool Fixed::operator<(const Fixed& other) const
{
	return(this->value < other.value);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return(this->value >= other.value);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return(this->value <= other.value);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return(this->value != other.value);
}

bool Fixed::operator==(const Fixed& other) const
{
	return(this->value == other.value);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed res;
	res.setRawBits(this->value + other.value);
	return res;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed res;
	res.setRawBits(this->value - other.value);
	return res;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed res;
	res.setRawBits((this->value << this->fraction_part) / other.value);
	return res;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->value++;
	return (tmp);
}

Fixed& Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->value--;
	return (tmp);
}

Fixed& Fixed::operator--()
{
	this->value--;
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	return this->value;
}

void Fixed::setRawBits( int const raw)
{
	this->value = raw;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}
