#include "hitobjects.h"

#include <cmath>

/*
    HitObject X:
    Calculate column number with key count
*/
int HitObject::getColumnNum(int keyNum)
{
    int columnNum = std::floor(X * keyNum / 512);
    
    if (columnNum < 0)
        return 0;
    if (columnNum >= keyNum)
        return keyNum;
    return columnNum;
}

/*
    HitObject Type Bitmask:
    0   -> hitcircle
    1   -> slider
    2   -> newcombo
    3   -> spinner
    4-6 -> # of colors to skin on newcombo
    7   -> holdnote
*/
bool HitObject::isHitCircle() const
{
    return Type & 1 == 1; // bit 0 on = 1
}

bool HitObject::isSlider() const
{
    return Type & 2 == 2; // bit 1 on = 2
}

bool HitObject::isNewCombo() const
{
    return Type & 4 == 4; // bit 2 on = 4
}

bool HitObject::isSpinner() const
{
    return Type & 8 == 8; // bit 3 on = 8
}

bool HitObject::isHoldNote() const
{
    return Type & 128 == 128; // bit 7 on = 128
}

/*
    HitObject ObjectParams
*/

/*
    Slider ObjectParams:
    0 -> CurveType
    1 -> CurvePoints
    2 -> Slides
    3 -> Length
    4 -> EdgeSounds
    5 -> EdgeSets
*/
SliderObjectParams HitObject::getSliderObjectParams() const
{
    return SliderObjectParams{
        _getTypeInVector<std::vector<ObjectParamsType>, char>(ObjectParams, 0),
        _getTypeInVector<std::vector<ObjectParamsType>, std::vector<std::string>>(ObjectParams, 1),
        _getTypeInVector<std::vector<ObjectParamsType>, int>(ObjectParams, 2),
        _getTypeInVector<std::vector<ObjectParamsType>, double>(ObjectParams, 3),
        _getTypeInVector<std::vector<ObjectParamsType>, std::vector<int>>(ObjectParams, 4),
        _getTypeInVector<std::vector<ObjectParamsType>, std::vector<std::string>>(ObjectParams, 5),
    };
}

/*
    Spinner ObjectParams:
    0 -> EndTime
*/
SpinnerObjectParams HitObject::getSpinnerObjectParams() const
{
    return SpinnerObjectParams{
        _getTypeInVector<std::vector<ObjectParamsType>, int>(ObjectParams, 0),
    };
}

/*
    HoldNote ObjectParams:
    0 -> EndTime
*/
HoldNoteObjectParams HitObject::getHoldNoteObjectParams() const
{
    return HoldNoteObjectParams{
        _getTypeInVector<std::vector<ObjectParamsType>, int>(ObjectParams, 0),
    };
}

/*
    HitObject HitSample:
    0th -> NormalSet
    1st -> AdditionSet
    2nd -> Index
    3rd -> Volume
    4th -> FileName

    x:x:x:x:x
*/
int HitObject::getNormalSet() const
{
    return _getTypeInVector<std::vector<HitSampleType>, int>(HitSample, 0);
}

int HitObject::getAdditionSet() const
{
    return _getTypeInVector<std::vector<HitSampleType>, int>(HitSample, 1);
}

int HitObject::getIndex() const
{
    return _getTypeInVector<std::vector<HitSampleType>, int>(HitSample, 2);
}

int HitObject::getVolume() const
{
    return _getTypeInVector<std::vector<HitSampleType>, int>(HitSample, 3);
}

std::string HitObject::getFileName() const
{
    return _getTypeInVector<std::vector<HitSampleType>, std::string>(HitSample, 4);
}

/*
    SliderHitObject
*/
char SliderHitObject::getCurveType() const
{
    return _sliderObjectParams.CurveType;
}

std::vector<std::string> SliderHitObject::getCurvePoints() const
{
    return _sliderObjectParams.CurvePoints;
}

int SliderHitObject::getSlides() const
{
    return _sliderObjectParams.Slides;
}

double SliderHitObject::getLength() const
{
    return _sliderObjectParams.Length;
}

std::vector<int> SliderHitObject::getEdgeSounds() const
{
    return _sliderObjectParams.EdgeSounds;
}

std::vector<std::string> SliderHitObject::getEdgeSets() const
{
    return _sliderObjectParams.EdgeSets;
}