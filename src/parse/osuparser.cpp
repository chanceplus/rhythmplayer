#include "osuparser.h"

#include <bits/stdc++.h>

// Parse osu mania map
Map OsuParser::parseMap(std::string filePath)
{
    std::ifstream osuFile(filePath);
    OsuMap newMap = OsuMap();

    if (!osuFile.is_open()) // Check open
    {
        std::cerr << "Could not open osu file: " << filePath << std::endl;
        return OsuMap();
    }

    std::string line;
    while (std::getline(osuFile, line))
    {
        std::cout << line << std::endl;
    }

    osuFile.close();

    return newMap;
}

OsuParser::~OsuParser()
{
    return;
}