#include <iostream>
#include <eigen3/Eigen/Dense>
#include "utils.hpp"

int main(int argc, char** argv){
    Eigen::VectorXi elements = ReadElements();
    double m = elements.mean();
    std::cout << "Arithmetic mean: " << m << std::endl;

    return 0;
}