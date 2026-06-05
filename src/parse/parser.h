#pragma once

#include <string>
#include "../map/map.h"

class Parser
{
public:
    // Parser implementation functions
    virtual Map parseMap(std::string filePath) = 0;

    virtual ~Parser() = 0;
};