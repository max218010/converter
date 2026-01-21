#pragma 
#include "converter.h"
#include "validators.h"
#include <string>
#include <stdexcept>

class BinToDec : public Converter<std::string>
{
public:
    std::string convert(std::string bin) override;
    bool isValid(const std::string& input) override;
};