#include "vector.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <cmath>

heppoko::vector::vector()
{

}

heppoko::vector::vector(std::vector<double> e)
{
    std::copy(e.begin(), e.end(), std::back_inserter(elements));
}

void
heppoko::vector::init(std::vector<double> e)
{
    std::copy(e.begin(), e.end(), std::back_inserter(elements));
}

void
heppoko::vector::print()
{
    std::cout << "(";
    for(size_t i = 0; i < elements.size(); ++i) {
        std::cout << " " << elements.at(i);
    }
    std::cout << " )" << std::endl;
}

double
heppoko::vector::norm()
{
    return std::sqrt(*this * *this);
}

heppoko::vector
heppoko::vector::normalize()
{
    double tmp = this->norm();
    heppoko::vector result(elements);
    for(size_t i = 0; i < result.elements.size(); ++i) {
        result.elements.at(i) /= tmp;
    }
    return result;
}

double
heppoko::vector::operator*(const heppoko::vector &rhs)
{
    double result = 0;

    if(rhs.elements.size() != elements.size()) {
        throw std::invalid_argument("Invalid Arguments(inner product): vector size is different!!");
    }

    for(size_t i = 0; i < rhs.elements.size(); ++i) {
        result += rhs.elements.at(i) * elements.at(i);
    }
    return result;
}

heppoko::vector
heppoko::vector::operator*(const double &rhs) {
    heppoko::vector result(elements);

    for(size_t i = 0; i < result.elements.size(); ++i) {
        result.elements.at(i) *= rhs;
    }
    return result;
}

heppoko::vector
heppoko::vector::operator-(const heppoko::vector &rhs)
{
    heppoko::vector result(elements);

    if(rhs.elements.size() != elements.size()) {
        throw std::invalid_argument("Invalid Arguments(substraction): vector size is different!!");
    }

    for(size_t i = 0; i < result.elements.size(); ++i) {
        result.elements.at(i) -= rhs.elements.at(i);
    }
    return result;
}

std::vector<double>
heppoko::vector::get_elements()
{
    return elements;
}
