#include <gtest/gtest.h>

#include "maniawrapper.h"

std::string getAssetPath(const std::string& path)
{
    return std::string(std::getenv("ASSETS_PATH")) + "\\" + path;
}

TEST(ManiaWrapper, TestFileFormat)
{
    OsuParser* osuParser = new OsuParser();
    ManiaWrapper* maniaWrapper = new ManiaWrapper(osuParser);
    maniaWrapper->loadMap(getAssetPath("test\\maps\\4key\\4key.osu"));

    std::string fileFormat = maniaWrapper->getFileFormat();

    delete maniaWrapper;
    delete osuParser;

    EXPECT_EQ(fileFormat, "osu file format v128");
}

TEST(ManiaWrapper, TestGeneralSection)
{
    OsuParser* osuParser = new OsuParser();
    ManiaWrapper* maniaWrapper = new ManiaWrapper(osuParser);
    maniaWrapper->loadMap(getAssetPath("test\\maps\\4key\\4key.osu"));

    std::string audioFilename = maniaWrapper->getAudioFilename();
    int audioLeadIn = maniaWrapper->getAudioLeadIn();
    int previewTime = maniaWrapper->getPreviewTime();
    int countdown = maniaWrapper->getCountdown();
    std::string sampleSet = maniaWrapper->getSampleSet();
    double stackLeniency = maniaWrapper->getStackLeniency();
    int mode = maniaWrapper->getMode();
    int letterboxInBreaks = maniaWrapper->getLetterboxInBreaks();
    int useSkinSprites = maniaWrapper->getUseSkinSprites();
    std::string overlayPosition = maniaWrapper->getOverlayPosition();
    std::string skinPreference = maniaWrapper->getSkinPreference();
    int epilepsyWarning = maniaWrapper->getEpilepsyWarning();
    int countdownOffset = maniaWrapper->getCountdownOffset();
    int specialStyle = maniaWrapper->getSpecialStyle();
    int widescreenStoryboard = maniaWrapper->getWidescreenStoryboard();
    int samplesMatchPlaybackRate = maniaWrapper->getSamplesMatchPlaybackRate();

    delete maniaWrapper;
    delete osuParser;

    EXPECT_EQ(audioFilename, "audio.mp3");
    EXPECT_EQ(audioLeadIn, 0);
    EXPECT_EQ(previewTime, 13701);
    EXPECT_EQ(countdown, 0);
    EXPECT_EQ(sampleSet, "Normal");
    EXPECT_EQ(stackLeniency, 0.7);
    EXPECT_EQ(mode, 3);
    EXPECT_EQ(letterboxInBreaks, 0);
    EXPECT_EQ(specialStyle, 0);
    EXPECT_EQ(widescreenStoryboard, 1);
}

TEST(ManiaWrapper, TestEditorSection)
{
    OsuParser* osuParser = new OsuParser();
    ManiaWrapper* maniaWrapper = new ManiaWrapper(osuParser);
    maniaWrapper->loadMap(getAssetPath("test\\maps\\4key\\4key.osu"));

    int distanceSpacing = maniaWrapper->getDistanceSpacing();
    int beatDivisor = maniaWrapper->getBeatDivisor();
    int gridSize = maniaWrapper->getGridSize();
    int timelineZoom = maniaWrapper->getTimelineZoom();

    delete maniaWrapper;
    delete osuParser;

    EXPECT_EQ(distanceSpacing, 1);
    EXPECT_EQ(beatDivisor, 4);
    EXPECT_EQ(gridSize, 4);
    EXPECT_EQ(timelineZoom, 1);
}

TEST(ManiaWrapper, TestMetadataSection)
{
    OsuParser* osuParser = new OsuParser();
    ManiaWrapper* maniaWrapper = new ManiaWrapper(osuParser);
    maniaWrapper->loadMap(getAssetPath("test\\maps\\4key\\4key.osu"));

    std::string title = maniaWrapper->getTitle();
    std::string titleUnicode = maniaWrapper->getTitleUnicode();
    std::string artist = maniaWrapper->getArtist();
    std::string artistUnicode = maniaWrapper->getArtistUnicode();
    std::string creator = maniaWrapper->getCreator();
    std::string version = maniaWrapper->getVersion();
    std::string tags = maniaWrapper->getTags();
    int beatmapID = maniaWrapper->getBeatmapID();
    int beatmapSetID = maniaWrapper->getBeatmapSetID();

    delete maniaWrapper;
    delete osuParser;

    EXPECT_EQ(title, "Pardontekk");
    EXPECT_EQ(titleUnicode, "Pardontekk");
    EXPECT_EQ(artist, "HELLBLADE");
    EXPECT_EQ(artistUnicode, "HELLBLADE");
    EXPECT_EQ(creator, "greedx");
    EXPECT_EQ(version, "Minijacks");
    EXPECT_EQ(tags, "chordjack cj quadjack densejack minijack");
    EXPECT_EQ(beatmapID, 5679570);
    EXPECT_EQ(beatmapSetID, 2556618);
}

