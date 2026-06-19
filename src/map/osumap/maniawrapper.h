#pragma once

#include "osuparser.h"

#include <algorithm>

class ManiaWrapper
{
public:
    ManiaWrapper();
    ManiaWrapper(OsuParser* osuParser);
    ManiaWrapper(
        OsuParser* osuParser, 
        const std::string& filePath
    );
    ~ManiaWrapper();

    // File System
    void loadMap(const std::string& filePath);
    bool isMapLoaded() { return this->mapLoaded; }

    // File Format
    const std::string& getFileFormat() const { return this->map->fileFormat; }

    // General
    const std::string& getAudioFilename() const { return this->map->generalSection.AudioFilename; }
    int getAudioLeadIn() const { return this->map->generalSection.AudioLeadIn; }
    int getPreviewTime() const { return this->map->generalSection.PreviewTime; }
    int getCountdown() const { return this->map->generalSection.Countdown; }
    const std::string& getSampleSet() const { return this->map->generalSection.SampleSet; }
    double getStackLeniency() const { return this->map->generalSection.StackLeniency; }
    int getMode() const { return this->map->generalSection.Mode; }
    int getLetterboxInBreaks() const { return this->map->generalSection.LetterboxInBreaks; }
    int getUseSkinSprites() const { return this->map->generalSection.UseSkinSprites; }
    const std::string& getOverlayPosition() const { return this->map->generalSection.OverlayPosition; }
    const std::string& getSkinPreference() const { return this->map->generalSection.SkinPreference; }
    int getEpilepsyWarning() const { return this->map->generalSection.EpilepsyWarning; }
    int getCountdownOffset() const { return this->map->generalSection.CountdownOffset; }
    int getSpecialStyle() const { return this->map->generalSection.SpecialStyle; }
    int getWidescreenStoryboard() const { return this->map->generalSection.WidescreenStoryboard; }
    int getSamplesMatchPlaybackRate() const { return this->map->generalSection.SamplesMatchPlaybackRate; }

    // Editor
    const std::vector<int>& getBookmarks() const { return this->map->editorSection.Bookmarks; }
    double getDistanceSpacing() const { return this->map->editorSection.DistanceSpacing; }
    int getBeatDivisor() const { return this->map->editorSection.BeatDivisor; }
    int getGridSize() const { return this->map->editorSection.GridSize; }
    double getTimelineZoom() const { return this->map->editorSection.TimelineZoom; }

    // Metadata
    const std::string& getTitle() const { return this->map->metadataSection.Title; }
    const std::string& getTitleUnicode() const { return this->map->metadataSection.TitleUnicode; }
    const std::string& getArtist() const { return this->map->metadataSection.Artist; }
    const std::string& getArtistUnicode() const { return this->map->metadataSection.ArtistUnicode; }
    const std::string& getCreator() const { return this->map->metadataSection.Creator; }
    const std::string& getVersion() const { return this->map->metadataSection.Version; }
    const std::string& getSource() const { return this->map->metadataSection.Source; }
    const std::string& getTags() const { return this->map->metadataSection.Tags; }
    int getBeatmapID() const { return this->map->metadataSection.BeatmapID; }
    int getBeatmapSetID() const { return this->map->metadataSection.BeatmapSetID; }

    // Difficulty
    double getHPDrainRate() const { return this->map->difficultySection.HPDrainRate; }
    double getCircleSize() const { return this->map->difficultySection.CircleSize; }
    double getOverallDifficulty() const { return this->map->difficultySection.OverallDifficulty; }
    double getApproachRate() const { return this->map->difficultySection.ApproachRate; }
    double getSliderMultiplier() const { return this->map->difficultySection.SliderMultiplier; }
    double getSliderTickRate() const { return this->map->difficultySection.SliderTickRate; }

    // Events
    const std::vector<Event*>& getEvents() const { return this->map->events; }
    int getEventCount() const { return this->map->events.size(); }

    // TimingPoints
    const std::vector<TimingPoint> getTimingPoints() const { return this->map->timingPoints; }
    int getTimingPointsCount() const { return this->map->timingPoints.size(); }
    int getTimingPointIndex(double ms);
    double getBPMAt(double ms);
    double getSVAt(double ms);

    // Colours
    const std::vector<Colour> getColours() const { return this->map->colours; }
    int getColoursCount() const { return this->map->colours.size(); }

    // HitObjects
    const std::vector<HitObject*> getHitObjects() const { return this->map->hitObjects; }
    int getHitObjectsCount() const { return this->map->hitObjects.size(); }

private:
    OsuParser* osuParser;
    OsuMap* map;
    bool mapLoaded;
};