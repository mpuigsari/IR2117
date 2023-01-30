#include <iostream>
#include <string>

int main()
{
    std::cout << "What is your name?" << std::endl;
    std::string username;
    std::cin >> username;
    std::cout << "Hello " << username << "!" << std::endl;
    return 0;
}

