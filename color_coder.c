#include "color_coder.h"
#include <stddef.h>

// Arrays to hold the string names of the colors
const char* TelCoColorCoder_MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};
const char* TelCoColorCoder_MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

// Calculate the number of colors automatically
const int TelCoColorCoder_numberOfMajorColors =
    sizeof(TelCoColorCoder_MajorColorNames) / sizeof(TelCoColorCoder_MajorColorNames[0]);
const int TelCoColorCoder_numberOfMinorColors =
    sizeof(TelCoColorCoder_MinorColorNames) / sizeof(TelCoColorCoder_MinorColorNames[0]);

// Function to get a color pair from a pair number
TelCoColorCoder_ColorPair TelCoColorCoder_GetColorFromPairNumber(int pairNumber) {
    int zeroBasedPairNumber = pairNumber - 1;
    MajorColor majorColor = (MajorColor)(zeroBasedPairNumber / TelCoColorCoder_numberOfMinorColors);
    MinorColor minorColor = (MinorColor)(zeroBasedPairNumber % TelCoColorCoder_numberOfMinorColors);
    
    // Create and return the struct
    TelCoColorCoder_ColorPair pair = {majorColor, minorColor};
    return pair;
}

// Function to get the pair number from a color pair
int TelCoColorCoder_GetPairNumberFromColor(MajorColor major, MinorColor minor) {
    return major * TelCoColorCoder_numberOfMinorColors + minor + 1;
}
