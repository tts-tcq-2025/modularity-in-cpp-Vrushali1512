#include "color_code.h"
#include <sstream>
#include <stdexcept>

namespace ColorCode {

const std::vector<std::string> majorColors = {
    "White", "Red", "Black", "Yellow", "Violet"
};

const std::vector<std::string> minorColors = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

ColorPair GetColorFromPairNumber(int pairNumber) {
    if (pairNumber < 1 || pairNumber > numberOfColorPairs) {
        throw std::out_of_range("Invalid pair number");
    }
    int zeroBasedPair = pairNumber - 1;
    int majorIndex = zeroBasedPair / numberOfMinorColors;
    int minorIndex = zeroBasedPair % numberOfMinorColors;
    return ColorPair{majorColors[majorIndex], minorColors[minorIndex]};
}

int GetPairNumberFromColor(const ColorPair& colorPair) {
    int majorIndex = -1;
    int minorIndex = -1;
    for (int i = 0; i < numberOfMajorColors; ++i) {
        if (majorColors[i] == colorPair.majorColor) {
            majorIndex = i;
            break;
        }
    }
    for (int i = 0; i < numberOfMinorColors; ++i) {
        if (minorColors[i] == colorPair.minorColor) {
            minorIndex = i;
            break;
        }
    }
    if (majorIndex == -1 || minorIndex == -1) {
        throw std::invalid_argument("Invalid color names");
    }
    return majorIndex * numberOfMinorColors + minorIndex + 1;
}

std::string GetReferenceManual() {
    std::ostringstream oss;
    oss << "Pair Number | Major Color | Minor Color\n";
    oss << "-------------------------------------\n";
    for (int i = 1; i <= numberOfColorPairs; ++i) {
        ColorPair pair = GetColorFromPairNumber(i);
        oss << "     " << i << "      | " << pair.majorColor << "       | " << pair.minorColor << "\n";
    }
    return oss.str();
}

}  // namespace ColorCode
