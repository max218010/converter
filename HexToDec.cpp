#include "hextodec.h"

std::string HexToDec::convert(std::string value)
{
    int dec = std::stoi(value, nullptr, 16);
    return std::to_string(dec);
}

bool HexToDec::isValid(const std::string& input)
{
    return Validators::hex(input);
}
