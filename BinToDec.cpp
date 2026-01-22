#include "BinToDec.h"

std::string BinToDec::convert(std::string bin)
{
    // Converteer binaire string naar decimal string
    {
        int value = 0;
        for (char c : bin)
        {
            value = (value << 1) + (c - '0'); // bit shift en optellen
        }
        if (value < 0){throw std::exception("Invalid binary input");}
        return std::to_string(value);
    }
}

bool BinToDec::isValid(const std::string& input)
{
	return Validators::binary(input);
}
