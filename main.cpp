#include <stdio.h>
#include <assert.h>
#include "color_coder.h"

// Test function to check number-to-pair conversion
void testNumberToPair(int pairNumber, MajorColor expectedMajor, MinorColor expectedMinor) {
    TelCoColorCoder_ColorPair colorPair = TelCoColorCoder_GetColorFromPairNumber(pairNumber);
    assert(colorPair.majorColor == expectedMajor && colorPair.minorColor == expectedMinor);
    printf("Test for pair number %d passed.\n", pairNumber);
}

// Test function to check pair-to-number conversion
void testPairToNumber(MajorColor major, MinorColor minor, int expectedPairNumber) {
    int pairNumber = TelCoColorCoder_GetPairNumberFromColor(major, minor);
    assert(pairNumber == expectedPairNumber);
    printf("Test for color pair %s %s passed.\n",
           TelCoColorCoder_MajorColorNames[major],
           TelCoColorCoder_MinorColorNames[minor]);
}

int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);
    
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
    
    return 0;
}
