#include <iostream>
#include <string>

int main(){
    int a,b,sum = 0;
    std::cout << "Enter a number: ";
    std::cin >> a;
    std::cout << "Enter b number: ";
    std::cin >> b;
    for(int n = a; n <= b; n++ ){
        sum += n;}
    std::cout << "The sum from "<< std::to_string(a) 
    << " to " << std::to_string(b) << " is " 
    << std::to_string(sum) << std::endl;
    return 0;
}