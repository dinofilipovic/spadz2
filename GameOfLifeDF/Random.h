#pragma once

#include <random>

class Random
{
    public:
        Random();

        int getIntInRange(int low, int high);

    private:
        std::mt19937 m_randNumGenerator;
};