#include "DecToBin.h"

std::string DecToBin::convert(int value)
{
    if (value == 0) return "0";

    std::string result;
    while (value > 0)
    {
        result = (value % 2 == 0 ? "0" : "1") + result;
        value /= 2;
    }
    return result;
}

bool DecToBin::isValid(const std::string& input)
{
    return Validators::decimal(input);
}

