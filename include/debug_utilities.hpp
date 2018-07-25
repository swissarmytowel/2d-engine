#pragma once

#include <vector>
#include <utilities.hpp>

namespace tb_debug
{
    template <typename T>
    void logVector(const std::vector<T> &vector, std::ostream &os=std::cout);

    template <typename T>
    void logMatrix(const std::vector<std::vector<T>> &matrix, std::ostream &os=std::cout)
    {
        for(auto &&row : matrix)
        {
            for(auto &&item : row)
            {
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }
    }

    void logRectangle(util::rectangle rect, std::ostream &os=std::cout);
}