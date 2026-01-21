#pragma once
#include "converter.h"
#include "validators.h"
#include <string>

class HexToDec : public Converter<std::string>
{
public:
    std::string convert(std::string value) override;
    bool isValid(const std::string& input) const override;
};