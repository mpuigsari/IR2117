#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv){
    double m = 0, s = 0;
    int n, element;
    std::vector<int> elements;
    std::cin >> element;
    while(not std::cin.eof()){
        elements.push_back(element);
        std::cin >>element;
    }
    std::sort(elements.begin(), elements.end());
    n = elements.size();
    if(n%2!=0)
        m= elements[(n/2)];
    else
        m=0;
    std::cout << "Median: " << m << std::endl;

    return 0;
}