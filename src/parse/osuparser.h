#pragma once

#include "osumap.h"
// #include "parser.h"

// class OsuParser : public Parser
class OsuParser
{
public:
    OsuMap parseMap(std::string filePath);
    ~OsuParser() {};
};