#include "vector.hpp"

int main()
{
    ft::vector<int> v(10, 42);

    ft::vector<int> k;
    k.insert(k.begin(), v.begin(), v.end());
    return 0;
}
