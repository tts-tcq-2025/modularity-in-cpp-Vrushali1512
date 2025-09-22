#include <stdio.h>
#include <assert.h>
#include "color_code.h"

void testNumberToPair(int pairNumber, MajorColor expectedMajor, MinorColor expectedMinor) {
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairStr[20];
    ToString(colorPair, colorPairStr, sizeof(colorPairStr));
    printf("Got pair %s\n", colorPairStr);
    assert(colorPair.major == expectedMajor);
    assert(colorPair.minor == expectedMinor);
}

void testPairToNumber(MajorColor major, MinorColor minor, int expectedPairNumber) {
    int pairNumber = GetPairNumberFromColor(major, minor);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
    printf("All tests passed.\n");
    return 0;
}
