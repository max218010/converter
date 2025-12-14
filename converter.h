#pragma once
#include <string>
#include <vector>

class Converter
{
public:
    void showresult();
    virtual std::string convert(int a) = 0;
    void log();
};
