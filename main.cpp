#include <iostream>
#include <vector.h>

int main()
{
    std::vector<double> initalize_vec[3] = {{1, 1, 1}, {1, -1, 2}, {-1, 1, 3}};
    std::vector<heppoko::vector> v(3);

    for(size_t i = 0; i < v.size(); ++i)
        v[i].init(initalize_vec[i]);

    for(size_t i = 0; i < v.size(); ++i)
        v[i].print();

    for(size_t i = 0; i < v.size(); ++i) {
        for(size_t j = 0; j < i-1; ++i) {
            std::cout << i << " " << j << std::endl;
            v[i].print();
            v[j].print();
            double m = (v[i] * v[j]) / (v[j].norm() * v[j].norm());
            std::cout << m << std::endl;
            v[i] = v[i] -  v[j] * m;
            v[i].print();
        }
    }

    for(size_t i = 0; i < v.size(); ++i)
        v[i].print();

    return 0;
}
