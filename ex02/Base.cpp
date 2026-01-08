#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    std::srand(time(NULL));
    switch (std::rand() % 3)
    {
        case 0:
            return new B;
        case 1:
            return new A;
        case 2:
            return new C;
        default:
            return NULL;
    }
}

void identify(Base* p)
{
    Base *myCastA = dynamic_cast<A*>(p);
    Base *myCastB = dynamic_cast<B*>(p);
    Base *myCastC = dynamic_cast<C*>(p);
    if (myCastA)
        std::cout << "A\n";
    if (myCastB)
        std::cout << "B\n";
    if (myCastC)
        std::cout << "C\n";
    return ;
}

void identify(Base& p)
{
    try // because we cant return null in a reference
    {
        Base myCastA = dynamic_cast<A&>(p);
        std::cout << "A\n";
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        Base myCastB = dynamic_cast<B&>(p);
        std::cout << "B\n";
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        Base myCastC = dynamic_cast<C&>(p);
        std::cout << "C\n";
    }
    catch(const std::exception& e)
    {
    }
}
Base::~Base()
{
}