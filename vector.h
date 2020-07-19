#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

namespace heppoko
{
class vector
{
public:
    vector();
    vector(std::vector<double> e);
    void init(std::vector<double> e);
    void print();
    double norm();
    double inner_product();
    heppoko::vector normalize();
    double operator*(const heppoko::vector &rhs);
    heppoko::vector operator*(const double &rhs);
    heppoko::vector operator-(const heppoko::vector &rhs);
    std::vector<double> get_elements();

private:
    std::vector<double> elements;
};
}

#endif // VECTOR_H
