#pragma once

#include "base.h"
#include <vector>

class Long {
private:
    std::vector<uint> digits;
    bool sign;
    
    #define MODULE 65536
    #define MASK   MODULE - 1
    #define BITS   16

public:
    Long() : digits(1), sign(0) {}
};
