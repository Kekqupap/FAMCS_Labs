#include <iostream>
#include <string>
#include "Par.h"

int main()
{
    std::string str;
    std::cout << "Enter math equation to calculate: " << std::endl;
    std::getline(std::cin, str);
    Parser p((str.c_str()));
    auto expr = p.parse();
    auto result = eval(expr);
    std::cout << result << std::endl << "Press any key and then enter to close" << std::endl;
    std::cin >> str;
    return 0;
}