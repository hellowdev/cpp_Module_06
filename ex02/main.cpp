#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{

    Base *deriv = generate();
    {
        std::cout << "Test With pointer\n"; 
        identify(deriv);
    }

    {
        std::cout << "Test With Reference\n";
        identify(*deriv); // with reference test
    }
    delete deriv;
}