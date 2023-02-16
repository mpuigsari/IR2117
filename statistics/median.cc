#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.hpp"

int main(int argc, char** argv){
    std::vector<int> elements = ReadElements();
    double m;
    int n;
    std::sort(elements.begin(), elements.end());
    n = elements.size();
    if(n%2!=0)
        m= elements[(n/2)];
    else
        m= double(elements[(n/2)-1] + elements[n/2])/2;
    std::cout << "Median: " << m << std::endl;

    return 0;
}