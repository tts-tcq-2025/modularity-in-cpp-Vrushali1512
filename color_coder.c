#include "./color_coder.h"
#include <stdio.h>

const char* MajorColorNames[NUMBER_OF_MAJOR_COLORS] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

const char* MinorColorNames[NUMBER_OF_MINOR_COLORS] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

ColorPair GetColorFromPairNumber(int pairNumber) {
    int zeroBasedPairNumber = pairNumber - 1;
    ColorPair colorPair;
    colorPair.major = (MajorColor)(zeroBasedPairNumber / NUMBER_OF_MINOR_COLORS);
    colorPair.minor = (MinorColor)(zeroBasedPairNumber % NUMBER_OF_MINOR_COLORS);
    return colorPair;
}

int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
    return major * NUMBER_OF_MINOR_COLORS + minor + 1;
}

void ToString(ColorPair colorPair, char* buffer, int bufferLen) {
    // Safely create a string with "Major Minor"
    snprintf(buffer, bufferLen, "%s %s", MajorColorNames[colorPair.major], MinorColorNames[colorPair.minor]);
}
