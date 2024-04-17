#include <iostream>
#include "CMyString.h"

int main() 
{
    CMyString s1; 
    CMyString s2("Hello, world!"); 
    CMyString s3(s2); 

    s1 = s2;

    CMyString s4 = s2 + " This is a test";
    std::cout << s4 << std::endl;

    if (s2 == s1) std::cout << "s2 equals s1" << std::endl;
    if (s3 != s1) std::cout << "s3 not equals s1" << std::endl;
    if (s2 < s4) std::cout << "s2 is less than s4" << std::endl;
    if (s4 > s1) std::cout << "s4 is greater than s1" << std::endl;

    CMyString sub = s4.SubString(7, 5);
    std::cout << "Substring: " << sub << std::endl;

    std::cout << "Iterating over s4: ";
    for (auto it = s4.begin(); it != s4.end(); ++it)
    {
        std::cout << *it;
    }
    std::cout << std::endl;

    return 0;
}
