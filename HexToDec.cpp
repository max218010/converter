#include "HexToDec.h"
#include <sstream>
#include <iomanip>
#include <iostream>
std::string HexToDec::convert(int value)
{
    int result = 0;
    std::stringstream ss;
    ss << std::hex << value;
    ss >> result;

    return std::to_string(result);
}
