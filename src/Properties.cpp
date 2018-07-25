#include "../include/Properties.hpp"

util::Properties::Properties(const std::string &fileName)
{
    std::ifstream fileStream(fileName);
    if (fileStream.bad())
    {
        std::cerr << "Can not open properties file " << fileName << std::endl;
        return;
    }
    for (std::string line; fileStream >> line;)
    {
        std::stringstream lineStream(line);
        std::string name;
        std::string value;

        std::getline(lineStream, name, '=');
        std::getline(lineStream, value, '=');

        if (!name.empty() && !value.empty())
        {
            properties.emplace(std::pair<std::string, double>(name, std::stod(value)));
        }
    }
    fileStream.close();
}
