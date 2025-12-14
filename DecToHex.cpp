#include "dectohex.h"
#include <sstream>
#include <iomanip>

std::string DecToHex::convert(int value)
{
    std::stringstream ss;
    ss << std::uppercase << std::hex << value;
    return ss.str();
}
