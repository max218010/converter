#include "dectohex.h"

std::string DecToHex::convert(int value)
{

    std::stringstream ss;
    ss << std::uppercase << std::hex << value;
    return ss.str();
}

bool DecToHex::isValid(const std::string& input)
{
    return Validators::decimal(input);
}
