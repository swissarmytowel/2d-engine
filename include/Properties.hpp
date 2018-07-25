#pragma once

#include <map>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <strstream>
#include <sstream>
#include "utilities.hpp"

namespace util
{
    class Properties
    {
    public:
        Properties() = delete;
        ~Properties() = default;

        explicit Properties(const std::string &fileName);

        const std::map<std::string, double> &getProperties() const
        {
            return properties;
        }

    private:
        std::map<std::string, double> properties;
    };
}