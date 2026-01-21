#pragma once
#include <string>
#include <regex>

namespace Validators
{
    inline bool decimal(const std::string& s)
    {
        static const std::regex dec("^[0-9]+$");
        return std::regex_match(s, dec);
    }

    inline bool hex(const std::string& s)
    {
        static const std::regex hex("^(0[xX])?[0-9A-Fa-f]+$");
        return std::regex_match(s, hex);
    }

    inline bool binary(const std::string& s)
    {
        static const std::regex bin("^[01]+$");
        return std::regex_match(s, bin);
    }
}
