#include <iostream>
#include <eigen3/Eigen/Dense>
#include "utils.hpp"
int main(int argc, char** argv){
    Eigen::VectorXi elements = ReadElements();
    double m = 0;
    int n = elements.size();
    int count[n], max= 0;
    for(int i=0; i<n; i++){
        count[i]=0;
        for(int j = 0; j<n; j++){
            if(elements[i] == elements[j])
                count[i]++;
            if(count[i]>count[max])
                max=i;}}
    m = elements[max];
    std::cout << "Mode: " << m << std::endl;

    return 0;
}