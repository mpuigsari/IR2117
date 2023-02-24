#include "utils.hpp"

Eigen::VectorXi ReadElements(){
    int element;
    Eigen::VectorXi elements;
    std::cin >> element;
    while(not std::cin.eof()){
        elements<<element;
        std::cin>>element;
    }
    return elements;
}