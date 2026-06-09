#pragma once

#include <vector>
#include <variant>
#include <string>
#include <stdexcept>

using ObjectParamsType = std::variant<
    int, 
    double, 
    char, 
    std::string,
    std::vector<int>,
    std::vector<std::string>
>;
using HitSampleType = std::variant<
    int,
    std::string
>;

struct SliderObjectParams
{
    char CurveType;
    std::vector<std::string> CurvePoints;
    int Slides;
    double Length;
    std::vector<int> EdgeSounds;
    std::vector<std::string> EdgeSets;
};

struct SpinnerObjectParams
{
    int EndTime;
};

struct HoldNoteObjectParams
{
    int EndTime;
};


struct HitObject
{
public:
    int X;
    int Y;
    int Time;
    int Type;
    int HitSound;
    std::vector<ObjectParamsType> ObjectParams;
    std::vector<HitSampleType> HitSample;

    // Time
    int getStartTime() const;

    // Type
    bool isHitCircle() const;
    bool isSlider() const;
    bool isNewCombo() const;
    bool isSpinner() const;
    bool isHoldNote() const;
    static bool isHitCircle(const int& type);
    static bool isSlider(const int& type);
    static bool isNewCombo(const int& type);
    static bool isSpinner(const int& type);
    static bool isHoldNote(const int& type);

    // HitSound
    bool hasNormalHitsound() const;
    bool hasWhistleHitsound() const;
    bool hasFinishHitsound() const;
    bool hasClapHitsound() const;

    // ObjectParams
    SliderObjectParams getSliderObjectParams() const;
    SpinnerObjectParams getSpinnerObjectParams() const;
    HoldNoteObjectParams getHoldNoteObjectParams() const;

    // HitSample
    int getNormalSet() const;
    int getAdditionSet() const;
    int getIndex() const;
    int getVolume() const;
    std::string getFileName() const;

protected:
    template <typename T, typename R>
    R _getTypeInVector(T vec, int pos) const
    {
        if (std::holds_alternative<R>(vec[pos])
            && pos < vec.size()
            && pos >= 0)
        {
            return std::get<R>(vec[pos]);
        }
        throw std::invalid_argument("Not correct type or not in range.");
    }
};


struct SliderHitObject : public HitObject
{
public:
    SliderHitObject() { _sliderObjectParams = getSliderObjectParams(); }

    // ObjectParams
    char getCurveType() const;
    std::vector<std::string> getCurvePoints() const;
    int getSlides() const;
    double getLength() const;
    std::vector<int> getEdgeSounds() const;
    std::vector<std::string> getEdgeSets() const;

protected:
    SliderObjectParams _sliderObjectParams;
};


struct SpinnerHitObject : public HitObject
{
public:
    SpinnerHitObject() { _spinnerObjectParams = getSpinnerObjectParams(); }

    // ObjectParams
    int getEndTime() const;

protected:
    SpinnerObjectParams _spinnerObjectParams;
};


struct HoldNoteHitObject : public HitObject
{
public:
    HoldNoteHitObject() { _holdNoteObjectParams = getHoldNoteObjectParams(); }

    // ObjectParams
    int getEndTime() const;

protected:
    HoldNoteObjectParams _holdNoteObjectParams;
};

/*
    Specific Gamemode Hitobjects
*/

// Taiko Note
struct TaikoHitObject : public HitObject
{
    int getStartTime() const;
    int isKat() const;
};

// Taiko Drumroll
struct TaikoSliderHitObject : public SliderHitObject
{
    int getStartTime() const;
    int getSliderLength() const;
    int getEndTime() const;
};

// Taiko Spinner
struct TaikoSpinnerHitObject : public SpinnerHitObject
{
    int getStartTime() const;
    int getSpinnerLength() const;
    int getEndTime() const;
};

// Mania Note
struct ManiaHitObject : public HitObject
{
public:
    int KeyCount;

    int getColumnNum();
    int getStartTime() const;
};

// Mania Note
struct ManiaHoldNoteHitObject : public HoldNoteHitObject
{
public:
    int KeyCount;

    int getColumnNum();
    int getStartTime() const;
    int getEndTime() const;
};