TEST(ManiaWrapper, TestDifficultySection)
{
    OsuParser* osuParser = new OsuParser();
    ManiaWrapper* maniaWrapper = new ManiaWrapper(osuParser);
    maniaWrapper->loadMap(getAssetPath("test\\maps\\4key\\4key.osu"));

    double hpDrainRate = maniaWrapper->getHPDrainRate();
    double circleSize = maniaWrapper->getCircleSize();
    double overallDifficulty = maniaWrapper->getOverallDifficulty();
    double approachRate = maniaWrapper->getApproachRate();
    double sliderMultiplier = maniaWrapper->getSliderMultiplier();
    double sliderTickRate = maniaWrapper->getSliderTickRate();

    delete maniaWrapper;
    delete osuParser;

    EXPECT_EQ(hpDrainRate, 7);
    EXPECT_EQ(circleSize, 4);
    EXPECT_EQ(overallDifficulty, 7.5);
    EXPECT_EQ(approachRate, 5);
    EXPECT_EQ(sliderMultiplier, 1.3999999687075613);
    EXPECT_EQ(sliderTickRate, 1);
}

TEST(ManiaWrapper, TestEventsSection)
{
    OsuParser* osuParser = new OsuParser();
    ManiaWrapper* maniaWrapper = new ManiaWrapper(osuParser);
    maniaWrapper->loadMap(getAssetPath("test\\maps\\4key\\4key.osu"));

    BackgroundEvent event = *dynamic_cast<BackgroundEvent*>((maniaWrapper->getEvents())[0]);
    int eventCount = maniaWrapper->getEventCount();
    std::string fileName = event.getFileName();

    delete maniaWrapper;
    delete osuParser;

    ASSERT_GT(eventCount, 0);
    EXPECT_EQ(fileName, "\"bg.jpg\"");
}

TEST(ManiaWrapper, TestTimingPoints)
{
    OsuParser* osuParser = new OsuParser();
    ManiaWrapper* maniaWrapper = new ManiaWrapper(osuParser);
    maniaWrapper->loadMap(getAssetPath("test\\maps\\4key\\4key.osu"));

    TimingPoint timingPoint = maniaWrapper->getTimingPoints()[0];
    int timingPointsCount = maniaWrapper->getTimingPointsCount();
    
    double time = timingPoint.Time;
    double beatLength = timingPoint.BeatLength;
    int meter = timingPoint.Meter;
    int sampleSet = timingPoint.SampleSet;
    int sampleIndex = timingPoint.SampleIndex;
    int volume = timingPoint.Volume;
    int uninherited = timingPoint.Uninherited;
    int effects = timingPoint.Effects;

    delete maniaWrapper;
    delete osuParser;

    ASSERT_GT(timingPointsCount, 0);
    EXPECT_EQ(time, 1681);
    EXPECT_EQ(beatLength, 430.4160688665709);
    EXPECT_EQ(meter, 4);
    EXPECT_EQ(sampleSet, 1);
    EXPECT_EQ(sampleIndex, 0);
    EXPECT_EQ(volume, 100);
    EXPECT_EQ(uninherited, 1);
    EXPECT_EQ(effects, 0);
}

TEST(ManiaWrapper, TestColours)
{
    OsuParser* osuParser = new OsuParser();
    ManiaWrapper* maniaWrapper = new ManiaWrapper(osuParser);
    maniaWrapper->loadMap(getAssetPath("test\\maps\\4key\\4key.osu"));

    int coloursCount = maniaWrapper->getColoursCount();
    ASSERT_GT(coloursCount, 0);

    Colour colour = maniaWrapper->getColours()[0];

    int comboNum = colour.ComboNum;
    int r = colour.Red;
    int g = colour.Green;
    int b = colour.Blue;
    int a = colour.Alpha;

    delete maniaWrapper;
    delete osuParser;

    EXPECT_EQ(comboNum, 1);
    EXPECT_EQ(r, 255);
    EXPECT_EQ(g, 192);
    EXPECT_EQ(b, 0);
    EXPECT_EQ(a, 255);
}

TEST(ManiaWrapper, TestHitObjects)
{
    OsuParser* osuParser = new OsuParser();
    ManiaWrapper* maniaWrapper = new ManiaWrapper(osuParser);
    maniaWrapper->loadMap(getAssetPath("test\\maps\\4key\\4key.osu"));

    int hitObjectsCount = maniaWrapper->getHitObjectsCount();
    ASSERT_GT(hitObjectsCount, 0);

    HitObject* hitObject = maniaWrapper->getHitObjects()[0];

    int x = hitObject->X;
    int y = hitObject->Y;
    int time = hitObject->Time;
    int type = hitObject->Type;
    int hitSound = hitObject->HitSound;
    std::vector<HitSampleType> hitSample = hitObject->HitSample;

    delete maniaWrapper;
    delete osuParser;

    EXPECT_EQ(x, 448);
    EXPECT_EQ(y, 192);
    EXPECT_EQ(time, 1681);
    EXPECT_EQ(type, 1);
    EXPECT_EQ(hitSound, 0);
    EXPECT_EQ(std::get<int>(hitSample[0]), 1);
}