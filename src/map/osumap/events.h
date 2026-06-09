#pragma once

#include <variant>
#include <vector>
#include <string>

enum EEventType
{
    EBackgroundEvent =  0,
    EVideoEvent      =  1,
    EBreakEvent      =  2,
    EUnusedEvent     = -1,
};

struct Event
{
public:
    virtual EEventType getEventType() const = 0;
    virtual bool verifyEvent() const = 0;

    Event() {};
    virtual ~Event() {};

    std::variant<int, std::string> EventType;
    int StartTime;
    std::vector<std::variant<int, std::string>> EventParams;    
};

struct BackgroundEvent : public Event
{
    std::string getFileName() const;
    int getXOffset() const;
    int getYOffset() const;

    EEventType getEventType() const override;
    bool verifyEvent() const override;
};

struct VideoEvent : public Event
{
    int getStartTime() const;
    std::string getFileName() const;
    int getXOffset() const;
    int getYOffset() const;

    EEventType getEventType() const override;
    bool verifyEvent() const override;
};

struct BreakEvent : public Event
{
    int getStartTime() const;
    int getEndTime() const;

    EEventType getEventType() const override;
    bool verifyEvent() const override;
};