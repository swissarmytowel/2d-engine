#include<debug_utilities.hpp>

template<typename T>
void tb_debug::logVector(const std::vector<T> &vector, std::ostream &os)
{
    for (auto &&item : vector)
    {
        os << item << " ";
    }
    os << std::endl;
}

//template<typename T>
//void tb_debug::logMatrix(const std::vector<std::vector<T>> &matrix, std::ostream &os)
//{
//    for(auto &&row : matrix)
//    {
//        for(auto &&item : row)
//        {
//            std::cout << item << " ";
//        }
//        std::cout << std::endl;
//    }
//}

void tb_debug::logRectangle(util::rectangle rect, std::ostream &os)
{
    std::cout << "(" << rect.x << ", " << rect.y << "):[" << rect.w << ", " << rect.h << "]" << std::endl;
}