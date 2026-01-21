#pragma once
#include "converter.h"
#include "validators.h"
#include <string>
#include <sstream>

class DecToHex : public Converter<int>
{
public:
    std::string convert(int value) override;
    bool isValid(const std::string& input) override;
};