#include <iostream>
#include <vector.h>

int main()
{
    std::vector<double> initalize_vec[4] = {{}, {1, 1, 1}, {1, -1, 2}, {-1, 1, 3}};
    std::vector<heppoko::vector> v(4);

    for(size_t i = 1; i < v.size(); ++i)
        v[i].init(initalize_vec[i]);

    for(size_t i = 1; i < v.size(); ++i)
        v[i].print();

    for(size_t i = 1; i < v.size(); ++i) {
        for(size_t j = 1; j <= i-1; ++j) {
            double m = (v[i] * v[j]) / (v[j] * v[j]);
            v[i] = v[i] - (v[j] * m);
        }
    }

    std::cout << std::endl <<  "orthogonalizationed:" << std::endl << std::endl;
    for(size_t i = 1; i < v.size(); ++i)
        v[i].print();
    return 0;
}
