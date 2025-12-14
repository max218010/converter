#pragma once
#include "converter.h"

class DecToHex : public Converter
{
public:
    std::string convert(int value) override;
};
