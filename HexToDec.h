#pragma once
#include "converter.h"

class HexToDec : public Converter
{
public:
    std::string convert(int value) override;
};
