#pragma once

struct TimingPoint
{
    double Time;
    double BeatLength;
    int Meter;
    int SampleSet;
    int SampleIndex;
    int Volume;
    int Uninherited;
    int Effects;

    // BeatLength
    bool isBPM() const;
    double getBPM() const;
    double getSV() const;

    // Effects
    bool isKiaiEnabled() const;
    bool isFirstBarlineOmitted() const;
};