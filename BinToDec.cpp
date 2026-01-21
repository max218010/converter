#include "BinToDec.h"

std::string BinToDec::convert(std::string bin)
{
    // Converteer binaire string naar decimal string
    {
        int value = 0;
        for (char c : bin)
        {
            if (c != '0' && c != '1')
                throw std::invalid_argument("Invalid binary input");

            value = (value << 1) + (c - '0'); // bit shift en optellen
        }
        return std::to_string(value);
    }
}

bool BinToDec::isValid(const std::string& input)
{
	return Validators::binary(input);
}
