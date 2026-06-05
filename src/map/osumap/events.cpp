#include "events.h"

/*
    Verify Events
*/
bool BackgroundEvent::verifyEvent() const
{
    if (std::holds_alternative<int>(EventType))
    {
        return std::get<int>(EventType) == 0;
    }
    return false;
}

bool VideoEvent::verifyEvent() const
{
    if (std::holds_alternative<int>(EventType))
    {
        return std::get<int>(EventType) == 1;
    }
    if (std::holds_alternative<std::string>(EventType))
    {
        return std::get<std::string>(EventType) == "Video";
    }
    return false;
}

bool BreakEvent::verifyEvent() const
{
    if (std::holds_alternative<int>(EventType))
    {
        return std::get<int>(EventType) == 2;
    }
    if (std::holds_alternative<std::string>(EventType))
    {
        return std::get<std::string>(EventType) == "Break";
    }
    return false;
}

/*
    Get EventTypes Enum
*/
EEventType BackgroundEvent::getEventType() const
{
    return EEventType::BackgroundEvent;
}

EEventType VideoEvent::getEventType() const
{
    return EEventType::VideoEvent;
}

EEventType BreakEvent::getEventType() const
{
    return EEventType::BreakEvent;
}

/*
    BackgroundEvent vars:
    p0 -> fileName
    p1 -> xOffset
    p2 -> yOffset
*/
std::string BackgroundEvent::getFileName() const
{
    return std::get<std::string>(EventParams[0]);
}

int BackgroundEvent::getXOffset() const
{
    return std::get<int>(EventParams[1]);
}

int BackgroundEvent::getYOffset() const
{
    return std::get<int>(EventParams[2]);
}

/*
    VideoEvent vars:
    startTime
    p0 -> fileName
    p1 -> xOffset
    p2 -> yOffset
*/
int VideoEvent::getStartTime() const
{
    return StartTime;
}

std::string VideoEvent::getFileName() const
{
    return std::get<std::string>(EventParams[0]);
}

int VideoEvent::getXOffset() const
{
    return std::get<int>(EventParams[1]);
}

int VideoEvent::getYOffset() const
{
    return std::get<int>(EventParams[2]);
}

/*
    BreakEvent vars
    startTime
    p0 -> endTime
*/
int BreakEvent::getStartTime() const
{
    return StartTime;
}

int BreakEvent::getEndTime() const
{
    return std::get<int>(EventParams[0]);
}