#pragma once
#include "converter.h"
#include "validators.h"
#include <string>


class DecToBin : public Converter<int>
{
public:
    std::string convert(int value) override;
    virtual bool isValid(const std::string& input) override;
};
