#pragma once

#include "osumap.h"
#include "parser.h"

class OsuParser : public Parser
{
public:
    Map parseMap(std::string filePath);
    ~OsuParser();
};