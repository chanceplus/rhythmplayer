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
    std::vector<std::string>,
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
    int X;
    int Y;
    int Type;
    int HitSound;
    std::vector<ObjectParamsType> ObjectParams;
    std::vector<HitSampleType> HitSample;

    // X
    int getColumnNum(int keyNum); // Mania only

    // Type
    bool isHitCircle() const;
    bool isSlider() const;
    bool isNewCombo() const;
    bool isSpinner() const;
    bool isHoldNote() const;

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

private:
    template <typename T, typename R>
    R _getTypeInVector(T vec, int pos) const
    {
        if (std::holds_alternative<R>(ObjectParams[pos])
            && pos < ObjectParams.size()
            && pos >= 0)
        {
            return std::get<R>(ObjectParams[pos]);
        }
        throw std::invalid_argument("Not correct type or not in range.");
    }
};

struct SliderHitObject : public HitObject
{
public:
    SliderHitObject() { _sliderObjectParams = getSliderObjectParams(); }
    char getCurveType() const;
    std::vector<std::string> getCurvePoints() const;
    int getSlides() const;
    double getLength() const;
    std::vector<int> getEdgeSounds() const;
    std::vector<std::string> getEdgeSets() const;

private:
    SliderObjectParams _sliderObjectParams;
};

// TODO: SpinnerHitObject

// TODO: HoldNoteHitObject