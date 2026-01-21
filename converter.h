#pragma once
#include <string>
#include <vector>

template <typename InputType>
class Converter
{
public:
    virtual std::string convert(InputType a) = 0;
    virtual bool isValid(const std::string& input) = 0;
};