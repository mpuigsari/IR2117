#include <iostream>
#include <eigen3/Eigen/Dense>
#include "utils.hpp"
int main(int argc, char** argv){
    Eigen::ArrayXXi elements = ReadElements();
    double m = 0;
    int n = elements.cols();
    int count,max= 0;
    for(int i=0; i<n; i++){
        count= (elements == elements[0,i]).count();
        if(count > max){
            max=count;
            m = elements[0,i];}}
    std::cout << "Mode: " << m << std::endl;

    return 0;
}