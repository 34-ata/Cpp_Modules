#include "whatever.hpp"
#include <iostream>

#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define RESET "\033[0m"
#define YELLOW "\n\033[1;33m"

int main()
{
    {
        int a = 10, b = 20;
        std::cout << BLUE "Before swap - a: " << a << ", b: " << b << RESET << std::endl;
        swap(a, b);
        std::cout << GREEN "After swap - a: " << a << ", b: " << b << RESET << std::endl;

        std::cout << CYAN "Min of " << a << " and " << b << " is: " << min(a, b) << RESET << std::endl;
        std::cout << MAGENTA "Max of " << a << " and " << b << " is: " << max(a, b) << RESET << std::endl;

        double x = 5.5, y = 3.7;
        std::cout << BLUE "Before swap - x: " << x << ", y: " << y << RESET << std::endl;
        swap(x, y);
        std::cout << GREEN "After swap - x: " << x << ", y: " << y << RESET << std::endl;

        std::cout << CYAN "Min of " << x << " and " << y << " is: " << min(x, y) << RESET << std::endl;
        std::cout << MAGENTA "Max of " << x << " and " << y << " is: " << max(x, y) << RESET << std::endl;

        char p = 'A', q = 'Z';
        std::cout << BLUE "Before swap - p: " << p << ", q: " << q << RESET << std::endl;
        swap(p, q);
        std::cout << GREEN "After swap - p: " << p << ", q: " << q << RESET << std::endl;

        std::cout << CYAN "Min of " << p << " and " << q << " is: " << min(p, q) << RESET << std::endl;
        std::cout << MAGENTA "Max of " << p << " and " << q << " is: " << max(p, q) << RESET << std::endl;
    }
    {
        int a = 2;
        int b = 3;
        
        std::cout << YELLOW "TESTS FROM THE PDF:" RESET << std::endl;
        std::cout << BLUE "Before swap - a: " << a << ", b: " << b << RESET << std::endl;
        ::swap(a, b);
        std::cout << GREEN "After swap - a: " << a << ", b: " << b << RESET << std::endl;
        
        std::cout << CYAN "min(a, b) = " << ::min(a, b) << RESET << std::endl;
        std::cout << MAGENTA "max(a, b) = " << ::max(a, b) << RESET << std::endl;

        std::string c = "chaine1";
        std::string d = "chaine2";
        
        std::cout << BLUE "Before swap - c: " << c << ", d: " << d << RESET << std::endl;
        ::swap(c, d);
        std::cout << GREEN "After swap - c: " << c << ", d: " << d << RESET << std::endl;
        
        std::cout << CYAN "min(c, d) = " << ::min(c, d) << RESET << std::endl;
        std::cout << MAGENTA "max(c, d) = " << ::max(c, d) << RESET << std::endl;

        std::cout << YELLOW "SHOULD OUTPUT:" RESET << std::endl;
        std::cout << "a = 3, b = 2" << std::endl;
        std::cout << "min(a, b) = 2" << std::endl;
        std::cout << "max(a, b) = 3" << std::endl;
        std::cout << "c = chaine2, d = chaine1" << std::endl;
        std::cout << "min(c, d) = chaine1" << std::endl;
        std::cout << "max(c, d) = chaine2" << std::endl;
    }

    return 0;
}
