#pragma once

#include "osumap.h"
// #include "parser.h"

// class OsuParser : public Parser
class OsuParser
{
public:
    OsuMap* parseMap(const std::string& filePath);
    ~OsuParser() {};
};