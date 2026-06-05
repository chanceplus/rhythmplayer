#pragma once

#include <string>
#include <vector>

struct GeneralSection
{
    std::string AudioFilename;
    int AudioLeadIn;
    int PreviewTime;
    int Countdown;
    std::string SampleSet;
    double StackLeniency;
    int Mode;
    int LetterboxInBreaks;
    int UseSkinSprites;
    std::string OverlayPosition;
    std::string SkinPreference;
    int EpilepsyWarning;
    int CountdownOffset;
    int SpecialStyle;
    int WidescreenStoryboard;
    int SamplesMatchPlaybackRate;
};

struct EditorSection
{
    std::vector<int> Bookmarks;
    double DistanceSpacing;
    int BeatDivisor;
    int GridSize;
    double TimelineZoom;
};

struct MetadataSection
{
    std::string Title;
    std::string TitleUnicode;
    std::string Artist;
    std::string ArtistUnicode;
    std::string Creator;
    std::string Version;
    std::string Source;
    std::string Tags;
    int BeatmapID;
    int BeatmapSetID;
};

struct DifficultySection
{
    double HPDrainRate;
    double CircleSize;
    double OverallDifficulty;
    double ApproachRate;
    double SliderMultiplier;
    double SliderTickRate;
};