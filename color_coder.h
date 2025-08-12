#ifndef TELCO_COLOR_CODER_H
#define TELCO_COLOR_CODER_H

// Enums for major and minor colors
typedef enum {WHITE, RED, BLACK, YELLOW, VIOLET} MajorColor;
typedef enum {BLUE, ORANGE, GREEN, BROWN, SLATE} MinorColor;

// A struct to represent a color pair
typedef struct {
    MajorColor majorColor;
    MinorColor minorColor;
} TelCoColorCoder_ColorPair;

// Arrays to hold the string names of the colors
extern const char* TelCoColorCoder_MajorColorNames[];
extern const char* TelCoColorCoder_MinorColorNames[];

// Constants for the number of colors
extern const int TelCoColorCoder_numberOfMajorColors;
extern const int TelCoColorCoder_numberOfMinorColors;

// Function prototypes
TelCoColorCoder_ColorPair TelCoColorCoder_GetColorFromPairNumber(int pairNumber);
int TelCoColorCoder_GetPairNumberFromColor(MajorColor major, MinorColor minor);

#endif // TELCO_COLOR_CODER_H
