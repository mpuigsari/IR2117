#include <iostream>
#include <string>

int main(){
    int a = 0, b = 0, sum = 0;
    while(a<1){
    std::cout << "Enter a number: ";
    std::cin >> a;}
    while(b<1){
    std::cout << "Enter b number: ";
    std::cin >> b;}
    for(int n = a; n <= b; n++ ){
        sum += n;}
    std::cout << "The sum from "<< std::to_string(a) 
    << " to " << std::to_string(b) << " is " 
    << std::to_string(sum) << std::endl;
    return 0;
}