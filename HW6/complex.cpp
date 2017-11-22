/*
Author: AWildTeddyBear
Filename: complex.cpp
Description: Contains the functions and overloads for complex.h
*/

#include <iostream>
#include "complex.h"

//Addition Overloader
complex complex::operator+(const complex& c){
    complex comp;
    comp.real = this->real + c.real;
    comp.imag = this->imag + c.imag;
    return comp;
}

//Subtraction Overloader
complex complex::operator-(const complex& c){
    complex comp;
    comp.real = this->real - c.real;
    comp.imag = this->imag - c.imag;
    return comp;
}

//Multiplication Overloader
complex complex::operator*(const complex& c){
    complex comp;
    comp.real = this->real*c.real - c.imag*this->imag;
    comp.imag = c.imag*this->real + this->imag*c.real;
    return comp;
}

//Division Overloader
complex complex::operator/(const complex& c){
    complex comp;
    comp.real = (this->real*c.real + this->imag*c.imag) / ((c.real*c.real) + (c.imag*c.imag));
    comp.imag = (this->imag*c.real - this->real*c.imag) / ((c.real*c.real) + (c.imag*c.imag));
    return comp;
}

//isEqualTo Overloader
bool complex::operator==(const complex& c){
    return this->real == c.real && this->imag == c.imag;
}

//Print Function
void complex::print(void){
    std::cout << this->real << (this->imag > 0 ? "+" : "") << this->imag << "i" << std::endl;
}