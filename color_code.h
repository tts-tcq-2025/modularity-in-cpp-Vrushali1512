#ifndef COLOR_CODE_H
#define COLOR_CODE_H

#include <string>
#include <vector>

namespace ColorCode {

struct ColorPair {
    std::string majorColor;
    std::string minorColor;
};

const int numberOfMajorColors = 5;
const int numberOfMinorColors = 5;
const int numberOfColorPairs = numberOfMajorColors * numberOfMinorColors;

ColorPair GetColorFromPairNumber(int pairNumber);
int GetPairNumberFromColor(const ColorPair& colorPair);
std::string GetReferenceManual();

}  // namespace ColorCode

#endif  // COLOR_CODE_H
