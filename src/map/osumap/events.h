#pragma once

#include <variant>
#include <vector>
#include <string>

enum EEventType
{
    BackgroundEvent,
    VideoEvent,
    BreakEvent,
    UnusedEvent
};

struct Event
{
public:
    virtual EEventType getEventType() const;
    virtual bool verifyEvent() const;

protected:
    std::variant<int, std::string> EventType;
    int StartTime;
    std::vector<std::variant<int, std::string>> EventParams;    
};

struct BackgroundEvent : protected Event
{
    std::string getFileName() const;
    int getXOffset() const;
    int getYOffset() const;

    EEventType getEventType() const override;
    bool verifyEvent() const override;
};

struct VideoEvent : protected Event
{
    int getStartTime() const;
    std::string getFileName() const;
    int getXOffset() const;
    int getYOffset() const;

    EEventType getEventType() const override;
    bool verifyEvent() const override;
};

struct BreakEvent : protected Event
{
    int getStartTime() const;
    int getEndTime() const;

    EEventType getEventType() const override;
    bool verifyEvent() const override;
};