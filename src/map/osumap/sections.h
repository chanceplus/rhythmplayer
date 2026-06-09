#pragma once

#include <string>
#include <vector>

struct GeneralSection
{
    std::string AudioFilename    = "";
    int AudioLeadIn              = 0;
    int PreviewTime              = -1;
    int Countdown                = 1;
    std::string SampleSet        = "Normal";
    double StackLeniency         = 0.7;
    int Mode                     = 0;
    int LetterboxInBreaks        = 0;
    int UseSkinSprites           = 0;
    std::string OverlayPosition  = "NoChange";
    std::string SkinPreference   = "";
    int EpilepsyWarning          = 0;
    int CountdownOffset          = 0;
    int SpecialStyle             = 0;
    int WidescreenStoryboard     = 0;
    int SamplesMatchPlaybackRate = 0;
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