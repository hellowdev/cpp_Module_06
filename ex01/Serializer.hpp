#pragma once
#include <iostream>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer();
    public:
        Serializer(const Serializer& original);
        Serializer& operator=(const Serializer& original);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
        ~Serializer();
};