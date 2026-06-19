#include "maniawrapper.h"

ManiaWrapper::ManiaWrapper()
{
    this->mapLoaded = false;
}

ManiaWrapper::ManiaWrapper(OsuParser* osuParser)
{
    this->mapLoaded = false;
    this->osuParser = osuParser;
}

ManiaWrapper::ManiaWrapper(
    OsuParser* osuParser, 
    const std::string& filePath
)
{
    this->osuParser = osuParser;
    this->loadMap(filePath);
}

ManiaWrapper::~ManiaWrapper()
{
    // Delete Map
    delete this->map;
    this->map = nullptr;
    this->mapLoaded = false;

    // Delete OsuParser pointer
    this->osuParser = nullptr;
}

/*
    File System
*/

void ManiaWrapper::loadMap(const std::string& filePath)
{
    this->mapLoaded = true;
    this->map = this->osuParser->parseMap(filePath);
}

/*
    TimingPoints
*/

int ManiaWrapper::getTimingPointIndex(double ms)
{
    auto it = std::lower_bound(
        this->getTimingPoints().begin(),
        this->getTimingPoints().end(),
        ms,
        [](const TimingPoint& t, int key)
        {
            return t.Time < key;
        }
    );

    if (it == this->getTimingPoints().end()) { return -1; }
    return it - this->getTimingPoints().begin();
}

double ManiaWrapper::getBPMAt(double ms)
{
    int index = this->getTimingPointIndex(ms);
    if (index == -1) { return -1; }
    
    for (int i = index; i >= 0; i--)
    {
        if (this->getTimingPoints().at(i).isBPM())
        {
            return this->getTimingPoints().at(i).getBPM();
        }
    }

    return -1;
}

double ManiaWrapper::getSVAt(double ms)
{
    int index = this->getTimingPointIndex(ms);
    if (index == -1) { return -1; }
    
    for (int i = index; i >= 0; i--)
    {
        if (!this->getTimingPoints().at(i).isBPM())
        {
            return this->getTimingPoints().at(i).getSV();
        }
    }

    return -1;
}