#include "Serializer.hpp"

int main()
{
    Data *ptr = new Data;
    ptr->x = 4;
    Data *ptr2;
    uintptr_t t = Serializer::serialize(ptr);
    ptr2 = Serializer::deserialize(t);
    std::cout << ptr2->x << '\n';
    delete ptr;
}