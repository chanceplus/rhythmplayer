#pragma once

#include <variant>
#include "map.h"
#include "timingpoints.h"
#include "sections.h"
#include "events.h"
#include "colours.h"

class OsuMap : public Map
{
public:
    OsuMap();
    ~OsuMap();

protected:
    std::string _fileFormat;
    GeneralSection _generalSection;
    EditorSection _editorSection;
    MetadataSection _metadataSection;
    DifficultySection _difficultySection;
    std::vector<Event> _events;
    std::vector<TimingPoint> _timingPoints;
    std::vector<Colour> _colours;
};