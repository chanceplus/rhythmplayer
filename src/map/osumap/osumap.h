#pragma once

#include <variant>
#include "map.h"
#include "timingpoints.h"
#include "sections.h"
#include "events.h"
#include "colours.h"
#include "hitobjects.h"

struct OsuMap : public Map
{
    OsuMap() {};
    ~OsuMap()
    {
        for (int i = 0; i < events.size(); i++)
        {
            delete events[i];
        }
    }

    std::string fileFormat;
    GeneralSection generalSection;
    EditorSection editorSection;
    MetadataSection metadataSection;
    DifficultySection difficultySection;
    std::vector<Event*> events;
    std::vector<TimingPoint> timingPoints;
    std::vector<Colour> colours;
    std::vector<HitObject*> hitObjects;
};