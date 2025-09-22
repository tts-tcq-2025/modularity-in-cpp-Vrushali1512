#ifndef COLOR_CODER_H
#define COLOR_CODER_H

typedef enum {
    WHITE, RED, BLACK, YELLOW, VIOLET, NUMBER_OF_MAJOR_COLORS
} MajorColor;

typedef enum {
    BLUE, ORANGE, GREEN, BROWN, SLATE, NUMBER_OF_MINOR_COLORS
} MinorColor;

typedef struct {
    MajorColor major;
    MinorColor minor;
} ColorPair;

const char* MajorColorNames[NUMBER_OF_MAJOR_COLORS];
const char* MinorColorNames[NUMBER_OF_MINOR_COLORS];

ColorPair GetColorFromPairNumber(int pairNumber);
int GetPairNumberFromColor(MajorColor major, MinorColor minor);
void ToString(ColorPair colorPair, char* buffer, int bufferLen);

#endif // COLOR_CODER_H
