#include <iostream>
#include <vector>
int main(int argc, char** argv){
    double m = 0, s = 0;
    int n = 0, element;
    std::vector<int> elements;
    std::cin >> element;
    while(not std::cin.eof()){
        elements.push_back(element);
        n+=1;
        std::cin >>element;
    }
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