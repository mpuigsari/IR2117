#include <iostream>
#include <eigen3/Eigen/Dense>
#include "utils.hpp"

int main(int argc, char** argv){
    Eigen::VectorXi elements = ReadElements();
    double m, s = 0;
    int n = elements.size();
    
    for(int i=0;i<n;i++)
        s+= elements[i];
    m = s/n;
    std::cout << "Arithmetic mean: " << m << std::endl;

    return 0;
}